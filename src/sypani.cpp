#include "sypani.h"

Sypani::Sypani(/* args */)
{
}

Sypani::~Sypani()
{
}

void Sypani::Behavior(){
     Seize(F);
     Wait(Utils::normalMinMax(4, 15));
     Release(F);
     (new Spekani())->Activate();
}