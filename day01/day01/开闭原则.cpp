#include<iostream>
using namespace std;
class BankWorker 
{
public:
	void deposit()
	{
		cout << "���" << endl;
	}

	void transferAccounts()
	{
		cout << "ת��" << endl;
	}

	void payTheFees()
	{
		cout << "�ɷ�" << endl;
	}
};

class AbBankWorker
{
public:
	virtual	void dothing() = 0;
};

class PayTheFeesBankWorker :public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "�ɷ�" << endl;
	}
};

class DepositBankWorker :public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "���" << endl;
	}
};

class TransferAccountsBankWorker :public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "ת��" << endl;
	}
};

class AdvTransferAccountsBankWoker :public TransferAccountsBankWorker
{
	virtual void dothing()
	{
		cout << "����ת��" << endl;
	}
};

void howDo(AbBankWorker* abBankWorker)
{
	abBankWorker->dothing();
}

int mainHowdo()
{
	AbBankWorker* abBankWorker = nullptr;
	abBankWorker = new PayTheFeesBankWorker;
	abBankWorker->dothing();
	delete abBankWorker;

	abBankWorker = new AdvTransferAccountsBankWoker;
	howDo(abBankWorker);
	delete abBankWorker;
	cout << "������Ȼ���ã�"<< endl;
	system("pause");
	return 0;
}
int mainBankWorker()
{
	BankWorker bankWorker;
	bankWorker.deposit();
	bankWorker.payTheFees();
	bankWorker.transferAccounts();
	cout <<"hello"<< endl;
	system("pause");
	return 0;
}