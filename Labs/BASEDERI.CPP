#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

class Base
{
 protected:
 int a,b;

 public:
 Base()
 {
 cout<<"Base default constructor is calling\n";
 a=0;
 b=0;
 }
 Base(int a,int b)
 {
 cout<<"Base constructor is calling\n";
 this->a=a;
 this->b=b;
 }
 Base(Base &ba)
 {
 cout<<"Base copy constructor is calling\n";
 a=ba.a;
 b=ba.b;
 }
 ~Base()
 {
 cout<<"Base destructor is calling\n";
 }
 void seta(int a);
 void setb(int b);
 int  calcsum();

};


 void Base:: seta(int a)
 {
 this->a=a;
 }
 void Base:: setb(int b)
 {
 this->b=b;
 }
 int  Base:: calcsum()
 {
 cout<<"\nBase sum=";
 return a+b;
 }

 class Derived : public Base
 {
 int c;

 public:
 Derived()
 {
 cout<<"Derived default constructor is calling\n";
 a=0;
 b=0;
 c=0;
 }
 Derived(int a,int b,int c)
 {
 cout<<"Derived constructor is calling\n";
 this->a=a;
 this->b=b;
 this->c=c;
 }
 Derived(Derived &d)
 {
 cout<<"Derived copy constructor is calling\n";
 a=d.a;
 b=d.b;
 c=d.c;
 }
 ~Derived()
 {
 cout<<"Derived Destructor is calling\n";
 }
 void setc(int c);
 int  getcc();
 int  calcsum();

 };

 void Derived:: setc(int c)
 {
 this->c=c;
 }
 int  Derived:: getcc()
 {
 return c;
 }
 int  Derived:: calcsum()
 {
 cout<<"\nDerived sum=";
 return  a+b+c;
 }

void main()
{
clrscr();

Base b;
Derived d(1,2,3);
//d.setc(1);
cout<<b.calcsum();
cout<<d.calcsum();

getch();
}