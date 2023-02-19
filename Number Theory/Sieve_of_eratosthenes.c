#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define sz 101

bool siv[sz];
int primes[sz];


void sieve()
{
    int limit=sqrt(sz+1)+1, i, j, cnt=0;

    for (i=3; i<limit; i+=2) {
        if (siv[i]) continue;
        for (j=i*i; j<sz; j+=i+i) siv[j]=true;
    }
    primes[cnt++]=2;
    for (i=3; i<sz; i+=2) if (!siv[i]) primes[cnt++]=i;
    printf("Number of primes = %d\n", cnt);

    for (i=0; i<cnt; i++) printf("%d ", primes[i]);
    puts("");
}

int main()
{
    sieve();
    return 0;
}
