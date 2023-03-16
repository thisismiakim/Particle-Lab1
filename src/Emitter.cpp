#include "Emitter.h"
#include "Random.h"
#include <iostream>

Emitter::Emitter(size_t _numParticles)
{
    m_particles.resize(_numParticles);
    for(auto &p : m_particles)
    {
        p.m_dir = m_emitDir * 
        Random::randomPositiveFloat() +
        Random::randomVectorOnSphere();
        p.m_dir.m_y=std::abs(p.m_dir.m_y);
    }
}

size_t Emitter::numParticles() const
{
    return m_particles.size();
}

void Emitter::update(float _dt)
{
    for(auto &p : m_particles)
    {
        p.m_pos += p.m_dir;
    }
}

void Emitter::render() const
{
    for (auto p : m_particles)
    {
        std::cout<<p.m_pos.m_x<<','<<p.m_pos.m_y<<','<<p.m_pos.m_z<<'\n';
    }
}