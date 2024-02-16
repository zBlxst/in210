#include "ratp.h"

static const float Price = 1.2;
float computePrice(int age, int tourist)
{
    int limite_age;
    recupAge(&limite_age);
    if (age>limite_age)
    {
        if (tourist)
            return Price*2;
        return Price;
    }
    else 
    {
        if (tourist)
            return Price;
        return Price/2;
    }
}
