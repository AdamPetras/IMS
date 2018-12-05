#include "utils.h"

double Utils::normalMinMax(double min, double max)
{
    double mi = max - min;
    double sigma = (max - mi) / 6;
    return Normal(mi, sigma);
}