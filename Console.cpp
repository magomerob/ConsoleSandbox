//
// Created by Marcos on 22/03/2022.
//

#include "Console.h"


Console::Console(int height, int width, TCHAR title[256]) : m_width(width), m_height(height) {

    m_bufScreen = new CHAR_INFO[m_width*m_height];
    memset(m_bufScreen, 0, sizeof(CHAR_INFO) * m_width * m_height);
    for (int i = 0; i < m_width*m_height; i++) {
        m_bufScreen[i].Char.AsciiChar = ' ';
    }

    m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    m_hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(m_hConsole, &csbi))
        return;
    SMALL_RECT r = csbi.srWindow;
    r.Top = 0;
    if (r.Bottom < r.Top + m_height)
        r.Bottom = r.Top + m_height;

    m_rectWindow = r;
    SetConsoleWindowInfo(m_hConsole, TRUE, &r);

    m_rectWindow = { 0, 0, static_cast<SHORT>((short)m_width - 1), static_cast<SHORT>((short)m_height - 1) };
    if (!SetConsoleWindowInfo(m_hConsole, TRUE, &m_rectWindow)){}
    if (!SetConsoleMode(m_hConsoleIn, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT)){}

    SetConsoleTitle(title);
}

void Console::writeChar(short c, int X, int Y, short col) {
    if(X<0 || X>m_width || Y<0 || Y>m_height)return;
    m_bufScreen[Y * m_width + X].Char.UnicodeChar = c;
    m_bufScreen[Y * m_width + X].Attributes = col;
}

void Console::update() {
    WriteConsoleOutput(m_hConsole, m_bufScreen, { (short)m_width, (short)m_height }, { 0,0 }, &m_rectWindow);

    INPUT_RECORD inBuf[32];
    DWORD events = 0;
    GetNumberOfConsoleInputEvents(m_hConsoleIn, &events);
    if (events > 0)
        ReadConsoleInput(m_hConsoleIn, inBuf, events, &events);

    // Handle events - we only care about mouse clicks and movement
    // for now
    for (DWORD i = 0; i < events; i++)
    {
        switch (inBuf[i].EventType)
        {
            case FOCUS_EVENT:
            {
                m_bConsoleInFocus = inBuf[i].Event.FocusEvent.bSetFocus;
            }
                break;

            case MOUSE_EVENT:
            {
                switch (inBuf[i].Event.MouseEvent.dwEventFlags)
                {
                    case MOUSE_MOVED:
                    {
                        m_mousePosX = inBuf[i].Event.MouseEvent.dwMousePosition.X;
                        m_mousePosY = inBuf[i].Event.MouseEvent.dwMousePosition.Y;
                    }
                        break;

                    case 0:
                    {
                        for (int m = 0; m < 5; m++)
                            m_mouseState[m] = (inBuf[i].Event.MouseEvent.dwButtonState & (1 << m)) > 0;

                    }
                        break;

                    default:
                        break;
                }
            }
                break;

            default:
                break;
                // We don't care just at the moment
        }
    }
    Sleep(2);
}

void Console::makeBorder(short c) {
    for (int i = 0; i<m_height; i++){
        for (int j = 0; j<m_width; j++){
            if((j == 0 || j == m_width-1) || (i == 0 || i == m_height-1)){
                writeChar(c, j,i);
            }
        }
    }
}

int Console::getMouseX() {
    return m_mousePosX;
}

int Console::getMouseY() {
    return m_mousePosY;
}

void Console::writeStr(std::wstring str, int X, int Y, short col) {
    for (size_t i = 0; i < str.size(); i++)
    {
        if(X<0 || X+i>m_width || Y<0 || Y>m_height)return;
        m_bufScreen[Y * m_width + X + i].Char.UnicodeChar = str[i];
        m_bufScreen[Y * m_width + X + i].Attributes = col;
    }
}

void Console::clear() {
    free(m_bufScreen);
    m_bufScreen = new CHAR_INFO[m_width*m_height];
    memset(m_bufScreen, 0, sizeof(CHAR_INFO) * m_width * m_height);
}

bool Console::isRightClicked() {
    return m_mouseState[1];
}

bool Console::isLeftClicked() {
    return m_mouseState[0];
}

int Console::getDimensionsX() {
    return m_width;
}

int Console::getDimensionsY() {
    return m_height;
}

bool Console::pixelFilled(int X, int Y) {
    return m_bufScreen[Y * m_width + X].Char.AsciiChar != ' ';
}



