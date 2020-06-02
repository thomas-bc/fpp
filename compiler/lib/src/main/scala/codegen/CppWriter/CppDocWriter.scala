package fpp.compiler.codegen

import java.time.Year

/** A C++ doc writer */
trait CppDocWriter extends CppDocVisitor with LineUtils {

  case class Input(
    /** The hpp file */
    hppFile: CppDoc.HppFile,
    /** The cpp file name */
    cppFileName: String,
    /** The list of enclosing class names, backwards. A class name may include :: */
    classNameList: List[String] = Nil,
  ) {

    def getEnclosingClassQualified = classNameList.reverse.mkString("::")
 
    def getEnclosingClassUnqualified = classNameList.head.split("::").reverse.head

  }

  def default(in: Input) = Output()

  def visitCppDoc(cppDoc: CppDoc): Output

  /*
  def visitCppDoc(cppDoc: CppDoc): Output = {
    val hppFile = cppDoc.hppFile
    val cppFileName = cppDoc.cppFileName
    val in = Input(hppFile, cppFileName)
    val body = cppDoc.members.foldRight(Output())(
      { case (member, output) => visitMember(in, member) ++ output }
    )
    List(
      Output(CppDocWriter.writeBanner(in.hppFile.name), CppDocWriter.writeBanner(in.cppFileName)),
      Output.hpp(CppDocWriter.openIncludeGuard(hppFile.includeGuard)),
      body,
      Output.hpp(CppDocWriter.closeIncludeGuard)
    ).fold(Output())(_ ++ _)
  }

  override def visitClass(in: Input, c: CppDoc.Class): Output = {
    val name = c.name
    val newClassNameList = name :: in.classNameList
    val in1 = in.copy(classNameList = newClassNameList)
    val hppStartLines = c.superclassDecls match {
      case Some(d) => List(
        Line.blank,
        line(s"class $name :"), 
        indentIn(line(d)),
        line("{")
      )
      case None => List(Line.blank, line(s"class $name {"))
    }
    val output = {
      val Output(hppLines, cppLines) = c.members.foldRight(Output())(
        { case (member, output) => visitClassMember(in1, member) ++ output }
      )
      Output(hppLines.map(_.indentIn(2 * indentIncrement)), cppLines)
    }
    val hppEndLines = List(
      Line.blank,
      line("};")
    )
    Output.hpp(hppStartLines) ++ output ++ Output.hpp(hppEndLines)
  }

  override def visitConstructor(in: Input, constructor: CppDoc.Class.Constructor) = {
    val unqualifiedClassName = in.getEnclosingClassUnqualified
    val qualifiedClassName = in.getEnclosingClassQualified
    val hppLines = {
      val lines1 = CppDocWriter.doxygenCommentOpt(constructor.comment)
      val lines2 = {
        val params = CppDocWriter.writeHppParams(unqualifiedClassName, constructor.params)
        Line.addSuffix(params, ";")
      }
      lines1 ++ lines2
    }
    val cppLines = {
      val nameLines = lines(s"$qualifiedClassName ::")
      val paramLines = {
        val lines1 = CppDocWriter.writeCppParams(unqualifiedClassName, constructor.params)
        val lines2 = constructor.initializers match {
          case Nil => lines1
          case _ => Line.addSuffix(lines1, " :")
         }
        lines2.map(indentIn(_))
      }
      val initializerLines = constructor.initializers.reverse match {
        case Nil => Nil
        case head :: tail => {
          val list = head :: tail.map(_ ++ ",")
          list.reverse.map(line(_)).map(_.indentIn(2 * indentIncrement))
        }
      }
      val bodyLines = CppDocWriter.writeFunctionBody(constructor.body)
      Line.blank :: List(
        nameLines,
        paramLines,
        initializerLines,
        bodyLines
      ).flatten
    }
    Output(hppLines, cppLines)
  }

  override def visitDestructor(in: Input, destructor: CppDoc.Class.Destructor) = {
    val unqualifiedClassName = in.getEnclosingClassUnqualified
    val qualifiedClassName = in.getEnclosingClassQualified
    val hppLines = {
      val lines1 = CppDocWriter.doxygenCommentOpt(destructor.comment)
      val lines2 = destructor.virtualQualifier match {
        case CppDoc.Class.Destructor.Virtual => lines(s"virtual ~$unqualifiedClassName();")
        case _ => lines(s"~$unqualifiedClassName();")
      }
      lines1 ++ lines2
    }
    val cppLines = {
      val startLine1 = line(s"$qualifiedClassName ::")
      val startLine2 = indentIn(line(s"~$unqualifiedClassName()"))
      val bodyLines = CppDocWriter.writeFunctionBody(destructor.body)
      Line.blank :: startLine1 :: startLine2 :: bodyLines
    }
    Output(hppLines, cppLines)
  }

  override def visitFunction(in: Input, function: CppDoc.Function) = {
    import CppDoc.Function._
    val hppLines = {
      val lines1 = CppDocWriter.doxygenCommentOpt(function.comment)
      val lines2 = {
        val prefix = {
          val prefix1 = function.svQualifier match {
            case Virtual => "virtual "
            case PureVirtual => "virtual "
            case Static => "static "
            case _ => ""
          }
          prefix1 ++ s"${function.retType.hppType} ${function.name}"
        }
        val lines1 = {
          val lines1 = CppDocWriter.writeHppParams(prefix, function.params)
          function.constQualifier match {
            case Const => Line.addSuffix(lines1, " const")
            case _ => lines1
          }
        }
        val lines2 = function.svQualifier match {
          case PureVirtual => lines(" = 0;")
          case _ => lines(";")
        }
        Line.joinLists(Line.NoIndent)(lines1)("")(lines2)
      }
      lines1 ++ lines2
    }
    val cppLines = {
      val contentLines = {
        val startLines = {
          val prototypeLines = {
            val lines1 = CppDocWriter.writeCppParams(function.name, function.params)
            function.constQualifier match {
              case CppDoc.Function.Const => Line.addSuffix(lines1, " const")
              case CppDoc.Function.NonConst => lines1
            }
          }
          in.classNameList match {
            case head :: _ => {
              val line1 = line(s"${function.retType.getCppType} $head ::")
              line1 :: prototypeLines.map(indentIn(_))
            }
            case Nil => prototypeLines
          }
        }
        val bodyLines = CppDocWriter.writeFunctionBody(function.body)
        in.classNameList match {
          case _ :: _ => startLines ++ bodyLines
          case Nil => Line.joinLists(Line.NoIndent)(startLines)(" ")(bodyLines)
        }
      }
      Line.blank :: contentLines
    }
    Output(hppLines, cppLines)
  }

  override def visitLines(in: Input, lines: CppDoc.Lines) = {
    val content = lines.content
    lines.output match {
      case CppDoc.Lines.Hpp => Output.hpp(content)
      case CppDoc.Lines.Cpp => Output.cpp(content)
      case CppDoc.Lines.Both => Output.both(content)
    }
  }

  override def visitNamespace(in: Input, namespace: CppDoc.Namespace): Output = {
    val name = namespace.name
    val output = namespace.members.foldRight(Output())(
      { case (member, output) => visitNamespaceMember(in, member) ++ output }
    )
    val startLines = List(Line.blank, line(s"namespace $name {"))
    val endLines = List(Line.blank, line("}"))
    val startOutput = Output.both(startLines)
    val endOutput = Output.both(endLines)
    startOutput ++ output.indentIn() ++ endOutput
  }
  */

