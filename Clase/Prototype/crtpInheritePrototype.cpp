<<<<<<< HEAD
<<<<<<< HEAD
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

template <class Base, class SubClass>
class Clone : public Base
{
public:
	Base* clone()
	{
		return new SubClass(dynamic_cast<SubClass&>(*this));
	}
};

class Princesa : public Clone<Personaje, Princesa>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
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
	cout << "Princesa2 Nombre: " << p->nombre << endl;
	cout << "Princesa2 Correo: " << endl;
	cout << "Princesa2 Telefono: " << endl;
	cout << "Princesa2 Mundo: " << p->mundo->name << endl << endl;

	Princesa* p3 = dynamic_cast<Princesa*>(p->clone()); //Downcast
	p3->mundo->name = "Paletita";
	cout << "Princesa3 Nombre: " << p3->nombre << endl;
	cout << "Princesa3 Correo: " << p3->correo << endl;
	cout << "Princesa3 Telefono: " << p3->telefono << endl;
	cout << "Princesa3 Mundo: " << p3->mundo->name << endl;

	cout << endl;

	return 0;
=======
=======
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
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

template <class Base, class SubClass>
class Clone : public Base
{
public:
	Base* clone()
	{
		return new SubClass(dynamic_cast<SubClass&>(*this));
	}
};

class Princesa : public Clone<Personaje, Princesa>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
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
	cout << "Princesa2 Nombre: " << p->nombre << endl;
	cout << "Princesa2 Correo: " << endl;
	cout << "Princesa2 Telefono: " << endl;
	cout << "Princesa2 Mundo: " << p->mundo->name << endl << endl;

	Princesa* p3 = dynamic_cast<Princesa*>(p->clone()); //Downcast
	p3->mundo->name = "Paletita";
	cout << "Princesa3 Nombre: " << p3->nombre << endl;
	cout << "Princesa3 Correo: " << p3->correo << endl;
	cout << "Princesa3 Telefono: " << p3->telefono << endl;
	cout << "Princesa3 Mundo: " << p3->mundo->name << endl;

	cout << endl;

	return 0;
<<<<<<< HEAD
>>>>>>> Subir todo despues de borrarlo
=======
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
}