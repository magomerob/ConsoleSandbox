//
// Created by Marcos on 24/03/2022.
//

#ifndef CONSOLESANDBOX_WATERPARTICLE_H
#define CONSOLESANDBOX_WATERPARTICLE_H


#include "Particle.h"

class WaterParticle : public Particle{
public:
    WaterParticle(int x, int y, Console* c);
    virtual void onUpdate();
};


#endif //CONSOLESANDBOX_WATERPARTICLE_H
