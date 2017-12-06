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
<<<<<<< HEAD

	//Nacimiento
	Personaje() = default;
	Personaje(string nombre) : nombre(nombre){}
	
	//Atributos
	string nombre;
	int telefono;
	string correo;
	
=======
	Personaje() = default;
	Personaje(string nombre) : nombre(nombre){}
    string nombre;
	int telefono;
	string correo;
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
	Mundo* mundo;
    virtual Personaje* clone() = 0;
};

class Princesa : public Personaje
{
public: 
	Princesa(string n) : Personaje(n){}
	Princesa(const Princesa& p)
	{
		nombre = p.nombre;
		telefono = p.telefono;
		correo = p.correo;
		mundo = new Mundo(p.mundo->name);
	}
    void grita(){cout << "aaaaa" << endl ;}
    Personaje* clone()
    {
        return new Princesa(*this);
    }

};

class Villano : public Personaje
{
public:
	Villano(string n) : Personaje(n){}
    void secuestra(){cout << "te atrape" << endl ;}
	Villano(const Villano& v)
	{
		nombre = v.nombre;
		telefono = v.telefono;
		correo = v.correo;
		mundo = new Mundo(v.mundo->name);
	}
    Personaje* clone()
    {
        return new Villano(*this);
    }
};

class Heroe : public Personaje
{
public: 
	Heroe(string n) : Personaje(n){}
    void salvar(){cout << "yo te rescatareeeee" << endl ;}
	Heroe(const Heroe& h)
	{
		nombre = h.nombre;
		telefono = h.telefono;
		correo = h.correo;
		mundo = new Mundo(h.mundo->name);
	}
    Personaje* clone()
    {
        return new Heroe(*this);
    }
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
	
	return 0;

}