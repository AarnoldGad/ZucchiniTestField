#ifndef TF_APPLICATION
#define TF_APPLICATION

#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

#include "TestLayer.hpp"

class TestField : public ze::Application
{
public:
   void onConnection() override;
   void tick(ze::Time deltaTime) override;
   void render();
   void onDisconnection() override;

   TestField(zg::GraphicsEngine* gfx);

private:
   void handleEvent(ze::Event& event);

   zg::GraphicsEngine* m_gfx;
   ze::EventSubscriber<ze::Event> m_eventSubscriber;
   ze::Listener<void ()> m_renderListener;

   TestLayer m_testLayer;
};

#endif // TF_APPLICATION
