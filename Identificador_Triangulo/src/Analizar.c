#include <Analizar.h>
#include <stdio.h>

int Analizar(int a, int b, int c) {
    if (a+b<c || a+c<b || b+c<a) 
        return 1;  // No es un triángulo
  else 
  return 0;
}
