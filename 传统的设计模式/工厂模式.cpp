#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void getFruitName() = 0;
};

class Banana :public Fruit
{
public:
	void getFruitName()
	{
		cout << "我是香蕉" << endl;
	}
};

class Apple :public Fruit
{
public:
	void getFruitName()
	{
		cout << "我是apple" << endl;
	}
};

class AbFactory
{
public:
	virtual Fruit* createProduct() = 0;
};

class BananaFactory :public AbFactory 
{
public:
	Fruit* createProduct()
	{
		return new Banana;
	}
};
int mainAbFactory()
{
	AbFactory*	abFactory = nullptr;
	Fruit*		fruit = nullptr;

	abFactory = new BananaFactory;
	fruit = abFactory->createProduct();
	fruit->getFruitName();

	delete fruit;
	delete abFactory;
	cout << "hello" << endl;
	system("pause");
	return 0;
}