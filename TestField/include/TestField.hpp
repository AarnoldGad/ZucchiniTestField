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

   TestField();

private:
   void handleEvent(ze::Event& event);

   ze::EventSubscriber<ze::Event> m_eventSubscriber;
   zg::VertexArray m_vao;
   zg::VertexBuffer m_vbo;
   zg::IndexBuffer m_ebo;
   zg::Shader m_shader;
   zg::Texture m_texture;
   zg::Sprite m_sprite;
};

#endif // TF_APPLICATION
