// 線上編譯： https://goo.gl/cQdoqZ 2016.10.14 by LiYu

#include <stdio.h>
int isprime(long int);

int main(){
    long int x=300320077;
    int s=isprime(x);
    if(s==0)
        printf("\n%d is not a prime number\n",x);
    else
        printf("\n%d is a prime number\n",x);

    return 0;
}

int isprime(long int m){
    if (m <= 1) return 0;
    if (m % 2 == 0 && m > 2) return 0;
    for(int i = 3; i < m / 2; i+= 2){
        if (m % i == 0)
        return 0;
    }
    return 1;
}
