#include <iostream>
using namespace std;

class singleton{
private:
	singleton() = default;

public:

	static singleton* getInstance(){
		if (!instance)
		{
			instance = new singleton;
		}
		return instance;
	}

	void operacion(){

		cout << "Dir de singleton: " << instance <<endl;
	}
protected:
	static singleton* instance;
};

singleton* singleton::instance = 0;

int main(int argc, char** argv)
{
	singleton s;
	s.operacion();
	singleton * instance = singleton::getInstance();
	instance->operacion();
	singleton * instance2 = singleton::getInstance();
	instance2->operacion();
	singleton * instance3 = singleton::getInstance();
	instance3->operacion();
}