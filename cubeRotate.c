#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/graphics1/proj/glut.h>
#include <math.h>

int th = 0;
int ph = 0;

float x1 = 0;
float z1 = 0;
float zz1 = 0.0;

float cubes[128];
int len = 0;

void SetEye(void){
    glRotatef(ph, 1, 0, 0);
    glRotatef(th, 0, 1, 0);
}


void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

    SetEye();

    for(int i = 0; i < len; i++){
        float x = cubes[i*2];
        float z = cubes[i*2+1];
        
        glTranslatef(x,z,zz1);
	        glutWireCube(0.5);
        glTranslatef(-x,-z,-zz1);
        
    }
    
	
	glFlush();
    glutSwapBuffers();
	return;
}

void MyMenu(int value){

}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	glViewport(0,0,w,h);
	return;
}

void CreateMyMenu(void){
    int menu = glutCreateMenu(MyMenu);
    glutAddMenuEntry("item1", 1);
    glutAddMenuEntry("item2", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void WindowKey(int key, int x, int y){
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

void MouseKey(int key, int state, int x, int y){
    if(key == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        x1 = ((x*2)-500.0)/500.0;
        z1 = -((y*2)-500.0)/500.0;

        cubes[len*2] = x1;
        cubes[len*2+1] = z1;

        len +=1;
        
    }

    glutPostRedisplay();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
    CreateMyMenu();
    glutSpecialFunc(WindowKey);
    glutMouseFunc(MouseKey);

	glutMainLoop();
}