add_test( Particle.ctor /home/s5314663/CGA/Labs/Particle/build/ParticleTests [==[--gtest_filter=Particle.ctor]==] --gtest_also_run_disabled_tests)
set_tests_properties( Particle.ctor PROPERTIES WORKING_DIRECTORY /home/s5314663/CGA/Labs/Particle/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( Emitter.ctor /home/s5314663/CGA/Labs/Particle/build/ParticleTests [==[--gtest_filter=Emitter.ctor]==] --gtest_also_run_disabled_tests)
set_tests_properties( Emitter.ctor PROPERTIES WORKING_DIRECTORY /home/s5314663/CGA/Labs/Particle/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( Vec3.opmult /home/s5314663/CGA/Labs/Particle/build/ParticleTests [==[--gtest_filter=Vec3.opmult]==] --gtest_also_run_disabled_tests)
set_tests_properties( Vec3.opmult PROPERTIES WORKING_DIRECTORY /home/s5314663/CGA/Labs/Particle/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( ParticleTests_TESTS Particle.ctor Emitter.ctor Vec3.opmult)
