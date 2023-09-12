#pragma once
#include <string>
#include <iostream>
using namespace std;


class Coffee 
{
	string m_name;

public:
	Coffee(string s) : m_name(s) {}

	void makeCoffee() 
	{
		void putEspresso();
		void putExtra();
		void takeout();
	}

	void putEspresso();
	void takeout();

	virtual void putExtras() = 0;
};


class Americano : public Coffee 
{
public:
	Americano(string s) : Coffee(s) {}
	void putExtras() override
	{
		cout << "Add Water";
	}
};

class CaffeLatte : public Coffee
{
public:
	CaffeLatte(string s) : Coffee(s) {}
	void putExtras() override
	{
		cout << "Add Milk";
	}
};


class TemplateMethod
{
public:
	void Start()
	{
		Americano* americano = new Americano("merimericano");
		CaffeLatte* caffelatte = new CaffeLatte("lalalatte");

		americano->makeCoffee();
		caffelatte->makeCoffee();
	}
};