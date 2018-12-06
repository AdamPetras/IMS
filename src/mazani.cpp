#include "mazani.h"
int Mazani::Input = 0;
int Mazani::Sumtime1 = 0;
int Mazani::Sumtime2 = 0;
Stat Mazani::Fstat1("První mazač");
Stat Mazani::Fstat2("Druhý mazač");
Histogram Mazani::Fhist("Mazani", 0, 60*60*24, 14);
Facility Mazani::first("Prvni mazač");
Facility Mazani::second("Druhy mazač");
Mazani::Mazani(/* args */)
{

}

Mazani::~Mazani()
{
}

void Mazani::Behavior()
{
     
     double d = Uniform(0,99);
     Orezavani *tmp = new Orezavani;
     double t;
     if(d<50)
     {
          Seize(first);
          t = Time;
          if(Input < 2)
          {
               Release(first);
               return;
          }
          Fhist(Time);
          Wait(Uniform(5,10));
          Input-=2;
          t = Time-t;
          Fstat1(t);
          Sumtime1 += t;
          Release(first);
     }
     else if(d>=50)
     {
          Seize(second);
          t = Time;
          if(Input < 2)
          {
               Release(second);
               return;
          }
          Fhist(Time);
          Wait(Uniform(5,10));
          Input-=2;
          t = Time-t;
          Fstat2(t);
          Sumtime2 += t;
          Release(second);
     }
     tmp->Input++;
     tmp->Activate();
}
