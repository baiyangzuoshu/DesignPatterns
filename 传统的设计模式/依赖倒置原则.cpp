#include<iostream>
using namespace std;

class HardDisk
{
public:
	virtual void work() = 0;
};

class Memory
{
public:
	virtual void work() = 0;
};

class Cpu
{
public:
	virtual void work() = 0;
};

class Computer
{
public:
	Computer(HardDisk* hardDisk, Cpu* cpu, Memory* memory)
	{
		m_HardDisk = hardDisk;
		m_Cpu = cpu;
		m_Memory = memory;
	}
	void work()
	{
		m_HardDisk->work();
		m_Cpu->work();
		m_Memory->work();
	}
private:
	HardDisk*	m_HardDisk;
	Cpu*		m_Cpu;
	Memory*		m_Memory;
};

class IntelCpu:public Cpu
{
public:
	virtual void work()
	{
		cout << "我是英特尔的cpu" << endl;
	}
};

class KingSton :public Memory
{
public:
	virtual void work()
	{
		cout << "我是金士顿的memory" << endl;
	}
};

class WestermDigital :public HardDisk
{
public:
	virtual void work()
	{
		cout << "我是金士顿西数的harddisk" << endl;
	}
};

#define SAFE_DELETE(m_p) if(m_p){delete m_p;m_p=nullptr;}
int mainComputer()
{
	Cpu* cpu = new IntelCpu;
	Memory* memory =new KingSton;
	HardDisk* hardDisk = new WestermDigital;

	Computer* computer = new Computer(hardDisk,cpu,memory);
	computer->work();

	SAFE_DELETE(cpu);
	SAFE_DELETE(memory);
	SAFE_DELETE(hardDisk);
	SAFE_DELETE(computer);
	cout << "hello" << endl;
	system("pause");
	return 0;
}

class A
{
public:
	void doA()
	{

	}
};

class B:public A
{
public:
	void doB()
	{

	}
};

class C
{
public:
	C(A* a, B* b)
	{
		this->a = a;
		this->b = b;
	}
private:
	A* a;
	B* b;
};