#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <unordered_map>
#include <vector>
#include <memory>
#include "Event.h"
#include "Subscriber.h"

class Publisher {
private:
    std::unordered_map<std::string, std::vector<std::shared_ptr<Subscriber>>> subscribers;

public:
    void subscribe(std::string eventType, std::shared_ptr<Subscriber> subscriber);
    void publish(std::string eventType, const Event& event);
};

#endif // PUBLISHER_H