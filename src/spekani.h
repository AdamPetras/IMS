#pragma once
#include <simlib.h>
#include "vazeni.h"

class Spekani : public Process
{
   private:
   public:
     static Facility F;
     static int Input;
     static Stat Fstat;
     static double Sumtime;
     Spekani(/* args */);
     ~Spekani();
     void Behavior();
};