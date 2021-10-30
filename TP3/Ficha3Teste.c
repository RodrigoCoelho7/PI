#include<stdio.h>

void swapM (int *x, int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

void swap(int v[],int i, int j){
    int temp;
    temp = v[i];
    v[i]=v[j];
    v[j]=temp;
}

int soma(int v[], int N){
    int r=0,i=0;
    while(i<N){
        r+=v[i];
        i++;
    }
    return r;
}

void PrintArray(int v[], int N){
    int i;
    for(i=0;i<N;i++)
        printf("%d,",v[i]);
}

void InverteArray(int v[], int N){
    int r, i;
    for(i=0;i<N/2;i++)
        swap(v,i,N-1-i);
    PrintArray(v,N);
}

void InverteArrayV2(int v[], int N){
    int r, i;
    for(i=0;i<N/2;i++)
        swapM(v+i,v+(N-1-i));
    PrintArray(v,N);
}

int maximum(int v[], int N, int *m){
    int r,i;

    if (N>0){
        r=0;
        *m = v[0];
        for(i=0;i<N;i++){
            if (v[i]>*m)   *m = v[i];
        }
    }
    else r=-1;

    return r;
}

void quadrados(int q[], int N){
    int i;
    if (N>0){
        q[0] = 0;
        for(i=1;i<N;i++)
            q[i] = q[i-1] + (2*(i-1)+1);
    }
    PrintArray(q,N);
}

void Pascal(int v[],int N){
    int i,n;
    for(n=1;n<=N;n++){
        v[n-1] = 1;
        v[0]=1;
        for(i=n-2;i>0;i--)
            v[i] = v[i] + v[i-1];
    }
    PrintArray(v,N);
}

void PascalV2(int v[], int N){
    int i,j;
    for(i=0;i<N;i++){
        j=i;
        while(j>=0){
            if (j==i)  v[j]=1;
            else if (j>0) v[j] += v[j-1];
            j--;
        }
    }
}

void PascalV3(int v[], int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=i;j>=0;j--){
            if (i==j)  v[j] = 1;
            else v[j] = v[j] + v[j-1];
        }
    }
    PrintArray(v,N);
}

void Printpascal(int v[],int N){
    int k;
    for (k=0;k<N;k++){
        PascalV3(v,k);
        PrintArray(v,k);
        putchar('\n');
    }
}

int main(){
    int a=5,b=10;
    //swapM(&a,&b);
    //printf("%d %d\n",a,b);
    int v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
    int z[11] = {1,2,3,4,5,6,7,8,9,10,11};
    //printf("%d %d\n",v[0],v[9]);
    //swap(v,0,9);
    //printf("%d %d\n",v[0],v[9]);
    //int c = soma(v,10);
    //printf("%d",c);
    //InverteArrayV2(z,11);
    //int c=0;
    //maximum(z,11,&c);
    //printf("%d",c);
    //quadrados(v,10);
    PascalV3(v,6);
    //Printpascal(v,10);
    return 0;
}