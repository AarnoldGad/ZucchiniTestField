#include "TestField.hpp"

namespace
{
   constexpr char const* vs = "#version 330\n"
   "layout (location = 0) in vec3 pos;\n"
   "layout (location = 1) in vec2 texCoord;\n"
   "out vec2 iTexCoord;\n"
   "void main()\n"
   "{ gl_Position = vec4(pos.x, pos.y, pos.z, 1.0); iTexCoord = texCoord; }\0";
   
   constexpr char const* fs = "#version 330\n"
   "out vec4 FragColor;\n"
   "in vec2 iTexCoord;\n"
   "uniform sampler2D tex;\n"
   "void main()\n"
   "{ FragColor = texture(tex, iTexCoord); }\0";

   constexpr float vertices[] =
   {
      -0.5f, -0.5f, 0.f, 0.f, 0.f,
      -0.5f , 0.5f, 0.f, 0.f, 1.f,
       0.5f, -0.5f, 0.f, 1.f, 0.f,
       0.5f,  0.5f, 0.f, 1.f, 1.f,
   };

   constexpr unsigned int elements[] =
   {
      0, 1, 2,
      1, 2, 3
   };

   unsigned int vao;
}

TestField::TestField()
   : ze::Application("TestField"), m_eventSubscriber(&TestField::handleEvent, this)
{
   APP_LOG_INFO("Creating new TestField...");

   ze::Core::UseEventBus().addSubscriber(m_eventSubscriber);
}

void TestField::onConnection()
{
   zg::Image icon("assets/icon.png", zg::Image::Format::RGBA);
   m_texture.loadImage(icon);

   zg::VertexLayout layout;
   layout.add<glm::vec3>(1);
   layout.add<glm::vec2>(1);

   m_vao.bind();

   m_vbo.setData(sizeof(vertices), vertices);
   m_ebo.setData(sizeof(elements), elements);

   m_vao.setLayout(layout);

   m_shader.loadSource(vs, fs);
}

void TestField::tick(ze::Time deltaTime)
{
//   APP_LOG_DEBUG("%d", deltaTime.asMilliseconds());
   if (zg::Keyboard::IsKeyPressed(zg::Keyboard::Key::Escape))
      ze::Core::Stop();
}

void TestField::render()
{
//   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   m_shader.use();
   m_texture.bind();
   m_vao.bind();
   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void TestField::handleEvent(ze::Event& event)
{
   APP_LOG_DEBUG(event.toString());
}

void TestField::onDisconnection()
{
}
