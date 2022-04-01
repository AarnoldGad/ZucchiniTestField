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

   explicit TestField(zg::GraphicsSettings const& settings);

private:
   void handleEvent(ze::Event& event);

   zg::GraphicsEngine m_gfx;

   // TODO Layer stack
   std::unique_ptr<TestLayer> m_layer;

   ze::EventSubscriber<ze::Event> m_eventSubscriber;
   ze::Listener<void ()> m_renderListener;
};

#endif // TF_APPLICATION
