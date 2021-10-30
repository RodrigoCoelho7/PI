#include<stdio.h>
#include <string.h>
#include <math.h>

void printArray(int v[], int N){
    int i;
    for (i=0;i<N;i++)
        printf("%d,",v[i]);
}

void swap(int v[],int i, int j){
    int z;
    z = v[i];
    v[i] = v[j];
    v[j] = z;
}

int bubble(int y[], int N,int *c){
    int i,troca=0;
    int z;
    for (i=1;i<N;i++)
        if(y[i]<y[i-1]){
            swap(y,i,i-1);
            troca=1;
            (*c)++;
        }
    return troca;
}

void ordena (int y[], int N){
    int troca = 1,c=0;
    while (troca){
        troca = bubble(y,N,&c);
    }
    printf("\n\n O numero de swaps e %d\n",c);
}

int sumhtpo (int n,int *size){
  int r = 0,u=0;
  while (n != 1) {
    (*size)++;
    printf("%d\n",n);
    r += n;
    if (n%2 == 0) n = n/2;
    else
        n = 1+(3*n);
  }
  return r;
}

int sumhtpov2 (int n,int y[]){
  int r = 0,u=0;
  while (n != 1) {
    y[u] = n;
    r += n;
    u++;
    if (n%2 == 0) n = n/2;
    else
        n = 1+(3*n);
  }
  return r;
}

int sumhtpov3 (int n,int *size,int y[]){
  int r = 0,u=0;
  while (n != 1) {
    y[(*size)] = n;
    (*size)++;
    r += n;
    if (n%2 == 0) n = n/2;
    else
        n = 1+(3*n);
  }
  return r;
}

int main(){
    /*int size=0;
    int a = sumhtpo(97,&size);
    printf("\n\n\n%d,%d\n\n",a,size);
    int y [size];
    sumhtpov2(97,y);
    printArray(y,size);
    //int lista [] = {97,292,146,73,220,110,55,166,83,250,125,376,188,94,47,142,71,214,107,322,161,484,242,121,364,182,91,274,137,412,206,103,310,155,466,233,700,350,175,526,263,790,395,1186,593,1780,890,445,1336,668,334,167,502,251,754,377,1132,566,283,850,425,1276,638,319,958,479,1438,719,2158,1079,3238,1619,4858,2429,7288,3644,1822,911,2734,1367,4102,2051,6154,3077,9232,4616,2308,1154,577,1732,866,433,1300,650,325,976,488,244,122,61,184,92,46,23,70,35,106,53,160,80,40,20,10,5,16,8,4,2};
    ordena (y,size);
    printArray(y,size);
    */
    int size = 0;
    int y[200];
    sumhtpov3(97,&size,y);
    ordena(y,size);
    printArray(y,size);

    return 0;
}