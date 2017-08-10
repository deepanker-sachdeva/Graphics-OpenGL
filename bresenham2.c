/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
void MyInit ( void ) {
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,25);
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
int x0,y0,x1,y1;
printf("x0,y0,x1,y1");
scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
glutInit(&argc,argv);
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_POINTS); // render with points
//glVertex2i(x0,y0); //display a point
int m;
int dx=x1-x0,dy=y1-y0;
if(dy==0)
	{
		int x=x0;
		while(x<x1)
		{	
			glVertex2i(x,y1);
			x++;
		}
	}
else if(dx==0)
	{
		int y=y0;
		while(y<y1)
		{	
			glVertex2i(x1,y);
			y++;
		}
	}
else
{
	m=dy/dx;

/*
if(m>1)
{
	int temp=dx;
	dx=dy;
	dy=temp;
	temp=x0;
	x0=y0;
	y0=temp;
	temp=x1;
	x1=y1;
	y1=temp;
}
*/
int p0=(2*dy)-dx;
int p=p0,x=x0,y=y0;
/*
10 100
100 10
m=-90/90=-1
p=+90
11,100
12,100
-180
13,101
*/
/*
while(x<x1)
{
	
	if(p<0)
	{
		p=p-2*dy;
		x=x+1;
		y=y;
	}
	else
	{
		p=p-(2*dy)-(2*dx);
		x=x+1;		
		y=y+1;
		

	}

if(m>1)
	glVertex2i(y,x);
else
	glVertex2i(x,y); //display a point
//printf("%d %d \t %d\n",x,y,p);
	
	
}
*/
while(x<x1)
{
	if(p<0)
	{
		p=p+2*dy+2*dx;
		x=x+1;
		y=y-1;
	}
	else
	{
		p=p+(2*dy);
		x=x+1;		
		y=y;
	}
if(m>1)
	glVertex2i(y,x);
else
	glVertex2i(x,y); //display a point
//printf("%d %d \t %d\n",x,y,p);
}

}
glEnd();
glFlush();

glutMainLoop();
return 0;
}