  case class Output(
    /** The lines of the hpp file */
    hppLines: List[Line] = Nil,
    /** The lines of the cpp file */
    cppLines: List[Line] = Nil,
  ) {

    def ++(output: Output) = Output(hppLines ++ output.hppLines, cppLines ++ output.cppLines)

    def indentIn(increment: Int = indentIncrement) = 
      Output(hppLines.map(_.indentIn(increment)), cppLines.map(_.indentIn(increment)))

  }

  object Output {

    def both(lines: List[Line]) = Output(lines, lines)
    
    def cpp(lines: List[Line]) = Output(Nil, lines)

    def hpp(lines: List[Line]) = Output(lines, Nil)

  }

}

object CppDocWriter extends LineUtils {

  def accessTag(tag: String) = List(
    Line.blank,
    line(s"$tag:").indentOut(2)
  )

  def bannerComment(comment: String) = {
    def banner =
      line("// ----------------------------------------------------------------------")
    (Line.blank :: banner :: commentBody(comment)) :+ banner
  }

  def comment(comment: String) = Line.blank :: commentBody(comment)

  def doxygenCommentOpt(commentOpt: Option[String]) = commentOpt match {
    case Some(comment) => doxygenComment(comment)
    case None => Line.blank :: Nil
  }
    
  def doxygenComment(comment: String) = 
    Line.blank ::lines(comment).map(Line.join(" ")(line("//!"))_)
    
