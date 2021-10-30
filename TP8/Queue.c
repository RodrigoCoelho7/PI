#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue (Queue *q){
    q->inicio = q->fim = NULL;
}

int QisEmpty (Queue q){
    return (q.inicio == NULL);
}

int enqueue (Queue *q, int x){
    int r = 1;
    LInt novo = newLInt(x,NULL);
    if (q->fim==NULL){
        q->inicio = q->fim = novo;
    }
    else{
        q->fim->prox = novo;
        q->fim = novo;
    }
    if (novo)   r = 0;
    
    return r;
}

int dequeue (Queue *q, int *x){
    int r = 1;
    if (!QisEmpty(*q)){
        LInt aux = q->inicio;
        *x = q->inicio->valor;
        q->inicio = aux->prox;
        free(aux);
        r = 0;  //sucesso
    }
    return r;
}

int frontQ (Queue q, int *x){
    int r = 1;
    if (!QisEmpty(q)){
        *x = q.inicio->valor;
        r = 0;
    }
    return r;
}

//typedef LInt QueueC;

void initQueueC (QueueC *q){
    *q = NULL;
}

int QisEmptyC (QueueC q){
    return (q==NULL);
}
int enqueueC (QueueC *q, int x){
    int r = 1;
    //QueueC *q: q aponta para o ultimo
    // inicio: q->prox
    //fim: *q
    LInt novo = newLInt(x,NULL);
    if (QisEmptyC(*q)){
        *q = novo;
        (*q)->prox = novo;
    }
    else{
        novo->prox = (*q)->prox;
        (*q)->prox = novo;
        *q = novo;
    }
    
    if (novo)   r = 0;
    return -1;
}

int dequeueC (QueueC *q, int *x){
    int r = 1;
    if (!QisEmptyC(*q)){
        LInt aux = (*q)->prox;
        *x = (*q)->prox->valor;
        (*q)->prox = aux->prox;
        free(aux);
        r = 0;  //sucesso
    }
    return r;
}

int frontC (QueueC q, int *x){
    int r = 1;
    if (!QisEmptyC(q)){
        *x = q->prox->valor;
        r = 0;  //sucesso
    }
    return r;
}