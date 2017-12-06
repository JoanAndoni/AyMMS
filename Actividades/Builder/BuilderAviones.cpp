#ifndef Builder_hpp
#define Builder_hpp
#include <iostream>
#include <string>

using namespace std;

class Motor{
private:
    int potencia;
    int numSerie;
public:
    Motor() = default;
    //Lista de inicialización, asignar parametros a variable
    Motor(int pot, int nS) : potencia(pot), numSerie(nS){}
    int getPotencia() {return potencia;}
    int getNumSerie() {return numSerie;}
};

class Alas{
    string marca;
    int numSerie;
    int hiper;
    int spoilers;
public:
    Alas() = default;
    Alas(string mc, int nS, int hp, int sp) : marca(mc), numSerie(nS), hiper(hp), spoilers(sp){	}
    string getMarca() {return marca;}
    int getNumSerie() {return numSerie;}
    int getHiper() {return hiper;}
    int getSpoiler() {return spoilers;}
};

class Avion
{
    Alas* alas;
    Motor* motor;
    int numSerie;
    string modelo;
    string marca;
 
 public:
    void setAlas(Alas* a){alas = a;}
    void setMotor(Motor* a) {motor = a;}
    void setnumSerie(int ns){numSerie = ns;}
    void setModelo(string mod){modelo = mod;}
    void setMarca(string m){marca = m;}
public:
    string getMarca() {return marca;}
    string getModelo() {return modelo;}
    int getNumSerie() {return numSerie;}
    Alas * getAlas() {return alas;}
    Motor * getMotor() {return motor;}
};

class Builder
{
    Avion* avion;
public:
    Avion* getAvion() {return avion;}
    void createAvion()
    {
        avion = new Avion;

    }
    virtual Motor* buildMotor() = 0;
    virtual Alas* buildAlas() = 0;
    virtual string buildMarca() = 0;
    virtual string buildModelo() = 0;
    virtual int buildNumSerie() = 0;
};

class BoeingBuilder : public Builder
{
public:
    Motor* buildMotor()
    {
        Motor* motor = new Motor(10000, 111111);
        Avión->setMotor(motor);
        return motor;
    }
    Alas* buildAlas()
    {
        Alas* alas = new Alas("Boeing", 101010, 10,10);
        avion->setAlas(alas);
        return alas;
    }
    string buildMarca()
    {
        avion->setMarca("Boeing");
        return avion->getMarca();
    }
    
    string buildModelo()
    {
        avion->setModelo("722");
        return avion->getModelo();
    }
    int buildNumSerie()
    {
        avion->setNumSerie(234453);
        return avion->getNumSerie();
    }

};

class Director
{
    Builder * builder;

public:
    void setBuilder(string tipoAvion)
    {
        if(tipoAvion == "Boeing")
        {
            builder = new BoeingBuilder;
        }
    }

    Avion* getAvion()
    {
        return builder->getAvion();
    } 
    void construct()
    {
        builder->createAvion();
        builder->buildMotor();
        builder->buildModelo();
        builder->buildAlas();
        builder->buildMarca();
        builder->buildNumSerie();
    }
};

int main()
{
    Director d;
    d.setBuilder("Boeing");
    d.construct();
    Avion* a = d.getAvion();
    cout << a->getMarca();
}