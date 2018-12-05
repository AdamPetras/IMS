#include "peceni.h"

     int Vlhceni::Input = 0;

     Peceni::Peceni()
     {
          
     }

     Peceni::~Peceni()
     {

     }

     void Peceni::Behavior()
     {
          double d = Uniform(0,99);
          if(d<50)
          {
               Vlhceni *tmp = new Vlhceni;
               tmp->Input++;
               tmp->Activate();
               Activate(Time+Exponential(45));
          }
          else if(d>=50)
          {
               Mazani *tmp = new Mazani();
               Mazani::Input++;
               tmp->Activate();
               Activate(Time+Exponential(45));
          }
     }
