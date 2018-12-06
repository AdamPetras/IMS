#pragma once
#include <simlib.h>
#include <iostream>

class Baleni : public Process
{
   private:
     /* data */
   public:
     static int Input;
     static Facility F;
     static Stat Fstat;
     static Histogram Fhist;
     static double Sumtime;
     Baleni(/* args */);
     ~Baleni();
     void Behavior();
};