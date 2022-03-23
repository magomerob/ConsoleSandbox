//
// Created by Marcos on 23/03/2022.
//

#include "SandParticle.h"

SandParticle::SandParticle(int x, int y, Console *c) : Particle(x, y, c) {
    c->writeChar('o',x,y, COLOUR::FG_YELLOW);
}

void SandParticle::onUpdate() {
//SandParticle
    if(m_posY + 1 > m_console->getDimensionsY()-1)return;
    // &  & m_posX>1)
    if(!m_console->pixelFilled(m_posX, m_posY+1)){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('o',m_posX,m_posY+1,COLOUR::FG_YELLOW);
        m_posY = m_posY+1;
    }else if((m_posX+1 < m_console->getDimensionsX()-1) & (!m_console->pixelFilled(m_posX+1, m_posY+1))){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('o',m_posX+1,m_posY+1,COLOUR::FG_YELLOW);
        m_posX = m_posX+1;
        m_posY = m_posY+1;
    }else if((m_posX-1 > 1) & (!m_console->pixelFilled(m_posX-1, m_posY+1))){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('o',m_posX-1,m_posY+1,COLOUR::FG_YELLOW);
        m_posX = m_posX-1;
        m_posY = m_posY+1;
    }
}
