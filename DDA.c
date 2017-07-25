/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int xa,xb;
int ya,yb;
void Displaydot ( void ) {
glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_POINTS); // render with points
float steps,Xinc,Yinc;
float dx=xb-xa;
float dy=yb-ya;
if(fabs(dx)>fabs(dy))
	steps=fabs(dx);
else
	steps=fabs(dy);
Xinc=dx/steps;
Yinc=dy/steps;
int i;
float x=xa,y=ya;
glVertex2i(xa,ya); //display a point
printf("%f\n",steps);
for(i=0;i<steps;i++)
{
	
	x=x+Xinc;
	y=y+Yinc;
	printf("%f %f\n",x,y);
	glVertex2i(round(x),round(y)); //display a point

}
glEnd();
glFlush();
}
void MyInit ( void ) {
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(10,10);
glutInitWindowSize(500,500);
glutCreateWindow("Green window");

glClearColor ( 0.0, 0.0, 0.0, 0.0 ); //white background
glColor3f(0.0f, 1.0f,0.0f); // green drawing colour
glPointSize(5.0); // 5 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)500, 0.0, (GLdouble)500 ); //Display area
}

int main(int argc, char **argv)
{
printf("Enter x1,y1,x2,y2\n");
scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
glutInit(&argc,argv);

MyInit ( );

glutDisplayFunc ( Displaydot );
glutMainLoop();
return 0;
}
