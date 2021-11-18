#include "TestField.hpp"

TestField::TestField(zg::GraphicsEngine* gfx)
   : ze::Application("TestField"), m_gfx(gfx),
     m_eventSubscriber(&TestField::handleEvent, this), m_renderListener(&TestField::render, this), m_testLayer(m_gfx)
{
   APP_LOG_INFO("Creating new TestField...");

   m_gfx->renderingSignal.addListener(m_renderListener);
   ze::Core::UseEventBus().addSubscriber(m_eventSubscriber);
}

void TestField::onConnection()
{
   m_testLayer.onConnection();
}

void TestField::tick(ze::Time deltaTime)
{
   m_testLayer.tick(deltaTime);
}

void TestField::render()
{
   m_testLayer.render();
}

void TestField::handleEvent(ze::Event& event)
{
   APP_LOG_DEBUG(event.toString());
   m_testLayer.handleEvent(event);
}

void TestField::onDisconnection()
{
   m_testLayer.onDisconnection();
}
