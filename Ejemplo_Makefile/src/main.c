#include <suma.h>
#include <stdio.h>
int main ()
{ int a, b, r;

    printf("Introduce el primer numero: ");
    scanf("%d", &a);
    printf("Introduce el segundo numero: ");
    scanf("%d", &b);
    r = suma(a, b);
    printf("La suma es %d\n", r);
    return 0;

}