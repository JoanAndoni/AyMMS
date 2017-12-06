#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Observer{
protected:
    string name;
public:
    virtual void anuncio(string crash1, string crash2) = 0;
};

class NASA : public Observer{
public:
    NASA(){ name = "NASA"; }
    void anuncio(string crash1, string crash2) {
        cout << "NASA informs that the " << crash1 << " and the " << crash2 << " had crash now." << endl ;
    }
};

class CNN : public Observer{
public:
    CNN(){ name = "CNN"; }
    void anuncio(string crash1, string crash2) {
        cout << "CNN informs that the " << crash1 << " and the " << crash2 << " had crash now." << endl ;
    }
};

class Evento{
    vector<Observer*> lista;
public:
    void addObservador(Observer * observer){
        lista.push_back(observer);
    }
    void anunciar(string crash1, string crash2){
        for(int i = 0; lista.size() > i; i++)
            lista[i]->anuncio(crash1, crash2);
    }
};

class SpaceThing
{
public:
    int x, y, opt, random, _id;
    bool exist = true;
    string nombre;
    SpaceThing() = default;
    SpaceThing(int a, int b) {this->x = a; this->y = b;}
    void move()
    {
        opt=rand()%4;
        random = opt;
        if (random == 0) {
            if(y != 0) y = y-1;
            else{ cout << "Reboto la nave"<< this->nombre << endl;} 
        } //UP
        else if (random == 1){
            if(y != 10) y = y+1;
            else{ cout << "Reboto "<< this->nombre << endl;}
        } //DOWN
        else if (random == 2) {
            if(x != 0) x = x-1;
            else{ cout << "Reboto "<< this->nombre << endl;}
        } //LEFT
        else if (random == 3) {
            if(x != 10) x = x+1;
            else{ cout << "Reboto "<< this->nombre << endl;}
        } //RIGHT
    }

    void crash() { this->exist = false; }
	virtual SpaceThing* clone() = 0;
};

template<class SubClase>
class ClonSpaceThing : public SpaceThing
{
public:
	SpaceThing* clone()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));  
	}
};

