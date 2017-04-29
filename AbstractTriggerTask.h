#ifndef ABSTRACTTRIGGERTASK_H
#define ABSTRACTTRIGGERTASK_H

class AbstractTriggerTask : public AbstractTask {
public:
  bool doUpdate() {
	  return hasUpdateScheduled;
  }

  void triggerUpdate() {
	  hasUpdateScheduled = true;
  }
private:
	bool hasUpdateScheduled = false;
  
    
};

#endif /* ABSTRACTTRIGGERTASK_H */

