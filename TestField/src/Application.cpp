#include "Application.hpp"

Application::Application()
   : Core("TestField") {}

void Application::tick(std::vector<ze::State *>& states, ze::Time deltaTime)
{
   using namespace std::chrono_literals;
   static ze::Time timer;
   timer += deltaTime;

   if (timer > 1s)
      stop();
}
