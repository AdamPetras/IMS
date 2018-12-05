#include "mazani.h"
int Mazani::Input = 0;
Mazani::Mazani(/* args */)
{
     Input = 0;
}

Mazani::~Mazani()
{
}

void Mazani::Behavior()
{
     
     double d = Uniform(0,99);
     Orezavani *tmp = new Orezavani;
     if(d<50)
     {
          Seize(first);
          if(Input < 2)
          {
               Release(first);
               std::cerr<<"Mazani potřebuje 2 korpusy"<<std::endl;
               return;
          }
          Wait(Exponential(5));
          Input-=2;
          Release(first);
     }
     else if(d>=50)
     {
          Seize(second);
          if(Input < 2)
          {
               Release(second);
               std::cerr<<"Mazani potřebuje 2 korpusy"<<std::endl;
               return;
          }
          Wait(Exponential(5));
          Input-=2;
          Release(second);
     }
     tmp->Input++;
     tmp->Activate();
}
