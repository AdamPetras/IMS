#include "peceni.h"

     Peceni::Peceni()
     {
          
     }

     Peceni::~Peceni()
     {

     }

     void Peceni::Behavior()
     {
          double d = Uniform(0,99);
          if(d<65)
          {
               Vlhceni *tmp = new Vlhceni;
               Vlhceni::Input++;
               tmp->Activate();
               Activate(Time+1);
          }
          else if(d>=65)
          {
               Mazani *tmp = new Mazani();
               Mazani::Input++;
               tmp->Activate();
               Activate(Time+1);
          }
     }
