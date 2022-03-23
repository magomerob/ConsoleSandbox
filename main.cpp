#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include "Console.h"
#include <string>
#include "COLOUR.h"
#include "Particle.h"
#include "SandParticle.h"
#include "WaterParticle.h"


int WHITE = 0x000F;

int main() {

    auto* cons = new Console(50,100, "Sandbox");

    auto** particles = new Particle*[50*100];
    memset(particles, 0, sizeof(Particle*) * 50 * 100);
    int numparts = 0;

    cons->makeBorder();

    for(double i=1; i<99;i+=0.1){
        int X = round(i);
        int Y = round(10*cos(i/(2*3.14)) + 15) ;
        cons->writeChar( short(219), X, Y, COLOUR::FG_RED);
    }for(double i=1; i<99;i+=0.1){
        int X = round(i)+1;
        int Y = round(10*cos(i/(2*3.14)) + 15) ;
        cons->writeChar( short(219), X, Y, COLOUR::FG_RED);
    }


    int i = 0;
    while(i<100){
        cons->update();
        if(cons->isLeftClicked() & !cons->pixelFilled(cons->getMouseX(), cons->getMouseY())){
            auto* npart = new SandParticle(cons->getMouseX(), cons->getMouseY(), cons);
            particles[numparts] = npart;
            numparts++;
        }
        if(cons->isRightClicked() & !cons->pixelFilled(cons->getMouseX(), cons->getMouseY())){
            auto* npart = new WaterParticle(cons->getMouseX(), cons->getMouseY(), cons);
            particles[numparts] = npart;
            numparts++;
        }
        for(int j = 0; j<numparts;j++){
            particles[j]->onUpdate();
        }
    }
    cons->update();
    std::cin.ignore();
    std::cin.ignore();

    return 0;
}