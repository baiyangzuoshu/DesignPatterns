#include<iostream>
#include"string"
using namespace std;

class House
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setWindows(string windows)
	{
		this->m_windows = windows;
	}

	string getDoor()
	{
		cout << m_door << endl;
		return m_door;
	}
	string getWall()
	{
		cout << m_wall << endl;
		return m_wall;
	}
	string getWindows()
	{
		cout << m_windows << endl;
		return m_windows;
	}
private:
	string m_door;
	string m_wall;
	string m_windows;
};

class Bulider
{
public:
	void bulidDoor(House* h)
	{
		h->setDoor("door");
	}
	void bulidWall(House* h)
	{
		h->setWall("wall");
	}
	void bulidWindows(House* h)
	{
		h->setWindows("windows");
	}

	void makeBulid()
	{
		bulidDoor(m_house);
		bulidWall(m_house);
		bulidWindows(m_house);
	}

	House* getHouse()
	{
		return m_house;
	}

	Bulider()
	{
		m_house = new House;
	}

	~Bulider()
	{
		if (m_house)
		{
			delete m_house;
			m_house = nullptr;
		}
	}
private:
	House* m_house;
};
int mainBulider()
{
	House*    m_house = nullptr;
	Bulider*  m_bulider = nullptr;

	m_bulider = new Bulider();
	m_bulider->makeBulid();
	m_house = m_bulider->getHouse();
	m_house->getDoor();
	m_house->getWall();
	m_house->getWindows();

	delete m_bulider;
	m_bulider = nullptr;
	cout << "hello" << endl;
	system("pause");
	return 0;
}