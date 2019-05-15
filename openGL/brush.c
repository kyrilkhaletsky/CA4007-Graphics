#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/graphics1/proj/glut.h>
#include <math.h>

int first = 0;
GLfloat x1, Y1, x2, Y2;
int newx, newy ;
float width = 2;

GLfloat red = 1.0f;
GLfloat green= 0.0f;
GLfloat blue = 0.0f;

#define W1 1
#define W2 2
#define W3 3

#define C1 4
#define C2 5
#define C3 6

void display(void) {
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	
	glLineWidth(width);
	glBegin(GL_LINES);
		glColor3f(red,green,blue);
		glVertex2f(x1,Y1);
		glColor3f(1,1,1);
		glVertex2f(x2,Y2);
	glEnd();

	glFlush();
	return;
}

void myMouse(int button, int state, int x , int y){
	
	if(button == GLUT_LEFT_BUTTON & state ==GLUT_DOWN){
		if (first == 0){
			x1 =(x- 250)/250.0;
			Y1 = -(y - 250)/250.0;
			newx = x;
			newy = y;
			first++;
		}
	}
	if(button == GLUT_LEFT_BUTTON & state ==GLUT_UP){
		if (first == 1){
			x2 = (x-250.0)/250.0;
			Y2 = -(y-250.0)/250.0;
			first--;
			glutPostRedisplay();
		}
	}
	return;
}

void processEvents(int option){
	switch(option){
		case W1:
			width = 2.0;
			break;
		case W2:
			width = 4.0;
			break;
		case W3:
			width = 6.0;
			break;
		case C1:
			red = 1.0f;
			blue = 0.0f;
			green = 0.0f;
			break;
		case C2:
			red = 0.0f;
			blue = 0.0f;
			green = 1.0f;
			break;
		case C3:
			red = 0.0f;
			blue = 1.0f;
			green = 1.0f;
			break;			
	}
	glutPostRedisplay();
	return;	
}

void glutMenus(){
	
	int menu = glutCreateMenu(processEvents);
	
	glutAddMenuEntry("Width 1", W1);
	glutAddMenuEntry("Width 2", W2);
	glutAddMenuEntry("Width 3", W3);

	glutAddMenuEntry("Colour 1", C1);
	glutAddMenuEntry("Colour 2", C2);
	glutAddMenuEntry("Colour 3", C3);

	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("simple");
	glutMenus();
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutMainLoop();
}