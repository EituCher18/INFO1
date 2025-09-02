#include "Isoceles.h"
#include "Triangulo.h"
#include <string.h>

int Isoceles(int a, int b, int c)
{
    if (a == b || b == c || a == c)

        return 1;
    else
        return 0;
}