#include "Publisher.h"

void Publisher::subscribe(std::string eventType, std::shared_ptr<Subscriber> subscriber) {
    subscribers[eventType].push_back(subscriber);
}

void Publisher::publish(std::string eventType, const Event& event) {
    auto it = subscribers.find(eventType);
    if (it != subscribers.end()) {
        for (auto& subscriber : it->second) {
            subscriber->notify(event);
        }
    }
}