#include "Miner.h"

void Miner::Update()
{
	if (!m_currentState) 
	{
		m_currentState = EnterMineAndDigForNugget::GetInstance();
	}

	// 갈증은 상시로 계산한다.
	m_nThirst--;
	m_currentState->Excute(this);
}

void Miner::ChangeState(MinerState* pNewState)
{
	m_currentState->Exit(this);
	m_currentState = pNewState;
	m_currentState->Enter(this);
}
