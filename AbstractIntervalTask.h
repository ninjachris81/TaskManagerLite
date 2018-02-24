#ifndef ABSTRACTINTERVALTASK_H
#define ABSTRACTINTERVALTASK_H

#include "AbstractTask.h"

class AbstractIntervalTask : public AbstractTask {
public:
  AbstractIntervalTask(unsigned long intervalMs, bool firstUpdateImmediately = false) {
    this->intervalMs = intervalMs;
	this->lastUpdate = firstUpdateImmediately ? millis() + intervalMs : millis();
  }

  bool doUpdate() {
    unsigned long currentMillis = millis();
    if (currentMillis - lastUpdate >= intervalMs) {      
      lastUpdate = currentMillis;
	  return true;
    }
	return false;
  };

protected:
  void setInterval(unsigned long intervalMs) {
    this->intervalMs = intervalMs;
  }

private:
  unsigned long intervalMs = 1000;
  unsigned long lastUpdate;
};

#endif /* ABSTRACTINTERVALTASK_H */
