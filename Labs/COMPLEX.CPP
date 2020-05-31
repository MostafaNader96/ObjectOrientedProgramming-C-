#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <MATH.h>
//using namespace std;

class complex
{
private:
float real,imag;

public:

complex()
{
real=0;
imag=0;
}
complex(float r,float i)
{
real=r;
imag=i;
}

complex(complex &c)
{
 cout<<"copy constructor called\n";
 this->real=c.real;
 this->imag=c.imag;
}

~complex()
{
cout<<"destructor is calling\n";
}

float getreal();
void setreal(float r);
float getimag();
void setimag(float i);
void printcomp();
complex& operator=(complex &c);
complex  operator+(complex &c);
complex& operator++();
complex  operator++(int dummy);
		 operator float();
friend istream& operator>>(istream&in,complex&c);
friend ostream& operator<<(ostream&out,complex&c);

};

float complex:: getreal()
{
return real;
}
void complex:: setreal(float r)
{
real=r;

}
float complex:: getimag()
{
return imag;
}
void complex:: setimag(float i)
{
imag=i;
}
void complex:: printcomp()
{
//cout<<"Complex Number= ";
if(imag>0)
{
cout<<real;
cout<<"+";
cout<<imag;
cout<<"i\n";
}
if(imag<0)
{
cout<<real;
//cout<<"-";
cout<<imag;
cout<<"i\n";
}
if(imag==0)
{
cout<<real;
cout<<"\n";
}
}

complex& complex::  operator=(complex &c)
{
	this->real=c.real;
	this->imag=c.imag;
	return *this;
}
complex complex:: operator+(complex &c)
{
	 complex temp;
	 temp.real=real+c.real;
	 temp.imag=imag+c.imag;
	 return temp;
}

complex& complex:: operator++()
{
	this->real++;
	this->imag++;
	return *this;
}
complex complex:: operator++(int dummy)
{
	complex temp(*this);
	real++;
	imag++;
	return temp;

}

 complex:: operator float()
{
return (sqrt((real*real)+(imag*imag)));
}

istream& operator>>(istream&in,complex&c)
{
   cout<<"Enter real an imag:\n";
   cin>>c.real;
   cin>>c.imag;
   return in;
}

ostream& operator<<(ostream&out,complex&c)
{
  out<<"\nComplex #= ";
  out<<c.real<<"+"<<c.imag<<"i\n";
}

complex subcomplex(complex c1,complex c2);
complex addcomplex(complex c1,complex c2);

void main()
{
  float x,y,z,k,p;
  clrscr();
  complex cplus,cminus,c1,c2,c3,c4,c5;
  //c1.printcomp();
  //c2.printcomp();
  //c1.setreal(4);
  //c1.setimag(-5);
  //c1.printcomp();
  cout<<"Enter the real and imag of the first complex\n";
  cin>>x;
  c3.setreal(x);
  cin>>y;
  c3.setimag(y);
  cout<<"Enter the real and imag of the second complex\n";
  cin>>z;
  c4.setreal(z);
  cin>>k;
  c4.setimag(k);
  cin>>c3;
  //cminus=subcomplex(c3,c4);
  //cplus=addcomplex(c3,c4);
  cplus=c3+c4;
  cout<<"The sum of both complex numbers= ";
  cout<<cplus;
  p=(float)c3;
  c1=c3++;
  c1.printcomp();
  c2=++c4;
  c2.printcomp();

  cout<<"CASTED FLOAT= "<<p;
  //cout<<"The difference of both complex numbers= ";
  //cminus.printcomp();

  getch();




}




complex subcomplex(complex c1,complex c2)
{
  complex c;
  float x,y,z,k;
  x=c1.getreal();
  y=c1.getimag();
  z=c2.getreal();
  k=c2.getimag();
  c.setreal(x-z);
  c.setimag(y-k);
  return c;
}
complex addcomplex(complex c1,complex c2)
{
  complex c;
  float x,y,z,k;
  x=c1.getreal();
  y=c1.getimag();
  z=c2.getreal();
  k=c2.getimag();
  c.setreal(x+z);
  c.setimag(y+k);
  return c;
}
