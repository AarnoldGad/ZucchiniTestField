#include "TestLayer.hpp"

#include <glad/glad.h>

TestLayer::TestLayer(zg::GraphicsEngine* gfx)
   : ze::Layer("Test"), m_gfx(gfx),
     m_polygonMode(false), m_grabMouse(false), m_speed(2.f),
     m_sprite({1.f, 1.f}), m_camera(ze::degrees(85.f)) {}

void TestLayer::onConnection()
{
   float const aspectRatio = static_cast<float>(m_gfx->getWindow().getSize().x) / static_cast<float>(m_gfx->getWindow().getSize().y);
   m_camera.setAspectRatio(aspectRatio);
   m_camera.setSensitivity(0.2f);
   m_camera.setPosition({ 0.f, 0.f, 1.f });
   m_camera.setYaw(ze::degrees(-90.f));

   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_DEPTH_TEST);

   zg::Image::FlipOnLoad(true);

   ze::ResourceManager<zg::Shader>::AddSearchPath("TestField/assets/shaders");
   ze::ResourceManager<zg::Texture>::AddSearchPath("TestField/assets/textures");

   ze::ResourceManager<zg::Shader>::Load("default", "default.vs", "default.fs");
   ze::ResourceManager<zg::Texture>::Load("icon", "icon.png");

   //ze::ResourceManager<zg::Shader>::Add("text")->loadFile("default.vs", "text.fs");

   m_sprite.setTexture(ze::ResourceManager<zg::Texture>::Get("icon"));

   zg::VertexLayout layout;

   using ShaderType = zg::VertexAttribute::Type;
   layout.add(ShaderType::Vec2, "a_pos");
   layout.add(ShaderType::Vec4, "a_color");
   layout.add(ShaderType::Vec2, "a_texCoord");

   m_renderer.setLayout(layout);
}

void TestLayer::tick(ze::Time deltaTime)
{
   moveCamera(deltaTime);
}

void TestLayer::moveCamera(ze::Time deltaTime)
{
   glm::vec3 offset{};
   glm::vec3 right = glm::cross(m_camera.getFront(), m_camera.getUp());
   glm::vec3 front = glm::cross(-right, m_camera.getUp());

   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::W))
      offset += glm::normalize(front) * deltaTime.asSecondsFloat() * m_speed;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::A))
      offset -= glm::normalize(right) * deltaTime.asSecondsFloat() * m_speed;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::S))
      offset -= glm::normalize(front) * deltaTime.asSecondsFloat() * m_speed;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::D))
      offset += glm::normalize(right) * deltaTime.asSecondsFloat() * m_speed;

   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::Space))
      offset += glm::normalize(m_camera.getUp()) * deltaTime.asSecondsFloat() * m_speed;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::LeftControl))
      offset -= glm::normalize(m_camera.getUp()) * deltaTime.asSecondsFloat() * m_speed;

   m_camera.move(offset);
}

void TestLayer::render()
{
   float time = ze::Core::GetTime().asSecondsFloat();
   m_renderer.submit(m_sprite, m_sprite.getTransformationMatrix());

   zg::Shader shader = *ze::ResourceManager<zg::Shader>::Get("default");
   m_renderer.setViewProjection(&m_camera);
   m_renderer.render(shader);
}

void TestLayer::handleEvent(ze::Event& event)
{
   ze::EventDispatcher dispatcher(event);

   // Close window
   dispatcher.dispatch<zg::WindowClosedEvent>(
      [] (zg::WindowClosedEvent& event)
      {
         ze::Core::Stop();
      });

   dispatcher.dispatch<zg::KeyPressedEvent>(
      [&] (zg::KeyPressedEvent& event)
      {
         if (event.getKey() == zg::Keyboard::Key::P)
         {
            // Toggle polygon mode
            m_polygonMode = !m_polygonMode;
            if (m_polygonMode)
               glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            else
               glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         }
         if (event.getKey() == zg::Keyboard::Key::Escape)
            // Close Window
            ze::Core::Stop();
         else if (event.getKey() == zg::Keyboard::Key::M)
         {
            // Switch mouse mode (Normal / disabled)
            m_grabMouse = !m_grabMouse;
            zg::Mouse::SetCursorMode(m_grabMouse ? zg::Mouse::CursorMode::Disabled : zg::Mouse::CursorMode::Normal);

            // Center mouse
            glm::ivec2 windowSize = m_gfx->getWindow().getSize();
            zg::Mouse::SetPosition(windowSize / 2);
         }
      });

   dispatcher.dispatch<zg::MouseMovedEvent>(
      [&] (zg::MouseMovedEvent& event)
      {
         if (!m_grabMouse) return;

         glm::ivec2 windowSize = m_gfx->getWindow().getSize();
         glm::ivec2 offset = (windowSize / 2) - event.getPosition();

         m_camera.turn(offset);

         zg::Mouse::SetPosition(windowSize / 2);
      });
}

void TestLayer::onDisconnection()
{

}
