#pragma once
#include <simlib.h>
#include <iostream>
#include "globals.h"

class Baleni : public Process
{
   private:
     /* data */
   public:
     static int Input;
     static int Output;
     static Facility F;
     static Stat Fstat;
     static Histogram Fhist;
     static double Sumtime;
     Baleni(/* args */);
     ~Baleni();
     void Behavior();
};