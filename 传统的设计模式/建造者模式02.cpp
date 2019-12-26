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
	virtual void bulidDoor() = 0;
	virtual void bulidWall() = 0;
	virtual void bulidWindows() = 0;
	virtual House* getHouse() = 0;
};

class FlatBulider:public Bulider
{
public:
	void bulidDoor()
	{
		m_house->setDoor("flat door");
	}

	void bulidWall()
	{
		m_house->setWall("flat wall");
	}

	void bulidWindows()
	{
		m_house->setWindows("flat windows");
	}

	House* getHouse()
	{
		return m_house;
	}

	FlatBulider()
	{
		m_house = new House;
	}
	~FlatBulider()
	{
		if(m_house)
		{
			delete m_house;
			m_house = nullptr;
		}
	}
private:
	House* m_house;
};

class VillaBulider :public Bulider
{
public:
	void bulidDoor()
	{
		m_house->setDoor("villa door");
	}

	void bulidWall()
	{
		m_house->setWall("villa wall");
	}

	void bulidWindows()
	{
		m_house->setWindows("villa windows");
	}

	House* getHouse()
	{
		return m_house;
	}

	VillaBulider()
	{
		m_house = new House;
	}
	~VillaBulider()
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

class Director
{
public:
	Director(Bulider* bulider)
	{
		m_bulider = bulider;
	}

	void Construct()
	{
		m_bulider->bulidDoor();
		m_bulider->bulidWall();
		m_bulider->bulidWindows();
	}
private:
	Bulider* m_bulider;
};
int main()
{
	House*		house = nullptr;
	Bulider*	bulider = nullptr;

	bulider = new VillaBulider;
	Director*	director = new Director(bulider);
	director->Construct();
	house = bulider->getHouse();
	house->getDoor();
	house->getWall();
	house->getWindows();

	delete bulider;
	bulider = nullptr;
	delete director;
	director = nullptr;
	cout << "hello" << endl;
	system("pause");
	return 0;
}
