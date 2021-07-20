#ifndef TF_APPLICATION
#define TF_APPLICATION

#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

class Application : public ze::Core, public zg::GraphicApplication
{
public:
   Application(zg::GraphicsSettings settings);

   ~Application();
private:
   zg::GraphicsEngine m_gfx;
};

#endif // TF_APPLICATION
