#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/graphics1/proj/glut.h>
#include <math.h>

float x1;
float z1;

float x2;
float z2;

int click = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


    if(x1 >= -0.4 && x1 <= -0.2 && z1 >= -0.1 && z1 <= 0.1) {
        glColor3f(1,0,0);
    } else if (x2 >= -0.4 && x2 <= -0.2 && z2 >= -0.1 && z2 <= 0.1) {
        glColor3f(0.8,0,0);
    } else {
        glColor3f(1,1,1);
    }
    
    glTranslatef(-0.3,0,0);
        glBegin(GL_POLYGON);
            glVertex2f(-0.1,-0.1);
            glVertex2f(-0.1,0.1);
            glVertex2f(0.1,0.1);
            glVertex2f(0.1,-0.1);
        glEnd();
    glTranslatef(0.3,0,0);

    if(x1 >= -0.1 && x1 <= 0.1 && z1 >= -0.1 && z1 <= 0.1 && click == 1) {
        glColor3f(0,1,0); 
    } else if (x2 >= -0.1 && x2 <= 0.1 && z2 >= -0.1 && z2 <= 0.1) {
        glColor3f(0,0.8,0); 
    } else {
        glColor3f(1,1,1);
    }

    glBegin(GL_POLYGON);
		glVertex2f(-0.1,-0.1);
		glVertex2f(-0.1,0.1);
		glVertex2f(0.1,0.1);
		glVertex2f(0.1,-0.1);
	glEnd();

    if(x1 >= 0.2 && x1 <= 0.4 && z1 >= -0.1 && z1 <= 0.1) {
        glColor3f(0,0,1);
    } else if (x2 >= 0.2 && x2 <= 0.4 && z2 >= -0.1 && z2 <= 0.1) {
        glColor3f(0,0,0.8);
    } else {
        glColor3f(1,1,1);
    }

    glTranslatef(0.3,0,0);
        glBegin(GL_POLYGON);
            glVertex2f(-0.1,-0.1);
            glVertex2f(-0.1,0.1);
            glVertex2f(0.1,0.1);
            glVertex2f(0.1,-0.1);
        glEnd();
    glTranslatef(-0.3,0,0);

	glFlush();
	return;
}

void MyMouse(int button, int state, int x, int y){
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        x1 = ((x*2)-500.0)/500.0;
        z1 = -((y*2)-500.0)/500.0;
        click = 1;
    }
    glutPostRedisplay();
}

void MyMouse2(int x, int y){
    x2 = ((x*2)-500.0)/500.0;
    z2 = -((y*2)-500.0)/500.0;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitWindowSize(500,500);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
    glutMouseFunc(MyMouse);
    glutPassiveMotionFunc(MyMouse2);

	glutMainLoop();
}