/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
void Displaydot ( void ) {
}
void MyInit ( void ) {

glClearColor ( 1.0, 1.0, 1.0, 1.0 ); //white background
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
glutCreateWindow("Green window");
MyInit ( );



glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_POINTS); // render with points
glVertex2i(10,25); //display a point
glVertex2i(80,90);
glEnd();
glFlush();

glutMainLoop();
return 0;
}

//gcc create_point.c -lGLU -lglut -lGL

/*
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize();
glutInitWindowPosition();
glutCreateWindow("");

glClearColor();
glPointSize();
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D();

glClear(GL_COLOR_BUFFER_BIT);
glColor3f();
glBegin(GL_POINTS);
	glVertex2i();
glEnd();
glFlush();

glutMainLoop();
return 0;
}*/
