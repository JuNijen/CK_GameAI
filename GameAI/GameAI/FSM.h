#pragma once
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

class TrafficLight
{
public:
	enum States
	{
		red,
		yellow,
		green
	};

	States m_state;

	TrafficLight(States state = red) : m_state(red) {}

	void StartTrafficLight()
	{
		PrintState();

		switch (m_state) 
		{
		case red:
			Sleep(2000);
			m_state = green;
			break;

		case yellow:
			Sleep(1000);
			m_state = red;
			break;

		case green:
			Sleep(3000);
			m_state = yellow;
			break;
		}
	}

	void PrintState()
	{
		switch (m_state) 
		{
		case red:
			cout << "red\n";
			break;

		case yellow:
			cout << "yellow\n";
			break;

		case green:
			cout << "green\n";
			break;
		}
	}
};