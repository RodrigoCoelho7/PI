#include<stdio.h>
#include <string.h>

int contaVogais (char *s){
    int i,r=0;
    for(i=0;s[i]!='\0';i++){
        if ((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')||(s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U'))
            r++;
    }
    return r;
}

int IsVogal (char s){
    int i,r=0;
    if ((s=='a')||(s=='e')||(s=='i')||(s=='o')||(s=='u')||(s=='A')||(s=='E')||(s=='I')||(s=='O')||(s=='U'))
        r=1;
    return r;
}

int comprimento(char s[]){
    int i;
    
    for (i=0;s[i]!='\0';i++);

    return i;
}

int retiraVogaisRep (char *s){
    char aux [strlen(s)];
    int i,w=0,j;

    for(i=0;s[i]!='\0';i++)
        if (s[i] != s[i+1] || !IsVogal(s[i]))
            aux[w++]=s[i];
    aux[w] = '\0';

    for(j=0;j<=w;j++)
        s[j] = aux[j];
    s[w] = '\0';

    return (i-w);
}

int retiraVogaisRepV2 (char *s){
    int i,w=0,j;

    for(i=0;s[i]!='\0';i++)
        if (s[i] != s[i+1] || !IsVogal(s[i]))
            s[w++]=s[i];
    s[w] = '\0';

    return (i-w);
}

int duplicaVogais(char *s){
    int i,w,j;
    char aux [strlen(s)+contaVogais(s)];

    for (i=0,w=0;s[i]!='\0';i++,w++){
        aux[w] = s[i];
        if (IsVogal(s[i])){
            aux[w+1] = s[i];
            w++;
        }
    }
    aux[w] = '\0';

    for(j=0;j<=w;j++)
        s[j] = aux[j];
    s[j] = '\0';
    
    return (w-i);
}

int duplicaVogaisv2 (char *s){
    int r = strlen(s)-1;
    int c = contaVogais(s);
    int w = r+c; // assume-se que s tem espaco que chegue
    s[w+1] = '\0';

    while(r>=0){
  	if(IsVogal(s[r]))
  		s[w--]=s[r];
    s[w--]=s[r--];
    }

	return c;
}

void simNao (int x){
    if (!x) printf (" nao ");
}

void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}

int ordenado (int v[], int N){
    int i;
    int r=1;
    for(i=0;i<N-1 && r==1;i++)
        if (v[i]>v[i+1])
            r=0;
    return r;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int w,ra,rb;

    for(ra=0,rb=0,w=0 ;ra<na && rb<nb;w++){
        if(a[ra]<=b[rb])
            r[w] = a[ra++];
        else
            r[w] = b[rb++];
    }

    while(ra<na)
        r[w++] = a[ra++];
    while(rb<nb)
        r[w++] = b[rb++];
}

void swap (int v[],int i, int j){
    int z;
    z = v[i];
    v[i] = v[j];
    v[j] = z;
}


int partition (int v[], int N, int x){
    int r,i;

    for(r=i=0;i<N;i++)
        if (v[i]<=x)  swap(v,r++,i);

    //v[r] = x;
    return r;
}

int main(){
    char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    char s2 [20] = "Estaa e umaa";
    int x;
    
    //printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));

    //printf ("A string \"%s\" tem  tamanho %d \n", s1, comprimento (s1));

    //x = retiraVogaisRepV2 (s1);
    //printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);

    x = duplicaVogaisv2 (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);

    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
        b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
        c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
        d [50];
    //int x;
    

    //printf ("O array "); dumpV(a,15);
    //simNao(ordenado (a,15)); printf (" esta ordenado\n");
    //printf ("O array "); dumpV(b,10);
    //simNao(ordenado (b,10)); printf (" esta ordenado\n");
    //printf ("O array "); dumpV(c,10);
    //simNao(ordenado (c,10)); printf (" esta ordenado\n");
    //
    //printf ("\n\nMerge dos arrays "); dumpV (b,10);
    //printf ("\ne                "); dumpV (c,10); 
    //merge (b, 10, c, 10, d);
    //printf ("\nresulta em       "); dumpV (d,20);

    printf ("\n\n\nA particao do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partition (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x);

    //printf ("\nFim dos testes\n");

    return 0;
}