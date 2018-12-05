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
          Facility F = Facility("Baleni");
          Baleni(/* args */);
          ~Baleni();
          void Behavior();
};