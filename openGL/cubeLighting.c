#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/graphics1/proj/glut.h>
#include <math.h>

int th = 0;
int ph = 0;

GLfloat  ambient[4] = {0.3, 0.0, 0.0, 1.0};
GLfloat  diffuse[4] = {0.6, 0.0, 0.0, 1.0};
GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};
GLfloat shininess = 32.0;
GLfloat position[4] = {1.0,1.0,1.0,1.0};

void display(void) {
	glClearColor(0.0,0.0,1.0,1.0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	gluLookAt(1.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
   
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glRotatef(ph, 1, 0, 0);
    glRotatef(th, 0, 1, 0);

    glColor3f(1,0,0);

	glutSolidCube(1);

    glTranslatef(0,0,0.5);
        glutSolidCone(0.5, 0.5, 32, 32);
    glTranslatef(0,0,-0.5);

    glRotatef(180.0,1,0,0);
        glTranslatef(0,0,0.5);
            glutSolidCone(0.5, 0.5, 32, 32);
        glTranslatef(0,0,-0.5);
    glRotatef(-180.0,1,0,0);

    glRotatef(90.0,1,0,0);
        glTranslatef(0,0,0.5);
            glutSolidCone(0.5, 0.5, 32, 32);
        glTranslatef(0,0,-0.5);
    glRotatef(-90.0,1,0,0);

    glRotatef(-90.0,1,0,0);
        glTranslatef(0,0,0.5);
            glutSolidCone(0.5, 0.5, 32, 32);
        glTranslatef(0,0,-0.5);
    glRotatef(90.0,1,0,0);

    glRotatef(-90.0,0,1,0);
        glTranslatef(0,0,0.5);
            glutSolidCone(0.5, 0.5, 32, 32);
        glTranslatef(0,0,-0.5);
    glRotatef(90.0,0,1,0);

    glRotatef(90.0,0,1,0);
        glTranslatef(0,0,0.5);
            glutSolidCone(0.5, 0.5, 32, 32);
        glTranslatef(0,0,-0.5);
    glRotatef(-90.0,0,1,0);


	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	glViewport(0,0,w,h);
	return;
}

void MyKey(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT){
        th += 5;
    } else if(key == GLUT_KEY_LEFT){
        th -= 5;
    } else if(key == GLUT_KEY_UP){
        ph -= 5;
    } else if(key == GLUT_KEY_DOWN){
        ph += 5;
    }

    th %= 360;
    ph %= 360;

    glutPostRedisplay();
}




int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
    glutSpecialFunc(MyKey);


	glutMainLoop();
}