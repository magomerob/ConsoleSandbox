#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include "Console.h"

using namespace std;

int WHITE = 0x000F;

int main() {

    Console cons = Console(100,100);


    for(double i=0; i<100;i++){
        int X = i;
        int Y = (int) 10*cos(i/(2*3.14)) + 10 ;
        cons.writeChar( '█', X, Y);
    }
    cons.update();
    cin.ignore();
    cin.ignore();

    return 0;
}