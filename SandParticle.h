//
// Created by Marcos on 23/03/2022.
//

#ifndef CONSOLESANDBOX_SANDPARTICLE_H
#define CONSOLESANDBOX_SANDPARTICLE_H


#include "Particle.h"

class SandParticle : public Particle{
public:
    SandParticle(int x, int y, Console* c);
    virtual void onUpdate();
};


#endif //CONSOLESANDBOX_SANDPARTICLE_H
