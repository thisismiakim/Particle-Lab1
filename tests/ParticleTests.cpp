#include <gtest/gtest.h>
#include "Particle.h"
#include "Emitter.h"
#include "Vec3.h"

TEST(Particle,ctor)
{
  Particle p;
  ASSERT_TRUE(p.m_pos.m_x == 0.0f);
  ASSERT_FLOAT_EQ(p.m_pos.m_y, 0.0f);
  ASSERT_FLOAT_EQ(p.m_pos.m_z, 0.0f);

  ASSERT_FLOAT_EQ(p.m_dir.m_x, 0.0f);
  ASSERT_FLOAT_EQ(p.m_dir.m_y, 1.0f);
  ASSERT_FLOAT_EQ(p.m_dir.m_z, 0.0f);

  ASSERT_FLOAT_EQ(p.m_colour.m_x, 0.8f);
  ASSERT_FLOAT_EQ(p.m_colour.m_y, 0.8f);
  ASSERT_FLOAT_EQ(p.m_colour.m_z, 0.8f);
  ASSERT_EQ(p.life, 100); 
  ASSERT_FLOAT_EQ(p.size, 0.5f);

}



TEST(Emitter, ctor)
{
  Emitter e(100);
  ASSERT_EQ(e.numParticles(), 100);
}


TEST(Vec3, opmult)
{
  Vec3 a(1,2,3);
  auto b=a*2;
  ASSERT_FLOAT_EQ(b.m_x, 2.0f);
  ASSERT_FLOAT_EQ(b.m_y, 4.0f);
  ASSERT_FLOAT_EQ(b.m_z, 6.0f);

  
}