#include<stdio.h>
#include <string.h>

int hash (char s[]) {
  int r = 0;
  while (*s) {r += *s; s++;}
  return r;
}

int hash2 (char s[]) {
  int r = 0;
  int i = 1;
  while (*s) {
      r += (*s)*i;
   s++;
   i++;
   }
  return r;
}

int hash (char s[]) {
  int r = 0;
  while (*s) {r += *s; s++;}
  return r;
}

int next(char s[], int n) {
 while (n > 0) {
   n--;
   if (s[n] < 'z') {
     if (s[n] == 'Z') {s[n] = 'a';} // Saltar na tabela ASCII
     else s[n]++;
     return 1;
   } else {
     s[n] = 'A'; // Onde começar a percorrer a tabela ASCII
   }
 }
 return 0;
}

int main () {
 char s[10];
 int n,i;
 for (n=0;n<10;n++) {
   for (i=0;i<n;i++) s[i] = 'A'; // Onde começar a percorrer a tabela ASCII
   s[n] = '\0';
   do {
     if (hash(s) == 530) {printf("%s\n",s); return 0;} // Imprimir a menor string correspondente ao ASCII
   } while(next(s,n));
 }
 return 0;
}