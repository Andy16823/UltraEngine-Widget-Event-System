#pragma once
#include "UltraEngine.h"
#include "UIEvent.h"

using namespace UltraEngine;
using namespace std;

/// <summary>
/// Class representing a handler for UI events.
/// </summary>
class UIEventHandler
{
public:

	/// <summary>
	/// List of UI events registered with the handler.
	/// </summary>
	vector<shared_ptr<UIEvent>> events;
	
	/// <summary>
	/// Default constructor for the UIEventHandler class.
	/// </summary>
	UIEventHandler();

	/// <summary>
	/// Adds a UI event to the UIEventHandler's list of events.
	/// </summary>
	/// <param name="event">The UI event to add.</param>
	void AddEvent(shared_ptr<UIEvent> event);

	/// <summary>
	/// Processes the specified event for a given widget.
	/// </summary>
	/// <param name="widget">The widget for which the event is processed.</param>
	/// <param name="e">The event to process.</param>
	void ProcessEvent(shared_ptr<Widget> widget, Event e);

	/// <summary>
	/// Processes a UI event for the specified GUI interface.
	/// </summary>
	/// <param name="gui">The GUI interface to process the event for.</param>
	/// <param name="e">The event to be processed.</param>
	void ProcessEvent(shared_ptr<Interface> gui, Event e);

	/// <summary>
	/// Creates and returns a new instance of UIEventHandler.
	/// </summary>
	/// <returns>A shared pointer to the newly created UIEventHandler.</returns>
	static shared_ptr<UIEventHandler> CreateUIEventHandler();
};

