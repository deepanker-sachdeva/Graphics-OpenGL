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
printf("in drawLine\n");
glBegin(GL_LINES);
glPointSize(5.0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
glEnd();
glFlush();

}
void drawClippingRectangle(int xwmin,int ywmin,int xwmax,int ywmax)
{
drawLine(xwmin,ywmin,xwmax,ywmin);
drawLine(xwmin,ywmin,xwmin,ywmax);
drawLine(xwmax,ywmax,xwmin,ywmax);
drawLine(xwmax,ywmax,xwmax,ywmin);
}
float max(float a,float b)
{
printf("\nin MAX a=%f b=%f",a,b);
	if(a>b)
		return a;
	return b;
}
float min(float a,float b)
{
	if(a<b)
		return a;
	return b;
}

void liangBarsky(int x0,int y0,int x1,int y1,int xwmin,int ywmin,int xwmax,int ywmax)
{
float t1=0.0,t2=1.0;
int p[4],q[4],t[4];
int deltaX=x1-x0,deltaY=y1-y0;
p[0]=-deltaX;
p[1]=deltaX;
p[2]=-deltaY;
p[3]=deltaY;
q[0]=x0-xwmin;
q[1]=xwmax-x0;
q[2]=y0-ywmin;
q[3]=ywmax-y0;
int mode=1;
for(int i=0;i<4;i++)
{
	if(p[i]==0)
	{
		if(q[i]<0)
		{	mode=0; break;}
	}	
	t[i]=q[i]/p[i];
	if(p[i]<0)
	{
		t1=max(0,t[i]);
	}
	else
	{
		t2=min(1,t[i]);
	}
	if(t1>t2)
	{
		mode=0;
		break;
	}
	if(t1>0)
	{
		x0=round(x0+t1*deltaX);
		y0=round(y0+t1*deltaY);
	}
	if(t2<1)
	{
		x1=round(x0+t2*deltaX);
		y1=round(y0+t2*deltaY);
	}
}
drawLine(x0,y0,x1,y1);
}
void input()
{
/*
int n;
printf("Enter the no. of points the polygon has?\n");
scanf("%d",&n);
int x[n],y[n];
printf("Enter all the point coordinates!\n");
for(int i=0;i<n;i++)
{
	printf("(x[%d],y[%d])\t:\t",i,i);
	scanf("%d%d",&x[i],&y[i]);
}
*/
int x0,y0,x1,y1;
printf("Enter the begin & end coordinates of the line to clip i.e. \n");
printf("x0,y0:\t");
scanf("%d%d",&x0,&y0);
printf("x1,y1:\t");
scanf("%d%d",&x1,&y1);

int xwmin,ywmin,xwmax,ywmax;
printf("Enter the begin & end coordinates along which to clip i.e. \n");
printf("xw(min.):\t");
scanf("%d",&xwmin);
printf("yw(min.):\t");
scanf("%d",&ywmin);
printf("xw(max.):\t");
scanf("%d",&xwmax);
printf("yw(min.):\t");
scanf("%d",&ywmax);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("Green window");
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer




drawClippingRectangle(xwmin,ywmin,xwmax,ywmax);
//drawLine(x0,y0,x1,y1);
//liangBarsky(x0,y0,x1,y1,xwmin,ywmin,xwmax,ywmax);
//-----------------------------liangBarsky started---------------------------------


float t1=0.0,t2=1.0;
float p[4],q[4],t[4];
float deltaX=x1*(1.0)-x0,deltaY=y1*(1.0)-y0;
p[0]=-deltaX;
p[1]=deltaX;
p[2]=-deltaY;
p[3]=deltaY;
q[0]=x0-xwmin;
q[1]=xwmax-x0;
q[2]=y0-ywmin;
q[3]=ywmax-y0;
int mode=1;
printf("hi1");
float Tmin=0,Tmax=1;
for(int i=0;i<4;i++)
{
	if(p[i]==0)
	{
		if(q[i]<0)
		{	mode=0; break;}
		else
		{	mode=2;break;}
	}	
	t[i]=q[i]/p[i];
	//printf("p=%d q=%d",p[i],q[i]);
	if(p[i]<0)
	{
		//printf("p[%d]<0\n",i);
		t1=max(Tmin,t[i]);
		Tmin=t1;
		//printf("t1=%f\n",t1);
	}
	else
	{
		//printf("p[%d]>0\n",i);

		t2=min(Tmax,t[i]);
		Tmax=t2;
		//printf("t2=%f\n",t2);
	}
	if(t1>t2)
	{
		//printf("i= %d  t1>t2\n",i);

		mode=0;
		break;
	}
	
	//printf("hi       %d",i);
}
if(mode==0)
{
printf("Line outside the boundary!");
}
else if(mode==2)
{
drawLine(x0,y0,x1,y1);
}
else
{
int x0new,y0new,x1new,y1new;
if(t1>0)
{
	x0new=round(x0+t1*deltaX);
	y0new=round(y0+t1*deltaY);
}
else
{
x0new=x0;
y0new=y0;
}
if(t2<1)
{
	x1new=round(x0+t2*deltaX);
	y1new=round(y0+t2*deltaY);
}
else
{
x1new=x1;
y1new=y1;
}
//printf("hi in the");
//printf("%f %f\n",t1,t2);
//printf("%d %d-%d %d",x0new,y0new,x1new,y1new);
drawLine(x0new,y0new,x1new,y1new);
}
//----------------------------liangBarsky end--------------------------


}


int main(int argc, char **argv)
{
glutInit(&argc,argv);
input();

glutMainLoop();
return 0;
}

/*
30 20
280 160
70
60
230
150
*/
