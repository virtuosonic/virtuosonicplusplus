/**
Nombre: stack.cpp
Creado:14 - Julio - 2016
Autor Gabriel Espinoza
	<virtuosonic@users.sourceforge.net>
Licencia:     MIT
*/

void b();
void a(){b();}
void b() {a();}
int main()
{
	a();
	return 0;
}
