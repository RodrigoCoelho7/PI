#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Stack.h"

void SinitStack (SStack s){
	s->sp = 0;  //Stack vazia
}

int  SisEmpty (SStack s){
    int r=0;
    if (s->sp != 0)
	    r = -1;
	return r;
}

int  Spush (SStack s, int x){
	int r = 1;
	if (s->sp<Max){
	    s->values[(s->sp)++] = x;
	    r = 0;
	}
	return r;
}

int  Spop (SStack s, int *x) {
	int r=1;
	if (!SisEmpty){
	    *x = s->values[--s->sp];
	    r = 0;
	}
	return r;
}

int  Stop (SStack s, int *x) {
	int r=1;
	if (!SisEmpty){
	    *x = s->values[s->sp-1];
	    r = 0;
	}
	return r;
}

void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}

// Stacks with dynamic arrays

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void DinitStack (DStack s) {
	s->sp=0;
	s->size = Max;
	s->values = malloc(s->size*sizeof(int));
}

void Ddestroy(DStack s){
    s->sp=0;
    free(s->values);
}

int  DisEmpty (DStack s) {
	return (s->sp==0);
}

int  Dpush (DStack s, int x){
	int r = 0;
	if (s->sp == s->size){ //Stack is full
	    r = dupStack(s);
	}
	if (r==0){
	    s->values[(s->sp)++] = x;
	}
	return r;
}

int  Dpop (DStack s, int *x){
	int r=1;
	if (!SisEmpty){
	    *x = s->values[--s->sp];
	    r = 0;
	}
	return r;
}

int  Dtop (DStack s, int *x){
	int r=1;
	if (!SisEmpty){
	    *x = s->values[s->sp-1];
	    r = 0;
	}
	return r;
}

void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}