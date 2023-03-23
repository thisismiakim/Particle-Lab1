#include <iostream>
#include <chrono>
#include "Emitter.h"
#include <filesystem>
#include <fmt/format.h>

namespace fs = std::filesystem;

int main()
{

  const fs::path output_dir="/transfer/ParticleDemo/";
  if(!fs::exists(output_dir))
  {
    std::cout<<"output dir not there!";
    fs::create_directory(output_dir);
    
    return EXIT_FAILURE;
  }

  //std::cout<<"Particle System\n";
  // number of particles e()
  Emitter e(1000);
  for (int i=0; i<1000; ++i)
  {
    auto file=fmt::format("{}/particle.{:04d}.geo",output_dir.c_str(),i);
    std::cout<<file<<'\n';
    e.render(file);
    e.update(0.01f);//0.1f timestep
  }
  return EXIT_SUCCESS;
}