class PlanetExploration : public ClonSpaceThing<PlanetExploration>{
public:
    int opt;
    string name = "Planet Exploration Space";
    int _id = 1;
    PlanetExploration();
	PlanetExploration(int a, int b) { x = a; y = b; }
    PlanetExploration(const PlanetExploration& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class Colonization : public ClonSpaceThing<Colonization>   
{
public:
    int opt;
    string name = 'Colonization Space';
    int _id = 2;
    Colonization();
	Colonization(int a, int b) { x = a; y = b; }
    Colonization(const Colonization& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class PlanetObservation : public ClonSpaceThing<PlanetExploration>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
    int opt;
    string name = "Planet Observation Space";
    int _id = 3;
    PlanetObservation();
    PlanetObservation(int a, int b) { x = a; y = b; }
    PlanetObservation(const PlanetObservation& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class StonyMeteorites : public ClonSpaceThing<PlanetExploration>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
    int opt;
    string name = "Planet Observation Space";
    int _id = 5;
    StonyMeteorites();
    StonyMeteorites(int a, int b) { x = a; y = b; }
    StonyMeteorites(const StonyMeteorites& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class IronMeteorites : public ClonSpaceThing<PlanetExploration>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
    int opt;
    string name = "Planet Observation Space";
    int _id = 6;
    IronMeteorites();
	IronMeteorites(int a, int b) { x = a; y = b; }
    IronMeteorites(const IronMeteorites& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class DesertPlanets : public ClonSpaceThing<PlanetExploration>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
    int opt;
    string name = "Planet Observation Space";
    int _id = 8;
    DesertPlanets();
	DesertPlanets(int a, int b) { x = a; y = b; }
    DesertPlanets(const DesertPlanets& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class EarthAnalog : public ClonSpaceThing<PlanetExploration>  // Curiously Recurrying Template Pattern <-- C++ Idioms   
{
public:
    int opt;
    string name = "Planet Observation Space";
    int _id = 9;
    EarthAnalog();
	EarthAnalog(int a, int b) { x = a; y = b; }
    EarthAnalog(const EarthAnalog& p) { nombre = p.name, x = p.x; y = p.y; _id = p._id; }
};

class singleton{
public:
    singleton() = default;
    int a, b;
    Evento * Orbita;
    CNN * cnn;
    NASA * nasa;
    PlanetExploration* FirstShip;
    Colonization* SecondShip;
    PlanetObservation* ThirdShip;
    StonyMeteorites* FirstObj;
    IronMeteorites* SecondObj;
    DesertPlanets* ThirdObj;
    EarthAnalog* FourthObj;

	static singleton* getInstance(){
		if (!instance)
		{
			instance = new singleton;
		}
		return instance;
	}

	void operacion(){
        //Crear los observadores
        Orbita = new Evento();
        cnn = new CNN();
        nasa = new NASA();

        //Crear las tres naves primarias
        cout << "Introduce las coordenadas para la primera nave" << endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        FirstShip = new PlanetExploration(a,b);
        cout << "Introduce las coordenadas para la segunda nave" <<  endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        SecondShip = new Colonization(a,b);
        cout << "Introduce las coordenadas para la tercera nave" << endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        ThirdShip = new PlanetObservation(a,b);
        
        //Crear Asteroides
        cout << "Introduce las coordenadas para el primer asteroide" << endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        FirstObj = new StonyMeteorites(a,b);
        
        cout << "Introduce las coordenadas para el segundo asteroide" << endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        SecondObj = new IronMeteorites(a,b);

        //Crear Planetas
        cout << "Introduce las coordenadas para el planeta desierto" << endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        ThirdObj = new DesertPlanets(a,b);

        cout << "Introduce las coordenadas para el planeta tierra" << endl;
        cout << "X: ";
        cin >> a;
        cout << "Y: ";
        cin >> b; 
        FourthObj = new EarthAnalog(a,b);
	}
protected:
	static singleton* instance;
};

singleton* singleton::instance = 0;

int universe()
{
    int continuar, salida, checking1, checking2;
    bool terminar = false;
    singleton * instance = singleton::getInstance();
    instance->operacion();
    int vector[10][10] = {0};
    instance->Orbita->addObservador(instance->cnn);
    instance->Orbita->addObservador(instance->nasa);
    
    //Llenar el vector con mis objetos
    if(instance->FirstShip->exist) vector[instance->FirstShip->x][instance->FirstShip->y] = 1;
    if(instance->SecondShip->exist) vector[instance->SecondShip->x][instance->SecondShip->y] = 2;
    if(instance->ThirdShip->exist) vector[instance->ThirdShip->x][instance->ThirdShip->y] = 3;
    if(instance->FirstObj->exist) vector[instance->FirstObj->x][instance->FirstObj->y] = 5;
    if(instance->SecondObj->exist) vector[instance->SecondObj->x][instance->SecondObj->y] = 6;
    if(instance->ThirdObj->exist) vector[instance->ThirdObj->x][instance->ThirdObj->y] = 8;
    if(instance->FourthObj->exist) vector[instance->FourthObj->x][instance->FourthObj->y] = 9;
    
    cout << endl << "Imprimir UNIVERSO por primera vez" << endl;
    for(int i = 0; i < 10; i++) { for(int i2 = 0; i2 < 10; i2++) { cout << vector[i][i2] << "  "; } cout << endl; }
    
    for(int i = 0; i < 3 ; i++) {
        
        salida = 1;

        //Llenar el vector con ceros 
        for(int i = 0; i < 10; i++) { for(int i2 = 0; i2 < 10; i2++) { vector[i][i2] = 0; } }

        cout << endl << "Hace los movimientos" << endl;
        instance->FirstShip->move();
        instance->SecondShip->move();
        instance->ThirdShip->move();
        instance->FirstObj->move();
        instance->SecondObj->move();
        instance->ThirdObj->move();

        //Llenar el vector con mis objetos
        if(instance->FirstShip->exist) vector[instance->FirstShip->x][instance->FirstShip->y] = instance->FirstShip->_id;
        if(instance->SecondShip->exist) vector[instance->SecondShip->x][instance->SecondShip->y] = instance->SecondShip->_id;
        if(instance->ThirdShip->exist) vector[instance->ThirdShip->x][instance->ThirdShip->y] = instance->ThirdShip->_id;
        if(instance->FirstObj->exist) vector[instance->FirstObj->x][instance->FirstObj->y] = instance->FirstObj->_id;
        if(instance->SecondObj->exist) vector[instance->SecondObj->x][instance->SecondObj->y] = instance->SecondObj->_id;
        if(instance->ThirdObj->exist) vector[instance->ThirdObj->x][instance->ThirdObj->y] = instance->ThirdObj->_id;
        if(instance->FourthObj->exist) vector[instance->FourthObj->x][instance->FourthObj->y] = instance->FourthObj->_id;
        
        // CHECAR CUANDO CHOCAN LOS OBJETOS, CUALES SON Y PONERLES LA FUNCION DE CRASH() MANDARLOS AL OBSERVER
        

        //instance->Orbita->anunciar(instance->)

        cout << endl << "Imprimir UNIVERSO" << endl;
        for(int i = 0; i < 10; i++) { for(int i2 = 0; i2 < 10; i2++) { cout << vector[i][i2] << "  "; } cout << endl; }

        // Funciones para romper el ciclo infinito cuando ya no hay naves
        for(int i = 0; i < 10; i++) { for(int i2 = 0; i2 < 10; i2++) { if (vector[i][i2] != 0 ) { salida = 0; } } }
        if (salida == 1) {
            terminar = true;
            cout << endl << "Ya no quedan mas objetos en el universo" << endl;
        }

        if(terminar) break;

        cout << "Introduce cualquier caracter alfanumerico para ejecutar el siguiente movimiento... ";
        cin >> continuar;
    }


    //Ciclo infinito
    /*while(true)
    {

    }*/

    return 0;
}


int main()
{
    srand (time(NULL));
    universe();

    return 0;
}