#include "WestWorldProject.h"


// Work
void EnterMineAndDigForNugget::Enter(Miner* miner)
{
	cout << "���δ� ���꿡 �Խ��ϴ�.\n";
}

void EnterMineAndDigForNugget::Excute(Miner* miner)
{
	// ���� �Ѵ�
	// �κ��丮�� ä������.
	miner->SetInventory(miner->GetInventory() + (miner->GetAdd() * 2));
	cout << "�뵿�� �ؼ� �κ��丮�� ä�������ϴ�.";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n";

	// /ü���� �����Ѵ�.
	miner->SetHP(miner->GetHP() - miner->GetAdd());
	cout << "�뵿�� �ؼ� ü���� �����߽��ϴ�.";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n";

	// �ָӴϰ� �� ���� ���࿡ ����.	
	if (miner->GetInventory() >= miner->GetMax())
	{
		miner->ChangeState(VisitBankAndDepositGold::GetInstance());
	}

	// ���� ������ ������ ����.
	if (miner->GetThrist() == 0)
	{
		miner->ChangeState(QuenchThirst::GetInstance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner* miner)
{
	cout << "���δ� ���� �׸��ΰ� ���Խ��ϴ�.\n";
}


// Sell
void VisitBankAndDepositGold::Enter(Miner* miner)
{
	cout << "���δ� ���࿡ �湮�߽��ϴ�.\n\n";
}

void VisitBankAndDepositGold::Excute(Miner* miner)
{
	// �κ��丮�� ���ǵ��� �Ǵ�.
	cout << "���δ� ���ǵ��� �Ǹ��߽��ϴ�.\n";
	miner->SetGold(miner->GetGold() + miner->GetInventory());
	miner->SetInventory(0);
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n";

	// ���������ٸ� ���� ����.
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
	cout << "���δ� ������ ���Խ��ϴ�.\n\n";
}


// Rest
void GoHomeAndSleepTilRested::Enter(Miner* miner)
{
	cout << "���δ� ���� ���ƿԽ��ϴ�.\n";
}

void GoHomeAndSleepTilRested::Excute(Miner* miner)
{
	// �޽��� ���ϰ� ü���� ȸ���Ѵ�
	miner->SetHP(miner->GetHP() + miner->GetAdd());
	cout << "���δ� �޽��� ���մϴ�. " << miner->GetHP() << " \n";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n\n";


	// ü���� ������ ȸ���ϸ� ���Ϸ� ����.
	if (miner->GetHP() >= miner->GetMax())
	{
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* miner)
{
	cout << "���δ� ���� �������ϴ�.\n\n";
}


// Drink
void QuenchThirst::Enter(Miner* miner)
{
	cout << "���δ� ������ �湮�߽��ϴ�.\n";
}

void QuenchThirst::Excute(Miner* miner)
{
	// ���� ���Ŵ�.
	miner->SetThrist(miner->GetMax());
	cout << "���δ� ���� ���ʴϴ�. " << miner->GetThrist() << " \n";
	cout << "(HP: " << miner->GetHP() << "Thirst : " << miner->GetThrist() << " Gold : " << miner->GetGold() << "Inventory: " << miner->GetInventory() << ")\n\n";


	// ������ ������ ȸ���ϸ� ���Ϸ� ����.
	if (miner->GetThrist() >= miner->GetMax())
	{
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
}

void QuenchThirst::Exit(Miner* miner)
{
	cout << "���δ� ������ ���Խ��ϴ�.\n\n";
}