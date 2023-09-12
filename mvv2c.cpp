#include <iostream>
#include <cmath>
using namespace std;

/**Convierte de mV/V a Ohms.
**Para uso con RTD y un Voltage Divider
*@param mV/V leidos por el 1046.
*@param Valor en ohms de la resistencia
*conectada al positivo.
*@param Valor en ohms de la resistencia
*conectada al negativo.
*/
double mVperV2Ohms(double Vb, double R1,double R2)
{
	return R1 + R2 * ((Vb/1000) / (1-(Vb/1000)));
}

/**
*Convierte de ohms a grados celsius.
*Para uso con RTD y un Voltage Divider
*@param valor en ohms
*@param coeficiente alfa dependiente del RTD
*@param resistencia en ohms del RTD a 0 grados celsius
*/
double ohms2Cdeg(double ohms,double alfa,int RTD_type)
{
	double R100;
	R100 = alfa * 1000 + RTD_type;
	return (ohms - RTD_type) / (R100 - RTD_type);
}

/** leer pt100o pt1000
*/
double readRTD(double ohms,int RTD_type)
{
	return ( 4.7503 * 10e7 / pow(RTD_type,2) )
	* pow((ohms/(1000-ohms)),2) + (4.6156*10e5/RTD_type )
	 * (ohms/( 1000-ohms)) - 242.615;
}


int main()
{
	double n1;
    cout << "escribe el numero:";
    cin >> n1;
    double n2 = mVperV2Ohms(n1,1000,1000);
    cout << n2 << "\n";
    cout << ohms2Cdeg(n2,0.007701,2000) << "\n";
    cout << readRTD(n1,2000) << "\n";
    cout << 2000 * n1/(1-n1)<< "\n";
    return 0;
}
