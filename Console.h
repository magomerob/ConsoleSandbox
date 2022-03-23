//
// Created by Marcos on 22/03/2022.
//

#ifndef CONSOLESANDBOX_CONSOLE_H
#define CONSOLESANDBOX_CONSOLE_H


#include <windows.h>
#define UNICODE
#include <conio.h>
#include <string>

class Console {
private:
    HANDLE m_hConsole;
    HANDLE m_hConsoleIn;
    int m_width;
    int m_height;
    CHAR_INFO* m_bufScreen;
    SMALL_RECT m_rectWindow;
    bool m_bConsoleInFocus = true;
    int m_mousePosX;
    int m_mousePosY;
    bool m_mouseState[5] = { 0 };

public:
    Console(int height, int widht, TCHAR title[256]);
    void writeChar(short c = 0x0024, int X=0, int Y=0, short col = 0x000F);
    void writeStr(std::wstring str, int X=0, int Y=0, short col = 0x000F);
    void update();
    void clear();
    void makeBorder(short c = 219);
    int getMouseX();
    int getMouseY();
    bool isRightClicked();
    bool isLeftClicked();
    int getDimensionsX();
    int getDimensionsY();
    bool pixelFilled(int X, int Y);
};


#endif //CONSOLESANDBOX_CONSOLE_H
