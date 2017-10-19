#include<iostream>
using namespace std;

class Engine
{
public:
	virtual void InstallEngine() = 0;
};

class Engine4400cc:public Engine
{
public:
	void InstallEngine()
	{
		cout << "I am 4400c" << endl;
	}
};

class Engine4500cc :public Engine
{
public:
	void InstallEngine()
	{
		cout << "I am 4500c" << endl;
	}
};

class Car
{
public:
	Car(Engine* engine)
	{
		m_engine = engine;
	}
	virtual void installEngine() = 0;
protected:
	Engine* m_engine;
};

class BMW5 :public Car
{
public:
	BMW5(Engine* engine) :Car(engine)
	{

	}
	void installEngine()
	{
		m_engine->InstallEngine();
	}
};
int mainEngine()
{
	Engine* engine = new Engine4400cc;
	BMW5*   car = new BMW5(engine);
	car->installEngine();

	delete car;
	delete engine;
	car = nullptr;
	engine = nullptr;
	cout << "hello" << endl;
	system("pause");
	return 0;
}