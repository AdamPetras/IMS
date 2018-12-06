#pragma once
#include <simlib.h>
#include "vazeni.h"
#include "vazeni.h"
#include "vlhceni.h"
#include "globals.h"

class AutoSpekani : public Process
{
   private:
     double d;

   public:
     static Facility F;
     static Stat Fstat;
     static Histogram Fhist;
     static double Sumtime;
     static bool IsRunning;
     AutoSpekani(/* args */);
     ~AutoSpekani();
     void Behavior();
};