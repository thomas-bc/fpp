module Fw {
  port Cmd
  port CmdReg
  port CmdResponse
  port PrmGet
  port PrmSet
}

enum Phases {
  configConstants
  configObjects
  instances
  initComponents
  configComponents
  regCommands
  loadParameters
  startTasks
  stopTasks
}
