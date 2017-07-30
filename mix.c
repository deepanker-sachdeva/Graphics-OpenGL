/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void MyInit ( void ) {

glClearColor ( 0.0, 0.0, 0.0, 0.0 ); //black background
glColor3f(0.0f, 1.0f,0.0f); // green drawing colour
glPointSize(5.0); // 5 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)500, 0.0, (GLdouble)500 ); //Display area
}
void drawLine(int x1,int y1,int x2,int y2)
{
glBegin(GL_LINES);
glPointSize(5.0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
glEnd();
glFlush();

}
void drawCircle(int r,int xc,int yc,int x,int y)
{
glBegin(GL_POINTS); // render with points

x=0;
y=r;
int p=1-r,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8;
while(x<y)
{
x2=y+xc;
y2=x+yc;
x3=y+xc;
y3=-x+yc;
x4=x+xc;
y4=-y+yc;
x5=-x+xc;
y5=-y+yc;
x6=-y+xc;
y6=-x+yc;
x7=-y+xc;
y7=x+yc;
x8=-x+xc;
y8=y+yc;

glVertex2i(x+xc,y+yc);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);
glVertex2i(x5,y5);
glVertex2i(x6,y6);
glVertex2i(x7,y7);
glVertex2i(x8,y8);



if(p<0)
{
x=x+1;
p=p+2*x+1;
}
else
{
x=x+1;
y=y-1;
p=p+2*x+1-2*y;
}

}

glEnd();
glFlush();

}

void input1()
{

int r,xc,yc,x,y;
printf("Enter radius and centre of the circle!\n");
scanf("%d%d%d",&r,&xc,&yc);

int x1,y1,x2,y2;
printf("Enter the two vertices:\n");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);


glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("Green window");
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer





drawCircle(r,xc,yc,x,y);
//drawLine(x1,y1,x2,y2);
drawLine(xc-r,yc,xc+r,yc);
drawLine(xc,yc-r,xc,yc+r);

}

void input()
{

int r,xc,yc,x,y;
printf("Enter radius and centre of the circle!\n");
scanf("%d%d%d",&r,&xc,&yc);


glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("Green window");
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer





drawCircle(r,xc,yc,x,y);
drawCircle(r,round(xc+(1.5)*r),yc,x,y);
drawCircle(r,round(xc+(0.75)*r),round(yc+(1.299)*r),x,y);
//drawLine(x1,y1,x2,y2);
drawLine(xc,yc,round(xc+(1.5)*r),yc);
drawLine(round(xc+(1.5)*r),yc,round(xc+(0.75)*r),round(yc+(1.299)*r));
drawLine(round(xc+(0.75)*r),round(yc+(1.299)*r),xc,yc);
}


int main(int argc, char **argv)
{
glutInit(&argc,argv);
input();

glutMainLoop();
return 0;
}
