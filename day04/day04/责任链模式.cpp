#include<iostream>
using namespace std;

class CarHandle
{
public:
	virtual void HandleCar() = 0;
	CarHandle* setHandleCar(CarHandle* carHandle)
	{
		m_CarHandle = carHandle;
		return m_CarHandle;
	}
protected:
	CarHandle* m_CarHandle;
};

class HeadCarHandle :public CarHandle
{
public:
	void HandleCar()
	{
		cout << "headcarHandle" << endl;
		if (m_CarHandle)
		{
			m_CarHandle->HandleCar();
		}
	}
};

class BodyCarHandle :public CarHandle
{
public:
	void HandleCar()
	{
		cout << "bodycarhandle" << endl;
		if (m_CarHandle)
		{
			m_CarHandle->HandleCar();
		}
	}
};

class TailCarHandle :public CarHandle
{
public:
	void HandleCar()
	{
		cout << "tailcarhandle" << endl;
		if (m_CarHandle)
		{
			m_CarHandle->HandleCar();
		}
	}
};

int mainCarHandle()
{
	HeadCarHandle	*headCarHandle = new HeadCarHandle;
	BodyCarHandle	*bodyCarHandle = new BodyCarHandle;
	TailCarHandle	*tailCarHandle = new TailCarHandle;

	headCarHandle->setHandleCar(bodyCarHandle);
	bodyCarHandle->setHandleCar(tailCarHandle);
	tailCarHandle->setHandleCar(nullptr);

	headCarHandle->HandleCar();

	delete headCarHandle;
	delete bodyCarHandle;
	delete tailCarHandle;
	cout << "helloworld" << endl;
	system("pause");
	return 0;
}