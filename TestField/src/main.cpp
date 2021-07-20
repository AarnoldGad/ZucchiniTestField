#include <iostream>
#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

#include "Application.hpp"

#include <zengine/Memory/New.hpp>

void handler(ze::Event& event)
{
   if (event.toString() != "Render Event")
      APP_LOG_DEBUG(event.toString());
}

int main(int argc, char **argv)
{
   zg::GraphicsSettings settings;
   Application app(settings);
   app.setTickRate(60);

   ze::Subscriber<ze::Event> sub = app.useEventBusTo().subscribe<ze::Event>(&handler);

   app.run();

   return 0;
}
