#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
    } * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int max(int a, int b) {
    if (b>a) a=b;
    return a;
}

int altura (ABin a) {
    int r = 0;
    if (a != NULL) {
        r = 1 + max(altura(a->esq), altura(a->dir));
    }
    return r;
}

int nFolhas (ABin a) {
    int r=0;
    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL) r = 1;
        else r = nFolhas(a->esq) + nFolhas(a->dir);
    }
    return r;
}

ABin maisEsquerda (ABin a) {
    ABin pt = a;
    if (pt != NULL) 
        while (pt->esq != NULL) pt = pt->esq;
    return pt;
}

void imprimeNivel (ABin a, int l) {
    if (a != NULL) {
        if (l != 0) {
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
        else printf("%d ", a->valor);
    }
}

int procuraE (ABin a, int x) {
    return (a && (a->valor == x || procuraE(a->esq, x) || procuraE(a->dir, x)));
}

struct nodo *procura (ABin a, int x) {
    while (a != NULL && a->valor != x) {
        if (a->valor > x) a = a->esq;
        else a = a->dir;
    return a;
}
}

int nivel(ABin a, int x){
    int r = 0;
    while (a != NULL && a->valor != x) {
        if (a->valor > x) {a = a->esq; r++;}
        else {a = a->dir; r++;}
    }
    if (a == NULL) r = -1;
    return r;
}

void imprimeAte (ABin a, int x) {
    if (a != NULL) {
        if (a->valor > x) {
            imprimeAte(a->esq, x);
            printf("%d ", a->valor);
        }
        else {
            imprimeAte(a->esq, x);
            printf("%d ", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}