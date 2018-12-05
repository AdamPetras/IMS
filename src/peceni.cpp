#include "peceni.h"

     Peceni::Peceni(double time)
     {
          this->_time = time;
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
               tmp->Activate();
               Activate(Time+Exponential(45));
               tmp->Input++;
          }
          else if(d>=50)
          {
               Mazani *tmp = new Mazani();
               tmp->Activate();
               Activate(Time+Exponential(45));
               tmp->Input++;
          }
          Activate(this->_time);
     }
