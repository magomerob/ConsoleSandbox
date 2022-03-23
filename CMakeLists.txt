cmake_minimum_required(VERSION 3.20)
project(ConsoleSandbox)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleSandbox main.cpp Console.cpp Console.h Particle.cpp Particle.h COLOUR.h SandParticle.cpp SandParticle.h WaterParticle.cpp WaterParticle.h)
