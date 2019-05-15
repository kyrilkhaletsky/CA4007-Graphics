#include <GL/gl.h>
#include <GL/glext.h>
#include <math.h>
#include  <stdio.h>
#include <C:/Users/zarre/Desktop/proj/glut.h>

float x1 = 0.0;
float z1 = 0.0;

float x2 = 0.0;
float z2 = 0.0;

float x3 = 0.0;
float z3 = 0.0;

float x4 = 0.0;
float z4 = 0.0;

int click = 1;

int polyCount = 3;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

    if(click == 5){
        glBegin(GL_POLYGON);
            glVertex2f(x1,z1);
            glVertex2f(x2,z2);
            glVertex2f(x3,z3);
            glVertex2f(x4,z4);
	    glEnd();
    }
	

	glFlush();
	return;
}

void MyMouseFucion(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(click == 1) {
            x1 = ((x*2)-500.0)/500.0;
            z1 = -((y*2)-500.0)/500.0;

            click++;
            return;
        }

        if(click == 2) {
            x2 = ((x*2)-500.0)/500.0;
            z2 = -((y*2)-500.0)/500.0;

            click++;
            return;
        }

        if(click == 3) {
            x3 = ((x*2)-500.0)/500.0;
            z3 = -((y*2)-500.0)/500.0;

            click++;
            return;
        }

        if(click == 4) {
            x4 = ((x*2)-500.0)/500.0;
            z4 = -((y*2)-500.0)/500.0;

            click++;
            
            glutPostRedisplay();
            return;
        }
        
    }

    
}

void MyKeyFunction(int button, int x, int y){
    if (button == GLUT_KEY_RIGHT){
        x1 = 0.0;
        z1 = 0.0;

        x2 = 0.0;
        z2 = 0.0;

        x3 = 0.0;
        z3 = 0.0;

        x4 = 0.0;
        z4 = 0.0;

        glutPostRedisplay();

        printf("Polygon has been Deleted \n");

        click = 1;
    }
    return;
}

void Menu(int value){
    if(value == 1){
        polyCount = 3;
    } else if(value == 2){
        polyCount = 4;
    } else if(value == 3){
        polyCount = 5;
    }
}

void CreateMyMenu(void){
    int menuItem = glutCreateMenu(Menu);
    glutAddMenuEntry("3 Polygons", 1);
    glutAddMenuEntry("4 Polygons", 2);
    glutAddMenuEntry("5 Polygons", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
    glutInitWindowSize(500,500);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
    CreateMyMenu();
    glutMouseFunc(MyMouseFucion);
    glutSpecialFunc(MyKeyFunction);

	glutMainLoop();

}