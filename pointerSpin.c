#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/graphics1/proj/glut.h>
#include <math.h>

float x1 = 0;
float z1 = 0;

float spin = 0;

void display(void) {
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(spin, 0, 0, 1);
		glBegin(GL_POLYGON);
			glVertex2f(-0.5,-0.5);
			glVertex2f(-0.5,0.5);
			glVertex2f(0.5,0.5);
			glVertex2f(0.5,-0.5);
		glEnd();

	if(x1 > 0){
		spin -= 0.05;
	} else {
		spin += 0.05;
	}
		

	glFlush();
	return;
}

void MyIdle() {

	if(x1 > 0){
		spin += 0.05;
	} else {
		spin -= 0.05;
	}
	
	glutPostRedisplay();

	return;
}

void MyMouse(int x, int y){
	x1 = ((x*2)-500.0)/500.0;
	z1 = ((y*2)-500.0)/500.0;

	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutPassiveMotionFunc(MyMouse);
	glutIdleFunc(MyIdle);

	glutMainLoop();
}