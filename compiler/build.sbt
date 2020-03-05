scalaVersion := "2.13.1"

libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "1.1.2"
libraryDependencies += "org.scalatest" % "scalatest_2.13" % "3.1.0" % "test"
scalacOptions += "-deprecation"
scalacOptions += "-unchecked"

testOptions in Test += Tests.Argument(TestFrameworks.ScalaTest, "-oNCXELOPQRM")

lazy val fpp_syntax = (project in file("tools/fpp-syntax"))
lazy val root = (project in file(".")).aggregate(
  fpp_syntax
)
