#include "vlhceni.h"

Facility Vlhceni::Mala("Malá vlhčírna");
Facility Vlhceni::Velka("Velká vlhčírna");
int Vlhceni::Output = 0;
int Vlhceni::Input = 0;
Stat Vlhceni::FstatMala("Mala vlhcirna");
Stat Vlhceni::FstatVelka("Velka vlhcirna");
int Vlhceni::SumtimeMala = 0;
int Vlhceni::SumtimeVelka = 0;
bool Vlhceni::IsTimeSaved = false;
int Vlhceni::SavedTime = 0;

Vlhceni::Vlhceni(/* args */)
{
}

Vlhceni::~Vlhceni()
{
}

void Vlhceni::Behavior()
{
     //std::cout<<"###"<<Vlhceni::Input<<std::endl;
     double t;
     if(!Velka.Busy())
     {
          if(Vlhceni::Input>=VELKA_KAPACITA)
          {
               Seize(Velka);
               t = Time;
               Vlhceni::Input-=VELKA_KAPACITA;
               Wait(Uniform(1*24*60*60,2*24*60*60));
               Vlhceni::Output+=VELKA_KAPACITA;
               if(!AutoSpekani::IsRunning)
                    (new AutoSpekani)->Activate();
               if(!Sypani::IsRunning)
                    (new Sypani)->Activate();
               t = Time-t;
               FstatVelka(t);
               SumtimeVelka += t;
               if(!IsTimeSaved)
               {
                    SavedTime = Time;
                    IsTimeSaved = true;
               }
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
                    Seize(Mala);
                    t = Time;
                    Vlhceni::Input-=MALA_KAPACITA;
                    Wait(Uniform(1*24*60*60,2*24*60*60));
                    Vlhceni::Output+=MALA_KAPACITA;
                         if(!AutoSpekani::IsRunning)
                    (new AutoSpekani)->Activate();
                         if(!Sypani::IsRunning)
                    (new Sypani)->Activate();
                    t = Time-t;
                    FstatMala(t);
                    SumtimeMala += t;
                    if(!IsTimeSaved)
                    {
                         SavedTime = Time;
                         IsTimeSaved = true;
                    }
                    Release(Mala);
               }
          }
     }
}
