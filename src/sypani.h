#pragma once
#include <simlib.h>
#include "utils.h"
#include "spekani.h"

class Sypani : public Process
{
     private:
          /* data */
     public:
     Facility F = Facility("Sypanie");
     Sypani(/* args */);
     ~Sypani();
     void Behavior();
};
