//
// Created by Marcos on 22/03/2022.
//

#ifndef CONSOLESANDBOX_CONSOLE_H
#define CONSOLESANDBOX_CONSOLE_H


#include <windows.h>
#include <conio.h>

class Console {
private:
    HANDLE m_hConsole;
    int m_width;
    int m_height;
    CHAR_INFO* m_bufScreen;
    SMALL_RECT m_rectWindow;
public:
    Console(int height, int widht);
    void writeChar(short c = 0x2588, int X=0, int Y=0, short col = 0x000F);
    void update();
};


#endif //CONSOLESANDBOX_CONSOLE_H
