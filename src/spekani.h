#pragma once
#include <simlib.h>
#include "utils.h"
#include "vazeni.h"

class Spekani : public Process
{
     private:
     public:
          static Facility F;
          static int Input;
          Spekani(/* args */);
          ~Spekani();
          void Behavior();
};