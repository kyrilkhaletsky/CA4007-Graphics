#include <GL/gl.h>
#include <GL/glext.h>
#include <C:/Users/zarre/Desktop/proj/glut.h>
#include <math.h>

float x1, z1;
float red = 0.5f;
float green = 0.5f;

void display(void)
{
    if (x1 > -0.5 && x1 < 0.5 && z1 > -0.5 && z1 < 0.5){
        if(x1 > -0.5 && x1 < 0){         
            green = x1 * -2.0f;
            red = x1 + 0.5f;
        } else if(x1 > 0 && x1 < 0.5){
            red = x1 + 0.5f;
            green = x1 * -2.0f;
        } else {
            red = 0.5f;
            green = 0.5f;
        }

        glClearColor(red, green,0,1.0);
    }
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
        glColor3f(0,1,0);
		glVertex2f(-0.5,-0.5);		
		glVertex2f(-0.5,0.5);

		glColor3f(1,0,0);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();

	glFlush();
	return;
}

void myMouse(int button, int state , int x, int y){
	if(state == GLUT_DOWN & button == GLUT_LEFT_BUTTON){
		x1 = (x-250.0)/250.0;
		z1 = -(y-250)/250.0;

		glutPostRedisplay();
		return;
	}
	
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutMainLoop();
}