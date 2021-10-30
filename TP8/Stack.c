#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack (Stack *s){
    *s = NULL; 
}

int SisEmpty (Stack s){
    return (s==NULL);
}

int push (Stack *s, int x){
    int r = 1;
    *s = newLInt(x,*s);
    if (*s)
        r = 0;  //sucesso
    return r;
}

int pop (Stack *s, int *x){
    int r = 1;
    if (!SisEmpty(*s)){
        Lint aux = *s;
        *x = (*s)->valor;
        *s = aux->prox;
        free(aux);
        r = 0;  //sucesso
    }
    return 1;
}

int top (Stack s, int *x){
    int r = 1;
    if (!SisEmpty(s)){
        *x = s->valor;
        r = 0;
    }
    return r;
}
