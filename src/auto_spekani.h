#pragma once
#include <simlib.h>
#include "vazeni.h"
#include "vazeni.h"
#include "vlhceni.h"

class AutoSpekani : public Process
{
   private:
     double d;

   public:
     static Facility F;
     static Stat Fstat;
     static double Sumtime;
     AutoSpekani(/* args */);
     ~AutoSpekani();
     void Behavior();
};