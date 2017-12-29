#include<iostream>
using namespace std;

class Car
{
public:
	virtual	void	run() = 0;
	virtual void	turn() = 0;
	virtual void	stop() = 0;
};

class AutoSystem
{
public:
	AutoSystem(Car* _car):car(_car){}
	void	runCar()
	{
		car->run();
	}

	void	turnCar()
	{
		car->turn();
	}

	void	stopCar()
	{
		car->stop();
	}

	void	ceshi()
	{
		this->runCar();
		this->turnCar();
		this->stopCar();
	}
private:
	Car* car;
};

class Honda :public Car
{
public:
	virtual void run() override
	{
		cout << "Honda run" << endl;
	}

	virtual void stop() override
	{
		cout << "Honda stop" << endl;
	}

	virtual void turn() override
	{
		cout << "Honda turn" << endl;
	}
};

class Mercedes :public Car
{
public:
	virtual void run() override
	{
		cout << "Mercedes run" << endl;
	}

	virtual void stop() override
	{
		cout << "Mercedes stop" << endl;
	}

	virtual void turn() override
	{
		cout << "Mercedes turn" << endl;
	}
};

class FawVw :public Car
{
public:
	virtual void run() override
	{
		cout << "FawVw run" << endl;
	}

	virtual void stop() override
	{
		cout << "FawVw stop" << endl;
	}

	virtual void turn() override
	{
		cout << "FawVw turn" << endl;
	}
};

int  main()
{
	Honda*		_honda = new Honda();
	Mercedes*	_mercedes = new Mercedes();
	FawVw*		_fawVw = new FawVw();

	AutoSystem*	_autoSystem = new AutoSystem(_honda);
	_autoSystem->ceshi();
	system("pause");
	return 0;
}