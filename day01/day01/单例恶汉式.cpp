#include<iostream>
using namespace std;

class HungerSingleton
{
private:
	HungerSingleton()
	{

	}
	static HungerSingleton* m_singleton;
public:
	static HungerSingleton* getInstance()
	{
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
HungerSingleton* HungerSingleton::m_singleton = new HungerSingleton;

int mainHungerSingleton()
{
	HungerSingleton* p1 = HungerSingleton::getInstance();
	HungerSingleton* p2 = HungerSingleton::getInstance();
	if (p1 == p2)
	{
		cout << "p1和p2相同" << endl;
	}
	else
	{
		cout << "p1和p2不相同" << endl;
	}
	cout << "hello" << endl;
	system("pause");
	return 0;
}