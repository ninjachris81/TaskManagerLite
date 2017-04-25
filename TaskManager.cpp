#include "TaskManager.h"
#include <avr/wdt.h>

TaskManager::TaskManager() {
}

bool TaskManager::registerTask(AbstractTask *task) {
  if (taskCount>=MAX_TASK_COUNT) return false;    // max tasks reached
  tasks[taskCount] = task;
  taskCount++;
  return true;
}

void TaskManager::init() {
  wdt_enable(TASK_INIT_WDTO);
  
  for (uint8_t i=0; i<taskCount; i++) {
    tasks[i]->init();
    wdt_reset();
  }
}

void TaskManager::update() {
  wdt_enable(TASK_UPDATE_WDTO);

  for (uint8_t i=0; i<taskCount; i++) {
    tasks[i]->update();
    wdt_reset();
  }
  
  wdt_disable();
}

