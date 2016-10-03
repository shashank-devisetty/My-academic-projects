#include<iostream>
using namespace std;
#include<conio.h>
class s 
{
    public:
    float a,b,c,e,f,g,h,i,k,l,z;
    int d;
    s(float a,float b)
    {
            this->a=a;
            this->b=b;
            }
    void cacheinp()
    {
    cout<<"Cache Specification"<<endl;
    cout<<"Cache Size= "<<a<<"KB"<<endl;
    cout<<"Associativity = "<<b<<endl;
    }
};
class t:public s
{
    public:
           t(float a,float b,float c,int d):s(a,b)
           {
                   this->c=c;
                   this->d=d;
                   }
    void cacheinp1()
    {
    cout<<"Block Size = "<<c<<endl;
    if(d==1)
    {
            cout<<"Write Back"<<endl;
            }
    else
    {
            cout<<"Write Through"<<endl;
            }

    }
};
class u:public t
{
      public:
             u(float a,float b,float c,int d,float e,float f):t(a,b,c,d)
             {
                     this->e=e;
                     this->f=f;
                     }
    void cacheinp2()
    {
    t::cacheinp1();
    cout<<"%writes="<<e<<endl;
    cout<<"%Reads ="<<100-e<<endl;
    cout<<"%Dirty  ="<<f<<endl;
    }
    };
class v:public u
{
      public:
             v(float a,float b,float c,int d,float e,float f,float g,float h,float i):u(a,b,c,d,e,f)
             {
                     this->g=g;
                     this->h=h;
                     this->i=i;
                     }
    void cacheinp3()
    {
         u::cacheinp2();
         cout<<"Hit Time= "<<h<<endl;
         cout<<"Miss peanlty= "<<g<<endl;
    
    }
    };
class w:public v
{
      public:
      w(float a,float b,float c,int d,float e,float f,float g,float h,float i):v(a,b,c,d,e,f,g,h,i)
      {}
    void disp()
    {
    v::cacheinp3();
    k=0.936,l=0.064;
    cout<<"Hit Rate= "<<k<<endl;
    cout<<"Miss Rate= "<<l<<endl;
    if(d==1)
    {
    cout<<"Read Hit Contributition: "<<(((100-e)/100)*k*h)<<endl;
    cout<<"Read Miss Contributition: "<<(((100-e)/100)*l*((g+h)+((f/100)*g)))<<endl;
    cout<<"Write Hit Contributition: "<<((e/100)*k*h)<<endl;
    cout<<"Write Miss Contributition: "<<((e/100)*l*g)<<endl;
    z=(((100-e)/100)*k*h)+(((100-e)/100)*l*((g+h)+((f/100)*g)))+((e/100)*k*h)+((e/100)*l*g);
    cout<<"Total Average Memory Access Time(Avg.Clocks Per Memory Access)= "<<z<<endl;    
    }
    else
    {
    cout<<"Read Hit Contributition: "<<(((100-e)/100)*k*h)<<endl;
    cout<<"Read Miss Contributition: "<<(((100-e)/100)*l*(g+h))<<endl;
    cout<<"Write Hit Contributition: "<<((e/100)*k*i)<<endl;
    cout<<"Write Miss Contributition: "<<((e/100)*l*i)<<endl;
    z=(((100-e)/100)*k*h)+(((100-e)/100)*l*(g+h))+((e/100)*k*i)+((e/100)*l*i);
    cout<<"Total Average Memory Access Time(Avg.Clocks Per Memory Access)= "<<z<<endl;  
}  
}
};
int main()
{
    float a,b,c,e,f,g,h,i;
    int d;
    cout<<"Cache Time Analysis \n";
    cout<<"Enter the cache size (2^0-2^8)kbytes \n";
    cin>>a;
    cout<<"Enter the Associativity(2^0-2^5)#sets \n";
    cin>>b;
    cout<<"Enter the Block Size (2^4-2^8)bytes \n";
    cin>>c;
    cout<<"Write Policy"<<endl;
    cout<<"1)Write Back\n2)Write Through \n";
    cin>>d;
    cout<<"Enter no. of percentage Writes\n";
    cin>>e;
    cout<<"Enter no. of percentage Dirty Data\n";
    cin>>f;
    cout<<"Enter Miss Penalty(cycles)(range 1-99)\n";
    cin>>g;
    cout<<"Enter Hit Time(cycles)\n";
    cin>>h;
    cout<<"Enter Memory Write(cycles)\n";
    cin>>i;
    w w1(a,b,c,d,e,f,g,h,i);
    w1.disp();
    getch();
}
    
    
    
    
