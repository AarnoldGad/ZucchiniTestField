#include "TestField.hpp"

TestField::TestField(zg::GraphicsSettings settings)
   : ze::Application("TestField"), m_gfx(settings)
{}

void TestField::onConnection()
{
   ze::Core::ConnectEngine(m_gfx);
}

void TestField::tick(ze::Time deltaTime)
{
   APP_LOG_DEBUG("%d", deltaTime.asMilliseconds());
}

void TestField::onDisconnection()
{
   ze::Core::DisconnectEngine(m_gfx);
}
