#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <GRAPHICS.h>


class Shape
{
int color;

public:
Shape()
{
//cout<<"Shape default constructor is calling\n";
color=0;
}
Shape(int col)
{
//cout<<"Shape Constructor is calling\n";
color=col;
}
Shape(Shape &sh)
{
//cout<<"Shape copy Constructor is calling\n";
color=sh.color;
}
~Shape()
{
//cout<<"Shape destructor is calling\n";
}
virtual void draw()=0;
void setcolor(int color)
{
  this->color=color;
}
int getcolor()
{
return color;
}

};

class point
{
private:
int x,y;

public:
point()
{
//cout<<"Point Default constructor is calling\n";
x=0;
y=0;
}
point(int x, int y)
{
//cout<<"Point Constructor is calling\n";
this->x=x;
this->y=y;
}
point(point &p)
{
//cout<<"Point Copy constructo is calling\n";
x=p.x;
y=p.y;
}
~point()
{
//cout<<"Point Destructor is calling\n";
}
void setx(int x);
void sety(int y);
int  getx();
int  gety();
void setall(int x,int y);
void viewpoint();
};



void point:: setx(int x)
{
this->x=x;
}
void point:: sety(int y)
{
this->y=y;
}
int  point:: getx()
{
return x;
}
int  point:: gety()
{
return y;
}
void point:: setall(int x,int y)
{
this->x=x;
this->y=y;
}
void point:: viewpoint()
{
cout<<"\nPoint: X="<<x<<"  Y="<<y<<"\n";
}

class Line : public Shape
{
private:
point start,end;

public:
Line()
{
//cout<<"Line Default constructor is calling\n";
start.setall(0,0);
end.setall(0,0);
}
Line(int x1,int y1,int x2,int y2)
{
//cout<<"Line Constructor is calling\n";
start.setall(x1,y1);
end.setall(x2,y2);
}
Line(point p1,point p2)
{
start=p1;
end=p2;
}
~Line()
{
//cout<<"Line Destructor is calling\n";
}
void setstart(int x,int y);
void setend  (int x,int y);
void printLine();
void draw();

};

void Line:: draw()
{
int x1,x2,y1,y2;
x1=start.getx();
x2=end.getx();
y1=start.gety();
y2=end.gety();
line(x1,y1,x2,y2);
}

void Line:: setstart(int x,int y)
{
start.setall(x,y);
}
void Line:: setend (int x,int y)
{
end.setall(x,y);
}
void Line:: printLine()
{
cout<<"\nStart: ";
start.viewpoint();
cout<<"\nEnd: ";
end.viewpoint();
}

class Circle : public Shape
{
private:
int rad;
point center;

public:
Circle()
{
//cout<<"Circle Default constuctor is calling\n";
center.setall(0,0);
rad=0;
}
Circle(int x,int y,int rad)
{
//cout<<"Circle constructor is calling\n";
center.setall(x,y);
this->rad=rad;
}
Circle(point p1,int rad)
{
center=p1;
this->rad=rad;
}
~Circle()
{
//cout<<"Circle destructor is calling\n";
}
void setcenter(int x,int y);
void setrad(int rad);
point getcenter();
int   getrad();
void printCircle();
void draw();

};

void Circle:: draw()
{
int x,y;
x=center.getx();
y=center.gety();
circle(x,y,rad);
}

void Circle:: setcenter(int x,int y)
{
center.setall(x,y);
}
void Circle:: setrad(int rad)
{
this->rad=rad;
}
point Circle:: getcenter()
{
return center;
}
int Circle::  getrad()
{
return rad;
}
void Circle:: printCircle()
{
cout<<"\nCircle   Center:";
center.viewpoint();
cout<<"\nRadius= "<<rad<<"\n";

}

class Rect : public Shape
{
private:
point p1,p2;

public:
Rect()
{
//cout<<"Rectangle default constuctor is calling\n";
p1.setall(0,0);
p2.setall(0,0);
}
Rect(int x1,int y1,int x2, int y2)
{
//cout<<"Rectangle constructor is calling\n";
p1.setall(x1,y1);
p2.setall(x2,y2);
}
Rect(point p1,point p2)
{
this->p1=p1;
this->p2=p2;
}

~Rect()
{
//cout<<"Rectange destructor is calling\n";
}
void setupperpoint(int x,int y);
void setlowerpoint(int x,int y);
point getupperpoint();
point getlowerpoint();
void printRect();
void draw();


};

