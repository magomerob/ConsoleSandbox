//
// Created by Marcos on 23/03/2022.
//

#ifndef CONSOLESANDBOX_PARTICLE_H
#define CONSOLESANDBOX_PARTICLE_H

#include "Console.h"
#include "COLOUR.h"

class Particle {
protected:
    int m_posX;
    int m_posY;
    Console* m_console;
public:
    Particle(int x, int y, Console* c);
    virtual void onUpdate() = 0;
    void kill();
    Particle();
};


#endif //CONSOLESANDBOX_PARTICLE_H
