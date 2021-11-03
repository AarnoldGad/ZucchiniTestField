#ifndef TF_APPLICATION
#define TF_APPLICATION

#include <zengine/zengine.hpp>
#include <zgraphics2D/zgraphics2D.hpp>

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

   bool m_polygonMode;
   bool m_grabMouse;
   float m_sensitivity;
   float m_speed;

   zg::VertexLayout m_layout;

   zg::DefaultRenderer m_renderer;
   zg::Shader m_shader;
   zg::Texture m_texture;
   zg::Cube m_sprite;
   zg::FPSCamera m_camera;
};

#endif // TF_APPLICATION
