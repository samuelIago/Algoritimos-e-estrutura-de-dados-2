/*7 No calend´ario gregoriano, geralmente um ano X ´e bissexto se o ano (x-4) tamb´em foi. Este pode
ser uma etapa para calcular o algoritmo recursivo para um ano bissexto, mas n˜ao est´a correto por
completo. Explique o porquˆe e apresente uma solu¸c˜ao*/
#include<stdio.h>

int bissexto(int);
int main () {
    int ano = 2023;
    if (bissexto(ano) == 1){
        printf("Bissexto");
    }else{
        printf("nao bissexto");
    }
}

int bissexto(int ano){
    if(ano%4 == 0 && ano %100 == 0){
        if(ano%400 ==0){
            return 1;
        }
    }
    if (ano %4 == 0)
    {
        return 1;
    }
    
}
