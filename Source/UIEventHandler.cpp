#include "UltraEngine.h"
#include "UIEventHandler.h"

/// <summary>
/// Default constructor for the UIEventHandler class.
/// </summary>
UIEventHandler::UIEventHandler()
{

}

/// <summary>
/// Adds a UI event to the UIEventHandler's list of events.
/// </summary>
/// <param name="event">The UI event to add.</param>
void UIEventHandler::AddEvent(shared_ptr<UIEvent> event) 
{
	this->events.push_back(event);
}

/// <summary>
/// Processes the specified event for a given widget.
/// </summary>
/// <param name="widget">The widget for which the event is processed.</param>
/// <param name="e">The event to process.</param>
void UIEventHandler::ProcessEvent(shared_ptr<Widget> widget, Event e)
{

	for (auto event : this->events) 
	{
		if (event->widget == widget)
		{
			event->action(widget, e);
		}
	}
}

/// <summary>
/// Processes a UI event for the specified GUI interface.
/// </summary>
/// <param name="gui">The GUI interface to process the event for.</param>
/// <param name="e">The event to be processed.</param>
void UIEventHandler::ProcessEvent(shared_ptr<Interface> gui, Event e)
{
	gui->ProcessEvent(e);
	if (e.id == EVENT_WIDGETACTION) {
		this->ProcessEvent(e.source->As<Widget>(), e);
	}
}

/// <summary>
/// Creates and returns a new instance of UIEventHandler.
/// </summary>
/// <returns>A shared pointer to the newly created UIEventHandler.</returns>
shared_ptr<UIEventHandler> UIEventHandler::CreateUIEventHandler()
{
	return std::make_shared<UIEventHandler>();
}