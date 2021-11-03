#include "TestField.hpp"

TestField::TestField(zg::GraphicsEngine* gfx)
   : ze::Application("TestField"), m_gfx(gfx),
     m_eventSubscriber(&TestField::handleEvent, this), m_renderListener(&TestField::render, this),
     m_polygonMode(false), m_grabMouse(false), m_sensitivity(0.1f), m_speed(2.f), m_sprite({ .5f, .5f, .5f }),
     m_camera(ze::degrees(85.f), 800.f / 600.f, 0.2f, { 0.f, 0.f, 1.f }, {0.f, 0.f, -1.f})
{
   APP_LOG_INFO("Creating new TestField...");

   m_camera.setYaw(ze::degrees(-90.f));

   m_gfx->renderingSignal.addListener(m_renderListener);
   ze::Core::UseEventBus().addSubscriber(m_eventSubscriber);
}

void TestField::onConnection()
{
//   zg::Mouse::SetRawMouseMotion(true);

   glEnable(GL_DEPTH_TEST);

   zg::Image::FlipOnLoad(true);

   zg::Image icon("assets/textures/container.jpg", zg::Image::Format::RGBA);
   m_texture.loadImage(icon);

   m_sprite.setTexture(&m_texture);

   m_shader.loadFile("assets/shaders/default.vs", "assets/shaders/default.fs");

   m_sprite.setOrigin({ 0.25f, 0.25f, 0.25f });

   m_layout.add<glm::vec3>(1);
   m_layout.add<glm::vec2>(1);

   m_renderer.setLayout(m_layout);
}

void TestField::tick(ze::Time deltaTime)
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

void TestField::render()
{
   m_renderer.submit(m_sprite, m_sprite.getTransformation());

   m_renderer.setViewProjection(&m_camera);

   m_renderer.render(m_shader);
}

void TestField::handleEvent(ze::Event& event)
{
   APP_LOG_DEBUG(event.toString());
   ze::EventDispatcher dispatcher(event);

   // Close window
   dispatcher.dispatch<zg::WindowClosedEvent>(
      [](zg::WindowClosedEvent& event)
      {
         ze::Core::Stop();
      });

   dispatcher.dispatch<zg::KeyPressedEvent>(
      [&](zg::KeyPressedEvent& event)
      {
         if (event.getKey() == zg::Keyboard::Key::P) // Toggle polygon mode
         {
            m_polygonMode = !m_polygonMode;
            if (m_polygonMode)
               glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            else
               glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         }
         else if (event.getKey() == zg::Keyboard::Key::Escape) // Close Window
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
      [&](zg::MouseMovedEvent& event)
      {
         if (!m_grabMouse) return;

         glm::ivec2 windowSize = m_gfx->getWindow().getSize();
         glm::ivec2 offset = (windowSize / 2) - event.getPosition();

         m_camera.turn(offset);

         zg::Mouse::SetPosition(windowSize / 2);
      });
}

void TestField::onDisconnection()
{
}
