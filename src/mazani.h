#pragma once
#include <simlib.h>
#include "mazani.h"
#include "orezavani.h"
#include <iostream>

class Mazani:public Process
{
     private:
          static Facility first;
          static Facility second;
     public:
          static Stat Fstat1;
          static Stat Fstat2;
          static Histogram Fhist;
          static int Sumtime;
          static int Input;
          Mazani(/* args */);
          ~Mazani();
          void Behavior();
};
