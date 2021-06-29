#include <iostream>
#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

#include "Application.hpp"

#include <zengine/Memory/New.hpp>

void handler(zg::WindowClosedEvent& event)
{
   ze::Core::GetApplication().stop();
}

int main(int argc, char **argv)
{
   Application app;
   app.setTickRate(60);

   zg::GraphicsEngine gfx;

   app.initialise();
   app.connectEngine(gfx);

   ze::Subscriber<zg::WindowClosedEvent> sub = app.useEventBusTo().subscribe<zg::WindowClosedEvent>(&handler);

   app.run();
   
   app.terminate();
   
   return 0;
}
