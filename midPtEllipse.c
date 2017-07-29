/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void MyInit ( void ) {

glClearColor ( 1.0, 1.0, 1.0, 1.0 ); //white background
glColor3f(0.1725f, 0.937f,0.1725f); // green drawing colour
glPointSize(1.0); // 5 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)500, 0.0, (GLdouble)500 ); //Display area
}
int main(int argc, char **argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

int rx,ry,xc,yc,x,y;
printf("Enter rx, ry and centre of the ellipse!\n");
scanf("%d%d%d%d",&rx,&ry,&xc,&yc);

glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("White window");
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_POINTS); // render with points

x=0;
y=ry;
int p1=(ry*ry)-(rx*rx*ry)+(1/4)*(rx*rx);
int x2,y2,x3,y3,x4,y4;
while((2*(ry*ry*x))<(2*(rx*rx*y)))
{


x2=x+xc;
y2=-y+yc;
x3=-x+xc;
y3=-y+yc;
x4=-x+xc;
y4=y+yc;

glVertex2i(x+xc,y+yc);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);



if(p1<0)
{
x=x+1;
p1=p1+2*(ry*ry*x)+(ry*ry);
}
else
{
x=x+1;
y=y-1;
p1=p1+2*(ry*ry*x)+(ry*ry)-2*(rx*rx*y);
}

}

int p2=(ry*ry*pow((x+0.5),2))+(rx*rx*pow((y-1),2))-(rx*rx*ry*ry);

while(y>=0)
{


x2=x+xc;
y2=-y+yc;
x3=-x+xc;
y3=-y+yc;
x4=-x+xc;
y4=y+yc;

glVertex2i(x+xc,y+yc);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);



if(p2>0)
{
y=y-1;
p2=p2-2*(rx*rx*y)+(rx*rx);
}
else
{
x=x+1;
y=y-1;
p2=p2+2*(ry*ry*x)+(rx*rx)-2*(rx*rx*y);
}

}


glEnd();
glFlush();

glutMainLoop();
return 0;
}
