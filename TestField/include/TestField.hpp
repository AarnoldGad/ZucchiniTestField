#ifndef TF_APPLICATION
#define TF_APPLICATION

#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

class TestField : public ze::Application
{
public:
   TestField(zg::GraphicsSettings const& settings);

   void onConnection() override;
   void tick(ze::Time deltaTime) override;
   void onDisconnection() override;

private:
   void render();

   zg::GraphicsEngine m_gfx;
   ze::Listener<void ()> m_renderListener;
};

#endif // TF_APPLICATION
