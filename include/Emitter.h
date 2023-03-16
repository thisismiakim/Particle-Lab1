#ifndef EMITTER_H_
#define EMITTER_H_
#include <cstddef> //size_t
#include <vector>
#include "Particle.h"

class Emitter
{
    public :
        Emitter(size_t _numParticles);
        size_t numParticles() const;
        void update(float _dt);
        void render() const;
    private :
        std::vector<Particle> m_particles;
        Vec3 m_emitDir = {0.0f,1.0f,0.0f};
};
#endif