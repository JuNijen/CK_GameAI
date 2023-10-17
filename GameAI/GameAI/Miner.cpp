#include "Miner.h"

void Miner::Update()
{
	if (!m_currentState) 
	{
		m_currentState = EnterMineAndDigForNugget::GetInstance();
	}

	// ������ ��÷� ����Ѵ�.
	m_nThirst--;
	m_currentState->Excute(this);
}

void Miner::ChangeState(MinerState* pNewState)
{
	m_currentState->Exit(this);
	m_currentState = pNewState;
	m_currentState->Enter(this);
}
