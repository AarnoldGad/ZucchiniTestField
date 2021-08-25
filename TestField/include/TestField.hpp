#ifndef TF_APPLICATION
#define TF_APPLICATION

#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

class TestField : public ze::Application
{
public:
   TestField(zg::GraphicsSettings settings);

   void onConnection() override;
   void tick(ze::Time deltaTime) override;
   void onDisconnection() override;

private:
   zg::GraphicsEngine m_gfx;
};

#endif // TF_APPLICATION
