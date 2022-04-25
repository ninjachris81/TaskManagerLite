#include "TaskManager.h"

#if defined(ESP8266) || defined(ESP31B) || defined(ESP32)
	// WDT defined in ESP.h
#else
	#include <avr/wdt.h>
#endif

TaskManager::TaskManager() {
  for (uint8_t i=0; i<taskCount; i++) {
	  tasks[i] = NULL;
  }
}

bool TaskManager::registerTask(AbstractTask *task) {
  if (taskCount>=MAX_TASK_COUNT) return false;    // max tasks reached
  tasks[taskCount] = task;
  taskCount++;
  task->setTaskManager(this);
  return true;
}

bool TaskManager::registerTask(AbstractTask *task, uint8_t index) {
  if (index>=MAX_TASK_COUNT) return false;    // max tasks reached
  tasks[index] = task;
  taskCount = max(index, taskCount) + 1;
  task->setTaskManager(this);
  return true;
}

void TaskManager::init() {
#ifndef	ESP32
  wdt_enable(TASK_INIT_WDTO);
#endif
  
  for (uint8_t i=0; i<taskCount; i++) {
    if (tasks[i] != NULL) tasks[i]->init();
#ifndef	ESP32
    wdt_reset();
#endif
  }
}

void TaskManager::update() {
#ifndef	ESP32
  wdt_enable(TASK_UPDATE_WDTO);
#endif
  
  for (uint8_t i=0; i<taskCount; i++) {
	  if (tasks[i] != NULL) {
		if (tasks[i]->doUpdate()) tasks[i]->update();
		#ifndef	ESP32
		wdt_reset();
		#endif
		}
	  }
  
#ifndef	ESP32
  wdt_disable();
#endif
}