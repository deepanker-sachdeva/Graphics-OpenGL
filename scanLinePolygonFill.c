/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

struct scanLine
{
	int y;
	int x[20];
};
struct Edge
{
int x1,y1;	
float m;
}e[20];
void MyInit ( void ) {

glClearColor ( 0.0, 0.0, 0.0, 0.0 ); //white background
glColor3f(0.0f, 1.0f,0.0f); // green drawing colour
glPointSize(1.0); // 5 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)500, 0.0, (GLdouble)500 ); //Display area
}
int main(int argc, char **argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

int n;
printf("Enter the no. of vertices in the polygon!\n");
scanf("%d",&n);
float xt[n],yt[n];
//int x[2*n],y[2*n];
printf("Enter x,y for each vertex!\n");
int i=0;
for(i=0;i<n;i++)
{
	printf("%d\t",i);	
	scanf("%f%f",&xt[i],&yt[i]);
}
int index=0;
for(i=0;i<n;i++)
{
	e[index].x1=xt[i];
	e[index].y1=yt[i];
	e[index].x2=xt[(i+1)%n];
	e[index].y2=yt[(i+1)%n];
	index++;
}
/*
glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("Green window");
MyInit ( );

glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_POINTS); // render with points
*/
i=0;
int cur=0,pre=n-1,nex=1;
float m=0;
for(cur=0;cur<n;cur++)
{
	if(yt[pre]<yt[cur]&&yt[cur]<yt[nex])
	{
		m=(yt[pre]-yt[cur])/(xt[pre]-xt[cur]);
		//printf("%f\t",m);
		e[i].m=m;
		e[i].x1=round(xt[pre]+(1/m)*(yt[cur]-yt[pre]-1));
		e[i].y1=yt[cur]-1;	
		//i++;
		//x[i]=xt[cur];
		//y[i]=yt[cur];
		e[i].x2=xt[cur];
		e[i].x2=yt[cur];
	}
	else if(yt[pre]>yt[cur]&&yt[cur]>yt[nex])
	{
		m=(yt[nex]-yt[cur])/(xt[nex]-xt[cur]);
		//printf("%f\t",m);
		x[i]=xt[cur];
		y[i]=yt[cur];
		i++;				
		x[i]=round(xt[nex]+(1/m)*(yt[cur]-yt[nex]-1));
		y[i]=yt[cur]-1;
		nv[nvi].index=i;
		nv[nvi].up=1;
		nvi++;
	}
	else
	{
		x[i]=xt[cur];
		y[i]=yt[cur];
	}
	pre=(pre+1)%n;
	nex=(nex+1)%n;
	i++;
}
int end=i;
for(i=0;i<end;i++)
printf("%d , %d\n",x[i],y[i]);
int ymin,xmin,ymax;
for(i=0;i<end;i++)
{
	if(i==nv[nvi]
}
//glVertex2i(x8,y8);



/*
glEnd();
glFlush();

glutMainLoop();
*/
return 0;
}
