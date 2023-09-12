#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "escribe numero:" << endl;
    double m_value,m_max,m_min;
    m_max = 110; m_min = 20;

    cin >> m_value;
//
    double rangorotacion = M_PI * 1.5;
	double n3 = (m_max - m_min) / rangorotacion;
	n3 = ((m_value - m_min) / n3);
	n3 = n3 - (rangorotacion/2);
	n3 *= -1;
	cout << n3 << "\n";
    return 0;
}
