//
// Created by Marcos on 24/03/2022.
//

#include "WaterParticle.h"

WaterParticle::WaterParticle(int x, int y, Console *c) : Particle(x, y, c) {
    c->writeChar('~',x,y, COLOUR::FG_BLUE);
}

void WaterParticle::onUpdate() {

    if(m_posY + 1 > m_console->getDimensionsY()-1)return;
    // &  & m_posX>1)
    if(!m_console->pixelFilled(m_posX, m_posY+1)){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('~',m_posX,m_posY+1,COLOUR::FG_BLUE);
        m_posY = m_posY+1;
    }else if((m_posX+1 < m_console->getDimensionsX()-1) & (!m_console->pixelFilled(m_posX+1, m_posY+1))){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('~',m_posX+1,m_posY+1,COLOUR::FG_BLUE);
        m_posX = m_posX+1;
        m_posY = m_posY+1;
    }else if((m_posX-1 > 1) & (!m_console->pixelFilled(m_posX-1, m_posY+1))){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('~',m_posX-1,m_posY+1,COLOUR::FG_BLUE);
        m_posX = m_posX-1;
        m_posY = m_posY+1;
    }else if((m_posX+1 < m_console->getDimensionsX()-1) & (!m_console->pixelFilled(m_posX+1, m_posY))){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('~',m_posX+1,m_posY,COLOUR::FG_BLUE);
        m_posX = m_posX+1;
    }else if((m_posX-1 > 1) & (!m_console->pixelFilled(m_posX-1, m_posY))){
        m_console->writeChar(' ',m_posX,m_posY);
        m_console->writeChar('~',m_posX-1,m_posY,COLOUR::FG_BLUE);
        m_posX = m_posX-1;
    }
}
