#include "vlhceni.h"

Facility Vlhceni::Mala("Malá vlhčírna");
Facility Vlhceni::Velka("Velká vlhčírna");
int Vlhceni::aktualni_mala = 0;
int Vlhceni::aktualni_velka = 0;
Store Vlhceni::Output;
Vlhceni::Vlhceni(/* args */)
{
}

Vlhceni::~Vlhceni()
{
}

void Vlhceni::Behavior()
{
     if(!Velka.Busy())
     {
          Seize(Velka);
          Release(Velka);
          aktualni_velka++;
          if(aktualni_velka==VELKA_KAPACITA)
          {
               Seize(Velka);
               Wait(Utils::normalMinMax(2*24*60*60,7*24*60*60));
               Leave(Output,40800);
               Release(Velka);
          }
          (new AutoSpekani)->Activate();
          (new Sypani)->Activate();
     }
     else if(!Mala.Busy())
     {
          Seize(Mala);
          Release(Mala);
          aktualni_mala++;
          if(aktualni_mala == MALA_KAPACITA)
          {
               Seize(Mala);
               Wait(Utils::normalMinMax(2*24*60*60,7*24*60*60));
               Leave(Output,26900);
               Release(Mala);
          }
          (new AutoSpekani)->Activate();
          (new Sypani)->Activate();
     }
     else
     {
          //ERROR
          return;
     }
}
