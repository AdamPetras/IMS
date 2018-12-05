#pragma once
#include <simlib.h>
#include "utils.h"
#include "spekani.h"

class Sypani : public Process
{
     private:
          /* data */
     public:
     Facility F;
     Sypani(/* args */);
     ~Sypani();
     void Behavior();
};
