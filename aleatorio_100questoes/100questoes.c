#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

LInt cloneL (LInt l){
    LInt nova = malloc(sizeof(struct lligada));
    if (!l) return NULL;
    else{
        nova->valor = l->valor;
        nova->prox = cloneL(l->prox);
        return nova;
    }
}

LInt cloneL_iterativa (LInt l){
    LInt r,ult,nova;
    if (!l) return NULL;
    else{
        r = malloc(sizeof(struct lligada));
        r->valor = l->valor;
        ult = r;
        while(l){
            l = l->prox;
            nova = malloc(sizeof(struct lligada));
            nova->valor = l->valor;
            ult->prox = nova;
            ult = nova;
        }
        ult->prox = NULL;
    }
    return r;
}

//95

int lookupAB (ABin a, int x) {
    if (a == NULL)  return 0;
    if (a->valor == x)  return 1;
    if (a->valor < x)   return (lookupAB(a->dir,x));
    else                return (lookupAB(a->esq,x));
}

//15

int iguaisConsecutivos (char s[]) {
    int i,conta = 1,maior = 0;
    for(i=0;s[i]!='\0';i++){
        if (s[i] == s[i+1]){
            conta +=1;
        }
        else{
            if (conta>maior)    maior = conta;
            conta = 1;
        }
    }
    return maior;
}

//100

void listToBTree (LInt l, ABin *a) {
    if (l == NULL)  *a == NULL;
    else{
        while(l){
            *a = malloc(sizeof(struct nodo));
            (*a)->valor = l->valor;
            (*a)->esq = NULL;
            l = l->prox;
            a = &(*a)->dir;
        }
        *a = NULL;
    }
}

//83

void posorder_aux(ABin a, LInt *l){
    if(a){
    *l = newLInt(a->valor,*l);
    posorder_aux(a->dir,l);
    posorder_aux(a->esq,l);
    }
}
 
void posorder (ABin a, LInt * l) {
    *l = NULL;
    posorder_aux(a,l);
}

// 57

void merge (LInt *r, LInt l1, LInt l2){
    while (l1 && l2){
        *r = malloc(sizeof(struct lligada));
        (*r)->prox = NULL;
        if (l1->valor <= l2->valor){
            (*r)->valor = l1->valor;
            r = &((*r)->prox);
            l1 = l1->prox;
        }
        else{
            (*r)->valor = l2->valor;
            r = &((*r)->prox);
            l2 = l2->prox;
        }
    }
    while(l1){
        *r = malloc(sizeof(struct lligada));
        (*r)->prox = NULL;
        (*r)->valor = l1->valor;
        r = &((*r)->prox);
        l1 = l1->prox;
    }
    while(l2){
        *r = malloc(sizeof(struct lligada));
        (*r)->prox = NULL;
        (*r)->valor = l2->valor;
        r = &((*r)->prox);
        l2 = l2->prox;
    }
}

//80

void mirror (ABin *a) {
    if (*a){
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}

// 69

int take (int n, LInt *l){
    LInt temp;
    int comp = 0;
    while(n && *l){
        l = &((*l)->prox);
        n--;
        comp++;
    }
    while(*l){
        temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
        
    return comp;
}

//46

int depthOrd (ABin a, int x) {
    int d;
    if (a == NULL)  return -1;
    if (a->valor == x)  return 1;
    if (a->valor>x)    d = depthOrd(a->esq,x);
    else    d = depthOrd(a->dir,x);
    if (d == -1)    return d;
    else    return (d+1);
}

//54

LInt reverseL (LInt l){
    LInt aux,aux2;
    if (l && l->prox){
        aux = l->prox;
        l->prox = NULL;
        while(aux){
            aux2 = aux->prox;
            aux->prox = l;
            l = aux;
            aux = aux2;
        }
    }
    return l;
}

//32

int maxCresc (int v[], int N) {
    int r,i,conta = 1,maior = 0;
        for(i=0;i<N-1;i++){
            if (v[i+1]>=v[i]){
                conta++;
            }
            else{
                if (conta>maior) maior = conta;
                conta = 1;
            }
        }
return maior;
}

//49

typedef struct posicao {
int x, y;
} Posicao;


int maiscentral (Posicao pos[], int N) {
    int i,r = 0;
    int perto,menor = abs(pos[0].x) + abs(pos[0].y);
    for (i=1;i<N;i++){
        perto = abs(pos[i].x)+ abs(pos[i].y);
        if (perto<menor){ menor = perto; r = i;}
    }
    return r;
}

//65

void concatL (LInt *a, LInt b){
    while(*a){
        a = &((*a)->prox);
    }
    (*a) = b;
}

//17

int maiorPrefixo (char s1 [], char s2 []) {
    int i,conta = 0;
    for(i=0;s1[i]!='\0' && s2[i]!='\0';i++){
        if(s1[i] == s2[i])  conta++;
        else break;
    }
    return conta;
}

//18

int maiorSufixo (char s1[], char s2[]) {
    int i,j,conta = 0;
    int l1 = strlen(s1),l2 = strlen(s2);
    for(i=l1-1,j=l2-1;i>=0 && j>=0;i--,j--){
        if(s1[i] == s2[j])  conta++;
        else break;
    }
    return conta;
}

//19

int sufPref (char s1[], char s2[]) {
    int i,j=0,conta = 0;
    for(i=0;s1[i];i++){
        if(s1[i] == s2[j++])  conta++;
        else conta = j = 0;
    }
    return conta;
}


//46

int cardinalMSet (int N, int v[N]){
   	  int c=0,i;
   	  for(i=0;i<N;i++)  c += v[i];
   	  return c;
   }

//12

void strnoV (char t[]){
    int i,j=0;
    char aux[strlen(t)];
    for(i=0;t[i];i++){
        if (!(isVogal(t[i]))) aux[j++] = t[i];
    }
    aux[j] = '\0';
    
    for(i=0;aux[i];i++)
        t[i] = aux[i];
        
    t[i] = '\0';
}

void strnoVv2 (char t[]){
    int i,j=0;
    for(i=0;t[i];i++){
        if (!(isVogal(t[i]))) t[j++] = t[i];
    }
    t[j] = '\0';
}

//34

int elimRepOrd (int v[], int N) {
    int r = N,i,j=0,conta=0;
    for(i=0;i<N-1;i++){
        if (v[i+1] == v[i])  conta++;
        else v[j++] = v[i];
    }
    v[j] = v[i];
    return N-conta;
}

//9

int mystrcmp(char s1[], char s2[]) {
    int l1,l2,i;
    for(l1=0;s1[l1];l1++);
    for(l2=0;s1[l2];l2++);
    for(i=0;s1[i] && s2[i] && s1[i]==s2[i];i++);
    return s1[i]-s2[i];
}

//89

int nivelV (ABin a, int n, int v[]) {
    int i=0,e,d;
    if (a == NULL || n == 0)    i=0;
    else if(n == 1){
        v[0]=a->valor;
        i++;
    }
    else{
        e = nivelV(a->esq,n-1,v);
        d = nivelV(a->dir,n-1,v+e);
        return e+d;
    }
    return i;
}







