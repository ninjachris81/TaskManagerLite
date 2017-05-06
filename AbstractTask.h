#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include "TaskManager.h"

class TaskManager;

class AbstractTask {
public:
  virtual void init() = 0;

  virtual void update() = 0;
  
  virtual bool doUpdate() {
	  return true;
  }
  
  void setTaskManager(TaskManager* taskManager) {
	  this->taskManager = taskManager;
  }
  
  
protected:
  TaskManager* taskManager;
};

#endif /* ABSTRACTTASK_H */

