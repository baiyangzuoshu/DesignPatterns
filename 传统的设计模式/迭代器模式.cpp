#include<iostream>
using namespace std;

typedef  int	Object;
#define  SIZE	5
class MyItreator
{
public:
	virtual void	First() = 0;
	virtual void	Next() = 0;
	virtual bool    isDone() = 0;
	virtual Object	getCurItem() = 0;
};
class Aggregate
{
public:
	virtual	MyItreator* createMyItreator() = 0;
	virtual int			getItemSize() = 0;
	virtual Object		getItem(int index) = 0;
};

class ContreteItreator :public MyItreator
{
public:
	ContreteItreator(Aggregate* m_ag)
	{
		this->ag = m_ag;
	}
	virtual void	First()
	{
		current_index = 0;
	}
	virtual void	Next()
	{
		if (current_index < ag->getItemSize())
		{
			current_index++;
		}
	}
	virtual bool    isDone()
	{
		return current_index == ag->getItemSize();
	}
	virtual Object getCurItem()
	{
		return ag->getItem(current_index);
	}
private:
	int			current_index;
	Aggregate	*ag;
};

class ContreteAggregate:public Aggregate
{
public:
	ContreteAggregate()
	{
		for (int i = 0; i < SIZE; i++)
		{
			object[i] = 100 + i;
		}
	}
	virtual	MyItreator* createMyItreator()
	{
		return new ContreteItreator(this);
	}
	virtual int			getItemSize()
	{
		return SIZE;
	}
	virtual Object		getItem(int index)
	{
		return object[index];
	}
private:
	Object	object[SIZE];
};
int main()
{
	Aggregate	*ag = new ContreteAggregate();
	MyItreator	*myItreator = ag->createMyItreator();

	for (; !myItreator->isDone(); myItreator->Next())
	{
		cout << myItreator->getCurItem() << endl;
	}
	cout << "helloworld" << endl;
	system("pause");
	return 0;
}