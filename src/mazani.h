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
          static int Input;
          Mazani(/* args */);
          ~Mazani();
          void Behavior();
};
