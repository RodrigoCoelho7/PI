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


//----------------QUESTAO 1---------------------------------

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

int length (LInt l){
    int r = 0;
    if (l){
        while (l != NULL){
            l = l->prox;
            r++;
        }
    }
    return r;
}

//--------------------------------------------------------------------

//----------------QUESTAO 2----------------------------------

void freeL (LInt l){
    while(l){
        LInt aRemover = l;
        l = l->prox;
        free(aRemover);
}
}

//Verificar melhor

//---------------------------------------------------------------------

//----------------QUESTÃO 3---------------------------------

void imprimeL (LInt l){
    if(l){
        LInt aux = l;
        while(aux){
            printf("%d\n",aux->valor);
            aux = aux->prox;
        }
    }
}

//----------------------------------------------------------

//-----------------QUESTAO 4------------------------------

LInt reverseL (LInt l){
    LInt aux2, aux;
    if (l != NULL && l->prox != NULL){
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

//----------------------------------------------------------

//---------------QUESTAO 5--------------------------------

void insertOrd (LInt *l, int x){
    LInt nova;
    nova = malloc(sizeof(struct lligada));
    nova->valor = x;
    LInt aux = *l,ant;
    if (*l == NULL || aux->valor > nova->valor){
        nova->prox = *l;
        *l = nova;
    }
    else{
        while(aux != NULL && nova->valor>=aux->valor){
            ant = aux;
            aux = aux->prox;
        }
        nova->prox = aux;
        ant->prox = nova;
        }
}

//-----------------------------------------------------------------

//---------------QUESTAO 6----------------------------------------

int removeOneOrd (LInt *l, int x){
    LInt pt,ant;
    int r = 0;
    //assumir que a lista está ordenada
    //procurar x em l
    pt = *l;
    while (pt!=NULL && pt->valor < x){
        ant = pt;pt = pt->prox;
    }

    if (pt!= NULL && pt->valor == x){
        //encontrado
        if (pt != *l)    ant->prox=pt->prox;
        else *l = (*l)->prox;
        free(pt);
    }
    else{
        r = 1;
    }
    return r;
}


//----------------QUESTAO 7---------------------------------

void merge (LInt *r, LInt l1, LInt l2){
    
    while( l1!=NULL && l2!=NULL){
        (*r)=malloc(sizeof(struct lligada));
        (*r)->prox=NULL;
        if(l1->valor<=l2->valor){
            (*r)->valor=l1->valor;
            r=&((*r)->prox);
            l1=l1->prox;
        }else{
            (*r)->valor=l2->valor;
            r=&((*r)->prox);
            l2=l2->prox;
            
        }
    }
    
    while(l2!=NULL ){
        (*r)=malloc(sizeof(struct lligada));
        (*r)->valor=l2->valor;
        r=&((*r)->prox);
        l2=l2->prox;
    }
    while(l1!=NULL){
        (*r)=malloc(sizeof(struct lligada));
        (*r)->valor=l1->valor;
        r=&((*r)->prox);
        l1=l1->prox;
    }
    
}

//----------------------------------------------------------

//---------------QUESTAO 8-----------------------------------

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if (l != NULL){
        while (l != NULL){
            if (l->valor < x){
                (*mx) = malloc(sizeof(struct lligada));
                (*mx)->valor = l->valor;
                mx = &((*mx)->prox);
            }
            else{
                (*Mx) = malloc(sizeof(struct lligada));
                (*Mx)->valor = l->valor;
                Mx = &((*Mx)->prox);
            }
            l = l->prox;
        }
    }
}

//----------------------------------------------------------

//----------------QUESTAO 9---------------------------------

int parteAmeioaux(LInt l){
    int r = 0;
    while (l != NULL){
        r++;
        l = l->prox;
    }
    return r;
}

LInt parteAmeio (LInt *l){
    LInt r = NULL;
    LInt *pt = &r;
    int i = parteAmeioaux(*l)/2;
    for(i;i>0;i--){
        *pt = *l;
        *l = (*l)->prox;
        pt = &(*pt)->prox;
    }
    *pt = NULL;
    return r;
}

//-------------------------------------------

//---------------QUESTAO 10------------------

int removeAll (LInt *l, int x){
    int ocorr = 0;
    LInt ant = NULL,pt = *l;
    if (*l){
        while(*l){
            if ((*l)->valor == x){
                if (!ant)   *l = (*l)->prox;
                else{
                    ant->prox = (*l)->prox;
                }
            ocorr++;
            }
            else{
                ant = *l;
                l = &((*l)->prox);
                
            }
        }
    }
    
    return ocorr;
}

//-----------------------------------------------------------

//----------------QUESTAO 11---------------------------------

int removeDups (LInt *l){
    int x;
    int r;
    LInt *sch = l;
    LInt *swp = l;
    LInt aux;
    if (*l){
        while (*swp != NULL){
            x = (*swp)->valor;
            sch = &(*swp)->prox;
            while(*sch != NULL){
                if ((*sch)->valor == x){
                    aux = *sch;
                    *sch = (*sch)->prox;
                    free(aux);
                    r++;
                }
                else sch = &(*sch)->prox;
            }
            swp = &(*swp)->prox;
        }
    }
    return r;
}

//---------------QUESTAO 12----------------------------------

int removeMaiorL (LInt *l){
    int max = (*l)->valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = *l;
    LInt list = *l;
    while(list){
        if (list->valor >max){
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list;
        list = list->prox;
    }
    if (!maxPrev)   *l = (*l)->prox;
    else{
        maxPrev->prox = maxL->prox;
        free(maxL);
    }
    return max;
}

//----------------QUESTAO 13--------------------------------

void init (LInt *l){
    while(*l){
        if((*l)->prox == NULL){
            *l = NULL;
            free(*l);
        }
        else{
        l = &((*l)->prox);
        }
    }
}

//----------------QUESTAO 14--------------------------------

void appendL (LInt *l, int x){
    if (*l == NULL){
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = x;
        (*l)->prox = NULL;
    }
    else{
        while(*l){
            l = &((*l)->prox);
            }
            *l = malloc(sizeof(struct lligada));
            (*l)->valor = x;
            (*l)->prox = NULL;
        }
}

//----------------QUESTAO 15---------------------------------

void concatL (LInt *a, LInt b){
    while(*a){
        a = &((*a)->prox);
    }
    (*a) = b;
}

//---------------QUESTAO 16----------------------------------

LInt newlista (int x, LInt l){
    LInt r = NULL;
    r = malloc(sizeof(struct lligada));
    r->valor = x;
    r->prox = l;
    return r;
}


LInt cloneL (LInt l){
    LInt r,cauda;
    if (l == NULL)  r = NULL;
    else{
        cauda = cloneL(l->prox);
        r = newlista(l->valor,cauda);
    }
    return r;
}

LInt cloneLv2 (LInt l){
    LInt r = malloc(sizeof(struct lligada));
    if (l == NULL ) r = NULL;
    else{
        r->valor = l->valor;
        r->prox = cloneL(l->prox);
    }
    return r;
}

//----------------QUESTAO 17---------------------------------

LInt cloneRev (LInt l){
    LInt aux2, aux,r;
    if (l == NULL || l->prox == NULL)   r = l;
    else{
        aux = l->prox;
        r->prox = NULL;
        while(aux){
            aux2 = aux->prox;
            aux->prox = r;
            r = aux;
            aux = aux2;
        }
    }
    return l;
}

//-----------------------------------------------------------

//----------------QUESTAO 18--------------------------------

int maximo (LInt l){
    int maximo = l->valor;
    while(l){
        if (l->valor>maximo)    maximo = l->valor;
        l = l->prox;
    }
    return maximo;
}

//------------------------------------------------------------

//----------------QUESTAO 19--------------------------------

int take (int n, LInt *l){
    int i = 0;
    while(i<n && *l){
        l = &((*l)->prox);
        i++;
    }
    if(*l == NULL)  return i;
    while(*l){
        LInt temp = (*l)->prox;
        free(*l);
        (*l) = temp;
    }
    return n;
}

//-------------------------------------------------------------

//-----------------QUESTAO 20----------------------------------

int drop (int n, LInt *l){
    int removidos = 0;
    while (*l && n){
        *l = (*l)->prox;
        n--;
        removidos++;
    }
    return removidos;
}

//----------------------------------------------------------

//----------------QUESTAO 21--------------------------------

LInt NForward (LInt l, int N){
    while(N){
        l = l->prox;
        N--;
    }
    return l;
}

//----------------QUESTAO 22--------------------------------

int listToArray (LInt l, int v[], int N){
    int i = 0,tamanho = 0;
    while(N && l){
        v[i++] = l->valor;
        l = l->prox;
        tamanho++;
        N--;
    }
    return tamanho;
}

//-----------------------------------------------------------

//----------------QUESTAO 23---------------------------------

LInt arrayToList (int v[], int N){
    LInt r = NULL;
    int i;
    for(i=N-1;i>=0;i--){
        r = newLInt(v[i],r);
    }
    return r;
}

//-----------------------------------------------------------

//----------------QUESTAO 24---------------------------------
LInt somasAcL (LInt l) {
    LInt r = NULL,temp = NULL,nova;
    int soma = 0;
    while(l){
        soma += l->valor;
        nova = malloc(sizeof(struct lligada));
        nova->valor = soma;
        nova->prox = NULL;
        l = l->prox;
        if (!r)
            r = temp = nova;
        else
            temp = temp->prox = nova;
    }
    return r;
}

//-----------------------------------------------------------

//----------------QUESTAO 25---------------------------------

void remreps (LInt l){
    if(l){
    while(l->prox){
        if (l->prox->valor == l->valor){
            LInt aux = l->prox;
            l->prox = aux->prox;
            free(aux);
        }
        else l = l->prox;
    }
    }
}

//-----------------------------------------------------------

//----------------QUESTAO 26---------------------------------

LInt rotateL (LInt l){
    if (l && l->prox){
        LInt aux = l;
        l = l->prox;
        aux->prox = NULL;
        LInt aux2 = l;
        while(aux2->prox)   aux2 = aux2->prox;
        aux2->prox = aux;
    }
    return l;
}

//-----------------------------------------------------------

//----------------QUESTAO 27---------------------------------

LInt parte (LInt l){
    LInt r = NULL, temp = NULL;
    while(l && l->prox){
        if (!r) r = temp = l->prox;
        else    temp = temp->prox = l->prox;
        l = l->prox = l->prox->prox;
        temp->prox = NULL;
        
    }
    return r;
}


LInt partev2 (LInt l){
int par = 0;
LInt r = NULL;
LInt *wrt,*del;
if (l != NULL && l->prox != NULL){
    r = l->prox;
    wrt = &r;
    del = &l;
    while(*del != NULL){
        if (par) {
            *wrt = *del;
            *del = (*del)->prox;
            wrt = &(*wrt)->prox;
        }
        else{
            del = &(*del)->prox;
        }
        par = !par;
    }
    *wrt = NULL;
}
return r;
}


//-----------------------------------------------------------

//----------------------------------------------------------
//--------------------ARVORES BINARIAS----------------------
//----------------------------------------------------------

//---------------QUESTAO 28-----------------------------------

int max(int a, int b){
    if (a>b)  return a;
    else      return b;
}

int altura (ABin a){
    int alt = 0;
    if (a){
        alt = max(altura(a->esq),altura(a->dir)) + 1;
    }
	return alt;
}

//-----------------------------------------------------------

//----------------QUESTÃO 29---------------------------------

ABin cloneAB (ABin a) {
    ABin r = NULL;
    if(a){
    r = malloc(sizeof(struct nodo));
    r->valor = a->valor;
    r->esq = cloneAB(a->esq);
    r->dir = cloneAB(a->dir);
    }
    return r;
}

//----------------QUESTAO 30-------------------------------

void mirror (ABin *a) {
    if (*a){
        ABin temp;
        temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}

//-----------------------------------------------------------

//----------------QUESTAO 31--------------------------------

void inorder_aux (ABin a, ABin *l){
    if (a){
        inorder_aux(a->dir,l);
        *l = newLInt(a->valor,*l);
        inorder_aux(a->esq,l);
    }
}

void inorder(ABin a, ABin *l){

}

//-----------------------------------------------------------

//----------------QUESTAO 32--------------------------------

void preorder_aux(ABin a, LInt *l){
    if (a){
        preorder_aux(a->dir,l);
        preorder_aux(a->esq,l);
        *l = newLInt(a->valor,*l);
    }
} 

void preorder (ABin a, LInt * l) {
    *l = NULL;
    preorder_aux(a,l);
}

//--------------------------------------------------------------

//----------------QUESTAO 33---------------------------------

void posorder_aux(ABin a, LInt *l){
    if (a){
    *l = newLInt(a->valor,*l);
    posorder_aux(a->dir,l);
    posorder_aux(a->esq,l);
    }
}

 void posorder (ABin a, LInt * l) {
    *l = NULL;
    posorder_aux(a,l);
}

//----------------QUESTÃO 34---------------------------------

/* Apresente uma definição da função "int depth (ABin a, int x)" que calcula
 o nível (menor) a que um elemento está numa árvore binária ("-1" caso não
 exista). */
 
int min(int a, int b){
    if (a<b)    b = a;
    return b;
}


int depth (ABin a, int x) {
    // adicione o seu código...
    int e,d;
    if (a == NULL)  return -1;
    if (a->valor == x)  return 1;
    e = depth(a->esq,x);
    d = depth(a->dir,x);
    if (e == -1 && d == -1) return -1;
    if (e == -1)    return (d+1);
    if (d == -1)    return (e+1);
    return (1+ (min(e,d)));
}

//----------------------------------------------------------------------------

//--------------------QUESTAO 35---------------------------------------------

int freeAB (ABin a) {
    if (a == NULL)  return 0;
    if (!a->esq && !a->dir){
        free(a);
        return 1;
    }
    return (1 + freeAB (a->esq) + freeAB (a->dir));
}

//----------------------------------------------------------------------------

//--------------------QUESTAO 36----------------------------------------------

int pruneAB (ABin *a, int l) {
    int r = 0;
    if (*a){
        if (l==0){
            r = 1+ pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
            free(*a);
            *a = NULL;
        }
        else{
            r = pruneAB(&((*a)->esq),l-1) + pruneAB(&((*a)->dir),l-1);
        }
    }
    return r;
 }
 
//------------------------------------------------------------------

//-------------------QUESTAO 37------------------------------------

int iguaisAB (ABin a, ABin b) {
    if (a == NULL && b == NULL)   return 1;
    if ((!a && b) || (!b && a)) return 0;
    return (a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
}

//-----------------------------------------------------------------

//--------------------QUESTAO 38----------------------------------

LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}

LInt nivelL (ABin a, int n) {
    if (a == NULL || n < 1)  return NULL;
    if (n == 1) return (newLInt(a->valor,NULL));
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
}

//----------------------------------------------------------------------

//--------------------QUESTAO 39----------------------------------------

int nivelV (ABin a, int n, int v[]) {
    int e,d;
    if (a == NULL || n < 1)  return 0;
    if (n==1){
        v[0] = a->valor;
        return 1;
    }
    else{
        e = nivelV(a->esq,n-1,v);
        d = nivelV(a->dir,n-1,v+e);
        return (e+d);
    }
}

//-------------------------------------------------------------------------

//--------------------QUESTAO 40-------------------------------------------

int dumpAbin (ABin a, int v[], int N) {
    int e;
    if (!a) return 0;
    if (N){
        e = dumpAbin(a->esq,v,N);
        if (e<N){
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else    return N;
}
}

//-------------------------------------------------------------------------

//--------------------QUESTAO 41-------------------------------------------

ABin somasAcA (ABin a) {
    if (a == NULL)  return NULL;
    ABin nova = malloc(sizeof(struct nodo));
    nova->esq = somasAcA(a->esq);
    nova->dir = somasAcA(a->dir);
    if (nova->esq && !(nova->dir))      nova->valor = a->valor + nova->esq->valor;
    if (nova->dir && !(nova->esq))      nova->valor =  a->valor + nova->dir->valor;
    if (!(nova->dir) && !(nova->esq))   nova->valor =  a->valor;
    if (nova->dir && (nova->esq))       nova->valor =  a->valor + nova->dir->valor + nova->esq->valor;
    return nova;
}

//------------------------------------------------------------------------

//--------------------QUESTAO 42------------------------------------------

int contaFolhas (ABin a) {
    if (a == NULL)  return 0;
    if (a->esq == NULL && a->dir == NULL)   return 1;
    return (contaFolhas(a->esq) + contaFolhas(a->dir));
}

//------------------------------------------------------------------------

//--------------------QUESTAO 43------------------------------------------

ABin cloneMirror (ABin a) {
    if (a == NULL)  return NULL;
        ABin novo = malloc(sizeof(struct nodo));
        novo->valor = a->valor;
        novo->esq = cloneMirror(a->dir);
        novo->dir = cloneMirror(a->esq);
        return novo;
}

//------------------------------------------------------------------------

//--------------------QUESTAO 44------------------------------------------

int addOrd (ABin *a, int x) {
    while(*a){
        if (x == (*a)->valor)   return 1;
        else if (x< (*a)->valor)    a = &((*a)->esq);
        else    a = &((*a)->dir);
    }
    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = x;
    novo->esq = novo->dir = NULL;
    *a = novo;
    return 0;
}

//--------------------QUESTAO 45-------------------------------------------

int lookupAB (ABin a, int x) {
    if (a == NULL)  return 0;
    else{
        while(a){
            if (x == a->valor)  return 1;
            else if (x < a->valor) a = a->esq;
            else    a = a->dir;
        }
    }
    return 0;
}

//--------------------------------------------------------------------------

//--------------------QUESTAO 46--------------------------------------------

int depthOrd (ABin a, int x) {
    int d;
    if (a == NULL)  return -1;
    if (a->valor == x)  return 1;
    else if (a->valor > x)  d = depthOrd(a->esq,x);
    else    d = depthOrd(a->dir,x);
    if (d == -1)    return d;
    else return d+1;
}

//---------------------------------------------------------------------------

//--------------------QUESTAO 47---------------------------------------------

int maiorAB (ABin a) {
    while(a->dir){
        a = a->dir;
    }
    return a->valor;
}

//-----------------------------------------------------------------------------

//--------------------QUESTAO 48-----------------------------------------------

void removeMaiorA (ABin *a) {
    ABin temp;
    if ((*a)->dir == NULL){
        temp = (*a);
        free(*a);
        *a = temp->esq;
    }
    else removeMaiorA(&((*a)->dir));
}

//--------------------------------------------------------------------------------

//--------------------QUESTAO 49--------------------------------------------------

int quantosMaiores (ABin a, int x) {
    if (a == 0) return 0;
    if (a->valor <= x)   return quantosMaiores(a->dir,x);
    else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

//--------------------QUESTÃO 50-------------------------------------------------


/* Apresente uma definição da função "void listToBTree (LInt l, ABin *a)" que
 constrói uma árvore binária de procura a partir de uma lista ligada ordenada.*/
 
void listToBTree (LInt l, ABin *a) {
    while (l != NULL){
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = l->valor;
        (*a)->esq = NULL;
        a = &((*a)->dir);
        l = l->prox;
    }
    *a = NULL;
}

int length (LInt l){
    int r = 0;
    while (l != NULL){
        r++;
        l = l->prox;
    }
    return r;
}

LInt list2BTAux (int n, LInt l, ABin *a){
    //coloca em *a uma árvore com os primeiros n elementos de l
    //retorna o que sobra de l
    if (l == NULL || n == 0)    *a = NULL;
    else{
        *a = malloc(sizeof(struct nodo));
        l = list2BTAux (n/2,l,&((*a)->esq));
        (*a)->valor = l->valor;
        l = l->prox;
        l = list2BTAux (n-n/2-1,l,&((*a)->dir));
    }
    return l;
}

void listToBTree (LInt l, ABin *a){
    list2BTAux(length (l),l,a);
}

//------------------------------------------------------------------------------------

//---------------------QUESTAO 51------------------------------------------------------

/* Apresente uma definição da função "int deProcura (ABin a)" que testa se uma
 árvore é de procura. */
 
 /*
 int todosMenIguais(int n, ABin a){
    if (a == NULL)  return 1;
    return (a->valor <= n && todosMenIguais(n,a->esq) && todosMenIguais(n,a->dir));
 }
 
  int todosMaiIguais(int n, ABin a){
    if (a == NULL)  return 1;
    return (a->valor >= n && todosMaiIguais(n,a->esq) && todosMaiIguais(n,a->dir));
 }
 
int deProcura (ABin a) {
    // adicione o seu código...
    if (a == NULL)  return 1;
    return (todosMenIguais(a->valor,a->esq) 
         && todosMaiIguais(a->valor,a->dir)
         && deProcura(a->esq)
         && deProcura(a->dir));
    return -1;
}
*/

int maisDir (ABin a){
    if (a){
        while(a->dir != NULL)
            a = a->dir;
    }
    return a->valor;
}

int maisEsq (ABin a){
    if (a){
        while(a->esq != NULL)
            a = a->esq;
    }
    return a->valor;
}

int deProcuraAux (ABin a,int m, int M){
    //testa sse a é de procura e os elementos estão todos no intervalo [m,...,M]
    if (a == NULL)  return 1;
    if (a->valor < m || a->valor > M)   return 0;
    return (deProcuraAux(a->esq,m,a->valor)&&
            deProcuraAux(a->dir,a->valor,M));
}

int deProcura (ABin a){
    int m,M;
    if (a == NULL)  return 1;
    m = maisEsq(a);
    M = maisDir(a);
    return (deProcuraAux(a, m, M));
}

//---------------------------------------------------------------------------------------