#include <iostream>
#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

#include "TestField.hpp"

#include <zengine/Memory/New.hpp>

void handler(ze::Event& event)
{
   if (event.toString() != "Render Event")
      APP_LOG_DEBUG(event.toString());
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
//   ze::Core::Initialise();
//   ze::Core::SetTickRate(60);
//
//   zg::GraphicsSettings settings;
//   settings.context.versionMajor = 3;
//   settings.context.versionMinor = 3;
//   settings.context.openglProfile = zg::ContextSettings::Profile::Core;
//   settings.context.forwardCompatibility = true;
//   TestField app(settings);
//
//   ze::Core::PlaceApplication(app);
//   ze::Core::Run();
//
//   ze::Core::Terminate();

   return 0;
}
