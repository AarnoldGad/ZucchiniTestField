#include <iostream>
#include <zengine/zengine.hpp>

#include "Application.hpp"

int main(int argc, char **argv)
{
   Application app;
   app.setTickRate(60);

   app.initialise();

   app.run();

   app.terminate();

   return 0;
}
