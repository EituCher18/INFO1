void convertir(char * origen, int *destino)
{ for(char I=0; I<=8; I++) // Comentario agregado
    {
       if (origen[I]=='0')
       (destino | (1<<I));
       if (origen[I]=='1')
       (destino & ~(1<<I));
    }
    // Código para convertir unidades
}
