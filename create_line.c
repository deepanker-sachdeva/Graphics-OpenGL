#include<GL/glut.h>
void DisplayLine ( void ) {
glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_LINES);
    glVertex2f(10, 10);
    glVertex2f(50, 50);
    glVertex2f(100, 50);
    glVertex2f(50, 70);

glEnd();
glFlush();
}
void MyInit ( void ) {

glClearColor ( 0.6, 0.2, 0.5, 0.0 ); //pink background
glColor3f(0.0f, 1.0f,0.0f); // green drawing colour
glPointSize(10.0); // 10 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)100, 0.0, (GLdouble)100 ); //Display area
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("Green Line");
MyInit ( );
glutDisplayFunc ( DisplayLine );
glutMainLoop();
return 0;
}

//gcc create_line.c -o createLine -lGL -lglut -lGLU
/*
#include<GL/glut.h>
#include<stdio.h>
void MyInit()
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.0f,1.0f,0.0f);
glPointSize(10.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,(GLdouble)500,0.0,(GLdouble)500);
}
int main(int argc,char **argv)
{
int x1,y1,x2,y2;
printf("Enter the two vertices:\n");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(200,200);
glutInitWindowSize(1000,800);
glutCreateWindow("My Love");
MyInit();
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
glEnd();
glFlush();
glutMainLoop();
return 0;
}
*/
