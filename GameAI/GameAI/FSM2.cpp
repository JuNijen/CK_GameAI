#pragma once
#include "FSM2.h"
using namespace std;


void GameEntity::Update()
{
	m_state->Excute(this);
	Sleep(1000);
}

void GameEntity::ChangeState(State* pNewState)
{
	m_state->Exit(this);
	m_state = pNewState;
	m_state->Enter(this);
}

State* RedState::GetInstance()
{
	// 贸澜 角青老 版快
	if (!m_instance)
	{
		m_instance = new RedState();
	}

	return m_instance;
}
void RedState::Enter(GameEntity* ge)
{
	// 贸澜 角青老 版快
	if (!m_instance) 
	{
		m_instance = new RedState();
	}

	cout << "Red Enter\n";
}
void RedState::Excute(GameEntity* ge)
{
	cout << "Red Excute\n";

	// 矫埃 眉农
	if (ge->GetTimer() > 3)
	{
		ge->SetTimer(0);
		ge->ChangeState(GreenState::GetInstance());
	}
	else
	{
		int time = ge->GetTimer();
		ge->SetTimer(time++);
	}
}
void RedState::Exit(GameEntity* ge)
{
	cout << "Red Exit\n";
}


State* YellowState::GetInstance()
{
	// 贸澜 角青老 版快
	if (!m_instance)
	{
		m_instance = new YellowState();
	}

	return m_instance;
}
void YellowState::Enter(GameEntity* ge)
{
	cout << "Yellow Enter\n";
}
void YellowState::Excute(GameEntity* ge)
{
	cout << "Yellow Excute\n";

	// 矫埃 眉农
	if (ge->GetTimer() > 3)
	{
		ge->SetTimer(0);
		ge->ChangeState(RedState::GetInstance());
	}
	else
	{
		int time = ge->GetTimer();
		ge->SetTimer(time++);
	}
}
void YellowState::Exit(GameEntity* ge)
{
	cout << "Yellow Exit\n";
}


State* GreenState::GetInstance()
{
	// 贸澜 角青老 版快
	if (!m_instance)
	{
		m_instance = new GreenState();
	}

	return m_instance;
}
void GreenState::Enter(GameEntity* ge)
{
	cout << "Green Enter\n";
}

void GreenState::Excute(GameEntity* ge)
{
	cout << "Green Excute\n";

	// 矫埃 眉农
	if (ge->GetTimer() > 3)
	{
		ge->SetTimer(0);
		ge->ChangeState(YellowState::GetInstance());
	}
	else
	{
		int time = ge->GetTimer();
		ge->SetTimer(time++);
	}
}
void GreenState::Exit(GameEntity* ge)
{
	cout << "Green Exit\n";
}