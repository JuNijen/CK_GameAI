#pragma once
#include <iostream>
#include <stack>
#include <list>
#include "init.h"
#include "GameMap.h"

using namespace std;

class CGameMap;

class Dijkstra
{
	CGameMap* m_gameMap;
	stack<point> m_path;		// 최종 경로 저장 변수
	list<point> m_visitNode;
	bool m_bFound;

public:
	Dijkstra(CGameMap* map) : m_gameMap(map), m_bFound(false) {}

	void extractMin(point& choicePos);
	bool findPath(int sx, int sy, int dx, int dy);
	void draw();
};