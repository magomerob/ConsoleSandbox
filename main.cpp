#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main() {

    HWND myConsole = GetConsoleWindow();

    HDC mdc = GetDC(myConsole);


    COLORREF color = RGB(255,255,255);
    int c = 0;
    while(c < 10){
        for(double i=0; i<1000;i++){
            COORD point;
            point.X = i;
            point.Y = (int) 10*cos(i/(2*3.14)) + 20 ;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
            cout<<"O";
        }
        cin.ignore();
        c++;
        system("CLS");
    }


    system("CLS");
    ReleaseDC(myConsole, mdc);
    cin.ignore();

    return 0;
}