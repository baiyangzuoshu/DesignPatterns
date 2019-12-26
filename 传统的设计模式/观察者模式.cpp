#include<iostream>
#include<string>
#include<list>
using namespace std;

class PlayserObserver
{
public:
	void update(string action)
	{
		cout << "action:" << action << endl;
	}
};
class Secretary
{
public:
	Secretary()
	{
		m_list.clear();
	}

	void Notify(string action)
	{
		for (list<PlayserObserver*>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->update(action);
		}
	}

	void addPlayserObserver(PlayserObserver* po)
	{
		m_list.push_back(po);
	}
private:
	list<PlayserObserver*>	m_list;
};

int mainSecretary()
{
	Secretary			*secretary = nullptr;
	PlayserObserver		*po1 = nullptr;
	PlayserObserver		*po2 = nullptr;
	PlayserObserver		*po3 = nullptr;

	secretary = new Secretary;
	po1 = new PlayserObserver;
	po2 = new PlayserObserver;
	po3 = new PlayserObserver;

	secretary->addPlayserObserver(po1);
	secretary->addPlayserObserver(po2);
	secretary->addPlayserObserver(po3);
	secretary->Notify("我来了！");
	secretary->Notify("她来了？");
    
	delete secretary;
	delete po1;
	delete po2;
	delete po3;
	system("pause");
	return 0;
}