// File: event_handlers.cc
// Course: CS225
// Assignment: 2.1 - Event Handling
// Description: Functions for the event manager.

#include "event_handlers.hh"

void EventManager::registerEventHandler(IEventHandler* handler)
{
    handlers.push_back(handler);
}

IEventHandler* EventManager::getEventHandlerAt(std::size_t index)
{
    return handlers.at(index);
}

void EventManager::notifyEvent(Event* event)
{
    for (IEventHandler* handler : handlers)
    {
        if (handler != nullptr)
        {
            handler->call(event);
        }
    }
}