#include<stdio.h>
#include <math.h> 

// Exercício1
void ex1(){
    int x,y;
    x = 3;
    y= x+1;
    x = x*y;
    y = x + y;
    printf("%d  %d",x,y);
}

//Exercicio 2

void ex2(){
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);
}

//Exercício 3

void ex3(){
    char a, b, c;
    a = 'A'; b = ' '; c = '0';
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);
}

//Exercicio 4


void ex4(){
    int x, y;
    x = 200; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf ("%d %d\n", x, y);
}


//------- 2- Estruturas de Controlo -------

// Alínea 1

void ex2_1(){
    int x, y;
    x = 3; y = 5;
    if (x > y)
        y = 6;
    printf ("%d %d\n", x, y);
}

// Alínea 2

void ex2_2(){
    int x, y;
    x = y = 0;
    while (x != 11) {
        x++; y += x;
        }
    printf ("%d %d\n", x, y);
}

// Alínea 3

void ex2_3(){
    int i;
    for (i=0; (i<20) ; i++)
        if (i%2 == 0) putchar ('_');
        else putchar ('#');
}

// Alínea 4

/*
void f (int n) {
    while (n>0) {
        if (n%2 == 0) putchar ('0');
        else putchar ('1');
        n = n/2;
    }
    putchar ('\n');
}

int main () {
    int i;
    for (i=0;i<16;i++)
    f (i);
    return 0;
}
*/

// ------- Programas Iterativos --------

//Exercício 1

void ex3_1(int n){
    int i,j;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            putchar('#');
        }
        putchar('\n');
    }
}

//Exercicio 2

/*
int main(){
    int i,j;
    int n;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            if (j%2==0){
                if (i%2==0)
                    putchar('#');
                else
                    putchar('_');
            }
            else{
                if (i%2==0)
                    putchar('_');
                else
                    putchar('#');
            }
    }
    putchar('\n');
    }
    return 0;
}
*/


void ex3_2(int n){
    int i,j;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            if ((i+j)%2==0)
                putchar('#');
            else
                putchar('_');
    }
    putchar('\n');
    }
}


// Exercício 3

void vertical(int a){
    int i,j;
    for (i=1;i<=a;i++){
        for (j=0;j<i;j++){
            putchar('#');
        }
        putchar('\n');
    } 
    for (i=a-1;i>0;i--){
        for (j=0;j<i;j++){
            putchar('#');
        }
        putchar('\n');
    }
}

void verticalv2(int a){
    int i,j;
    for (i=1;i<2*a;i++){
        if (i<=a){
            for (j=0;j<i;j++)
                putchar('#');
        }
        else{
            for (j=2*a;j>i;j--)
                putchar('#');
        }
        putchar('\n');
    }
}

void horizontal(int a){
    int i,j;
    for (i=1;i<=a;i++){
        for (j=1;j<2*a;j++){
            if (j <a+i && j > a-i)
                putchar('#');
            else
                putchar(' ');
        }
    putchar('\n');
    }
}

void circulo(int r){
    int c1=r,
        c2=r,
        i,j,contador=0;

    for (i=0;i<r*2+1;i++){
        for (j=0;j<r*2+1;j++){
            if ((j-c1)*(j-c1)+(i-c2)*(i-c2)<=r*r){
                putchar('#');
                contador+=1;
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    printf("%d",contador);
}


int main(){
    //ex1();
    //ex2();
    //ex3();
    //ex4();

    //ex2_1();
    //ex2_2();
    //ex2_3();


    int dim;
    scanf("%d",&dim);
    //ex3_1(dim);

    //ex3_2(dim);

    //vertical(dim);
    //verticalv2(dim);

    horizontal(dim);

    //circulo(dim);
    return 0;
}
/*

int main(){
    int x = 1;

    while(x!=0)
        x++;
    
    printf("%d",x);

    return 0;

}

//Esta função acaba por dar return a 0, porque ocorre overflow

/*
int main(){
    int x = 1;

    while(x>0)
        x++;
    x--;
    
    printf("%d",x);

    return 0;

}
*/