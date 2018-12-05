#include "vlhceni.h"

Facility Vlhceni::Mala("Malá vlhčírna");
Facility Vlhceni::Velka("Velká vlhčírna");
int Vlhceni::Output = 0;
int Vlhceni::Input = 0;

Vlhceni::Vlhceni(/* args */)
{
}

Vlhceni::~Vlhceni()
{
}

void Vlhceni::Behavior()
{
     //std::cout<<"###"<<Vlhceni::Input<<std::endl;
     if(!Velka.Busy())
     {
          if(Vlhceni::Input>=VELKA_KAPACITA)
          {
               std::cout<<"##velká špina"<<Input<<"  "<<Output<<std::endl;
               Seize(Velka);
               Vlhceni::Input-=VELKA_KAPACITA;
               Wait(Utils::normalMinMax(2*24*60*60,7*24*60*60));
               Vlhceni::Output+=VELKA_KAPACITA;
               (new AutoSpekani)->Activate();
               (new Sypani)->Activate();
               Release(Velka);
          }
     }
     else
     {
          if(!Mala.Busy())
          {
               //std::cout<<"##Input"<<Input<<std::endl;
               if(Vlhceni::Input>=MALA_KAPACITA)
               {
                    std::cout<<"##malá špina"<<std::endl;
                    Seize(Mala);
                    Vlhceni::Input-=MALA_KAPACITA;
                    Wait(Utils::normalMinMax(2*24*60*60,7*24*60*60));
                    Vlhceni::Output+=MALA_KAPACITA;
                    (new AutoSpekani)->Activate();
                    (new Sypani)->Activate();
                    Release(Mala);
               }
          }
     }
}
