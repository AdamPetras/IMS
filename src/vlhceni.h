#pragma once
#include <simlib.h>

class Vlhceni:public Process
{
private:
     static Facility Velka;
     static Facility Mala;
public:
     static int Input;
     Vlhceni(/* args */);
     ~Vlhceni();
     void Behavior();
};