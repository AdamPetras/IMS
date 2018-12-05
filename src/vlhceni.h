#pragma once
#include <simlib.h>

class Vlhceni:public Process
{
private:
     Facility Velka;
     Facility Mala;
public:
     static int Input;
     Vlhceni(/* args */);
     ~Vlhceni();
     void Behavior();
};