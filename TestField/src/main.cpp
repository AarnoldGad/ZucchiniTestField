#include <iostream>
#include <zengine/zengine.hpp>

#include "Application.hpp"

class EventTest : public ze::Event
{
public:
   std::string toString() const override { return "TestEvent"; }
};

void handler(EventTest& event)
{
   "Hello" | tee;
}

class A
{
public:
   A() {}

   void foo(ze::Event& event) {}
};

int main(int argc, char **argv)
{
   Application app;
   app.setTickRate(60);

   app.initialise();

   //app.run();

   app.terminate();

   return 0;
}
