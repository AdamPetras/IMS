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
          if(d<75)
          {
               Vlhceni *tmp = new Vlhceni;
               Vlhceni::Input++;
               tmp->Activate();
               Activate(Time+5);
          }
          else if(d>=75)
          {
               Mazani *tmp = new Mazani();
               Mazani::Input++;
               tmp->Activate();
               Activate(Time+5);
          }
     }
