#pragma once
#include <simlib.h>
#include "utils.h"
#include "auto_spekani.h"
#include "sypani.h"
class Vlhceni:public Process
{
private:
     static Facility Velka;
     static Facility Mala;
     const int MALA_KAPACITA = 26900;
     static int aktualni_mala;
     static int aktualni_velka;
     const int VELKA_KAPACITA = 40800;
public:
     static int Input;
     static Store Output;
     Vlhceni(/* args */);
     ~Vlhceni();
     void Behavior();
};