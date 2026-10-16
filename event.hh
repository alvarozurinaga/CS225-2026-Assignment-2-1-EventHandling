// File: event.hh
// Course: CS225
// Assignment: 2.1 - Event Handling
// Description: Base class for all events.

#ifndef CS225_EVENT_HH
#define CS225_EVENT_HH

class Event
{
public:
    // Function: ~Event
    // Makes Event abstract and allows safe deletion through an Event pointer.
    // Parameters: None.
    // Returns: Nothing.
    virtual ~Event() = 0;
};

// Function: Event::~Event
// Gives the pure virtual destructor its required body.
// Parameters: None.
// Returns: Nothing.
inline Event::~Event()
{
}

#endif