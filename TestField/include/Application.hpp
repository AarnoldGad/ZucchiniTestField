#ifndef TF_APPLICATION
#define TF_APPLICATION

#include <zengine/zengine.hpp>

class Application : public ze::Core
{
public:
   Application();

   void tick(std::vector<ze::State*>& states, ze::Time deltaTime) override;

   ~Application() = default;

};

#endif // TF_APPLICATION
