
/****************************
  Programa para calcular
  las fechas de una nomina
  Version: 2.0
  Licencia: GPL v3
  Autor: Jose Gabriel Espinoza Reyes
  ****************************/

#define USE_STD_PUT_TIME 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>
#include <fstream>
#if USE_STD_PUT_TIME == 1
#include <iomanip>
#endif


namespace virtuosonic
{

using namespace std;
using namespace std::chrono;
/** configuracion */
const unsigned kCantidadSemanas = 12;///cantidad que se desea de salida
const unsigned kSemanasAntiguedad =12;/// semana mas vieja a calcular
const int kDiaDeCorte = 4;//jueves
const unsigned kSegDia = 86400; //segundo q tiene un dia

/**
 * generador que produce std::chrono::system_clock::time_point
 * retrasando la fecha un dia por cada llamada a la funcion
*/
class dias_pasados_gen
{
	public:
		dias_pasados_gen()
		{
			_timepoint = system_clock::now();
		}
		system_clock::time_point operator () ()
		{
			system_clock::time_point tmp = _timepoint;
			_timepoint -= hours(24);
			return tmp;
		}
	private:
		system_clock::time_point _timepoint;
};

bool es_corte_de_nomina(system_clock::time_point tp)
{
	time_t c_tp = system_clock::to_time_t(tp);
	tm* tm_dia = localtime(&c_tp);
	if (tm_dia->tm_wday == kDiaDeCorte)return false;
	//else ;)
	return true;
}

#if USE_STD_PUT_TIME == 0
/**
 * implementacion incorrecta de put_time, pero funcional,
 * ya que gcc todavia no lo implementa
 */
char* put_time(tm* t,const char* fmt)
{
	char* lstr = new char[100];
	strftime(lstr,100,fmt,t);
	return lstr;
}
#endif

/**
 * calcula el periodo de tiempo de una semana de nomina
 * sabiendo solo el dia de corte
 */
class semana_de_nomina
{
	public:
		semana_de_nomina(const system_clock::time_point& tp)
		{
			_tp = tp;
		}
		semana_de_nomina() {}
		semana_de_nomina(const semana_de_nomina& sn)
		{
			_tp = sn._tp;
		}
		semana_de_nomina& operator= (const semana_de_nomina& sn)
		{
			_tp = sn._tp;
			return *this;
		}
		semana_de_nomina& operator= (const system_clock::time_point& tp)
		{
			_tp = tp;
			return *this;
		}
		friend ostream& operator<<(ostream& os,const semana_de_nomina& sn)
		{
			time_t tmp = system_clock::to_time_t(sn._tp - hours(24*6));
			os << put_time(localtime(&tmp),"%d/%m/%Y") << "-";
			tmp = system_clock::to_time_t(sn._tp);
			os << put_time(localtime(&tmp),"%d/%m/%Y");
			return os;
		}
	private:
		system_clock::time_point _tp;
};

}//namespace virtuosonic

int main()
{
	//inicializar
	using namespace virtuosonic;
	vector<system_clock::time_point> diaspago(kSemanasAntiguedad*7);
	//cargar dias de corte
	dias_pasados_gen generador;
	generate(diaspago.begin(),diaspago.end(),generador);
	diaspago.erase(remove_if(diaspago.begin(),diaspago.end(),es_corte_de_nomina),diaspago.end());
	//filtar y ordenar
	random_shuffle(diaspago.begin(),diaspago.end());
	diaspago.erase(diaspago.begin(),diaspago.begin()+kSemanasAntiguedad-kCantidadSemanas);
	sort(diaspago.begin(),diaspago.end());
	//generar semanas
	vector<semana_de_nomina> semanas(diaspago.size());
	copy(diaspago.begin(),diaspago.end(),semanas.begin());
	//imprimir
	std::ofstream strm("out.txt");
	copy(semanas.begin(),semanas.end(),ostream_iterator<semana_de_nomina>(strm,"\n"));
	return 0;
}
