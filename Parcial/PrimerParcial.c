

#define		( (volatile unsigned int *)0XA0003000 )		PUERTO
#define		( (volatile unsigned int *)0XE0003000 )		DIRECCION

/*Propósito: Establecer un pin de puerto como entrada o salida
Recibe como parámetros número de puerto, numero de pin y dirección (0 entrada, 1 salida)
Retorna 0 por exito o -1 por error (número de puerto mayor que tres, número de pin mayor que 31, dirección diferente de 0 o uno)
*/

int SetDir( unsigned char port , unsigned char pin, unsigned char direccion);
{
	int salida = -1 ;

	if ( port < 4 && pin < 32)
	{
		salida = 0;
		if ( direccion )
			DIRECCION[ port ] = DIRECCION[ port ] | ( 1 << pin) ;
		else
			DIRECCION[ port ] = DIRECCION[ port ] & ~( 1 << pin) ;
	}
}
/*
Propósito: Colocar un cero o un uno en un pin de un puerto;
Recibe como parámetros número de puerto y número de pin
Retorna 0 por éxito o -1 por error (número de puerto mayor que tres o número de pin mayor que 31)
*/
int SetPin( unsigned char port , unsigned char pin , unsigned char estado )
{
	int salida = -1 ;

	if ( port < 4 && pin < 32 )
	{
		salida = 0;
		if ( estado )
			PUERTO[ port ] = PUERTO[ port ] | ( 1 << pin) ;
		else
			PUERTO[ port ] = PUERTO[ port ] & ~( 1 << pin) ;
	}
}

/*
Propósito: Leer el valor de un pin de un puerto;
Recibe como parámetros número de puerto y número de pin
Retorna valor leído  por éxito o -1 por error (número de puerto mayor que tres o número de pin mayor que 31)
*/
int GetPin( unsigned char port , unsigned char pin)
{
	int in = -1 ;
	if ( port < 4 && pin < 32)
		in = ( PUERTO[ port ] >> pin ) & 1 ;
	return in;
}

/*
Realizar una función que reciba un puntero a estructura y cargue en sus campos
el numero de  canal y el valor medido.
En donde la estructura deberá tener el siguiente formato
*/

struct canales
{
	unsigned char canal;
	unsigned int valor;
};

union registro
{
	struct bits
	{
		unsigned int x:11;
		unsigned int c:3;
		unsigned int x:2;
		unsigned int v:12;

	};
	unsigned int REG;
};

#define		(*( (volatile union registro *)0x40005600 ))		ADC

void LecturaDeCanal( struct canales * cn )
{
	cn->canal = ADC.c;
	cn->valor = ADC.v;
}

/*
Realizar una función que reciba un puntero a una strings cargada con
ceros y unos (siempre 8 valores) y un puntero a un unsigned char tal que la convierta
a un número entero y la cargue en lo apuntado por el puntero a unsigned char que
recibió
*/

void convertir (char * origen , unsigned cha Destino )
{
	unsigned int valor  = 0 , i ;

	for ( i = 0 ; i < 8 ; i++ )
		valor = valor + (origen[ i ] - '0') * ( 0x80 >> i)
}

int main ( void )
{

}
