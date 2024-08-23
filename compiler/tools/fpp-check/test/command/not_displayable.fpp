module Fw {
  port Cmd
  port CmdReg
  port CmdResponse
}

type A

struct S {
  x: A
  y: U32
} default { y = 1 }

active component Comp {

  command recv port cmdIn
  command reg port cmdRegOut
  command resp port cmdResponseOut

  async command C(a1: S)

}
