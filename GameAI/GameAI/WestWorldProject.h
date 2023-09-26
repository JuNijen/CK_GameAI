#pragma once
#include <iostream>
#include "Miner.h"
#include "MinerState.h"



// Work
class EnterMineAndDigForNugget : public MinerState
{
public:
	EnterMineAndDigForNugget() {}

	static MinerState* GetInstance() {
		static MinerState* instance = new EnterMineAndDigForNugget();
		return instance;
	};

	void Enter(Miner* miner);
	void Excute(Miner* miner);
	void Exit(Miner* miner);
};


// Sell
class VisitBankAndDepositGold : MinerState
{
public:
	VisitBankAndDepositGold() {}

	static MinerState* GetInstance() {
		static MinerState* instance = new VisitBankAndDepositGold();
		return instance;
	};
	void Enter(Miner* miner);
	void Excute(Miner* miner);
	void Exit(Miner* miner);
};


// Rest
class GoHomeAndSleepTilRested : MinerState
{
public:
	GoHomeAndSleepTilRested() {}

	static MinerState* GetInstance() {
		static MinerState* instance = new GoHomeAndSleepTilRested();
		return instance;
	};
	void Enter(Miner* miner);
	void Excute(Miner* miner);
	void Exit(Miner* miner);
};


// Drink
class QuenchThirst : MinerState
{
public:
	QuenchThirst() {}

	static MinerState* GetInstance() {
		static MinerState* instance = new QuenchThirst();
		return instance;
	};

	void Enter(Miner* miner);
	void Excute(Miner* miner);
	void Exit(Miner* miner);
};
