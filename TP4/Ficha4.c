#include<stdio.h>
#include <string.h>

int contavogais (char *s){
    int i;
    int r = 0;

    for (i=0;s[i]!='\0';i++)
        if ((s[i]=='a') || (s[i]=='e')  || (s[i]=='i') || (s[i]=='o')  || (s[i]=='u')
            || (s[i]=='A') || (s[i]=='E') || (s[i]=='I') || (s[i]=='O') || (s[i]=='U'))
            r++;

    return r;
}

int isVogal(char c){
    int r=0;
    if ((c=='a') || (c=='e')  || (c=='i') || (c=='o')  || (c=='u')
    || (c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U'))
        r=1;
    return r;
}

int contavogaisv2 (char *s){
    int i;
    int r = 0;

    for (i=0;s[i]!='\0';i++)
        if (isVogal(s[i]))
            r++;

    return r;
}

int retiraVogaisRep(char *s){
    int r,w,i;
    char aux[strlen(s)];

    for(r=0;s[r]!='\0';r++){
        if (s[r] != s[r+1] || !isVogal(s[r]))
        aux[w++] = s[r];
    }

    aux[w] = '\0';

    for(i=0;i<=w;i++){
        s[i] = aux[i];
    }

    s[w] = '\0';

    return (r-w);
}

int retiraVogaisRepv2(char *s){
    int r,w,i;

    for(r=0;s[r]!='\0';r++){
        if (s[r] != s[r+1] || !isVogal(s[r]))
        s[w++] = s[r];
    }
    s[w] = '\0';

    return (r-w);
}

int duplicaVogais (char *s){

char aux[strlen(s)+contavogais(s)]; // assume-se que s tem espaco que chegue
int i,r,w;

  for(r=0,w=0;s[r]!='\0';r++,w++){
    aux[w]=s[r];
  	if(isVogal(s[r])){
  		aux[w+1]=s[r];
  		w++;
	}
	aux[w]='\0';

	// copiar aux para s

	for(i=0;i<w;i++) 
        s[i]=aux[i];

	s[i]='\0';

	return(w-r);
}
}

int duplicaVogaisv2 (char *s){
    int r = strlen(s)-1;
    int c = contavogais(s);
    int w = r+c; // assume-se que s tem espaco que chegue
    s[w+1] = '\0';

    while(r>=0){
  	if(isVogal(s[r]))
  		s[w--]=s[r--];
    s[w--]=s[r--];
    }

	return c;
}

int ordenado(int a[],int N){
    int i,r=1;

    for(i=0; i<N-1 && r==1;i++){
        if (a[i]>a[i+1])
            r=0;
    }
    return r;
}

void merge(int a[], int na, int b[], int nb, int r[]){
    int ra, rb,w;

    for (ra=0,rb=0,w=0;ra<na && rb<rb;w++)
        if(a[ra]<=b[rb])
            r[w] = a[ra++];
        else
            r[w] = b[rb++];

    while(ra<na)
        r[w++] = a[ra++];
    while(rb<nb)
        r[w++] = b[rb++];
}

int main(){
    int x;
    char s1[100] = "Estaa e umaa string coom duuuplicadoos";
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);

    return 0;
}