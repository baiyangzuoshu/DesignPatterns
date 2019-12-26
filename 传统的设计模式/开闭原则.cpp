#include<iostream>
using namespace std;
class BankWorker 
{
public:
	void deposit()
	{
		cout << "存款" << endl;
	}

	void transferAccounts()
	{
		cout << "转账" << endl;
	}

	void payTheFees()
	{
		cout << "缴费" << endl;
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
		cout << "缴费" << endl;
	}
};

class DepositBankWorker :public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "存款" << endl;
	}
};

class TransferAccountsBankWorker :public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "转账" << endl;
	}
};

class AdvTransferAccountsBankWoker :public TransferAccountsBankWorker
{
	virtual void dothing()
	{
		cout << "批量转账" << endl;
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
	cout << "生活依然美好！"<< endl;
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