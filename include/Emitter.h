#ifndef EMITTER_H_
#define EMITTER_H_
#include <cstddef> //size_t
#include <vector>
#include <string_view>
#include "Particle.h"

class Emitter
{
    public :
        Emitter(size_t _numParticles);
        size_t numParticles() const;
        void update(float _dt);
        void render(std::string_view _fname) const;
    private :
        std::vector<Particle> m_particles;
        Vec3 m_emitDir = {0.0f,5.0f,0.0f}; // size? 1.0f

        void resetParticle(Particle &_p); //reset

};
#endif