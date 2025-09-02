#include <stdio.h>
#include <Triangulo.h>
int main ()
{
    struct Triangulo_Datos T_D;
    Triangulo(&T_D);
    printf("El triángulo es: %s\n", T_D.tipo);
    return 0;
}

