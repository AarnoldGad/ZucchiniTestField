#include "TestField.hpp"

TestField::TestField(zg::GraphicsSettings const& settings)
   : ze::Application("TestField"), m_gfx(settings), m_layer(nullptr),
     m_eventSubscriber(&TestField::handleEvent, this), m_renderListener(&TestField::render, this)
{
   APP_LOG_INFO("Creating new TestField...");

   m_gfx.renderingSignal.addListener(m_renderListener);
   ze::Core::UseEventBus().addSubscriber(m_eventSubscriber);
}

void TestField::onConnection()
{
   ze::Core::ConnectEngine(m_gfx);

   m_layer = std::make_unique<TestLayer>(&m_gfx);

   m_layer->onConnection();
}

void TestField::tick(ze::Time deltaTime)
{
   m_layer->tick(deltaTime);
}

void TestField::render()
{
   m_layer->render();
}

void TestField::handleEvent(ze::Event& event)
{
 //  APP_LOG_DEBUG(event.toString());
   m_layer->handleEvent(event);
}

void TestField::onDisconnection()
{
   m_layer->onDisconnection();

   ze::Core::DisconnectEngine(m_gfx);
}

