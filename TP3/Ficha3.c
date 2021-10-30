#include<stdio.h>


void swapM(int *x,int *y){
    int z;
    z=*x;
    *x=*y;
    *y=z;
}

void swap(int v[],int i, int j){
    int z;
    z = v[i];
    v[i] = v[j];
    v[j] = z;
}

void swapV2(int v[],int i, int j){
    swapM(v+i,v+j);
    //swapM(&v[i],&v[j]);
}

int soma(int v[], int N){
    int sum = 0,i=0;
    while (i<N){
        sum +=v[i];
        i++;
    }
    //for (i=0;i<N;res+=v[i],i++);
    return sum;
}

void printArray(int v[], int N){
    int i;
    for (i=0;i<N;i++)
        printf("%d,",v[i]);
}

void inverteArray(int v[], int N){
    int i;
    for(i=0;i<N/2;i++)
        swapM(v+i,v+(N-1-i));
    printArray(v,10);
}

int maximum(int v[],int N, int *m){
    int maior=v[0],i,r=-1;
    if (N>0){
        r=0;
        for (i=0;i<N;i++)
            if (v[i]>v[0])
                maior = v[i];
        *m = maior;
    }
    return r;
}



int main() {
    int x = 3, y = 5;
    int v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
    /*printf("%d %d\n",x,y);
    swapM (&x, &y);
    printf ("%d %d\n", x, y);
    */
    //printf("%d %d\n",v[0],v[9]);
    //swap (v,0,9);
    //printf ("%d %d\n", v[0], v[9]);

    /*Usando a função swapM
    swapV2 (v,0,9);
    printf ("%d %d\n", v[0], v[9]);
    */
   /*int a;
   a = soma(v,10);
   printf("A soma dos elementos do array e %d",a);
   */

   // inverteArray(v,10);
    int z,f;
    z = maximum (v,10, &f);
    printf ("O maior elemento de ");
    printArray(v,10);
    printf ("e %d\n", f);


    
    return 0;
}