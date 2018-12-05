#pragma once
#include <simlib.h>
#include "vazeni.h"
#include "utils.h"
#include "vazeni.h"
#include "vlhceni.h"

class AutoSpekani : public Process
{
   private:
     double d;

   public:
     static Facility F;
     AutoSpekani(/* args */);
     ~AutoSpekani();
     void Behavior();
};