#include "TestField.hpp"

namespace
{
   constexpr unsigned int elements[] =
   {
      0, 1, 2,
      1, 2, 3
   };
}

TestField::TestField()
   : ze::Application("TestField"), m_polygonMode(false), m_eventSubscriber(&TestField::handleEvent, this), m_sprite({ 1.f, 1.f }),
     m_camera(ze::degrees(85.f), 800.f / 600.f, { 0.f, 0.f, -1.f }, {0.f, 0.f, 0.f})
{
   APP_LOG_INFO("Creating new TestField...");

   ze::Core::UseEventBus().addSubscriber(m_eventSubscriber);
}

void TestField::onConnection()
{
   zg::Image::FlipOnLoad(true);

   zg::Image icon("assets/icon.png", zg::Image::Format::RGBA);
   m_texture.loadImage(icon);


   m_sprite.setTexture(&m_texture);

   zg::VertexLayout layout;
   layout.add<glm::vec3>(1);
   layout.add<glm::vec2>(1);

   m_vao.bind();

   m_vbo.resize(4*5*sizeof(float));
   {
      float* buffer = m_vbo.map<float>();
      for (size_t i = 0; i < 4; ++i)
      {
         buffer[i*5] = reinterpret_cast<glm::vec3 const*>(m_sprite.getVertex(i)->getLocationData(0))->x;
         buffer[i*5 + 1] = reinterpret_cast<glm::vec3 const*>(m_sprite.getVertex(i)->getLocationData(0))->y;
         buffer[i*5 + 2] = reinterpret_cast<glm::vec3 const*>(m_sprite.getVertex(i)->getLocationData(0))->z;
         buffer[i*5 + 3] = reinterpret_cast<glm::vec2 const*>(m_sprite.getVertex(i)->getLocationData(1))->x;
         buffer[i*5 + 4] = reinterpret_cast<glm::vec2 const*>(m_sprite.getVertex(i)->getLocationData(1))->y;
      }
      m_vbo.unmap();
   }

   m_ebo.setData(sizeof(elements), elements);

   m_vao.setLayout(layout);

   m_shader.loadFile("assets/shaders/default.vs", "assets/shaders/default.fs");

   m_sprite.setOrigin({ 0.5f, 0.5f, 0.f });
}

void TestField::tick(ze::Time deltaTime)
{
//   APP_LOG_DEBUG("%d", deltaTime.asMilliseconds());
   glm::vec3 offset{};
   glm::vec3 look = m_camera.getTarget() - m_camera.getPosition();
   glm::vec3 right = glm::cross(look, m_camera.getUp());

   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::W))
      offset += glm::normalize(look) * deltaTime.asSecondsFloat() * 2.f;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::A))
      offset -= glm::normalize(right) * deltaTime.asSecondsFloat() * 2.f;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::S))
      offset -= glm::normalize(look) * deltaTime.asSecondsFloat() * 2.f;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::D))
      offset += glm::normalize(right) * deltaTime.asSecondsFloat() * 2.f;

   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::Space))
      offset += glm::normalize(m_camera.getUp()) * deltaTime.asSecondsFloat() * 2.f;
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::LeftControl))
      offset -= glm::normalize(m_camera.getUp()) * deltaTime.asSecondsFloat() * 2.f;

   m_camera.move(offset);
}

void TestField::render()
{
   m_shader.use();

   glActiveTexture(GL_TEXTURE0);
   m_texture.bind();
   m_shader.setInteger("tex0", 0);

   m_shader.setMatrix4("model", m_sprite.getTransformation());
   m_shader.setMatrix4("view", m_camera.getView());
   m_shader.setMatrix4("projection", m_camera.getProjection());

   m_vao.bind();
   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
   });
}

void TestField::onDisconnection()
{
}
