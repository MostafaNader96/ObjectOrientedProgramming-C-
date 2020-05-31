#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <STRING.h>
#include <CTYPE.h>

class String
{
private:
int size;
char *str;

public:
String()
{
//cout<<"Default constructor is calling\n";
size=0;
str=NULL;
}
String(char *s)
{
//cout<<"Constructor is calling\n";
size=strlen(s);
str=new char[size];
strcpy(str,s);
}
String(String &s)
{
//cout<<"Copy constructor is calling\n";
size=s.size;
str=new char[size];
strcpy(str,s.str);
}
~String()
{
//cout<<"Destructor is calling\n";
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

static String uppercase(String &s)
{
 String temp;
 temp.size=s.size;
 int i;
 for(i=0;i<s.size;i++)
 {
  temp.str[i]=toupper(s.str[i]);
 }
 return temp;
}

static String lowercase(String &s)
{
 String temp;
 temp.size=s.size;
 for(int i=0;i<s.size;i++)
 {
 if((int)s.str[i]<97)
 temp.str[i]=s.str[i]+32;
 else
 temp.str[i]=s.str[i];
 }
 return temp;
 /*String temp;
 temp.size=s.size;
 int i;
 for(i=0;i<s.size;i++)
 {
  temp.str[i]=tolower(s.str[i]);
 }
 return temp;*/
}



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
  int j=0;
  String temp;
  temp.size=size+s2.size;
  for(i=0;i<size;i++)
  {
  temp.str[i]=str[i];
  }
  for(i=size;i<temp.size;i++)
  {
  temp.str[i]=s2.str[j];
  j++;
  }
  return temp;
}

String String::  operator+(String s2)
{
  int i;
  int j=0;
  String temp;
  temp.size=size+s2.size;
  for(i=0;i<size;i++)
  {
  temp.str[i]=str[i];
  }
  for(i=size;i<temp.size;i++)
  {
  temp.str[i]=s2.str[j];
  j++;
  }
  return temp;

}


String& String::  operator+=(String s2)
{
  int i;
  int j=0;
  int k=size;
  size=size+s2.size;
  for(i=k;i<size;i++)
  {
	str[i]=s2.str[j];
	j++;
  }
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
	clrscr();

	String s1("Motivated"),s2,s3("People"),s4("Hello"),s5("World!"),s6("Upper"),s7("lOWER");
	String temp,temp1,temp2;

	c=s1.charAt(3);
	a=s1.indexof('t');
	b=s1.indexof(5,'t');
	cout<<"Character at index 3 in string Motivated is: "<<c<<"\n";
	cout<<"First 't' in string Motivated is found at index: "<<a<<"\n";
	cout<<"Character't'found starting from index 4 in string Motivated is found at index: "<<b;

	cout<<"\n----Invalid Cases---- ";
	c=s1.charAt(9);
	a=s1.indexof('Z');
	b=s1.indexof(11,'t');
	if(c=='-')
	cout<<"\nIndex invalid in this string!!";
	if(a==-1)
	cout<<"\nCharacter not found in this string!!";
	if(b==-1)
	cout<<"\nCharacter not found or Index invalid in this string!!\n\n";



	s2=s1.substring(2,6);
	cout<<"from the second index to the sixth in string Motivated: ";
	s2.printstring(); cout<<"\n";

	temp=s1.concat(s3);
	cout<<"String Motivated and String People concatenated: ";
	temp.printstring(); cout<<"\n";

	temp=s1+s3;
	cout<<"String Motivated and String People using +operator: ";
	temp.printstring(); cout<<"\n";


	s4+=s5;
	cout<<"String Hello and String World! using +=operator and returned in the same string:";
	s4.printstring();   cout<<"\n\n";

	temp1=String:: uppercase(s6);
	cout<<"String before converting to uppercase: ";
	s6.printstring();
	cout<<"\n";
	cout<<"String after converting to uppercase: ";
	temp1.printstring();  cout<<"\n";
	temp2=String:: lowercase(s7);
	cout<<"String before converting to lowercase: ";
	s7.printstring();
	cout<<"\n";
	cout<<"String after converting to lowercase: ";
	temp2.printstring();  cout<<"\n";

	cout<<"\n\nDefault/Valued/Copy constructors and the Destructor calls are hidden from the output window for the main example to be clear, if u want to see the flow of the constructors and the destructors uncomment the couts from the functions :)\n";

	getch();

}