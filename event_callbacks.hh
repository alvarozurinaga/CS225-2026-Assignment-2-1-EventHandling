// File: event_callbacks.hh
// Course: CS225
// Assignment: 2.1 - Event Handling
// Description: Event listeners and the callback dispatcher.

#ifndef CS225_EVENT_CALLBACKS_HH
#define CS225_EVENT_CALLBACKS_HH

#include "event.hh"
#include <cstddef>
#include <vector>

// A callback receives the object and the event.
using CallbackFunction = void (*)(void*, Event*);

struct EventListener
{
    void* contextObject = nullptr;
    CallbackFunction callbackFunction = nullptr;
};

class EventDispatcher
{
public:
    // Function: subscribe
    // Adds an object and its callback to the list.
    // Parameters: contextObject is the object; callbackFunction handles events.
    // Returns: Nothing.
    void subscribe(void* contextObject, CallbackFunction callbackFunction);

    // Function: getListenerAt
    // Gets the listener at the given position, starting from zero.
    // Parameters: index is the listener's position.
    // Returns: A pointer to the listener.
    // Throws std::out_of_range if the position is not in the list.
    EventListener* getListenerAt(std::size_t index);

    // Function: dispatchEvent
    // Sends the event to all registered callbacks.
    // Parameters: event is the event to send.
    // Returns: Nothing.
    void dispatchEvent(Event* event);

private:
    // The objects belong to the caller.
    std::vector<EventListener> listeners;
};

#endif