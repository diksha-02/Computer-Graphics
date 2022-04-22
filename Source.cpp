#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

void rectangle(int x1, int y1, int x2, int y2)
{
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y1);
	glEnd();
	glFlush();
}
void triangle(int x1, int x2, int x3, int y1, int y2, int y3)
{
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glFlush();
}
void circle(float x1, float y1, double radius) {
	float x2, y2;
	float angle;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle) * radius;
		y2 = y1 + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.58, 0.29, 0.0);
	rectangle(10, 10, 20, 70);
	rectangle(80, 10, 90, 100);
	glColor3f(0.0, 0.5, 0.0);
	rectangle(0, 0, 500, 10);
	triangle(0, 30, 15, 70, 70, 120);
	triangle(0, 30, 15, 100, 100, 150);
	circle(85, 130, 30);
	glColor3f(1.0, 0.0, 0.0);
	rectangle(120, 30, 200, 60);
	rectangle(135, 60, 185, 90);
	glColor3f(0.0, 0.0, 0.0);
	circle(135, 20, 10);
	circle(185, 20, 10);
	glColor3f(1.0, 1.0, 1.0);
	rectangle(137, 60, 147, 80);
	rectangle(173, 60, 183, 80);
	glColor3f(1.0, 1.0, 0.0);
	rectangle(250, 10,400,150);
	glColor3f(1.0,0.0, 0.0);
	triangle(230, 420, 325, 150, 150, 200);
	rectangle(280, 100, 300, 120);
	rectangle(360,100, 380, 120);
	glColor3f(0.0,0.0,1.0);
	rectangle(310, 10, 340, 70);
	glColor3f(1.0, 1.0, 0.0);
	circle(200, 400, 30);
	

}

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 480);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);								
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		
	glutInitWindowPosition(0, 0);						
	glutInitWindowSize(500,480);						
	glutCreateWindow("Scenery");
	Init();										
	glutDisplayFunc(display);							
	glutMainLoop();										
	return 0;
}