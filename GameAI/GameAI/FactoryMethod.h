#pragma once
#include <string>
using namespace std;

struct Drink
{
	Drink() {}
	virtual string drinkInfo() = 0;
};

struct Coffee : public Drink
{
	string drinkInfo() override
	{
		return "Coffee";
	}
};

enum drinkType
{
	COFFEE,
	COKE,
	SPRITE,
};

class DrinkFactory
{
public:
	DrinkFactory() {}
	virtual Drink* makeDrink() = 0;
};

class CoffeeFactory : public DrinkFactory
{
public:
	Drink* makeDrink() override
	{
		return new Coffee();
	}
};

class CokeFactory : public DrinkFactory
{

};

class SpriteFactory : public DrinkFactory
{

};