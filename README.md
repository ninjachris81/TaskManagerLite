# TaskManagerLite

There are 3 different types of task available:

init() -> setup stuff
update() -> execute task

AbstractTask - called every cycle
AbstractIntervalTask - interval tasks (e.g. every 1 second)
AbstractTriggerTask - to manually trigger an update once or delayed
