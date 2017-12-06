#include <iostream>
#include <string>

using namespace std;

class Mundo
{
public:
	Mundo(string nombre) : name(nombre){}
	string name;
};


class Personaje
{
public:
	Personaje() = default;
	Personaje(string nombre) : nombre(nombre){}
	string nombre;
	int telefono;
	string correo;
	Mundo* mundo;
	virtual Personaje* clone() = 0;
};

template<class SubClase>
class ClonPersonaje : public Personaje
{
public:
	Personaje* clone()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));  // Utilizamos referencia 
	}
};

class Princesa : public ClonPersonaje<Princesa>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Princesa(string n)
	{
		nombre = n;
	}
	Princesa(const Princesa& p)
	{
		nombre = p.nombre;
		telefono = p.telefono;
		correo = p.correo;
		mundo = new Mundo(p.mundo->name);
	}
	void grita(){ cout << "aaaaa" << endl; }
};

int main()
{
	Princesa* prin = new Princesa("Susan");
	prin->correo = "g.susan@gmail.com";
	prin->telefono = 65829213;
	prin->mundo = new Mundo("Paleta");
	prin->mundo->name = "Paleton";
	Personaje* p = prin->clone();
	cout << p->nombre << endl;
	cout << p->correo << endl;
	cout << p->telefono << endl;
	cout << p->mundo->name << endl;

	Princesa* p3 = dynamic_cast<Princesa*>(p->clone()); //Downcast
	p3->mundo->name = "Paletita";
	cout << "p3 Nombre: " << p3->nombre << endl;
	cout << "p3 Correo: " << p3->correo << endl;
	cout << "p3 Telefono: " << p3->telefono << endl;
	cout << "p3 Mundo: " << p3->mundo->name << endl;


	return 0;
}