#pragma once
#include <simlib.h>
#include <iostream>
#include "vazeni.h"
#include "utils.h"

class Orezavani:public Process
{
     private:
          Facility orezavani = Facility("Orezavani");
     public:
          static int Input;
          void Behavior();
          Orezavani(/* args */);
          ~Orezavani();
};
