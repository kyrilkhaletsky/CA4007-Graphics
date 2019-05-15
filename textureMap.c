#include <GL/gl.h>
#include <GL/glext.h>
#include <C:/Users/zarre/Desktop/proj/glut.h>
#include <math.h>
#include <stdio.h>

GLubyte texture[64][64][3];

#define Sin(x) sin(M_PI/180*(x))
#define Cos(x) cos(M_PI/180*(x))

int th = 0;
int ph = 0;

float dim = 1.0;

void SetEye(void){
	double Ex = -2 * dim * Sin(th) * Cos(ph);
	double Ey =  2 * dim * 			 Sin(ph);
	double Ez =  2 * dim * Cos(th) * Cos(ph);

	gluLookAt(Ex, Ey, Ez,  0,0,0,  0, Cos(ph), 0);
}

void display(void) {
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	SetEye();
	

	glEnable(GL_TEXTURE_2D);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	/*
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glTexCoord2f(1.0,1.0);
		glVertex3f(0.5,0.5,0.0);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-0.5,0.5,0.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-0.5,-0.5,0.0);
		glTexCoord2f(1.0,0.0);
		glVertex3f(0.5,-0.5,0.0);
	glEnd();
	*/

	GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricTexture(MyCylinder,1);
	
	glRotatef(-90.0,1.0,0.0,0.0);
	gluCylinder(MyCylinder,0.2,0.2,1.0,12,12);

		
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60, 1, dim/4, dim * 4);

	//glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	//glFrustum(-1.0,1.0,-1.0,1.0,1.0,3.0);
	glViewport(0,0,w,h);

	return;
}

void MyKey(int button, int x, int y){
	if(button == GLUT_KEY_RIGHT){
		th += 5;
	} else if (button == GLUT_KEY_LEFT){
		th -= 5;
	} else if (button == GLUT_KEY_UP){
		ph -= 5;
	} else if (button == GLUT_KEY_DOWN){
		ph += 5;
	}

	th %= 360;
	ph %= 360;

	glutPostRedisplay();
}


int main(int argc, char **argv) {

	int i,j,r,c;
	for(i=0; i<64; i++) 
	{ 
		for(j=0; j<64; j++) 
		{ 
			c = ((((i & 0x08)==0)*((j & 0x08))==0))*255; 
			texture[i][j][0] = (GLubyte)c; 
			texture[i][j][1] = (GLubyte)c;
			texture[i][j][2] = (GLubyte)c;  
		}
	}
	
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MyKey);

	glutMainLoop();
}