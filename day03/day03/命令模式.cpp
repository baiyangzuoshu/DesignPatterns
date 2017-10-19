#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void treat_eye()
	{
		cout << "doctor eye" << endl;
	}

	void treat_nose()
	{
		cout << "doctor nose" << endl;
	}
};
class Command
{
public:
	virtual void treat() = 0;
};

class CommandTreatNose :public Command
{
public:
	CommandTreatNose(Doctor* doctor)
	{
		this->m_doctor = doctor;
	}
	void treat()
	{
		m_doctor->treat_nose();
	}
private:
	Doctor* m_doctor;
};

class CommandTreatEye :public Command
{
public:
	CommandTreatEye(Doctor* doctor)
	{
		this->m_doctor = doctor;
	}
	void treat()
	{
		m_doctor->treat_eye();
	}
private:
	Doctor* m_doctor;
};

class BeautyNurse
{
public:
	BeautyNurse(Command* command)
	{
		m_command = command;
	}

	void SubmiitedCase()
	{
		m_command->treat();
	}
private:
	Command* m_command;
};

class HeadNurse
{
public:
	HeadNurse()
	{
		m_list.clear();
	}
public:
	void  addCommand(Command* command)
	{
		m_list.push_back(command);
	}
	void  SubmiitedCase()
	{
		for (list<Command*>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->treat();
		}
	}
private:
	list<Command*> m_list;
};

void testHeadNurse()
{
	HeadNurse		*headNurse = nullptr;
	Doctor			*doctor = nullptr;
	Command			*command1 = nullptr;
	Command			*command2 = nullptr;

	doctor = new Doctor;

	command1 = new CommandTreatNose(doctor);
	command2 = new CommandTreatEye(doctor);
	headNurse = new HeadNurse();
	headNurse->addCommand(command1);
	headNurse->addCommand(command2);

	headNurse->SubmiitedCase();

	delete doctor;
	delete command1;
	delete command2;
	delete headNurse;
}

void testBeautyNurse()
{
	BeautyNurse		*beautyNurse = nullptr;
	Doctor			*doctor = nullptr;
	Command			*command = nullptr;

	doctor = new Doctor;

	command = new CommandTreatNose(doctor);
	beautyNurse = new BeautyNurse(command);
	beautyNurse->SubmiitedCase();

	delete doctor;
	delete command;
	delete beautyNurse;
}
int mainCommand()
{
	//testBeautyNurse();
	testHeadNurse();
	cout << "hello" << endl;
	system("pause");
	return 0;
}