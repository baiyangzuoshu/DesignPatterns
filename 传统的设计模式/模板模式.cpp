#include<iostream>
using namespace std;

class MakeCar
{
public:
	virtual void MakeBody() = 0;
	virtual void MakeHead() = 0;
	virtual void MakeTail() = 0;
public:
	virtual void Make()
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}
};

class Bus :public MakeCar
{
public:
	virtual void MakeBody()
	{
		cout <<"Bus Body" << endl;
	}
	virtual void MakeHead()
	{
		cout << "Bus MakeHead" << endl;
	}
	virtual void MakeTail()
	{
		cout << "Bus MakeTail" << endl;
	}
};
int mainMakeCar()
{
	MakeCar* bus = new Bus;
	bus->Make();
	delete bus;
	bus = nullptr;
	cout << "hello" << endl;
	system("pause");
	return 0;
}