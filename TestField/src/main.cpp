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
   settings.color = { 0.1f, 0.02f, 0.1f, 1.f };

   zg::GraphicsEngine gfx(settings);

   ze::Core::ConnectEngine(gfx);

   TestField app(&gfx);

   ze::Core::PlaceApplication(app);

   ze::Core::Run();

   ze::Core::Terminate();

   return 0;
}
