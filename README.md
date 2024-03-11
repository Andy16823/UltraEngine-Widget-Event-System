# UltraEngine Widget Event System
Ultra Engine Event System is a powerful event handling library designed for the Ultra Engine. It introduces the ability to use lambdas instead of traditional function pointers, making event handling in your Ultra Engine projects more flexible and expressive.

## Getting Started
To integrate the Ultra Engine Event System into your project, follow these simple steps:

1. Clone the repository:

```c
git clone https://github.com/Andy16823/UltraEngine-Widget-Event-System.git
```

2. Initialize the event handler:

```c
g_eventHandler = UIEventHandler::CreateUIEventHandler();
```

3. Integrate the event handling loop into your main loop:

```c
while (window->Closed() == false and window->KeyDown(KEY_ESCAPE) == false)
{
    while (PeekEvent())
    {
        const Event ev = WaitEvent();
        g_eventHandler->ProcessEvent(g_ui->GetInterface(), ev);
    }
    g_world->Update();
    g_world->Render(framebuffer);

    #ifdef STEAM_API_H
        Steamworks::Update();
    #endif
}
```
## Example Usage
Here's an example demonstrating how to use the Ultra Engine Event System to create a main UI with buttons:

```c
void CreateMainUI(shared_ptr<Framebuffer> framebuffer) {
    g_mainUI = CreatePanel(0, 0, framebuffer->size.width, framebuffer->size.height, g_ui->GetInterface()->root);
    g_mainUI->SetColor(Vec4(0, 0, 0, 0));

    auto btn = CreateButton("Start Game", 15, 15, 150, 30, g_mainUI);
    g_eventHandler->AddEvent(UIEvent::CreateUIEvent(btn, [](shared_ptr<Widget> widget, Event e) {
        g_scene = LoadMap(g_world, "maps/start.ultra");
        g_mainUI->SetHidden(true);
    }));

    auto mpBtn = CreateButton("Multiplayer", 15, 55, 150, 30, g_mainUI);
    g_eventHandler->AddEvent(UIEvent::CreateUIEvent(mpBtn, [](shared_ptr<Widget> widget, Event e) {
        Print("Start Multiplayer");
    }));
}
```

## License
This project is licensed under the MIT License - see the LICENSE file for details.
Feel free to customize and enhance the Ultra Engine Event System to suit your project's needs. 
If you encounter any issues or have suggestions for improvement, please open an issue. 

Happy coding!
