#include "mazani.h"
int Mazani::Input = 0;
int Mazani::Sumtime = 0;
Stat Mazani::Fstat1("První mazač");
Stat Mazani::Fstat2("Druhý mazač");
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
          Wait(Uniform(3,7));
          Input-=2;
          t = Time-t;
          Fstat1(t);
          Sumtime += t;
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
          Wait(Uniform(3,7));
          Input-=2;
          t = Time-t;
          Fstat2(t);
          Sumtime += t;
          Release(second);
     }
     tmp->Input++;
     tmp->Activate();
}
