// Subscriber.h
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Event.h"

class Subscriber {
public:
    virtual ~Subscriber() {}
    virtual void notify(const Event& event) = 0;
};

#endif // SUBSCRIBER_H