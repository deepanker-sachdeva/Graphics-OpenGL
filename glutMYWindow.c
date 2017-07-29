#include<GL/glut.h>
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(300,300);
	glutCreateWindow("My Purple Window");
	glClearColor(0.5f,0.2f,0.7f,0.4f);
	//glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glutMainLoop();
	return 0;
}


// gcc glutMYWindow.c -lGL -lglut

