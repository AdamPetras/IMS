#pragma once
#include <simlib.h>
#include "vlhceni.h"
#include "mazani.h"
class Peceni : public Event
{
     private:
           double _time;
     public:
          Peceni(double);
          ~Peceni();
          void Behavior();
};
