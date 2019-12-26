#include<iostream>
#include"string"
#include"map"
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->age = age;
		this->strName = name;
	}
	virtual  void printObject() = 0;
protected:
	string	strName;
	int		age;
};

class  Teacher :public Person
{
public:
	Teacher(string name, int age,string id) :Person(name, age)
	{
		strId = id;
	}
	void printObject()
	{
		cout << "name:" << strName << ",age:" << age << ",id:" << strId << endl;
	}
private:
	string strId;
};

class FlyWeightTeacherFactory
{
public:
	FlyWeightTeacherFactory()
	{
		m_mfwtfPerson.clear();
	}

	Person* getObject(string id)
	{
		Person* tmp = nullptr;
		map<string, Person*>::iterator it;
		it = m_mfwtfPerson.find(id);
		if (it == m_mfwtfPerson.end())
		{
			string personName = "";
			cout << "/n请输入老师的名字" << endl;
			cin >> personName;

			int    personAge = 0;
			cout << "/n请输入老师的年龄" << endl;
			cin >> personAge;

			tmp =new Teacher(personName, personAge, id);
			m_mfwtfPerson.insert(pair<string, Person*>(id, tmp));
		}
		else
		{
			tmp = it->second;
		}
		return tmp;
	}

	~FlyWeightTeacherFactory()
	{
		while (!m_mfwtfPerson.empty())
		{
			Person* tmp = nullptr;
			map<string, Person*>::iterator it = m_mfwtfPerson.begin();
			tmp = it->second;
			m_mfwtfPerson.erase(it);
			delete tmp;
		}
	}
private:
	map<string, Person*> m_mfwtfPerson;
};
int mainFlyWeightTeacherFactory()
{
	Person* person1 = nullptr;
	Person* person2 = nullptr;
	FlyWeightTeacherFactory* fwtf = new FlyWeightTeacherFactory;
	person1 = fwtf->getObject("001");
	person1->printObject();

	person2 = fwtf->getObject("001");
	person2->printObject();

	delete fwtf;
	fwtf = nullptr;
	cout << "hello" << endl;
	system("pause");
	return 0;
}