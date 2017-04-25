#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "AbstractTask.h"

#define MAX_TASK_COUNT 16

#define TASK_INIT_WDTO WDTO_2S
#define TASK_UPDATE_WDTO WDTO_4S

class TaskManager {
public:
  TaskManager();

  bool registerTask(AbstractTask *task);

  void init();

  void update();

private:
  AbstractTask* tasks[MAX_TASK_COUNT];
  uint8_t taskCount = 0;

};

#endif /* TASKMANAGER_H */

