#include <stdio.h>
#include <Triangulo.h>
#include <Analizar.h>
#include <string.h>
#include <Isoceles.h>
void Triangulo(struct Triangulo_Datos *T_D)
{
    printf("Ingrese el lado A: ");
    scanf("%f", &T_D->a);
    printf("Ingrese el lado B: ");
    scanf("%f", &T_D->b);
    printf("Ingrese el lado C: ");
    scanf("%f", &T_D->c);
    int X;
    X = Analizar(T_D->a, T_D->b, T_D->c);
    if (X)
    {
        X = Equilatero(T_D->a, T_D->b, T_D->c);
        if (X)
        {
            strcpy(T_D->tipo, "Equilátero");
            return 1;
        }
        else
        {
            X = Isoceles(T_D->a, T_D->b, T_D->c);
            if (X)
            {
                X = Rectangulo(T_D->a, T_D->b, T_D->c);
                if (X)
                {
                    strcpy(T_D->tipo, "Rectángulo");
                    return 1;
                }
                else
                {
                    strcpy(T_D->tipo, "Isósceles");
                    return 1;
                }
            }
        }
    }
    else
    {
        return 0;
    }
}