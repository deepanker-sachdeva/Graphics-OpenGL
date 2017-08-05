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

void drawPolygon(int x[],int y[],int n)
{

for(int i=1;i<=n;i++)
{
drawLine(x[i-1],y[i-1],x[i%n],y[i%n]);
}

}
/*void transform(int x[],int y[],int n,float m,int c)
{
float theta=atan(m);
printf("%f",theta);
printf("%f",tan(theta));

float a=pow(cos(theta),2)-pow(sin(theta),2);
printf("\t%f\t",a);

float b=sin(2*theta);
printf("\t%f\t",b);
int tempx,tempy;
int xo[n],yo[n];
for(int i=0;i<n;i++)
{
xo[i]=round(x[i]*a+b*y[i]-c*b);
yo[i]=round(x[i]*b-y[i]*a+c*a+c);
//x[i]=tempx;
//y[i]=tempy;
}
drawPolygon(xo,yo,n);
}
*/
void input()
{

int c,n;
float m;
printf("Enter the no. of points the polygon has?\n");
scanf("%d",&n);
int x[n],y[n];
printf("Enter all the point coordinates!\n");
for(int i=0;i<n;i++)
{
printf("(x[%d],y[%d])\t:\t",i,i);
scanf("%d%d",&x[i],&y[i]);
}
printf("Enter the line along which you want to reflect it?\n");
printf("Enter slope:\t");
scanf("%f",&m);
printf("Enter y-intercept:\t");
scanf("%d",&c);


glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("Green window");
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer



drawPolygon(x,y,n);
int x0=0,y0=c,x1=500,y1=m*(500)+c;
drawLine(x0,y0,x1,y1);
//printf("hi");

//transform(x,y,n,m,c);
//-------------------transform-----------------
float theta=atan(m);
printf("%f",theta);
printf("%f",tan(theta));

float a=pow(cos(theta),2)-pow(sin(theta),2);
printf("\t%f\t",a);

float b=sin(2*theta);
printf("\t%f\t",b);
int tempx,tempy;
int xo[n],yo[n];
for(int i=0;i<n;i++)
{
xo[i]=round(x[i]*a+b*y[i]-c*b);
yo[i]=round(x[i]*b-y[i]*a+c*a+c);
//x[i]=tempx;
//y[i]=tempy;
}
drawPolygon(xo,yo,n);
//-------------------transform--------------------

}


int main(int argc, char **argv)
{
glutInit(&argc,argv);
input();

glutMainLoop();
return 0;
}
