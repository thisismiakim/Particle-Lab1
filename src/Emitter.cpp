#include "Emitter.h"
#include "Random.h"
#include <iostream>
#include <fstream>

Emitter::Emitter(size_t _numParticles)
{
    m_particles.resize(_numParticles);
    for(auto &p : m_particles)
    {
        //p.m_dir = m_emitDir * 
        //Random::randomPositiveFloat() +
        //Random::randomVectorOnSphere();
        //p.m_dir.m_y=std::abs(p.m_dir.m_y);
        //colour
        //p.m_colour=Random::randomPositiveVec3();

        resetParticle(p);
    }
}


void Emitter::resetParticle(Particle &_p)
{
        _p.m_dir = m_emitDir * 
        Random::randomPositiveFloat() + Random::randomVectorOnSphere();
        _p.m_dir.m_y=std::abs(_p.m_dir.m_y);
        _p.m_colour=Random::randomPositiveVec3();
        _p.life=static_cast<int> (Random::randomFloat(100));
        _p.size= 1.0f;

}

size_t Emitter::numParticles() const
{
    return m_particles.size();
}

void Emitter::update(float _dt)
{
    Vec3 gravity(0.0f, -9.81f, 0.0f);

    for(auto &p : m_particles)
    {
        // dir += gravity * _dt * 0.5f
        // pos += p.dir * _dt

        p.m_dir += gravity * _dt * 0.5f;
        p.m_pos += p.m_dir * _dt;
        p.size += 0.05f;


        if(--p.life <=0 || p.m_pos.m_y <= 0.0f)
        {
            resetParticle(p);
        }

        /* else
        {
            //update
            //p.m_dir += gravity * _dt * 0.5f;
            //p.m_pos += p.m_dir * _dt; //p.m_pos += p.m_dir;
        }*/

    }
}

void Emitter::render(std::string_view _fname) const
{
    auto file=std::ofstream(_fname.data());
    if(file.is_open())
    {
        file <<"PGEOMETRY V5\n";
        file <<"NPoints "<<m_particles.size()<<' ';
        file <<"NPrims 1 \n";
        file <<"NPointGroups 0 NPrimGroups 0 \n";
        file <<"NPointAttrib 2  NVertexAttrib 0 NPrimAttrib 1 NAttrib 0 \n";
        file <<"PointAttrib \n";
        file <<"Cd 3 float 0 0 0 \n";
        file <<"pscale 1 float 0.1 \n";

        // looping
        for(auto p : m_particles)
        {
            // single particle
            file<<p.m_pos.m_x<<' '<<p.m_pos.m_y<<' '<<p.m_pos.m_z<<" 1 (";
            file<<p.m_colour.m_x<<' '<<p.m_colour.m_y<<' '<<p.m_colour.m_z<<' ';
            file<<p.size<<")\n";
        }

        file <<"PrimitiveAttrib \n";
        file <<"generator 1 index 1 papi \n";
        file <<"Part "<<m_particles.size()<<" ";
        for(size_t i=0; i<m_particles.size(); ++i)
        {
            file <<i<<' ';
        }
        file <<"[0]\n";
        file <<"beginExtra\n";
        file <<"endExtra\n";





        //for (auto p : m_particles)
        //{
        //    file<<p.m_pos.m_x<<','<<p.m_pos.m_y<<','<<p.m_pos.m_z<<'\n';
        //}
    }
    file.close();
}