#include "WestWorldProject.h"


// Work
void EnterMineAndDigForNugget::Enter(Miner* miner)
{
	cout << "광부는 광산에 왔습니다.\n";
}

void EnterMineAndDigForNugget::Excute(Miner* miner)
{
	// 일을 한다
	// 인벤토리가 채워진다.
	miner->SetInventory(miner->GetInventory() + (miner->GetAdd() * 2));
	cout << "노동을 해서 인벤토리가 채워졌습니다.";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n";

	// /체력이 감소한다.
	miner->SetHP(miner->GetHP() - miner->GetAdd());
	cout << "노동을 해서 체력이 감소했습니다.";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n";

	// 주머니가 꽉 차면 은행에 간다.	
	if (miner->GetInventory() >= miner->GetMax())
	{
		miner->ChangeState(VisitBankAndDepositGold::GetInstance());
	}

	// 목이 마르면 주점에 간다.
	if (miner->GetThrist() == 0)
	{
		miner->ChangeState(QuenchThirst::GetInstance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner* miner)
{
	cout << "광부는 일을 그만두고 나왔습니다.\n";
}


// Sell
void VisitBankAndDepositGold::Enter(Miner* miner)
{
	cout << "광부는 은행에 방문했습니다.\n\n";
}

void VisitBankAndDepositGold::Excute(Miner* miner)
{
	// 인벤토리의 물건들을 판다.
	cout << "광부는 물건들을 판매했습니다.\n";
	miner->SetGold(miner->GetGold() + miner->GetInventory());
	miner->SetInventory(0);
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n";

	// 부유해졌다면 집에 간다.
	if (miner->GetGold() >= miner->GetMax())
	{
		miner->ChangeState(GoHomeAndSleepTilRested::GetInstance());
	}
	else 
	{
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
}

void VisitBankAndDepositGold::Exit(Miner* miner)
{
	cout << "광부는 은행을 나왔습니다.\n\n";
}


// Rest
void GoHomeAndSleepTilRested::Enter(Miner* miner)
{
	cout << "광부는 집에 돌아왔습니다.\n";
}

void GoHomeAndSleepTilRested::Excute(Miner* miner)
{
	// 휴식을 취하고 체력을 회복한다
	miner->SetHP(miner->GetHP() + miner->GetAdd());
	cout << "광부는 휴식을 취합니다. " << miner->GetHP() << " \n";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n\n";


	// 체력을 완전히 회복하면 일하러 간다.
	if (miner->GetHP() >= miner->GetMax())
	{
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* miner)
{
	cout << "광부는 집을 나섰습니다.\n\n";
}


// Drink
void QuenchThirst::Enter(Miner* miner)
{
	cout << "광부는 주점에 방문했습니다.\n";
}

void QuenchThirst::Excute(Miner* miner)
{
	// 술을 마신다.
	miner->SetThrist(miner->GetMax());
	cout << "광부는 술을 마십니다. " << miner->GetThrist() << " \n";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n\n";


	// 갈증을 완전히 회복하면 일하러 간다.
	if (miner->GetThrist() >= miner->GetMax())
	{
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
}

void QuenchThirst::Exit(Miner* miner)
{
	cout << "광부는 주점을 나왔습니다.\n\n";
}