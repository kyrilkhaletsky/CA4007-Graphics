#include <GL/gl.h>
#include <GL/glext.h>
#include <C:/Users/zarre/Desktop/proj/glut.h>
#include <math.h>
#include <stdio.h>

#define Cos(x) cos(M_PI/180*(x))
#define Sin(x) sin(M_PI/180*(x))

int th = 0;
int ph = 0;

float x = 0;
float y = 0;

int toggle = 0;

float dim = 1.0;

GLfloat ambient[4] = {0.3, 0.0, 0.0, 1.0};
GLfloat diffuse[4] = {0.6, 0.0, 0.0, 1.0};
GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};
GLfloat shininess = 32.0;

GLfloat position[4] = {1.0,1.0,0.0,0.0};

float theta = M_PI/4;


void SetEye(){
	if (toggle == 0) {
		float Ex = -2 * dim * Sin(th) * Cos(ph);
		float Ey =  2 * dim * 			Sin(ph);
		float Ez =  2 * dim * Cos(th) * Cos(ph);
		
		gluLookAt(Ex,Ey,Ez,  0,0,0,  0,Cos(ph),0);
	} else {
		gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
		glRotatef(ph, 1,0,0);
		glRotatef(th, 0,1,0);
	}	
}

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
		

	SetEye();	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	glutSolidCube(0.5);

	glutSwapBuffers();
	
	glFlush();
	return;
}

void MyReshape(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (toggle == 0) {
		gluPerspective(60, 1, dim/4, dim*4);
	} else {
		glOrtho(-dim,dim,-dim,dim,-dim,dim);
		glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	}	

	glViewport(0,0,w,h);
	return;
}

void MyMouse(int button, int state, int x1, int z1){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		x = ((x1*2)-500.0)/500.0;
		y = ((z1*2)-500.0)/500.0;
	}
	glutPostRedisplay();
}

void MyKey(int button, int x, int y){
	if(button == GLUT_KEY_RIGHT){
		th += 5;
	} else if(button == GLUT_KEY_LEFT){
		th -= 5;
	} else if(button == GLUT_KEY_UP){
		ph -= 5;
	} else if(button == GLUT_KEY_DOWN){
		ph += 5;
	}

	th %= 360;
	ph %= 360;

	glutPostRedisplay();
}

void MyMenuItem(){

}

void MyMenu(){
	int menu = glutCreateMenu(MyMenuItem);
	glutAddMenuEntry("item1", 1);
	glutAddMenuEntry("item2", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);

	glutSpecialFunc(MyKey);
	glutMouseFunc(MyMouse);
	MyMenu();


	glutMainLoop();
}