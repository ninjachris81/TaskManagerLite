#ifndef ABSTRACTIDLETASK_H
#define ABSTRACTIDLETASK_H

#include "AbstractTask.h"

class AbstractIdleTask : public AbstractTask {
public:
  virtual void init() = 0;

  void update() {}
  
  bool doUpdate() {
	  return false;
  }
};

#endif /* ABSTRACTIDLETASK_H */

