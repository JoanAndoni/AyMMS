#include <iostream>

using namespace std;

//Forward Declaration: Declara la clase que vas a usar sin que contenga el codigo
//La unica restricción es que todos los datos tienen que usar apuntadores 
//No puedes usar metodos de la clase porque todavia no tienen funcion, se tiene que
//tener el uso de la clase debajo de cuando ya se declaro la clase
template <class T>
class IntIterator;

template <class T>
class IntCollection {
protected:
	int size;
	T* array;
	int cont = 0;
public:
	friend class IntIterator<T>;//Friend class puede acceder a protected y private
	IntCollection() {
		size = 10;
		array = new T[size];
	}
	void add(T value) {
		if (cont<= size) {
			array[cont++] = value;
			return;
		}
		cout << "Ya no hay espacio para agregar elementos";
	}
	IntIterator<T> * getIterator();

	T at(int pos) {	//Devuelve un elemento en una posición
		return array[pos];
	}
};

template <class T>
class IntIterator {
protected:
	IntCollection<T> coll;
	int cont = 0;
public:
	IntIterator(const IntCollection<T>& coll) : coll(coll) {}

	bool hasNext() {
		if (cont < coll.cont)
			return true;
		return false;
	}

	T next() {
		return coll.at(cont++);
	}
};

template <class T>
bool even(T t) {
	if (t % 2 == 0) {
		return true;
	}
	return false;
}

template <class T, typename F>
void find_if(IntCollection<T> coll,F func) {
	IntIterator<int> * it = coll.getIterator();
	while (it->hasNext()) {
		T naxt = it->next();
		if (func(naxt)) {
			cout << naxt << endl;//Cada que encuentra uno que cumpla
		}
	}
}

template <class T>
IntIterator<T>* IntCollection<T>::getIterator() {//Devuelve instancia de un iterador
	return new IntIterator<T>(*this);//Devuelve una isntancia de si mismo
}	

//Normal
void doOperation(int num) {
	cout << num << endl;
}
//Funcion con tempate y parametro de función
template <typename F>
void doOperation(F f){
	int temp = 0;
	f(temp);
	cout << "Result is " << temp << std::endl;
}

int main() {
	IntCollection<int> i;
	i.add(1);
	i.add(4);
	i.add(3);
	i.add(2);

	IntIterator<int> * it = i.getIterator();
	
	find_if<int, bool(&)(int)>(i,even<int>);

	delete it;

	/*
	int arr[5] = {0,1,2,3,4};//arreglo -> pointer estatico
	int * a = new int(10);
	cout << a << endl;//Hex
	doOperation(5);
	//Ventaja de tener una funcion con apuntadores es que puedes recibir una funcion como parametro
	//Permite que el ususario escriba elementos dentro de la función
	cout << doOperation;
	*/
	int is;
	cin >> is;
	return 0;
}