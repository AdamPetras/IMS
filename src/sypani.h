#pragma once
#include <simlib.h>
#include "spekani.h"
#include "vlhceni.h"

class Sypani : public Process
{
     public:
     static bool IsRunning;
     static Facility F;
     static Stat Fstat;
     static Histogram Fhist;
     static double Sumtime;
     Sypani(/* args */);
     ~Sypani();
     void Behavior();
};
