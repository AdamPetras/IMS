#pragma once
#include <simlib.h>
#include <iostream>
#include "vazeni.h"
#include "utils.h"

class Orezavani:public Process
{
     private:
          static Facility orezavani;
          
     public:
          static int Sumtime;
          static Stat Fstat;
          static int Input;
          void Behavior();
          Orezavani(/* args */);
          ~Orezavani();
};
