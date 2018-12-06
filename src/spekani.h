#pragma once
#include <simlib.h>
#include "vazeni.h"
#include "globals.h"

class Spekani : public Process
{
public:
  static Facility F;
  static int Input;
  static Stat Fstat;
  static Histogram Fhist;
  static double Sumtime;
  Spekani(/* args */);
  ~Spekani();
  void Behavior();
};