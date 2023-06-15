fprime_dir=`dirname $PWD`/fprime

types()
{
  update "-p $PWD" types
  move_cpp NoArgsPort
  move_cpp NoArgsReturnPort
  move_cpp TypedPort 
  move_cpp TypedReturnPort
  move_cpp EEnum
  move_cpp AArray
  move_cpp SSerializable
}

empty()
{
  update "-i `cat deps-comma.txt`" "-p $PWD,$fprime_dir empty" empty
  move_cpp EmptyComponent
}

passive()
{
  update "-i `cat deps-comma.txt`,types.fpp" "-p $PWD,$fprime_dir passive" passive
  move_cpp PassiveCommandsComponent
  move_cpp PassiveEventsComponent
  move_cpp PassiveParamsComponent
  move_cpp PassiveSerialComponent
  move_cpp PassiveTelemetryComponent
  move_cpp PassiveTestComponent
}

active()
{
  update "-i `cat deps-comma.txt`,types.fpp" "-p $PWD,$fprime_dir active" active
  move_cpp ActiveCommandsComponent
  move_cpp ActiveDpComponent
  move_cpp ActiveEventsComponent
  move_cpp ActiveParamsComponent
  move_cpp ActiveSerialComponent
  move_cpp ActiveTelemetryComponent
  move_cpp ActiveTestComponent
}

queued()
{
  update "-i `cat deps-comma.txt`,types.fpp" "-p $PWD,$fprime_dir queued" queued
  move_cpp QueuedCommandsComponent
  move_cpp QueuedEventsComponent
  move_cpp QueuedParamsComponent
  move_cpp QueuedSerialComponent
  move_cpp QueuedTelemetryComponent
  move_cpp QueuedTestComponent
}