void Rect:: draw()
{
int x1,x2,y1,y2;
x1=p1.getx();
x2=p2.getx();
y1=p1.gety();
y2=p2.gety();
rectangle(x1,y1,x2,y2);
}


void Rect:: setupperpoint(int x,int y)
{
p1.setall(x,y);
}
void Rect:: setlowerpoint(int x,int y)
{
p2.setall(x,y);
}
point Rect:: getupperpoint()
{
return p1;
}
point Rect:: getlowerpoint()
{
return p2;
}
void Rect:: printRect()
{
cout<<"\nRectagle upper point:";
p1.viewpoint();
cout<<"Rectagle lower point:";
p2.viewpoint();

}


class pic
{
private:
int cnum,rnum,lnum;
Circle *cptr;
Line   *lptr;
Rect   *rptr;

public:
pic()
{
 cnum=0;
 rnum=0;
 lnum=0;
 cptr=NULL;
 rptr=NULL;
 lptr=NULL;
}
pic(int ccnum,int rrnum,int llnum,int *c,int *r,int *l)
{
 cnum=ccnum;
 rnum=rrnum;
 lnum=llnum;
 cptr=new int[cnum];
 rptr=new int[rnum];
 lptr=new int[lnum];
 for(int i=0;i<cnum;i++)
 {
 cptr[i]=c[i];
 }
 for(int i=0;i<rnum;i++)
 {
 rptr[i]=r[i];
d }
 for(int i=0;i<lnum;i++)
 {
 lptr[i]=l[i];
 }
}

void setLines(int x,Line *l);
void setCircles(int x,Circle *c);
void setRects(int x,Rect *r);
void paint();
};

void pic:: setLines(int x,Line *l)
{
lnum=x;
if(lptr) delete [] lptr;
lptr=new Line[lnum];
for(int i=0;i<lnum;i++)
{
lptr[i]=l[i];
}
}

void pic:: setCircles(int x,Circle *c)
{
cnum=x;
if(cptr) delete []cptr;
cptr=new Circle[cnum];
for(int i=0;i<cnum;i++)
{
cptr[i]=c[i];
}
}
void pic:: setRects(int x,Rect *r)
{
rnum=x;
if(rptr) delete []rptr;
rptr=new Rect[rnum];
for(int i=0;i<rnum;i++)
{
rptr[i]=r[i];
}
}
void pic:: paint()
{
for(int i=0;i<lnum;i++)
{
lptr[i].draw();
}
for(i=0;i<cnum;i++)
{
cptr[i].draw();
}
for(i=0;i<rnum;i++)
{
rptr[i].draw();
}
}


void main()
{
clrscr();

int gdriver=DETECT,gmode,errorCode;

initgraph(&gdriver,&gmode,"..\\BGI");
errorCode= graphresult();
if(errorCode != grOk)
{
cout<<"cant initialize graphics"<<endl;
}
else
{
pic p1;
Circle cArr[3]={Circle(50,50,50),Circle(200,100,100),Circle(250,50,30)};
Rect   rArr[2]={Rect(30,40,170,100),Rect(420,50,500,300)};
Line   lArr[2]={Line(420,50,300,300),Line(40,500,500,400)};

p1.setCircles(3,cArr);
p1.setRects(2,rArr);
p1.setLines(2,lArr);
		   setcolor(CYAN);
p1.paint();
getch();
closegraph();
}
/*point p1(1,2);
point p2(1,2);
Line l1;
Circle c1;
Rect r1;
l1.setstart(3,4);
l1.setend(5,6);
c1.setcenter(7,8);
c1.setrad(9);
r1.setupperpoint(10,11);
r1.setlowerpoint(12,13);
p1.viewpoint();
l1.printLine();
c1.printCircle();
r1.printRect();
r1.setcolor(3);
cout<<r1.getcolor();*/

}