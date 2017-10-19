#include<iostream>
#include"list"
#include"string"
using namespace std;

class IFile
{
public:
	virtual void disPlay() = 0;
	virtual int add(IFile* ifile) = 0;
	virtual int remove(IFile* ifile) = 0;
	virtual list<IFile*>* getChild() = 0;

};

class File :public IFile
{
public:
	File(string name)
	{
		strName = name;
	}
	void disPlay()
	{
		cout << strName << endl;
	}
	int add(IFile* ifile)
	{
		return -1;
	}
	int remove(IFile* ifile)
	{
		return -1;
	}
	list<IFile*>* getChild()
	{
		return nullptr;
	}
private:
	string strName;
};

class Dir :public IFile
{
public:
	Dir(string name)
	{
		strName = name;
		m_list = new list<IFile*>;
		m_list->clear();
	}
	~Dir()
	{
		if (m_list)
		{
			delete m_list;
			m_list = nullptr;
		}
	}
	void disPlay()
	{
		cout << strName << endl;
	}
	int add(IFile* ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	int remove(IFile* ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	list<IFile*>* getChild()
	{
		return m_list;
	}
private:
	string strName;
	list<IFile*>* m_list;
};
int mainIFile()
{
	Dir* root = new Dir("C");
	root->disPlay();

	Dir*	dir1 = new Dir("dir1");
	File*	aaafile = new File("aaa.txt");

	list<IFile*>* m_list = root->getChild();
	root->add(dir1);
	root->add(aaafile);
	
	for (list<IFile*>::iterator it = m_list->begin(); it != m_list->end(); it++)
	{
		(*it)->disPlay();
	}
	cout << "hello" << endl;
	system("pause");
	return 0;
}