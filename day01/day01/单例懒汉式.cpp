#include<iostream>
using namespace std;

class Singleton
{
private:
	Singleton()
	{

	}
	static Singleton* m_singleton;
public:
	static Singleton* getInstance()
	{
		if (nullptr == m_singleton)
		{
			m_singleton = new Singleton;
		}
		return m_singleton;
	}
	
	static void	freeInstance()
	{
		if (m_singleton)
		{
			delete m_singleton;
			m_singleton = nullptr;
		}
	}
};
Singleton* Singleton::m_singleton = nullptr;

int mainSingleton()
{
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	if (p1 == p2)
	{
		cout <<"p1和p2相同" << endl;
	}
	else
	{
		cout << "p1和p2不相同" << endl;
	}
	cout << "hello" << endl;
	system("pause");
	return 0;
}