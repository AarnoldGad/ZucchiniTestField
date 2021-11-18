#ifndef TF_TESTLAYER_HPP
#define TF_TESTLAYER_HPP

#include "zengine/zengine.hpp"
#include "zgraphics2D/zgraphics2D.hpp"

class TestLayer : public ze::Layer
{
public:
   void onConnection() override;
   void onDisconnection() override;

   void tick(ze::Time deltaTime) override;
   void render();
   void handleEvent(ze::Event& event);

   TestLayer(zg::GraphicsEngine* gfx);

private:
   void moveCamera(ze::Time deltaTime);

private:
   zg::GraphicsEngine* m_gfx;

   bool m_polygonMode;
   bool m_grabMouse;
   float m_speed;

   zg::VertexLayout m_layout;

   zg::DefaultRenderer m_renderer;
   zg::Cube m_sprite;
   zg::FPSCamera m_camera;
};

#endif // TF_TESTLAYER_HPP