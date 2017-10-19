#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void sayName() = 0;
};



class NorthBanana :public Fruit
{
public:
	void sayName()
	{
		cout <<"I am NorthBanana" << endl;
	}
};

class NorthApple :public Fruit
{
public:
	void sayName()
	{
		cout << "I am NorthApple" << endl;
	}
};

class SouthApple :public Fruit
{
public:
	void sayName()
	{
		cout << "I am SouthApple" << endl;
	}
};

class SouthBanana :public Fruit
{
public:
	void sayName()
	{
		cout << "I am SouthBanana" << endl;
	}
};

class  AbstractFactory
{
public:
	virtual Fruit* createBanana() = 0;
	virtual Fruit* createApple() = 0;
};

class NorthFactory :public AbstractFactory
{
public:
	Fruit* createBanana()
	{
		return new NorthBanana;
	}
	Fruit* createApple()
	{
		return new NorthApple;
	}
};

class SouthFactory :public AbstractFactory
{
public:
	Fruit* createBanana()
	{
		return new SouthBanana;
	}
	Fruit* createApple()
	{
		return new SouthApple;
	}
};

int mainAbstractFactory()
{
	Fruit*				fruit = nullptr;
	AbstractFactory*	abFactory = nullptr;
	
	abFactory = new NorthFactory;
	fruit = abFactory->createApple();
	fruit->sayName();
	delete fruit;

	fruit = abFactory->createBanana();
	fruit->sayName();
	delete fruit;
	delete abFactory;

	abFactory = new SouthFactory;
	fruit = abFactory->createApple();
	fruit->sayName();
	delete fruit;

	fruit = abFactory->createBanana();
	fruit->sayName();
	delete fruit;
	delete abFactory;
	cout << "hello" << endl;
	system("pause");
	return 0;
}