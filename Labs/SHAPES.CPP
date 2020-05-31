#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

class shape{
 private:
   int color;
 public:
   //default constructor
   shape()
   {color=0;}
   //constructor
   shape(int a)
   {color=a;}
   //copy constructor
   shape(shape& s)
   { color=s.color;
   }
   //destructor
   ~shape(){}
   //methods
   void set_color(int a)
   {color=a;}
   int get_color()
   {return color;}
};

class point{
  private:
	int x,y;
  public:
   //default constructor
   point()
   {
	 x=y=0;
	//out<<"\n point constructor";
   }
   //copy constructor prototype
   point(point&c)
   {
	 x=c.x;
	 y=c.y;
   }
   //operator= over load
   point& operator=(point& p){
	 x=p.x;
	 y=p.y;
	 return (*this);
   }

   point(int a,int b)
   {
	x=a;  y=b;
	//ut<<"\n point constructor";
   }
   //destructor
   ~point()
   {//cout<<"\n point deconstructor";
   }
   //class methods
   void set_x(int a)
   {x=a;}
   void set_y(int b)
   {y=b;}
   void set_xy(int a,int b)
   {x=a;  y=b;}
   int get_x()
   {return x;}
   int get_y()
   {return y;}
   void print()
   {
	 cout<<x<<"  "<<y;
   }
};

class linee:public shape{
   private:
	 point start,end;
   public:
	 //default constructor
	 linee():start(0,0),end(0,0)
	 {}
	 //constructor
	 linee(int x1,int y1,int x2,int y2):start(x1,y1),end(x2,y2)
	 {}
	 linee(point p1,point p2):start(p1),end(p2)
	 {
	  // cout<<"\nline constructor using point";
	 }
	 //copy constructor
	 linee(linee&l){
	  start=l.start;
	   end=l.end;
	 }
	 //= operator overload
	 linee& operator=(linee& l)
	 {
	   start=l.start;
	   end=l.end;
	   return(*this);
	 }
	 //destructor
	 ~linee()
	 {
	  //cout<<"\n line destructor";
	 }
	 //methods
	 void setline(point p1,point p2)
	 {
	   start=p1;
	   end=p2;
	 }
	 void print(){
	  cout<<"\n start values are  ";
	   start.print();
	  cout<<"\n end values are  ";
	   end.print();
	 }
	 void draw(){
		setcolor(20);
		line(start.get_x(),start.get_y(),end.get_x(),end.get_y());

	 }
};

class circlee:public shape{
  private:
	point center;
	int rad;
  public:
  //default constructor
	circlee() :center(0,0),rad(0)
	{}
  //constructor
	circlee(point c,int r):center(c),rad(r)
	{}
	circlee(int x,int y,int r):center(x,y),rad(r){}
  //copy constructor
	 circlee(circlee& c){
	   center=c.center;
	   rad=c.rad;
	 }
   //operator= overload
	circlee& operator=(circlee & c){
	  center=c.center;
	  rad=c.rad;
	  return *this;
	}
	//destructor
	~circlee()
	{
	//cout<<"\n circle destrctor";
	}
	//methods
	void setcenter(point c){center=c;}
	void setrad(int r){rad=r;}
	point getcenter(){ return center;}
	int getrad(){return rad;}
	void print(){
	 cout<<"\n circle data:";
	 cout<<"\n radius= "<<rad;
	 cout<<"\n center values are  ";
	 center.print();
	}
	void draw(){
		setcolor(20);
		circle(center.get_x(),center.get_y(),getrad());
	 }
};

class rect:public shape{
 private:
  point ul,lr;
 public:
   //default constructor
   rect() :ul(0,0),lr(0,0)
   {}
   //constructor
   rect(point pa,point pb):ul(pa),lr(pb)
   {}
   rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
   {

   }
   //copy constructor
   rect(rect & r){
	ul=r.ul;
	lr=r.lr;
   }
   //= operator overload
   rect& operator=(rect& r)
   {
	 ul=r.ul;
	 lr=r.lr;
	 return *this;
   }
   //default destructor
   ~rect(){}
   //methods
   void setul(point r){ul=r;}
   void setlr(point f){lr=f;}
   void setrect(point p1,point p2){ul=p1;lr=p2;}
   point getul(){return ul;}
   point getlr(){return lr;}
   void print(){
	   cout<<"\n ur values are  ";
	   ul.print();
	  cout<<"\n ul values are  ";
	   lr.print();
   }
   void draw(){
		setcolor(20);
		rectangle(ul.get_x(),ul.get_y(),lr.get_x(),lr.get_y());
	 }
};
class pic{
 private:
   int c_num,r_num,l_num;
   circlee* cptr;
   linee* lptr;
   rect * rptr;
 public:
   //default constructor
   pic()
   {
	 c_num=r_num=l_num=0;
	 cptr=NULL;  lptr=NULL;  rptr=NULL;
   }
   pic(int c,int l,int r,circlee* cp,linee*lp,rect* rp);
   ~pic(){}
  public:
	void set_circle(int num ,circlee * cp);
	void set_line(int num ,linee * lp);
	void set_rect(int num ,rect * rp);
	void paint();

};
pic::pic(int c,int l,int r,circlee* cp,linee*lp,rect* rp){
   c_num=c;  l_num=l;  r_num=r;
   cp=new circlee[c_num];  lp=new linee[l_num];  rp=new rect[r_num];
	 for(int i=0;i<c_num;i++)  cptr[i]=cp[i];
	 for(i=0;i<l_num;i++)      lptr[i]=lp[i];
	 for(i=0;i<r_num;i++)      rptr[i]=rp[i];

}
void pic::set_circle(int num ,circlee * cp){
	   c_num=num;
	   if(cptr)  delete [] cptr;
	   cptr=new circlee[c_num];
	   for(int i=0;i<c_num;i++)  cptr[i]=cp[i];
}
void pic::set_line(int num ,linee * lp){
	   l_num=num;
	   if(lptr)  delete [] lptr;
	   lptr=new linee[l_num];
	   for(int i=0;i<l_num;i++)  lptr[i]=lp[i];
}
void pic::set_rect(int num ,rect * rp){
	   r_num=num;
	   if(rptr)  delete [] rptr;
	   rptr=new rect[r_num];
	   for(int i=0;i<r_num;i++)  rptr[i]=rp[i];
}
void pic::paint(){
 for(int i=0;i<c_num&&cptr;i++)  cptr[i].draw();
 for(i=0;i<l_num&&lptr;i++)      lptr[i].draw();
 for(i=0;i<c_num&&rptr;i++)      rptr[i].draw();
}
int main(){
  clrscr();


  int gdriver=DETECT,gmode,errorCode;
  initgraph(&gdriver,&gmode,"..\\BGI");
  errorCode=graphresult();
  if(errorCode != grOk){
	cout<<"can not initialize graphics"<<endl;
  }
 else{
	pic mypic;
	circlee carr[3]={circlee(50,50,2),circlee(200,100,1),circlee(420,50,12)};
	rect rarr[2]={rect(30,40,170,100),rect(420,50,500,300)};
	linee larr[2]={linee(420,50,300,300),linee(40,500,500,400)};
	mypic.set_circle(3,carr);
	mypic.set_rect(2,rarr);
	mypic.set_line(2,larr);
	mypic.paint();
 }

getch();
closegraph();
return 0;
}