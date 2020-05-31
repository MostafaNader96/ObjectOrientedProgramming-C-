#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

class myarray
{
private:
int size;
int *ptr;

public:

myarray(int s)
{
 this->size=s;
 ptr=new int[s];
}

myarray(myarray& m)
{
 int i;
 cout<<"copy constructor calling\n";
 size=m.size;
 for(i=0;i<size;i++)
 {
 ptr[i]=m.ptr[i];
 }
}

~myarray()
{
 cout<<"Destructor is calling\n";
 delete []ptr;
}

void resize(int newsize);
void setelement(int index,int data,int size);
void setarray();
int& operator[](int index);



};

void myarray:: resize(int newsize)
{
	int i, *temp;
	temp=new int[newsize];

	if(newsize>size)
	{
	for(i=0;i<size;i++)
	{
	temp[i]=ptr[i];
	}
	}
	else
	{
	for(i=0;i<newsize;i++)
	{
	temp[i]=ptr[i];
	}
	}
	size=newsize;
	delete []ptr;
	ptr=temp;
}

void myarray:: setelement(int index,int data,int size)
{
   if(index>size-1)
   cout<<"Exceeded index\n";
   else
   ptr[index]=data;
}

void myarray:: setarray()
{
	 int i;
	 for(i=0;i<size;i++)
	 {
	 ptr[i]=i+1;
	 }
}

int& myarray:: operator[](int index)
{
  return ptr[index];
}


void main()
{
clrscr();
int i;
int size,newsize;
;
cout<<"enter the size of the array: ";
cin>>size;
myarray m1(size);
m1.setelement(0,1,size);
m1.setelement(1,2,size);
m1.setelement(2,3,size);
m1.setelement(3,4,size);
m1.setelement(4,5,size);
m1.setelement(5,6,size);

cout<<"ARRAY ELEMENTS: \n";
for(i=0;i<size;i++)
{
cout<<m1[i]<<"\n";
}

cout<<"enter the new size: ";
cin>>newsize;
cout<<"ARRAY AFTER RESIZING:\n";
m1.resize(newsize);
m1.setarray();
for(i=0;i<newsize;i++)
{
cout<<m1[i]<<"\n";
}

getch();

}