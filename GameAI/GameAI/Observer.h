#pragma once
#include <iostream>
#include <list>
using namespace std;


__interface iObserber
{
	virtual void update(int num) = 0;
};

__interface iSubject
{
	virtual void registerObserver(iObserber* obs) = 0;
	virtual void removeObserver(iObserber* obs) = 0;
	virtual void notifyObservers() = 0;
};


class SubjectA : public iSubject
{
private:
	list<iObserber*> m_observers;
	int m_number;

public:
	SubjectA() : m_number(0) {};

	void setNumber(int num) 
	{
		m_number = num;
		notifyObservers();
	}
	void registerObserver(iObserber* obs) override
	{
		m_observers.push_back(obs);
	}
	void removeObserver(iObserber* obs) override
	{
		m_observers.remove(obs);
	}

	void notifyObservers() override 
	{
		list<iObserber*>::iterator iterPos;

		for (iterPos = m_observers.begin(); iterPos != m_observers.end(); iterPos++) 
		{
			iObserber* curPos = *iterPos;
			curPos->update(m_number);
		}
	}
};

class ObserverA : public iObserber 
{
public:
	ObserverA(iSubject* sub) 
	{
		sub->registerObserver(this);
	}

	void update(int num) override 
	{
		cout << "Observer A : " << num << endl;
	}
};

class ObserverB : public iObserber
{
public:
	ObserverB(iSubject* sub)
	{
		sub->registerObserver(this);
	}

	void update(int num) override
	{
		cout << "Observer B : " << num << endl;
	}
};


int main() 
{
	SubjectA* subject = new SubjectA();

	ObserverA* obsA = new ObserverA(subject);
	ObserverB* obsB = new ObserverB(subject);

	subject->setNumber(100);
}