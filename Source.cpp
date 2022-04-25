#include<GL/glut.h>
#include<iostream>
using namespace std;

void draw_pixel(int x, int y)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void reflection(int x, int y, int xc, int yc)
{
	draw_pixel(-x + xc, y + yc);
	draw_pixel(x + xc, y + yc);
	draw_pixel(y + xc, x + yc);
	draw_pixel(y + xc, -x + yc);
	draw_pixel(x + xc, -y + yc);
	draw_pixel(-x + xc, -y + yc);
	draw_pixel(-y + xc, -x + yc);
	draw_pixel(-y + xc, x + yc);
}
void circle(int r, int xc, int yc)
{
	int p = 5 / 4 - r;
	int x = 0;
	int y = r;
	reflection(x, y, xc, yc);
	while (x <= y)
	{

		if (p < 0)
		{
			p = p + 2 * x + 3;
			x++;
		}
		else {
			p = p + 2 * (x - y) + 5;
			y--;
			x++;
		}
		reflection(x, y, xc, yc);
	}
}
void lines(int X1, int Y1, int X2, int Y2)
{
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = X2 - X1;
	dy = Y2 - Y1;
	if (abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else
		step = abs(dy);
	Xin = dx / step;
	Yin = dy / step;
	x = X1;
	y = Y1;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	for (k = 1; k <= step; k++)
	{
		x = x + Xin;
		y = y + Yin;

		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
}

void  car()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	lines(100, 100, 100, 200);
	lines(100, 200, 600, 200);
	lines(600, 200, 600, 100);
	lines(200, 200, 250, 300);
	lines(500, 200, 450, 300);
	lines(250, 300, 450, 300);
	lines(100, 100, 200, 100);
	lines(600, 100, 500, 100);
	lines(300, 100, 400, 100);
	circle(50, 250, 100);
	circle(50, 450, 100);
	circle(10, 250, 100);
	circle(10, 450, 100);
	glFlush();
}


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0, 0, 1000, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 500);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Car");
	init();
	glutDisplayFunc(car);
	glutMainLoop();
	return 0;
}