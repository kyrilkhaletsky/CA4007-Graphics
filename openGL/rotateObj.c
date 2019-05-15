#include <GL/gl.h>
#include <GL/glext.h>
#include <math.h>
#include <C:/Users/zarre/Desktop/proj/glut.h>

double dim=10.0;

int toggleMode = 0; /* projection mode */
int th = 340;   /* azimuth of view angle */
int ph = 30;    /* elevation of view angle */
int fov = 55;   /* field of view for perspective */
int asp = 1;    /* aspect ratio */

void project() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-dim*asp,+dim*asp, -dim,+dim, -dim,+dim);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void setEye(){
	
    glRotatef(ph,1,0,0);
    glRotatef(th,0,1,0);
}

void display(void) {
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	setEye();

	glColor3f(1.0,0.0,0.0);
	
	//cube
	glutSolidCube(3.0);
	
	
	//cube with different location
	glTranslatef(2, 3, 0);
	glutSolidCube(2.0);
	glTranslatef(-2, -3, -0);
	
	//GLUquadricObj *quadratic;
	//quadratic = gluNewQuadric();
	//gluCylinder(quadratic, 0.1f, 0.1f, size, 32, 32);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	glViewport(0,0,w,h);
	
	project();
	
	return;
}

void WindowKey(int key,int x,int y) {
  if (key == GLUT_KEY_RIGHT) th += 5;

  else if (key == GLUT_KEY_LEFT) th -= 5;

  else if (key == GLUT_KEY_UP) ph += 5;

  else if (key == GLUT_KEY_DOWN) ph -= 5;

  /*  Keep angles to +/-360 degrees */
  th %= 360;
  ph %= 360;

  project();
  glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(WindowKey);


	glutMainLoop();
}