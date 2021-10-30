#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);

void libertaLista (Palavras l){
    while(l){
        l = l->prox;
        Palavras aRemover = l;
        free(aRemover->palavra);
        free(aRemover);
    }
}

int quantasP (Palavras l){
    //...
    return 0;
}

void listaPal (Palavras l){
    Palavras aux = l;
    while(aux){
        printf("%s %d\n",aux->palavra,aux->ocorr);
        aux = aux->prox;
    }
}

char * ultima (Palavras l){
    
    return NULL;
}

Palavras novaCelula(char *p, int ocorr){
    Palavras nova = (Palavras) malloc(sizeof(struct celula));
    nova -> palavra = strdup(p);
    nova -> ocorr = ocorr;
    nova -> prox = NULL;
    return nova;
}

Palavras acrescentaInicio (Palavras lst, char *p){
    Palavras nova = novaCelula(p, 1);
    nova->prox = lst;
    //lst = nova;
    //return lst;
    return nova;
}

Palavras acrescentaFim (Palavras l, char *p){
    Palavras nova = novaCelula(p, 1);
    if (l!=NULL){
        Palavras aux = l;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = nova;
        return l;
    }
    else
        return nova;

    return NULL;
}

Palavras acrescenta (Palavras l, char *p){
    Palavras nova = novaCelula(p, 1);
    if (l==NULL){
        l = novaCelula(p, 1);
    }
    else{
        Palavras aux = l,anterior = NULL;
        while(aux->prox && (strcmp(p,aux->palavra))>0){
            anterior = aux;
            aux = aux->prox;
        }
        if (!aux){
            anterior->prox = novaCelula(p,1);
        }
        else{
            if (strcmp(p,aux->palavra)==0){
                aux->ocorr ++;
            }
            else{
                if (!anterior){
                    l = novaCelula(p,1);
                    l->prox = anterior;
                }
            else{
               Palavras nova = novaCelula(p,1);
               nova->prox = aux;
               anterior->prox = nova;
            }
            }
        }
    }
    return l;
    }
    
struct celula * maisFreq (Palavras l){
    //...
    return NULL;
}



int main () {
    char palavra[20] = "ola";
    Palavras dic = NULL;

/*
    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");
*/

    free(dic->palavra);
    free(dic);
    dic = NULL;

    return 0;
}
