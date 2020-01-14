#include "GL/freeglut.h"
#include <glm/glm.hpp>
#include "game.h"
#include <vector>
#include <iostream>


using namespace std;

int gridX, gridY, gridTotal;
short sDirection = RIGHT;
int posX = 25, posY = 25;


struct cell
{
	int posX;
	int posY;
	bool alive;
	bool aliveNext;

};

cell cellArray[50][50];

cell createCell(int x, int y)
{
	cell c = { x,y,false,false };
return c;
}

void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
	gridTotal = gridX * gridY;


	for (int x = 0; x < gridX; x++)
	{
		for (int y = 0; y < gridY; y++)
		{
			cell c = createCell(x, y);
			cellArray[x][y] = c;
		}
	}

}


void drawGrid()
{
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY; j++)
		{
			drawSquare(i, j);
		}
	}
}

void drawSquare(int x, int y)
{
	glLineWidth(1.0);
	glColor3f(1.0, 1.0, 1.0); //white

	glBegin(GL_LINE_LOOP);

	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}

void drawCells()
{
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY; j++)
			drawUnit(cellArray[i][j].posX, cellArray[i][j].posY, cellArray[i][j].alive);
	}


}
void drawUnit(int x, int y, bool alive)
{
	if (alive == true)
		glColor3f(1.0, 1.0, 1.0); //white
	else
		glColor3f(0.0, 0.0, 0.0); //white


	glBegin(GL_QUADS);

	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}

void generateRandStart(int noOfAlive)
{
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY; j++)
		{
			int a = (rand() % 100);

			if (a < noOfAlive)
			{
				cellArray[i][j].alive = true;
				cellArray[i][j].aliveNext = true;
			}
		}
	}
}

int liveNeighbours(int x, int y)
{
	int liveCount = 0;
	//left row x = 0, cant take left 3 actions
	if (x == 0)
	{
		//check right
		if (cellArray[x + 1][y].alive == true)
			liveCount++;
		if (y == 0)
		{
			//check up
			if (cellArray[x][y + 1].alive == true)
				liveCount++;
			//check tr
			if (cellArray[x + 1][y + 1].alive == true)
				liveCount++;
		}
		else if (y == 50)
		{
			//check down
			if (cellArray[x][y - 1].alive == true)
				liveCount++;
			//check br
			if (cellArray[x + 1][y - 1].alive == true)
				liveCount++;
		}
		else
		{
			//check down
			if (cellArray[x][y - 1].alive == true)
				liveCount++;
			//check br
			if (cellArray[x + 1][y - 1].alive == true)
				liveCount++;
			//check up
			if (cellArray[x][y + 1].alive == true)
				liveCount++;
			//check tr
			if (cellArray[x + 1][y + 1].alive == true)
				liveCount++;
		}
	}
	else if (x == 50) //cant go right
	{
		//check left
		if (cellArray[x - 1][y].alive == true)
			liveCount++;
		if (y == 0)
		{
			//check up
			if (cellArray[x][y + 1].alive == true)
				liveCount++;
			//check tl
			if (cellArray[x - 1][y + 1].alive == true)
				liveCount++;
		}
		else if (y == 50)
		{
			//check down
			if (cellArray[x][y - 1].alive == true)
				liveCount++;
			//check bl
			if (cellArray[x - 1][y - 1].alive == true)
				liveCount++;
		}
		else
		{
			//check down
			if (cellArray[x][y - 1].alive == true)
				liveCount++;
			//check br
			if (cellArray[x - 1][y - 1].alive == true)
				liveCount++;
			//check up
			if (cellArray[x][y + 1].alive == true)
				liveCount++;
			//check tr
			if (cellArray[x - 1][y + 1].alive == true)
				liveCount++;
		}
	}
	else if (y == 0)
	{
		//check up
		if (cellArray[x][y + 1].alive == true)
			liveCount++;
		//check left
		if (cellArray[x - 1][y].alive == true)
			liveCount++;
		//check right
		if (cellArray[x + 1][y].alive == true)
			liveCount++;
		//check tl
		if (cellArray[x - 1][y + 1].alive == true)
			liveCount++;
		//check tr
		if (cellArray[x + 1][y + 1].alive == true)
			liveCount++;

	}
	else if (y == 50)
	{
		//check down
		if (cellArray[x][y - 1].alive == true)
			liveCount++;
		//check left
		if (cellArray[x - 1][y].alive == true)
			liveCount++;
		//check right
		if (cellArray[x + 1][y].alive == true)
			liveCount++;
		//check bl
		if (cellArray[x - 1][y - 1].alive == true)
			liveCount++;
		//check br
		if (cellArray[x + 1][y - 1].alive == true)
			liveCount++;
	}
	else
	{
		//check down
		if (cellArray[x][y - 1].alive == true)
			liveCount++;
		//check left
		if (cellArray[x - 1][y].alive == true)
			liveCount++;
		//check right
		if (cellArray[x + 1][y].alive == true)
			liveCount++;
		//check bl
		if (cellArray[x - 1][y - 1].alive == true)
			liveCount++;
		//check br
		if (cellArray[x + 1][y - 1].alive == true)
			liveCount++;
		//check up
		if (cellArray[x][y + 1].alive == true)
			liveCount++;
		//check tl
		if (cellArray[x - 1][y + 1].alive == true)
			liveCount++;
		//check tr
		if (cellArray[x + 1][y + 1].alive == true)
			liveCount++;
	}
	return liveCount;
}

void checkState(int x, int y)
{
	cellArray[x][y].alive = cellArray[x][y].aliveNext;
	cellArray[x][y].aliveNext = cellArray[x][y].alive;

	int liveCount = liveNeighbours(x, y);

	if (cellArray[x][y].alive == true)
	{
		//Any live cell with fewer than two live neighbours dies
		if (liveCount < 2)
		{
			cellArray[x][y].aliveNext = false;
		}
		//Any live cell with two or three live neighbours lives on to the next generation
		else if (liveCount == 2 | liveCount == 3)
		{
			cellArray[x][y].aliveNext = true;
		}
		//Any live cell with more than three live neighbours dies, as if by overpopulation
		else if (liveCount > 3)
		{
			cellArray[x][y].aliveNext = false;
		}
	}
	else
	{
		//Any dead cell with exactly three live neighbours becomes a live cell
		if (liveCount == 3)
		{
			cellArray[x][y].aliveNext = true;
		}
	}
}

