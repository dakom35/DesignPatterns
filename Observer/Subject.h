#ifndef SUBJECT_H
#define SUBJECT_H


#include "Observer.h"

#include <iostream>

// This is an interface class for GroceryStore (Subject/Publisher) class
class Subject {
public:
  virtual ~Subject(){};
  virtual void subscribe(Observer *observer) = 0;
  virtual void unsubscribe(Observer *observer) = 0;
  virtual void notify(std::string msg) = 0;
};

#endif