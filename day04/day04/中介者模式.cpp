#include<iostream>
#include<string>
using namespace std;
class Mediator;
class Person
{
public:
	Person(string name, int sex, int condi, Mediator* mediator)
	{
		this->m_name = name;
		this->sex = sex;
		this->condi = condi;
		this->mediator = mediator;
	}
	string getName()
	{
		return m_name;
	}
	int getSex()
	{
		return sex;
	}

	int getCondi()
	{
		return condi;
	}

	virtual void getParter(Person* p) = 0;
protected:
	string	m_name;
	int		sex;
	int		condi;
	Mediator* mediator;
};

class Mediator
{
public:
	void setMan(Person* man)
	{
		this->m_man = man;
	}
	void setWoMan(Person* woman)
	{
		this->m_woman = woman;
	}
	void getParter()
	{
		if (m_man->getSex() == m_woman->getSex())
		{
			cout << "gay" << endl;
		}
		if (m_man->getCondi() == m_woman->getCondi())
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " helloworld" << endl;
		}
		else
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " NONONO" << endl;
		}
	}
private:
	Person*	m_man;
	Person*	m_woman;
};

class Woman :public Person
{
public:
	Woman(string name, int sex, int condi, Mediator* mediator) :Person(name, sex, condi,mediator)
	{

	}
	void getParter(Person* p)
	{
		mediator->setMan(p);
		mediator->setWoMan(this);
		mediator->getParter();
	}
};

class Man :public Person
{
public:
	Man(string name, int sex, int condi,Mediator* mediator) :Person(name, sex, condi,mediator)
	{

	}
	void getParter(Person* p)
	{
		mediator->setWoMan(p);
		mediator->setMan(this);
		mediator->getParter();
	}
};


int mainMediator()
{
	Mediator*	mediator = new Mediator;
	Person*		xiaofang = new Woman("xiaofang", 2, 1,mediator);
	Person*		zhangsan = new Man("zhangsan", 1, 1,mediator);
	Person*		lisi = new Man("lisi", 1, 4,mediator);
	xiaofang->getParter(zhangsan);
	xiaofang->getParter(lisi);
	cout << "helloworld" << endl;
	system("pause");
	return 0;
}