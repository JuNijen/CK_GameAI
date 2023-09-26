#pragma once
#include "MinerState.h"
#include "WestWorldProject.h"
#include <string>
using namespace std;



class Miner
{
private:
	int m_nHP;
	int m_nThirst;
	int m_nGold;
	int m_nInventory;

	const int m_nAdd = 3;
	const int m_nMax = 20;
	string m_sName;
	class MinerState* m_currentState;

public:
	Miner(string name) : m_sName(name) 
	{
		m_nHP = m_nMax;
		m_nThirst = m_nMax;
		m_nGold = 0;
		m_nInventory = 0;
	};
	void Update();
	void ChangeState(class MinerState* pNewState);

	int GetHP() { return m_nHP; }
	int GetThrist() { return m_nThirst; }
	int GetGold() { return m_nGold; }
	int GetInventory() { return m_nInventory; }
	int GetAdd() { return m_nAdd; }
	int GetMax() { return m_nMax; }
	string GetName() { return m_sName; }

	void SetHP(int hp) { m_nHP = hp; }
	void SetThrist(int thirst) { m_nThirst = thirst; }
	void SetGold(int gold) { m_nGold = gold; }
	void SetInventory(int inven) { m_nInventory = inven; }
	void SetName(string name) { m_sName = name; }
};