#include<stdio.h>

//-------------Exercício 1------------------

float multInt1 (int n, float m){
    float r=0;
    while (n){
        r +=m;
        n--;
    }
    return r;
}

// Ou

float multInt1v2(int n, float m){
    float r=0;
    int i;
    for(i=0;i<n;i++)
        r +=m;
    return r;
}

//--------------------------------------------------------


//------------------------Exercício 2-------------------------

float multInt2(int n,float m){
    float r=0;
    while(n){
        if (n%2!=0)
            r+=m;
        n=n/2;
        m=m*2;
    }
    return r;
}

float multInt2V2(int n,float m,int *count){
    float r=0;
    while(n){
        if (n%2!=0)
            r+=m;
        n=n/2;
        m=m*2;
        (*count)++;
    }
    printf("%d\n",*count);
    return r;
}

//--------------------------------------------------------


//---------------Exercício 3---------------------------

int mdc1 (int a, int b){
    int r,i,menor;

    if (a<b)
        menor=a;
    else
        menor=b;
    
    for(i=menor;i>0;i--){
        if (a%i==0 && b%i==0){
            r = i;
            i=0;
        }
        }

    return r;
}

//Ou

int mdc1v2 (int a, int b){
    int r,i,menor;

    if (a<b)
        menor=a;
    else
        menor=b;
    
    while(menor){
        if (a%menor==0 && b%menor==0){
            r = menor;
            menor=0;
        }
        else
            menor--;
        }

    return r;
}

//------------------------------------------------------------------

//--------------Exercício 4-------------------------------------------

int mdc2 (int a, int b){
    int r;
    while(a && b){
        if (a>b)
            a -=b;
        else
            b -=a;
    }

    r = a+b;
    return r;
}

int mdc3 (int a, int b, int *count){
    (*count) = 0;
    while(a!=0 && b!=0){
        if (a<b)  b-=a;
        else      a-=b;
        (*count)++;
    }
    printf("%d\n",*count);
    return (a+b);
}

//------------------------------------------------------------


//------------------Exercicio 5-----------------------------------

int mdc4 (int a, int b,int *count){
    int r;
    while(a && b){
        if (a>b)
            a %=b;
        else
            b %=a;
        (*count)++;
    }
    printf("%d\n",*count);
    r = a+b;
    return r;
}

//---------------------------------------------


//---------------------Exercicio 6----------------

int fib1 (int n){
    int r;
    if (n<2)
        r = 1;
    else
        r = fib1(n-1) + fib1(n-2);
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

    /*Exercício 1-----------------
    float a = multInt1v2(5,7);
    printf("%f",a);
    //---------------------------*/

    /*Exercício 2--------------------
    int c=0;
    float b = multInt2V2(777,128,&c);
    printf("%f",b);
    --------------------------------*/

    /*Exercício 3--------------------
    int b = mdc1v2(35,15);
    printf("%d",b);
    //--------------------------------*/

    /*Exercício 4--------------------
    int c=0;
    int b = mdc3(177,19,&c);
    printf("%d",b);
    //--------------------------------*/

    /*Exercício 5--------------------
    int c=0;
    int b = mdc4(126,45,&c);
    printf("%d",b);
    //--------------------------------*/

    //Exercício 5--------------------
    int b = fastfib(10);
    printf("%d",b);
    //--------------------------------


    return 0;
}