#pragma once
#include <string>
using namespace std;

struct Drink 
{
	Drink() {}
	virtual string drinkInfo() = 0;
};

enum drinkType
{
	COFFEE,
	COKE,
	SPRITE,
};

class Drinkfactory 
{
public:
	Drinkfactory() {}

	virtual Drink* makeDrink(drinkType type) = 0;
	//{
	//	switch(type)
	//	{
	//	case COFFEE:
	//		return new Coffee();

	//	case COKE:
	//		return new Coke();

	//	case SPRITE:
	//		return new Sprite();

	//	default:
	//		return nullptr;
	//	}
	//	return nullptr;
	//}
};