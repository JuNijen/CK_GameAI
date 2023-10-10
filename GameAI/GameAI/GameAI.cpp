// GameAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "GameAI.h"



int main() 
{
	//templateMethod();
	//drinkFactory();
	//trafficLight();
	westWorld();

	return 0;
}

void templateMethod() 
{
	TemplateMethod* templateMethod = new TemplateMethod();
	templateMethod->Start();
}

//void drinkFactory()
//{
//	Drinkfactory* drinkfactory = new Drinkfactory();
//	Drink* coffee = drinkfactory->makeDrink(COFFEE);
//	cout << coffee->drinkInfo() << endl;
//}

//void canFactory() 
//{
//	CanFactory canfactory;
//	Can* can = canfactory.createClone(COKE);
//	can->draw()
//}

void trafficLight() 
{
	TrafficLight* trafficLightFSM = new TrafficLight();

	for (int i = 0; i < 10; i++) 
	{
		trafficLightFSM->StartTrafficLight();
	}
}

void westWorld() 
{
	Miner miner("en_miner_bob");

	for (int i = 0; i < 100; i++) 
	{
		miner.Update(); 
		Sleep(1000); 
	}
}
