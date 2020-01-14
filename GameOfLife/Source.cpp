#include "GL/glew.h"
#include "GL/freeglut.h"
#include <glm/glm.hpp> //includes GML
#include "game.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define COLUMNS 50
#define ROWS 50
#define fps 10


void timer_callback(int);
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(unsigned char, int, int);

bool paused;

void init(int noOfStart)
{
	glClearColor(0.0,0.0,0.0,1.0); //set to black
	initGrid(COLUMNS, ROWS);
	generateRandStart(noOfStart);
}

int main(int argc, char** argv)
{
	paused = false;
	int noOfStart;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);

	
	cout << "These are the rules of the Game of Life:" << endl;
	cout << "1. Any live cell with fewer than two live neighbours dies, as if caused by under-population." << endl;
	cout << "2. Any live cell with two or three live neighbours lives on to the next generation." << endl;
	cout << "3. Any live cell with more than three live neighbours dies, as if by over-population." << endl;
	cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
	cout << "Please input what percentage of live cells you would like to start with (between 1 - 100)" << endl;
	cin >> noOfStart;
	cout << "Press space  to pause and start the animation" << endl;

	glutCreateWindow("Game of Life");

	
	
	while (!paused)
	{
		glutDisplayFunc(display_callback);
		glutReshapeFunc(reshape_callback);
		glutTimerFunc(0, timer_callback, 0);
		glutKeyboardFunc(keyboard_callback);
		init(noOfStart);
		glutMainLoop();
	}
	return 0;
}

//int index = 0;

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			checkState(i, j);
		}
	}
	drawCells();
	drawGrid();
	glutSwapBuffers();
}

void reshape_callback(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //set up viewport
	glMatrixMode(GL_PROJECTION); //change to projection matrix
	glLoadIdentity();
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW); // switch back to model view
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / fps, timer_callback, 0);
}

void keyboard_callback(unsigned char key, int, int)
{
	switch (key)
	{
	case 32:
		//pause and start
		if (paused == false)
		{
			paused = true;
		}
		else
		{
			paused = false;
		}
		break;

	case 27:
		// exit
		exit(0);
		break;

	case 'c':
		//clear/ reset

		break;
	}


}