/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j] = values[i][j];
}


void Labirinth::initializeVisited()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			visited[i][j] = false;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << labirinth[i][j] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y) {
    initializeVisited();
    searchSol(x, y);
    return foundSol;
}

void Labirinth::searchSol(int x, int y) {
    if (foundSol)
        return;

    if (visited[x][y])
        return;
    else
        visited[x][y] = true;

    if (x < 0 || x >= 10 || y < 0 || y >= 10)
        return;

    if (labirinth[x][y] == 0) return;

    else if (labirinth[x][y] == 2) {
        foundSol = true;
        return;
    }

    searchSol(x + 1, y);
    searchSol(x - 1, y);
    searchSol(x, y + 1);
    searchSol(x, y - 1);
}

/*
 * 1b) Pior dos casos (Eficiencia Temporal): n**2
 */