  def commentBody(comment: String) = lines(comment).map(Line.join(" ")(line("//"))_)

  def cppParamString(p: CppDoc.Function.Param) = s"${p.t.hppType} ${p.name}"

  def writeCppParam(p: CppDoc.Function.Param) = line(cppParamString(p))

  def writeCppParamComma(p: CppDoc.Function.Param) = line(cppParamStringComma(p))

  def hppParamString(p: CppDoc.Function.Param) = {
    val s1 = CppDocWriter.cppParamString(p)
    val s2 = addParamComment(s1, p.comment)
    s2
  }

  def addParamComment(s: String, commentOpt: Option[String]) = commentOpt match {
    case Some(comment) => s"$s //!< ${"\n".r.replaceAllIn(comment, " ")}"
    case None => s
  }

  def closeIncludeGuard = lines(
    """|
       |#endif"""
  )

  def cppParamStringComma(p: CppDoc.Function.Param) = s"${p.t.hppType} ${p.name},"

  def hppParamStringComma(p: CppDoc.Function.Param) = {
    val s1 = cppParamStringComma(p)
    val s2 = addParamComment(s1, p.comment)
    s2
  }

  def leftAlignDirective(line: Line) =
    if (line.string.startsWith("#")) Line(line.string) else line

  def openIncludeGuard(guard: String): List[Line] = {
    lines(
      s"""|
          |#ifndef $guard
          |#define $guard"""
    )
  }

  def writeBanner(title: String) = lines(
    s"""|// ====================================================================== 
        |// \\title  $title
        |// \\author Generated by fpp-to-cpp
        |//
        |// \\copyright
        |// Copyright (C) ${Year.now.getValue} California Institute of Technology.
        |// ALL RIGHTS RESERVED.  United States Government Sponsorship
        |// acknowledged. Any commercial use must be negotiated with the Office
        |// of Technology Transfer at the California Institute of Technology.
        |// 
        |// This software may be subject to U.S. export control laws and
        |// regulations.  By accepting this document, the user agrees to comply
        |// with all U.S. export laws and regulations.  User has the
        |// responsibility to obtain export licenses, or other export authority
        |// as may be required before exporting such information to foreign
        |// countries or providing access to foreign persons.
        |// ======================================================================"""
  )

  def writeCppParams(prefix: String, params: List[CppDoc.Function.Param]) = {
    if (params.length == 0) lines(s"$prefix()")
    else if (params.length == 1)
      lines(s"$prefix(" ++ CppDocWriter.cppParamString(params.head) ++ ")")
    else {
      val head :: tail = params.reverse
      val paramLines = (writeCppParam(head) :: tail.map(writeCppParamComma(_))).reverse
      line(s"$prefix(") :: (paramLines.map(_.indentIn(2 * indentIncrement)) :+ line(")"))
    }
  }

  def writeFunctionBody(body: List[Line]) = {
    val bodyLines = body.length match {
      case 0 => Line.blank :: Nil
      case _ => body.map(indentIn(_))
    }
    (line("{") :: bodyLines) :+ line("}")
  }

  def writeHppParam(p: CppDoc.Function.Param) = line(hppParamString(p))

  def writeHppParamComma(p: CppDoc.Function.Param) = line(hppParamStringComma(p))

  def writeHppParams(prefix: String, params: List[CppDoc.Function.Param]) = {
    if (params.length == 0) lines(s"$prefix()")
    else if (params.length == 1 && params.head.comment.isEmpty)
      lines(s"$prefix(" ++ hppParamString(params.head) ++ ")")
    else {
      val head :: tail = params.reverse
      val paramLines = (writeHppParam(head) :: tail.map(writeHppParamComma(_))).reverse
      line(s"$prefix(") :: (paramLines.map(_.indentIn(2 * indentIncrement)) :+ line(")"))
    }
  }

}
