#include "UltraEngine.h"
#include "UIEvent.h"

/// <summary>
/// Constructor for the UIEvent class.
/// </summary>
/// <param name="widget">The associated widget for the event.</param>
/// <param name="action">The action to be executed when the event is triggered.</param>
UIEvent::UIEvent(shared_ptr<Widget> widget, std::function<void(shared_ptr<Widget> widget, Event e)> action)
{
	this->widget = widget;
	this->action = action;
}

/// <summary>
/// Creates and returns a new instance of UIEvent.
/// </summary>
/// <param name="widget">The associated widget for the event.</param>
/// <param name="action">The action to be executed when the event is triggered.</param>
/// <returns>A shared pointer to the newly created UIEvent.</returns>
shared_ptr<UIEvent> UIEvent::CreateUIEvent(shared_ptr<Widget> widget, std::function<void(shared_ptr<Widget> widget, Event e)> action)
{
	return std::make_shared<UIEvent>(widget, action);
}
