/*
a) Execute o algoritmo em modo de depuração.
b) Descubra através da depuração, qual a maior profundidade de (frames) esse código alcançar.
c) Descubra o que ocorre quando um parâmetro e 0.
d) Descubra o que ocorre quando os dois parâmetros apresentados são iguais e maiores que 1.
*/
#include<stdio.h>

// Funcao para calcular algo
int operacaoMatematica (int a , int b ) {
    int r ;
    while ( b != 0) {
        r = a % b ;
        a = b ;
        b = r ;
    }
    return a ;
    }
    int main () {
    int num1 , num2 ;
    printf (" Digite o primeiro numero : ") ;
    scanf ("%d", & num1 ) ;
    printf (" Digite o segundo numero : ") ;
    scanf ("%d", & num2 ) ;
    int res = operacaoMatematica ( num1 , num2 ) ;
    printf ("A operacao de %d e %d e: %d\n", num1 , num2 , res ) ;
    return 0;
    }