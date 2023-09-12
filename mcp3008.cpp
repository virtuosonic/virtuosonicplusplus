/*********************************
*Imprime los valores de las 8 entradas
*de un mcp3008 a la salida estandar.
*compilar usando -std=c++11 -lwiringPi
*/
#include <iostream>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <mcp3004.h>

using namespace std;

int main()
{
    wiringPiSetup();
    wiringPiSPISetup(0,500000);
    mcp3004Setup(100,0);
    for (auto i : {100,101,102,103,104,105,106,107})
        cout << i << ":" << analogRead(i) << "\n";

    return 0;
}
