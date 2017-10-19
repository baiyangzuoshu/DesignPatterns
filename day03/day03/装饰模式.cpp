#include<iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};

class RunCar :public Car
{
public:
	virtual void show()
	{
		cout << "run car"<< endl;
	}
};

class SwimCarDirector :public Car
{
public:
	SwimCarDirector(Car* car)
	{
		m_car = car;
	}

	void show()
	{
		m_car->show();
		swim();
	}
private:
	void swim()
	{
		cout << "swim" << endl;
	}
private:
	Car* m_car;

};

class FlayCarDirector :public Car
{
public:
	FlayCarDirector(Car* car)
	{
		m_car = car;
	}


	void show()
	{
		m_car->show();
		Flay();
	}
private:
	void Flay()
	{
		cout << "Flay" << endl;
	}
private:
	Car* m_car;

};

int mainSwimCarDirector()
{
	Car* m_car = nullptr;
	m_car = new RunCar;
	cout << "m_car....................." << endl;
	m_car->show();

	SwimCarDirector* swimCarDirector = new SwimCarDirector(m_car);
	cout << "swimCarDirector....................." << endl;
	swimCarDirector->show();

	FlayCarDirector* flayCarDirector = new FlayCarDirector(swimCarDirector);
	cout << "flayCarDirector....................." << endl;
	flayCarDirector->show();

	
	system("pause");
	return 0;
}