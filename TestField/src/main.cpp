#include <iostream>
#include <zengine/zengine.hpp>

int main(int argc, char **argv)
{
   ze::Logger logger("TESTFIELD", std::cout);
   logger.info() << "Hello world";
   return 0;
}
