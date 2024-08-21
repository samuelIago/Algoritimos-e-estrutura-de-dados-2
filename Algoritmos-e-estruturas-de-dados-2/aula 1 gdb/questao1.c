/*
a) Depure o código para descobrir quantas vezes o fibonacci(5) é calculado (requisitado). 89
b) Descubra através da depuração, qual a maior quantidade de níveis (frames) esse código alcançar. é no 1 pq ele vai ir pro 2 dps 3 dps 4 etc 15 frames
c) Depure o código até o momento que o primeiro fibonacci(14) é calculado e o executável irá começar
a calcular o fibonacci(15).
*/

#include <stdio.h>
int fibonacci (int n) {
    if (n <= 1) {
        return n;
    }else {
        return fibonacci(n - 1) + fibonacci (n - 2);
    }
}

int main () {
    fibonacci(15);
}