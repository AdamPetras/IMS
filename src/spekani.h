#pragma once
#include <simlib.h>
#include "utils.h"
#include "vazeni.h"

class Spekani : public Process
{
     private:
     public:
          Facility F;
          Spekani(/* args */);
          ~Spekani();
          void Behavior();
};