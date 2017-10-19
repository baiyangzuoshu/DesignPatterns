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

class Factory
{
public:
	Fruit* create(char* p)
	{
		if (strcmp(p, "banana")==0)
		{
			return new Banana;
		}
		else if (strcmp(p, "Apple")==0)
		{
			return new Apple;
		}
		else
		{
			return nullptr;
		}
	}
};
int mainFactory()
{
	Fruit* fruit = nullptr;
	Factory* factory = nullptr;

	fruit = factory->create("banana");
	fruit->getFruitName();
	delete fruit;

	fruit = factory->create("Apple");
	fruit->getFruitName();
	delete fruit;
	cout << "hello" << endl;
	system("pause");
	return 0;
}