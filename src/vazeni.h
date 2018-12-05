#pragma once
#include <simlib.h>
#include <iostream>
#include "utils.h"
#include "baleni.h"

class Vazeni : public Process
{
   private:
     double d;
     bool Fspekani = false;

   public:
     static Facility F;
     static int InputSpekani;
     static int InputOrezavani;
     Vazeni(/* args */);
     ~Vazeni();
     void Behavior();
};