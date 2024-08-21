#include <stdio.h>

int funcp(int);
int funcpaux(int,int);
int main(){
    int r = funcp(5);
    printf("%d\n", r);
}
int funcp(int n){
    return funcpaux(n,1);
}
int funcpaux(int n,int x){
    if(n == 0){
        return x;
    }
    funcpaux(n-1, x*n);
}