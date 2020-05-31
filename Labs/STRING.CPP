#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <STRING.h>

class String
{
private:
int size;
char *str;

public:
String()
{
cout<<"Default constructor is calling\n";
size=0;
str=NULL;
}
String(char *s)
{
cout<<"Constructor is calling\n";
int i,j;
i=0;
while(s[i]!=NULL)
{
 str[i]=s[i];
 i++;
}
size=i;
delete [] str;
str=new char[i];
for(j=0;j<i;j++)
{
str[j]=s[j];
}

}
String(String &s)
{
cout<<"Copy constructor is calling\n";
int i;
i=0;
size=s.size;
delete [] str;
str= new char[size];
for(i=0;i<size;i++)
{
 str[i]=s.str[i];
}
}
~String()
{
cout<<"Destructor is calling\n";
delete [] str;
}
void    printstring();
char    charAt(int index);
int     indexof(char ch);
int     indexof(int start,char ch);
String  substring(int start);
String  substring(int start,int end);
String  concat(String s2);
String  operator+(String s2);
String& operator+=(String s2);
String& operator=(String &s);

static String uppercase(String &s);
static String lowercase(String &s);



};

void String::   printstring()
{
int i;
for(i=0;i<size;i++)
{cout<<str[i];}
}

char String::   charAt(int index)
{
 int i;
 for(i=0;i<size;i++)
 {
 if(i==index)
 return str[i];
 }
return '-';
}

int String::    indexof(char ch)
{
 int i=0;
 while(str[i]!=NULL)
 {
 if(str[i]==ch)
 return i;
 i++;
 }
 return -1;
}

int String::    indexof(int start,char ch)
{
 while(str[start]!=NULL)
 {
 if(str[start]==ch)
 return start;
 start++;
 }
 return -1;
}

String String:: substring(int start)
{
 int i;
 int j=start;
 String temp;
 temp.size=size-start;
 for(i=0;i<temp.size;i++)
 {
 temp.str[i]=str[j];
 j++;
 }
 return temp;
}

String String:: substring(int start,int end)
{
 int i;
 int j=start;
 String temp;
 temp.size=(end-start)+1;
 for(i=0;i<temp.size;i++)
 {
 temp.str[i]=str[j];
 j++;
 }
 return temp;

}

String String::  concat(String s2)
{
  int i;
  String temp;
  temp.size=size+s2.size;
  for(i=0;i<size;i++)
  {
  temp.str[i]=str[i];
  }
  strcat(temp.str,s2.str);
  return temp;
}

String String::  operator+(String s2)
{
  int i;
  String temp;
  temp.size=size+s2.size;
  for(i=0;i<size;i++)
  {
  temp.str[i]=str[i];
  }
  strcat(temp.str,s2.str);
  return temp;
}


String& String::  operator+=(String s2)
{
  strcat(str,s2.str);
  return *this;
}

String& String:: operator=(String &s)
{
  int i;
  size=s.size;
  delete [] str;
  str= new char[size];
  for(i=0;i<size;i++)
  {
	str[i]=s.str[i];
  }
	return *this;
}

void main()
{
	int a,b;
	char c;
	int i;
	clrscr();

	String temp,s1("Ahmed"),s2("Mostafa"),s3,s4("Waleed"),s5("adel"),s6;

	c=s2.charAt(3);
	a=s2.indexof('a');
	b=s2.indexof(5,'a');
	cout<<"Character at index 3 in string Mostafa is: "<<c<<"\n";
	cout<<"First 'a' in string Mostafa is found at index: "<<a<<"\n";
	cout<<"Character 'a' found starting from index 5 in string Mostafa is found at index: "<<b;

	s3=s2.substring(1,5);
	cout<<"from the first index to the fifth in string Mostafa: ";
	s3.printstring(); cout<<"\n";

	temp=s2.concat(s1);
	cout<<"String Mostafa and String Ahmed concatenated: ";
	temp.printstring(); cout<<"\n";

	temp=s2+s1;
	cout<<"String Mostafa and String Ahmed using +operator: ";
	temp.printstring(); cout<<"\n";


   /*s6=s4+=s5;
	s6.printstring();*/

	getch();

}