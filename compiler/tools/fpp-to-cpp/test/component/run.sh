fprime_dir=`dirname $PWD`/fprime

types()
{
  run_test "-p $PWD" types && \
  diff_cpp NoArgsPort && \
  diff_cpp NoArgsReturnPort && \
  diff_cpp TypedPort && \
  diff_cpp TypedReturnPort && \
  diff_cpp EEnum && \
  diff_cpp AArray && \
  diff_cpp SSerializable
}

empty()
{
  run_test "-i `cat deps-comma.txt`" "-p $PWD,$fprime_dir empty" empty && \
  diff_cpp EmptyComponent
}

passive()
{
  run_test "-i `cat deps-comma.txt`,types.fpp" "-p $PWD,$fprime_dir passive" passive && \
  diff_cpp PassiveTestComponent && \
  diff_cpp PassiveSerialComponent && \
  diff_cpp PassiveCommandsComponent && \
  diff_cpp PassiveEventsComponent && \
  diff_cpp PassiveTelemetryComponent && \
  diff_cpp PassiveParamsComponent
}

active()
{
  run_test "-i `cat deps-comma.txt`,types.fpp" "-p $PWD,$fprime_dir active" active && \
  diff_cpp ActiveTestComponent && \
  diff_cpp ActiveSerialComponent && \
  diff_cpp ActiveCommandsComponent && \
  diff_cpp ActiveEventsComponent && \
  diff_cpp ActiveTelemetryComponent && \
  diff_cpp ActiveParamsComponent && \
  diff_cpp ActiveDpComponent
}

queued()
{
  run_test "-i `cat deps-comma.txt`,types.fpp" "-p $PWD,$fprime_dir queued" queued && \
  diff_cpp QueuedTestComponent && \
  diff_cpp QueuedSerialComponent && \
  diff_cpp QueuedCommandsComponent && \
  diff_cpp QueuedEventsComponent && \
  diff_cpp QueuedTelemetryComponent && \
  diff_cpp QueuedParamsComponent
}
