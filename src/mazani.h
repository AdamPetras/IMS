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
          static int Sumtime1;
          static int Sumtime2;
          static int Input;
          Mazani(/* args */);
          ~Mazani();
          void Behavior();
};
