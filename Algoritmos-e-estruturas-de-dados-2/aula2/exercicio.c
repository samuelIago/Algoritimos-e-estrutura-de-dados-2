/*Considere os seguintes tempos para o algoritmo abaixo:
    Chamada Recursiva: 2ns
    Retorno de chamada recursiva: 1ns
    Atrinuição e soma: 0.5ns
    Divisão e multiplicação: 1.5ns
*/
#include <stdio.h>

int f(int n) {
    if (n == 0) {
        return 1;
    }
    return f(n-1) + 1/f(n-1);
}

int main(){
    f(20);
}

/*Modifique o codigo e/ou use o GDB para calcular os tempos desse algoritmos para n = 30*/