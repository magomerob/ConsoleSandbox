//
// Created by Marcos on 22/03/2022.
//

#include "Console.h"

Console::Console(int height, int width) : m_width(width), m_height(height) {

    m_bufScreen = new CHAR_INFO[m_width*m_height];
    memset(m_bufScreen, 0, sizeof(CHAR_INFO) * m_width * m_height);

    m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(m_hConsole, &csbi))
        return;
    SMALL_RECT r = csbi.srWindow;
    r.Top = 0;
    if (r.Bottom < r.Top + m_height)
        r.Bottom = r.Top + m_height;

    m_rectWindow = r;
    SetConsoleWindowInfo(m_hConsole, TRUE, &r);
}

void Console::writeChar(short c, int X, int Y, short col) {
    m_bufScreen[Y * m_width + X].Char.UnicodeChar = c;
    m_bufScreen[Y * m_width + X].Attributes = col;
}

void Console::update() {
    WriteConsoleOutput(m_hConsole, m_bufScreen, { (short)m_width, (short)m_height }, { 0,0 }, &m_rectWindow);
}

