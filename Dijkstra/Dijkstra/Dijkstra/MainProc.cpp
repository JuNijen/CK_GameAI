#pragma once
#include "Dijkstra.h"
#include "AStar.h"

int main()
{
	CGameMap gameMap(10, 10);
	AStar shortestPath(&gameMap);

	shortestPath.draw();
	shortestPath.findPath(0, 9, 9, 0);

	return 0;
}