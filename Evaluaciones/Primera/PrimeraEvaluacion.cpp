<<<<<<< HEAD
<<<<<<< HEAD
//Joan Andoni Gonzalez Rioz
//A00569929

#include <iostream>
#include <string>

using namespace std;

class Shop
{
public:
	Shop(string nombre) : name(nombre){}
	string name;
};


class Computers
{
public:
	Computers() = default;
	Computers(string nombre) : nombre(nombre){}
	string nombre;
	string marca;
	int serie;
	int GB_Ram;
	int memory;
	Shop* shop;
	virtual Computers* create(string n, string m) = 0;

	void assembly(){ cout << "Ensamblado..... Hecho" << endl; }
	void Install_Config_Software(){ cout << "Instalando y configurando..... Hecho" << endl; }
	void Packing(){ cout << "Empaquetando..... Hecho" << endl; }
	void especification()
	{
		cout << "Nombre : " << nombre << endl;
		cout << "Marca : " << marca << endl;
		cout << "Serie : " << serie << endl;
		cout << "GB_Ram : " << GB_Ram << endl;
		cout << "Memory : " << memory << endl;
		cout << "Shop : " << shop->name << endl;
	}
};

template <class Base, class SubClass>
class Create : public Base
{
public:
	Base* create(string n, string m)
	{
		SubClass* ejemplo = new SubClass(n, m);
		return ejemplo;
	}
};


/*
Desktop
Laptop
NoteBook
Tablet
Server (Rack)
Server (Tower)
*/

class Desktop : public Create<Computers, Desktop> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Desktop(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	Desktop(const Desktop& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class Laptop : public Create<Computers, Laptop> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Laptop(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	Laptop(const Laptop& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class NoteBook : public Create<Computers, NoteBook> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	NoteBook(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	NoteBook(const NoteBook& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class Tablet : public Create<Computers, Tablet> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Tablet(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	Tablet(const Tablet& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class ServerRack : public Create<Computers, ServerRack> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	ServerRack(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	ServerRack(const ServerRack& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class ServerTower : public Create<Computers, ServerTower> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	ServerTower(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	ServerTower(const ServerTower& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};


int main()
{
	int compra, computadora;
	
	Shop* primera = new Shop("PC World");

	cout << "Hola bienvenido a: " << primera->name << endl;

	Create<Computers, Desktop>* D = new Create<Computers, Desktop>;
	Create<Computers, Laptop>* L = new Create<Computers, Laptop>;
	Create<Computers, NoteBook>* N = new Create<Computers, NoteBook>;
	Create<Computers, Tablet>* T = new Create<Computers, Tablet>;
	Create<Computers, ServerRack>* SR = new Create<Computers, ServerRack>;
	Create<Computers, ServerTower>* ST = new Create<Computers, ServerTower>;

	Computers* opcion1 = D->create("Inspiron 14", "Dell");

	opcion1->shop = primera;
	opcion1->serie = 62713;
	opcion1->GB_Ram = 8;
	opcion1->memory = 500;

	cout << endl << "Estas son las especificaciones de la computadora que se le ofrece" << endl;
	opcion1->especification();
	cout << endl << "Desea comprar la computadora Si = 1 / No = 0    R = ";
	cin >> compra;
	cout << endl;
	if (compra == 1)
	{
		opcion1->assembly();
		opcion1->Install_Config_Software();
		opcion1->Packing();
		cout << endl;
	}
	else
		cout << endl << "Que tenga buen d�a esperamos que vuelva pronto\n" << endl;

	return 0;
=======
=======
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
//Joan Andoni Gonzalez Rioz
//A00569929

#include <iostream>
#include <string>

using namespace std;

class Shop
{
public:
	Shop(string nombre) : name(nombre){}
	string name;
};


class Computers
{
public:
	Computers() = default;
	Computers(string nombre) : nombre(nombre){}
	string nombre;
	string marca;
	int serie;
	int GB_Ram;
	int memory;
	Shop* shop;
	virtual Computers* create(string n, string m) = 0;

	void assembly(){ cout << "Ensamblado..... Hecho" << endl; }
	void Install_Config_Software(){ cout << "Instalando y configurando..... Hecho" << endl; }
	void Packing(){ cout << "Empaquetando..... Hecho" << endl; }
	void especification()
	{
		cout << "Nombre : " << nombre << endl;
		cout << "Marca : " << marca << endl;
		cout << "Serie : " << serie << endl;
		cout << "GB_Ram : " << GB_Ram << endl;
		cout << "Memory : " << memory << endl;
		cout << "Shop : " << shop->name << endl;
	}
};

template <class Base, class SubClass>
class Create : public Base
{
public:
	Base* create(string n, string m)
	{
		SubClass* ejemplo = new SubClass(n, m);
		return ejemplo;
	}
};


/*
Desktop
Laptop
NoteBook
Tablet
Server (Rack)
Server (Tower)
*/

class Desktop : public Create<Computers, Desktop> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Desktop(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	Desktop(const Desktop& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class Laptop : public Create<Computers, Laptop> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Laptop(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	Laptop(const Laptop& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class NoteBook : public Create<Computers, NoteBook> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	NoteBook(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	NoteBook(const NoteBook& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class Tablet : public Create<Computers, Tablet> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	Tablet(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	Tablet(const Tablet& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class ServerRack : public Create<Computers, ServerRack> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	ServerRack(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	ServerRack(const ServerRack& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};

class ServerTower : public Create<Computers, ServerTower> // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
	ServerTower(string n, string m)
	{
		nombre = n;
		marca = m;
	}


	ServerTower(const ServerTower& d)
	{
		nombre = d.nombre;
		marca = d.marca;
		serie = d.serie;
		GB_Ram = d.GB_Ram;
		memory = d.memory;
		shop = new Shop(d.shop->name);
	}
};


int main()
{
	int compra, computadora;
	
	Shop* primera = new Shop("PC World");

	cout << "Hola bienvenido a: " << primera->name << endl;

	Create<Computers, Desktop>* D = new Create<Computers, Desktop>;
	Create<Computers, Laptop>* L = new Create<Computers, Laptop>;
	Create<Computers, NoteBook>* N = new Create<Computers, NoteBook>;
	Create<Computers, Tablet>* T = new Create<Computers, Tablet>;
	Create<Computers, ServerRack>* SR = new Create<Computers, ServerRack>;
	Create<Computers, ServerTower>* ST = new Create<Computers, ServerTower>;

	Computers* opcion1 = D->create("Inspiron 14", "Dell");

	opcion1->shop = primera;
	opcion1->serie = 62713;
	opcion1->GB_Ram = 8;
	opcion1->memory = 500;

	cout << endl << "Estas son las especificaciones de la computadora que se le ofrece" << endl;
	opcion1->especification();
	cout << endl << "Desea comprar la computadora Si = 1 / No = 0    R = ";
	cin >> compra;
	cout << endl;
	if (compra == 1)
	{
		opcion1->assembly();
		opcion1->Install_Config_Software();
		opcion1->Packing();
		cout << endl;
	}
	else
		cout << endl << "Que tenga buen d�a esperamos que vuelva pronto\n" << endl;

	return 0;
<<<<<<< HEAD
>>>>>>> Subir todo despues de borrarlo
=======
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
}