#include<iostream>
using namespace std;

class Subject
{
public:
	virtual void sailBook() = 0;
};

class RealSubjectBook :public Subject
{
public:
	void  sailBook()
	{
		cout << "sali book" << endl;
	}
};

class dangdangProxy :public Subject
{
public:
	void sailBook()
	{
		Subject*  subject = new RealSubjectBook;
		discount();
		subject->sailBook();
		discount();
	}

	void discount()
	{
		cout << "discount" << endl;
	}
private:
	Subject* m_subject;
};
int maindangdangProxy()
{
	Subject* subject = new dangdangProxy;
	subject->sailBook();
	delete subject;
	subject = nullptr;
	cout << "hello" << endl;
	system("pause");
	return 0;
}