#include <iostream>
#include <chrono>
#include "Emitter.h"

int main()
{
  //std::cout<<"Particle System\n";
  Emitter e(10);
  for (int i=0; i<100; ++i)
  {
    e.render();
    e.update(0.1f);
  }
  return EXIT_SUCCESS;
}

