#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Vec3.h"

class Particle
{
    public :
        Vec3 m_pos;
        Vec3 m_dir = {0.0f, 1.0f, 0.0f};
        Vec3 m_colour = {0.8f, 0.8f, 0.8f};
        int life = 100;
        float size = 0.5f;
};

#endif

