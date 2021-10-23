#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

#include "TestField.hpp"

int main(int argc, char* argv[])
{
   ze::Core::Initialise();
   ze::Core::SetTickRate(60);

   zg::GraphicsSettings settings;
   settings.window.resisable = true;
   settings.context.versionMajor = 3;
   settings.context.versionMinor = 3;
   settings.context.openglProfile = zg::ContextSettings::Profile::Core;
   settings.context.forwardCompatibility = true;
   settings.pos = zg::Window::PositionCentered;

   zg::GraphicsEngine gfx(settings);

   ze::Core::ConnectEngine(gfx);

   TestField app;
   ze::Listener<void ()> renderListener(&TestField::render, &app);
   gfx.renderingSignal.addListener(renderListener);

   ze::Core::PlaceApplication(app);
   ze::Core::Run();

   ze::Core::Terminate();
}
