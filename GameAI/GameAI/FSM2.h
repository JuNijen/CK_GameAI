#pragma once
#include <iostream>
#include <string>
#include <synchapi.h>
using namespace std;


//StateDesignPattern
class BaseGameEntity 
{
public:
	virtual void Update();
};

class GameEntity : public BaseGameEntity
{
private:
	State* m_state;
	int m_timer;

public:
	void Update();
	void ChangeState(State* pNewState);
	void SetTimer(int time) { m_timer = time; };
	int GetTimer() { return m_timer; };
};


class State
{
public:
private:
	static State* m_instance;

public:
	virtual State* GetInstance();
	virtual void Enter(BaseGameEntity* ge);
	virtual void Excute(BaseGameEntity* ge);
	virtual void Exit(BaseGameEntity* ge);
};


class RedState : public State
{
private:
	static State* m_instance;

public:
	static State* GetInstance();
	void Enter(GameEntity* ge);
	void Excute(GameEntity* ge);
	void Exit(GameEntity* ge);
};

class YellowState : public State
{
private:
	static State* m_instance;

public:
	static State* GetInstance();
	void Enter(GameEntity* ge);
	void Excute(GameEntity* ge);
	void Exit(GameEntity* ge);
};

class GreenState : public State
{
private:
	static State* m_instance;

public:
	static State* GetInstance();
	void Enter(GameEntity* ge);
	void Excute(GameEntity* ge);
	void Exit(GameEntity* ge);
};