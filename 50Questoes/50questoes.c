#include<stdio.h>
#include <assert.h>
#include <limits.h>

void maior_questao1(){
    int n,i,max;
    printf("Qual e o numero de elementos?");
    scanf("%d",&n);
    int lista[n];

    for(i=0;i<n;i++){
        printf("O elemento %d da lista e:\n",i);
        scanf("%d",&lista[i]);
    }
    
    max = lista[0];
    for(i=0;i<n;i++){
        if (lista[i]>max)
            max = lista[i];
    }
    printf("O maior valor da lista e %d\n",max);
}

void questao1v2(){
    printf("Calcular o maior de uma sequencia\n Insere uma lista de numeros (um por linha) terminada em 0:\n");
    int largest = INT_MIN;
    while(1){
        int num;
        scanf("%d",&num);
        if (num==0)
            break;
        else if (num>largest)
            largest = num;
    }
    printf("O maior elemento da sequencia e: %d\n",largest);
}

void media_questao2(){
    int n,i,sum = 0;
    printf("Qual e o numero de elementos?");
    scanf("%d",&n);
    int lista[n];

    for(i=0;i<n;i++){
        printf("O elemento %d da lista e:\n",i);
        scanf("%d",&lista[i]);
    }
    
    for(i=0;i<n;i++){
        sum+=lista[i];
    }
    float media = sum/(float)n;
    printf("A media e %f\n",media);
}

void questao2v2(){
    printf("Calcular a media de uma sequencia\n Insere uma lista de numeros (um por linha) terminada em 0:\n");
    int sum=0,n;
    while(1){
        int num;
        scanf("%d",&num);
        if (num==0)
            break;
        else
            sum +=num;
            n+=1;
    }
    float media = sum/(float)n;
    printf("A media da sequencia e: %f\n",media);
}

void maior2_questao3(){
    int n,i,max,a=0;
    printf("Qual e o numero de elementos?");
    scanf("%d",&n);
    int lista[n];

    for(i=0;i<n;i++){
        printf("O elemento %d da lista e:\n",i);
        scanf("%d",&lista[i]);
    }
    
    max = lista[0];
    for(i=0;i<n;i++){
        if (lista[i]>max){
            max = lista[i];
            a = i;
        }
    }
    
    max = lista[0];
    for(i=0;i<n;i++){
        if (i!=a){
            if (lista[i]>max)
                max = lista[i];
        }
    }

    printf("O segundo maior valor da lista e %d\n",max);
}

void questao3v2(){
    printf("Calcular o segundo maior elemento de uma sequencia\n Insere uma lista de numeros (um por linha) terminada em 0:\n");
    int largest = INT_MIN, second_largest = INT_MIN;
    while(1){
        int num;
        scanf("%d",&num);
        if (num==0)
            break;
        else if (num>largest){
            second_largest = largest;
            largest = num;
        }
        else if (num>second_largest)
            second_largest = num;
    }
    printf("O segundo maior elemento da sequencia e: %d\n",second_largest);
}

int bitsUm (unsigned int x){
    int r = 0;
    while(x) {
        r += (x % 2);
        x >>= 1; // x = x/2
    }
    return r;
}

int trailingZ (unsigned int n) {
    int N = 0;
    unsigned int pot = 1;
    while (n%(pot*2) == 0) {
        N += 1;
        pot *= 2;
        if (pot*2 < pot) {
            N += 1;
            break;
        }
    }
    printf("O numero de zeros e: %d", N);
    return N;
}

int qDig (int n) {
    int r=0;
    while(n){
        if (n/10<1){
            r+=1;
            break;
        }
        else{
            r+=1;
            n = n/10;
        }
    }
    return r;
}

int qDigv2 (int n) {
    int r;
    if (n/10<1)
        r=1;
    else
        r = 1 + qDig(n/10);
    return r;
}

char *mystrcat(char s1[], char s2[]) {
    int l1 = strlen(s1), l2 = strlen(s2);
    int j;
    for(j=0;j<l2;j++){
        s1[l1+j] = s2[j];
    }
    s1[l1+j] = '\0';
    return s1;
}

char* mystrcpy(char* dest, char source[]) {
    int i;
    for(i=0;source[i]!='\0';i++){
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

int mystrcmp(char s1[], char s2[]) {
    int l1 = strlen(s1), l2 = strlen(s2);
    int i;
    for(i=0;s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0';i++);
    if (s1[i]!='\0' && s2[i]=='\0') return 1;
    if (s1[i]=='\0' && s2[i]!='\0') return -1;
    if (s1[i]!='\0' && s2[i]!='\0') return (s1[i]-s2[i]);
    return 0;
}

// 34

void remover(int v[], int i, int N){
    while(i<N){
        v[i] = v[i+1];
        i++;
    }
}

int elimRepOrd (int v[], int N) {
    int r = N;
    int i;
    for (i=0;i<r-1;i++){
        if (v[i] == v[i+1]){
            remover(v,i,r);
            i--;
            r--;
        }
    }
    return r;
}





int comunsOrd (int a[], int na, int b[], int nb){
    int r=0,i,j;

    for(i=0;i<na;i++){
        for(j=0;j<nb && b[j]>a[i];j++){
            if (a[i] = b[j])
                r+=1;
        }
    }
    return r;
}

int main(){
    //maior_questao1();
    //questao1v2();
    //questao2v2();
    //questao3v2();
    //media_questao2();
    //maior2_questao3();
    //int a = bitsUm(10);
    //printf("%d",a);
    //trailingZ(4);
    //qDig(440);
    questao2v2();
    return 0;
}