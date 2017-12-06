<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#include <ctime>
using namespace std;


class Clock{
private:
	Clock() = default;

public:

	static Clock* getInstance(){
		if (!instance)
		{
			instance = new Clock;
		}
		return instance;
	}

	void operacion(){
		time_t now = time(0);
		char* dt = ctime(&now);
		cout << "The local date and time is: " << dt << endl;
	}
protected:
	static Clock* instance;
};

Clock* Clock::instance = 0;

int main(int argc, char** argv)
{
	Clock * instance = Clock::getInstance();
	instance->operacion();
=======
=======
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
#include <iostream>
#include <ctime>
using namespace std;


class Clock{
private:
	Clock() = default;

public:

	static Clock* getInstance(){
		if (!instance)
		{
			instance = new Clock;
		}
		return instance;
	}

	void operacion(){
		time_t now = time(0);
		char* dt = ctime(&now);
		cout << "The local date and time is: " << dt << endl;
	}
protected:
	static Clock* instance;
};

Clock* Clock::instance = 0;

int main(int argc, char** argv)
{
	Clock * instance = Clock::getInstance();
	instance->operacion();
<<<<<<< HEAD
>>>>>>> Subir todo despues de borrarlo
=======
>>>>>>> dc71be081124da78cefa269cb09ab8f2c52e68ac
}