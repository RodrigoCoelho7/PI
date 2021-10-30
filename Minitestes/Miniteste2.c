#include<stdio.h>


int perfeito(int n){
    int count = 1;
    for (int i=2; i<n; i++){
        if (n%i == 0) count += i;
    }
    if (count == n) return 1;
    return 0;
}

int sumhtpo (int n, int *count, int *countb){
  int r = 0;
  (*count) = 0;
  (*countb)=0;
  while (n != 1) {
    r += n;
    if (perfeito(n)==1)  (*countb)++;
    (*count)++;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  return r;
}

int main(){
    int a,c=0,d=0,e;
    a = sumhtpo(27,&c,&d);
    printf("%d\n",a);
    printf("%d\n",c);
    printf("%d\n",d);
    return 0;
}