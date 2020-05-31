#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

class geoshape
{
  protected:
  float dim1,dim2;

  public:
  geoshape()
  {
  dim1=0;
  dim2=0;
  }
  geoshape(float f1,float f2)
  {
  dim1=f1;
  dim2=f2;
  }
  ~geoshape(){};
  void setdim1(float f);
  void setdim2(float f);
  float getdim1();
  float getdim2();
  float calcsum();
  virtual float calcarea()=0;
  //friend float calcsumareas(geoshape *p,geoshape *pp,geoshape *ppp);
};

void geoshape:: setdim1(float f)
{
dim1=f;
}
  void geoshape:: setdim2(float f)
  {
  dim2=f;
  }
  float geoshape:: getdim1()
  {
  return dim1;
  }
  float geoshape:: getdim2()
  {
  return dim2;
  }


  float calcsumareas(geoshape *p,geoshape *pp,geoshape *ppp,geoshape *pppp)
  {
  float f;
  f=(p->calcarea()+pp->calcarea()+ppp->calcarea()+pppp->calcarea());
  return f;
  }

  class rect: public geoshape
  {
  public:
  rect() : geoshape(0,0){}
  ~rect(){}
  rect(float w,float h):geoshape(w,h){}
  float calcarea()
  {
  return dim1*dim2;
  }
  };

  class circle : public geoshape
  {
  public:
  circle() : geoshape(0,0){}
  circle(float r): geoshape(r,r){}
  ~circle(){}
  float calcarea()
  {
  return dim1*dim2*3.14;
  }
  };

  class triangle : public geoshape
  {
  public:
  triangle(): geoshape(0,0){}
  triangle(float b,float h): geoshape(b,h){}
  ~triangle(){}
  float calcarea()
  {
  return dim1*dim2*0.5;
  }
  };

  class square: public rect
  {
  public:
  square():rect(0,0){}
  square(float l): rect(l,l){}
  ~square(){}
  float calcarea()
  {
  return dim1*dim2 ;
  }

  };

  void main()
  {
  clrscr();
  rect r(10,10);
  circle c(10);
  triangle t(10,10);
  square s(10);

  cout<<"rec area=";
  cout<<r.calcarea();  cout<<"\n";
  cout<<"square area=";
  cout<<s.calcarea();  cout<<"\n";
  cout<<"triangle area=";
  cout<<t.calcarea();  cout<<"\n";
  cout<<"circle area=";
  cout<<c.calcarea();  cout<<"\n";
  cout<<"sum of areas=";// cout<<"\n";
  cout<<calcsumareas(&r,&t,&c,&s);
  cout<<endl;
		   getch();
  }