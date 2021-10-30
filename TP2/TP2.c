#include<stdio.h>

// Exercício 1

float multInt1(int n, float m){
    int i;
    float r;
    for (i=0;i<n;i++)
        r+=m;
    return r;
}

float multInt1v2(int n, float m){
    float r;
    while(n){
        r+=m;
        n--;
    }
    return r;
}

float multInt2 (int n, float m){
    int resultado=0;
    while (n){
        if (n%2!=0)
            resultado += m;
        n /= 2;
        m *= 2;
    }
    printf("%d\n",resultado);
    return resultado;
}

float multInt3 (int n, float m, int *count){
    int resultado=0;
    while (n){
        if (n%2!=0)
            resultado += m;
        n /= 2;
        m *= 2;
        (*count) ++;
    }
    printf("%d\n",resultado);
    return resultado;
}

int mdc1 (int a, int b){
    int menor,maior,r=0;
    if (a<=b)
        menor = a;
    else
        menor = b;

    while (menor){
        if (a%menor==0 && b%menor==0){
        r = menor;
        menor = 0;
    }
    else
        menor--;
    }
    printf("%d",r);
    return r;
}

int mdc2 (int a, int b){
    while(a!=0 && b!=0){
        if (a<b)  b-=a;
        else      a-=b;
    }
    printf("%d",(a+b));
    return (a+b);
}

int mdc3 (int a, int b, int *count){
    (*count) = 0;
    while(a!=0 && b!=0){
        if (a<b)  b-=a;
        else      a-=b;
        (*count)++;
    }
    printf("%d\n",(a+b));
    return (a+b);
}

int mdc4 (int a, int b, int *count){
    (*count) = 0;
    while(a!=0 && b!=0){
        if (a<b)  b%=a;
        else      a%=b;
        (*count)++;
    }
    printf("%d\n",(a+b));
    return (a+b);
}

int fib (int n){
    int r;
    if (n<2)
        r = 1;
    else
        r = fib(n-1) + fib(n-2);
    return r;
}

int fastfib (int n){

  int ac1 = 1, ac2 = 1, tmp;

  while(n>1){
    tmp = ac1;
    ac1 = ac2;
    ac2 += tmp;
    n--;
  }
  return ac2;
}




int main(){
    int c = 0;
    //multInt2(21,4);
    //multInt3(12,4,&c);
    //printf("%d",c);
    //mdc2(8,12);
    //mdc3(8,12,&c);
    //mdc4(8,12,&c);
    //printf("%d",c);
    int y = fib(5);
    printf("%d",y);
    return 0;
}

