#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>


// This is an interface class for Customer (Observer) class
class Observer {

public:
  virtual ~Observer(){};
  virtual void update(const std::string &message_from_subject) = 0;
};

#endif