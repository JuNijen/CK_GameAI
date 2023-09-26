#pragma once
#include "Miner.h"

class MinerState
{
public:
	virtual void Enter(class Miner* miner) =0;
	virtual void Excute(class Miner* miner)=0;
	virtual void Exit(class Miner* miner)=0;
};