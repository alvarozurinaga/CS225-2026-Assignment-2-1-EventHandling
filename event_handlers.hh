// File: event_handlers.hh
// Course: CS225
// Assignment: 2.1 - Event Handling
// Description: The event handler interface, template, and manager.

#ifndef CS225_EVENT_HANDLERS_HH
#define CS225_EVENT_HANDLERS_HH

#include "event.hh"
#include <cstddef>
#include <vector>

class IEventHandler
{
public:
    // Function: ~IEventHandler
    // Allows safe deletion through an IEventHandler pointer.
    // Parameters: None.
    // Returns: Nothing.
    virtual ~IEventHandler() = default;

    // Function: call
    // Handles an event in a derived class.
    // Parameters: event is the event to handle.
    // Returns: Nothing.
    virtual void call(Event* event) = 0;
};

template <typename T, typename E>
class EventHandler : public IEventHandler
{
public:
    // A pointer to a method in T that receives an E pointer.
    using ActionMethod = void (T::*)(E*);

    // Function: EventHandler
    // Stores the object and the method that handles its events.
    // Parameters: object receives events; actionMethod handles them.
    // Returns: Nothing.
    EventHandler(T* object, ActionMethod actionMethod)
        : object(object), actionMethod(actionMethod)
    {
    }

    // Function: call
    // Calls the method only when the event has the right type.
    // Parameters: event is the event to check and handle.
    // Returns: Nothing.
    void call(Event* event) override
    {
        // A wrong event type gives us a null pointer.
        E* specificEvent = dynamic_cast<E*>(event);

        if (specificEvent != nullptr &&
            object != nullptr &&
            actionMethod != nullptr)
        {
            (object->*actionMethod)(specificEvent);
        }
    }

private:
    T* object;
    ActionMethod actionMethod;
};

class EventManager
{
public:
    // Function: registerEventHandler
    // Adds an event handler to the list.
    // Parameters: handler is the handler to add.
    // Returns: Nothing.
    void registerEventHandler(IEventHandler* handler);

    // Function: getEventHandlerAt
    // Gets the handler at the given position, starting from zero.
    // Parameters: index is the handler's position.
    // Returns: A pointer to the handler.
    // Throws std::out_of_range if the position is not in the list.
    IEventHandler* getEventHandlerAt(std::size_t index);

    // Function: notifyEvent
    // Sends the event to all registered handlers.
    // Parameters: event is the event to send.
    // Returns: Nothing.
    void notifyEvent(Event* event);

private:
    // The caller owns the handlers, so the manager does not delete them.
    std::vector<IEventHandler*> handlers;
};

#endif