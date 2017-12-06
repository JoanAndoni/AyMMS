#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer{
protected:
    string name;
public:
    virtual void anuncio(string anuncio)=0;
};

class Mvs : public Observer{
public:
    Mvs(){
        name = "Mvs Noticias";
    }
    void anuncio(string anuncio){
        cout << "Noticiero Mvs: " << anuncio << "\n";
    }
};

class Televisa : public Observer{
public:
    Televisa(){
        name = "Televisa Noticias";
    }
    void anuncio(string anuncio){
        cout << "Noticiero Televisa: " << anuncio << "\n";
    }
};

class RadioCapital : public Observer{
public:
    RadioCapital(){
        name = "RadioCapital Noticias";
    }
    void anuncio(string anuncio){
        cout << "RadioCapital Televisa: " << anuncio << "\n";
    }
};

class CNN : public Observer{
public:
    CNN(){
        name = "CNN Noticias";
    }
    void anuncio(string anuncio){
        cout << "CNN Noticias: " << anuncio << "\n";
    }
};

class Subject{
    vector<Observer*> lista;
public:
    void addObservador(Observer * observer){
        lista.push_back(observer);
    }
    void anunciar(string anuncio){
        for(int i = 0; lista.size() > i; i++)
            lista[i]->anuncio(anuncio);
    }
};

class Trump : public Subject{
public:
    void anuncia(string anuncio){
        anunciar(anuncio);
    }
};

class EPN : public Subject{
public:
    void anuncia(string anuncio){
        anunciar(anuncio);
    }
};

class Kim : public Subject{
public:
    void anuncia(string anuncio){
        anunciar(anuncio);
    }
};



int main(int argc, const char * argv[]) {
    //Instanciar Subjects
    Kim * kim = new Kim();
    EPN * pena = new EPN();
    Trump * trompetas = new Trump();
    
    //Instanciar Observers
    Televisa * tele = new Televisa();
    CNN * cnn = new CNN();
    Mvs * mvs = new Mvs();
    RadioCapital * radio = new RadioCapital();
    
    //Agregar Observadores a Subjects
    kim->addObservador(cnn);
    
    pena->addObservador(cnn);
    pena->addObservador(tele);
    pena->addObservador(mvs);
    pena->addObservador(radio);

    trompetas->addObservador(cnn);
    trompetas->addObservador(mvs);
    trompetas->addObservador(tele);
    
    kim->anuncia("Hydrogen Bombs have been developed");
    pena->anuncia("1 ano menos como 5");
    trompetas->anuncia("I'm the best");

    
    delete tele;
    delete cnn;
    delete mvs;
    delete radio;
    delete kim;
    delete pena;
    delete trompetas;

    return 0;
}
