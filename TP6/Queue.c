#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Queue.h"

void SinitQueue (SQueue q){
	q->length = 0; //Fila vazia
}

int  SisEmptyQ (SQueue q){
	return (q->length==0);
}

int  Senqueue (SQueue q, int x){
	int r = 1;
	
	if (q->length <Max){
	    q->values[q->front+q->length] = x;
	    r = 0;
	}
	return r;
}