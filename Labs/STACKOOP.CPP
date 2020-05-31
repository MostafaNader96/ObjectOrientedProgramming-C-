#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

template<class T>
class STACK
{
   private:
   int tos,size;
   T *stk;
   static int count;

   public:
   STACK(int size=5)
   {
   this->size=size;
   tos=0;
   stk=new T[size];
   count++;
   }

   STACK(STACK &s)
   {
   int i;
   this->size=s.size;
   this->tos=s.tos;
   stk=new T[size];


   for(i=0;i<tos;i++)
   {
   stk[i]=s.stk[i];
   }

   count++;
   }

   ~STACK()
   {
   if(stk) delete []stk;
   //cout<<"DESTRUCTOR IS CALLING :)\n";
   count--;
   }

	   int isempty();
	   int isfull();
	   int push(T data);
	   int pop(T &data);
	   int peak();
	   STACK& operator=(STACK &s);
	   STACK operator+(STACK &s);

static int getcount() {return count;}
friend void viewcontent(STACK<T> &S);
};
	template<class T>
	int STACK<T>:: count=0;

   template <class T>
   void viewcontent(STACK<T> &S)
   {
	 int i;
	 for(i=0;i<S.tos;i++)
	 {
	 cout<<"Element #"<<i+1<<"="<<S.stk[i]<<"\n";
	 }
   }

   template <class T>
   int STACK<T>:: isempty()
   {
   if(tos==0) return 1;
   else return 0;
   }

   template <class T>
   int STACK<T>:: isfull()
   {
   if(tos==size) return 1;
   else return 0;
   }
   template <class T>
   int STACK<T>:: push(T data)
   {
   if(isfull()) return 0;
   stk[tos]=data;
   tos++;
   cout<<"PUSHED: "<<data<<"\n";
   return 1;
   }
   template <class T>
   int STACK<T>:: pop(T &data)
   {
   if(isempty()) return 0;
   tos--;
   data=stk[tos];
   cout<<"POPPED: "<<stk[tos]<<"\n";
   return 1;
   }
   template <class T>
   int STACK<T>:: peak()
   {
   if(isempty()) return 0;

   cout<<"Top value is= "<<stk[tos-1]<<"\n";
   return 1;
   }

   template <class T>
   STACK<T>& STACK<T>:: operator=(STACK<T> &s)
   {
   int i;
   this->size=s.size;
   this->tos=s.tos;
   delete []stk;
   stk=new T[size];
   for(i=0;i<tos;i++)
   {
   stk[i]=s.stk[i];
   }
   return *this;
   }
   template <class T>
   STACK<T> STACK<T>:: operator+(STACK<T> &s)
   {
	int i;
	STACK temp;
	temp.size=this->size+s.size;
	temp.tos=this->tos+s.tos;
	temp.stk=new T[temp.size];

	for(i=0;i<tos;i++)
	{
	temp.stk[i]=s.stk[i];
	}

	for(i=0;i<s.tos;i++)
	{
	temp.stk[i+tos]=this->stk[i];
	}
		 return temp;
   }

void main()
{
	 clrscr();
	 int temp;
	 STACK<int> s1(5);
	 STACK<float> s2(12);
	 STACK<float> s3(10);
	 cout<<s2.getcount()<<endl;
	 //cout<<STACK<char>::getcount()<<endl;
	 s1.push(1);
	 s1.push(2);
	 s1.pop(temp);
	 s1.pop(temp);
	 viewcontent(s1);
  /*STACK s1,s2,s3;
  int temp;
  clrscr();

  cout<<"Counter= "<<STACK::getcount()<<"\n";
  cout<<"STACK 1:\n";
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);
  cout<<"STACK 2:\n";
  s2.push(6);
  s2.push(7);
  s2.push(8);
  s2.push(9);
  s2.push(10);

  cout<<"\nCombined STACK:\n";
  s3=s2+s1;

  viewcontent(s3);*/

  getch();

}