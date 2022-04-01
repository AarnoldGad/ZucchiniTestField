#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

#include "TestField.hpp"

int main(int argc, char* argv[])
{
   ze::Core::Initialise();
   ze::Core::SetTickRate(60);

   zg::GraphicsSettings settings;
   settings.window.resisable = false;
   settings.context.versionMajor = 3;
   settings.context.versionMinor = 3;
   settings.context.openglProfile = zg::ContextSettings::Profile::Core;
   settings.context.forwardCompatibility = true;
   settings.pos = zg::Window::PositionCentered;
   settings.color = { 0.2f, 0.01f, 0.2f, 1.f };

   TestField app(settings);

   ze::Core::PlaceApplication(app);

   ze::Core::Run();

   ze::Core::Terminate();

   return 0;
}
