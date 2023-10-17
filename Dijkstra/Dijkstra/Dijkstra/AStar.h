#pragma once
#include <iostream>
#include <stack>
#include <list>
#include "init.h"
#include "GameMap.h"

using namespace std;

class CGameMap;

class AStar
{
	CGameMap* m_gameMap;
	stack<point> m_path;		// ���� ��� ���� ����
	list<point> m_visitNode;
	bool m_bFound;

public:
	AStar(CGameMap* map) : m_gameMap(map), m_bFound(false) {}

	void extractMin(point& choicePos, int dx, int dy);
	bool findPath(int sx, int sy, int dx, int dy);
	void draw();
};