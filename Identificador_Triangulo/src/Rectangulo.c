#include "Rectangulo.h"


int Rectangulo(int a, int b, int c)
{
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}