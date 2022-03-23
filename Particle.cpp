//
// Created by Marcos on 23/03/2022.
//

#include "Particle.h"

Particle::Particle(int x, int y, Console* c): m_posX(x), m_posY(y), m_console(c) {

}


Particle::Particle() {
    m_posX=-1;
    m_posY=-1;
    m_console= nullptr;
}
