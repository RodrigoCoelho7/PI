#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct slist {
  int valor;
  struct slist * prox;
} *LInt;

LInt newLInt (int x, LInt xs) {
  LInt r = malloc (sizeof(struct slist));
  if (r!=NULL) {
    r->valor = x;
    r->prox = xs;
  }
  return r;
}

LInt last (LInt l) {
  LInt a = l;
  while (l) {
    if (!l->prox) a = l;
    l = l->prox;
  }
  return a;
}


int main(){

    return 0;
}