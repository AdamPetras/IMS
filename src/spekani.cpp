#include "spekani.h"

Spekani::Spekani(/* args */)
{
}

Spekani::~Spekani()
{
}

void Spekani::Behavior(){
     Seize(F);
     Wait(45);
     Release(F);
     Vazeni V = Vazeni();
     (new Vazeni())->Activate();
}