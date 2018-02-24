#ifndef ABSTRACTTRIGGERTASK_H
#define ABSTRACTTRIGGERTASK_H

#include "AbstractTask.h"

class AbstractTriggerTask : public AbstractTask {
public:
  bool doUpdate() {
	  if (updateScheduledTime==0) return false;
	  
	  if (millis() > updateScheduledTime) {
		  updateScheduledTime = 0;
		  return true;
	  } else {
		  return false;
	  }
  }

  void triggerUpdate() {
	  updateScheduledTime = millis();
  }
  
  void triggerUpdateDelay(uint64_t inMs) {
	  updateScheduledTime = millis() + inMs;
  }
  
private:
	uint64_t updateScheduledTime = 0;
    
};

#endif /* ABSTRACTTRIGGERTASK_H */

