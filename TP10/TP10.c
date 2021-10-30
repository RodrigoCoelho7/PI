#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


ABin newABin (int r, ABin e, ABin d);
ABin RandArvFromArray (int v[], int N);
ABin cloneABin (ABin a);
void dumpABin (ABin a, int N);
void freeABin (ABin a);

// Questão 1
ABin removeMenor (ABin *a);
void removeRaiz (ABin *a);
int removeElem (ABin *a, int x);

// Questão 2
void rodaEsquerda (ABin *a);
void rodaDireita (ABin *a);
void promoveMenor (ABin *a);
void promoveMaior (ABin *a);
ABin removeMenorAlt (ABin *a);

// Questão 3
int constroiEspinha (ABin *a);
ABin equilibraEspinha (ABin *a, int n);
void equilibra (ABin *a);


// Questão 1
ABin removeMenor_sol (ABin *a);
void removeRaiz_sol (ABin *a);
int removeElem_sol (ABin *a, int x);

// Questão 2
int constroiEspinha_sol (ABin *a);
ABin equilibraEspinha_sol (ABin *a, int n);
void equilibra_sol (ABin *a);

// Questão 3
void promoveMenor_sol (ABin *a);
void promoveMaior_sol (ABin *a);



ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}


// Questão 1
ABin removeMenor (ABin *a){
    ABin menor = NULL;
    if (*a){
        //menor está na raíz?
        if ((*a)->esq == NULL){
            menor = *a;
            *a = (*a)->dir;
        }
        else{
            ABin aux = (*a);
            while(aux->esq != NULL && aux->esq->esq)
                aux = aux->esq;
                //aux->esq->esq == NULL, ou seja, aux->esq contém o menor
            menor = aux->esq;
            aux->esq = menor->dir;
        }
    }
    return menor;
}


void removeRaiz (ABin *a){
    if (*a){
    if ((*a)->dir == NULL)
        *a = (*a)->esq;
    else{
        ABin menorDir = removeMenor (&(*a)->dir);
        //promover o menor da direita a raiz
        menorDir->esq = (*a)->esq;
        menorDir->dir = (*a)->dir;
        free(*a);
        (*a) = menorDir;
    }
}
}


int removeElem (ABin *a, int x){
    ABin aux = *a;
    int r = 1; //não foi encontrado
    if (aux){
    while (x != aux->valor){
        if (x < aux->valor)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if(aux){  //encontramos o valor
        removeRaiz(&aux);
        r = 0;
    }
    }
    return r;
}

int removeElemRecursiva (ABin *a, int x){
    int r = 1; //não foi encontrado
    if (*a){
    while (x != (*a)->valor){
        if (x < (*a)->valor)
            r = removeElemRecursiva(&(*a)->esq,x);
        else
            r = removeElemRecursiva(&(*a)->dir,x);
    }
        if (*a) {
            r=0;
            removeRaiz(a);
        }
    }
    return r;
}

// Questão 2
void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}

void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

void promoveMenorinicial (ABin *a){
    while (*a && ((*a)->esq)){
       rodaDireita(a);
    }
}

void promoveMenor (ABin *a){
    if (*a && ((*a)->esq)){
        promoveMenorV2(&(*a)->esq);
        rodaDireita(a);
    }
}

void promoveMaior (ABin *a){
    if (*a && ((*a)->dir)){
        promoveMaior(&(*a)->dir);
        rodaEsquerda(a);
    }
}

ABin removeMenorAlt (ABin *a){
    promoveMenor(a);
    ABin menor = NULL;
    menor = *a;
    *a = (*a)->dir;
    return menor;
}

// Questão 3

int constroiEspinhaAux (ABin *a, ABin *ult){
    int r=0;
    promoveMenor(a);
    ABin aux = *a;
    a = &aux;
    while(aux->dir){
        promoveMenor(&aux->dir);
        aux = aux->dir;
        r++;
    }
    *ult = aux;
    return r;
}


ABin equilibraEspinha (ABin *a, int n) {
    int meio = n/2;
    ABin auxv2 = *a;
    a = &auxv2;
    int i=0;
    while(i!=meio){
        auxv2 = auxv2->dir;i++;}
    promoveMaior(auxv2);
    return auxv2;
}

void equilibra (ABin *a) {
    ABin aux = NULL;
    int n = constroiEspinhaAux(a,&aux);
    *a = equilibraEspinha(a,n);
}



int main (){
  int v1[15] = { 1, 3, 5, 7, 9,11,13,15,17,19,21,23,25,27,29},
      N=15, i;
  ABin a1,r;
  
  srand(time(NULL));
  
  printf ("_______________ Testes _______________\n\n");
  // N = rand() % 16;
  a1 = RandArvFromArray (v1, N);
  printf ("________________________________________\n");
  printf ("Primeira árvore de teste (%d elementos)\n", N);
  dumpABin (a1, N);
  
  /*
  printf ("Espinha\n");
  constroiEspinha_sol (&a1);

  dumpABin (a1, N);
  
  printf ("Equilibrar espinha\n");
  equilibraEspinha_sol (&a1,N);
  dumpABin (a1, N);
  */
  
  i = rand() %N;
  printf ("Remoção do elemento %d\n", v1[i]);
  removeElem_sol (&a1,v1[i]);
  dumpABin (a1, --N);
  
  
  r = removeMenor_sol (&a1);
  printf ("Remoção do menor %d\n", r->valor);
  dumpABin (a1, --N);

  printf ("Remoção da raiz %d\n", a1->valor);
  removeRaiz_sol (&a1);
  dumpABin (a1, --N);

  freeABin (a1);

  a1 = newABin(v1[7], RandArvFromArray (v1  ,7), 
                      RandArvFromArray (v1+8,7));
  N = 15;
  printf ("_______________________________________\n");
  printf ("Segunda árvore de teste (%d elementos)\n", N);
  dumpABin (a1, N);
  
  printf ("Rotação à direita\n");
  rodaDireita (&a1);
  dumpABin (a1, N);

  printf ("Rotação à esquerda\n");
  rodaEsquerda (&a1);
  dumpABin (a1, N);
  
  printf ("Promoção do maior\n");
  promoveMaior (&a1);
  dumpABin (a1, N);
  
  printf ("Promoção do menor\n");
  promoveMenor (&a1);
  dumpABin (a1, N);
  

  printf ("\n\n___________ Fim dos testes ___________\n\n");
  return 0;
} 