#pragma once
#include "UltraEngine.h"

using namespace UltraEngine;

/// <summary>
/// Class representing a UI event.
/// </summary>
class UIEvent
{
public:
    /// <summary>
    /// The associated widget for the event.
    /// </summary>
    shared_ptr<Widget> widget;

    /// <summary>
    /// The action to be executed when the event is triggered.
    /// </summary>
    std::function<void(shared_ptr<Widget> widget, Event e)> action;

    /// <summary>
    /// Constructor for the UIEvent class.
    /// </summary>
    /// <param name="widget">The associated widget for the event.</param>
    /// <param name="action">The action to be executed when the event is triggered.</param>
    UIEvent(shared_ptr<Widget> widget, std::function<void(shared_ptr<Widget> widget, Event e)> action);

    /// <summary>
    /// Creates and returns a new instance of UIEvent.
    /// </summary>
    /// <param name="widget">The associated widget for the event.</param>
    /// <param name="action">The action to be executed when the event is triggered.</param>
    /// <returns>A shared pointer to the newly created UIEvent.</returns>
    static shared_ptr<UIEvent> CreateUIEvent(shared_ptr<Widget> widget, std::function<void(shared_ptr<Widget> widget, Event e)> action);
};

