#pragma once
#include <simlib.h>

class Vlhceni:public Process
{
private:
     Facility Velka = Facility("Velka vlhcirna");
     Facility Mala = Facility("Mala vlhcirna");
public:
     static int Input;
     Vlhceni(/* args */);
     ~Vlhceni();
     void Behavior();
};