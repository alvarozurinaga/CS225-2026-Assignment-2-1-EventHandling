// File: event_callbacks.cc
// Course: CS225
// Assignment: 2.1 - Event Handling
// Description: Functions for the callback dispatcher.

#include "event_callbacks.hh"

void EventDispatcher::subscribe(void* contextObject,
                                CallbackFunction callbackFunction)
{
    EventListener listener;
    listener.contextObject = contextObject;
    listener.callbackFunction = callbackFunction;

    // Keep listeners in the order they were added.
    listeners.push_back(listener);
}

EventListener* EventDispatcher::getListenerAt(std::size_t index)
{
    return &listeners.at(index);
}

void EventDispatcher::dispatchEvent(Event* event)
{
    for (const EventListener& listener : listeners)
    {
        // Only call a callback if one was given.
        if (listener.callbackFunction != nullptr)
        {
            listener.callbackFunction(listener.contextObject, event);
        }
    }
}