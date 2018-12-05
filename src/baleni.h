#pragma once
#include <simlib.h>
#include <iostream>
#include "utils.h"

class Baleni : public Process
{
     private:
          /* data */
     public:
          static int Input;
          static Facility F;
          Baleni(/* args */);
          ~Baleni();
          void Behavior();
};