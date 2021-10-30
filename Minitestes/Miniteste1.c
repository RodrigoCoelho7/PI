#include<stdio.h>

int func(int x) {
  int r = 0;
  while (x > 0) {
    r += 1;
    x = x - r;
  }
  printf("%d\n",r);
  return r;
}



int main(){

func(7);

int x,y;
for (y=0;y<8;y++) {    
  for (x=0;x<8;x++) {
      if (x-y==0)
        putchar('#');
    else
        putchar('.');
  }
  putchar('\n');
}
return 0;
}