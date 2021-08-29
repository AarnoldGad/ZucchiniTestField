#include "TestField.hpp"

TestField::TestField(zg::GraphicsSettings settings)
   : ze::Application("TestField"), m_gfx(settings), m_renderListener(&TestField::render, this)
{
   APP_LOG_INFO("Creating new TestField...");

   m_gfx.renderingSignal.addListener(m_renderListener);
   zg::Image icon("assets/icon.png", zg::Image::Format::RGBA);
}

void TestField::onConnection()
{
   ze::Core::ConnectEngine(m_gfx);
}

void TestField::tick(ze::Time deltaTime)
{
   APP_LOG_DEBUG("%d", deltaTime.asMilliseconds());
   if (m_gfx.getKeyboard().isKeyPressed(zg::Keyboard::Key::Escape))
      ze::Core::Stop();
}

void TestField::render()
{

}

void TestField::onDisconnection()
{
   ze::Core::DisconnectEngine(m_gfx);
}
