#pragma once
#include <simlib.h>
#include "utils.h"
#include "spekani.h"
#include "vlhceni.h"

class Sypani : public Process
{
     private:
          /* data */
     public:
     static Facility F;
     Sypani(/* args */);
     ~Sypani();
     void Behavior();
};
