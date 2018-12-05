#pragma once
#include <simlib.h>
#include "mazani.h"
#include "orezavani.h"
#include <iostream>

class Mazani:public Process
{
     private:
          Facility first = Facility("Mazani 1");
          Facility second = Facility("Mazani 2");
     public:
          static int Input;
          Mazani(/* args */);
          ~Mazani();
          void Behavior();
};
