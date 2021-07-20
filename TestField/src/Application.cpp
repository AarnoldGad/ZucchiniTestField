#include "Application.hpp"

Application::Application(zg::GraphicsSettings settings)
   : Core("TestField"), GraphicApplication(m_gfx), m_gfx(settings)
{
   initialise();
   connectEngine(m_gfx);
}

Application::~Application()
{
   terminate();
}
