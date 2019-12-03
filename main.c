#include <stdio.h>
#include <stdlib.h>

const int N=5;

int busL (int [], int);
int busB (int [], int);
void insertion (int []);
void selection (int []);
void bubble (int []);

int main()
{
    int x, y, i, v[N];
    for (i=0; i<N; i++){
        scanf("%d", &v[i]);
    }
    printf("\n Esse eh o seu vetor atual:");
    for (i=0; i<N; i++){
        printf("% d", v[i]);
    }
    printf("\n \n MENU \n 1. Para Bubble Sort \n 2. Para Selection Sort \n 3. Para Insertion Sort \n 4. Para Busca Binária (requer um vetor ja ordenado) \n 5. Para Busca Linear");
    scanf("%d", &x);
    if (x==1){
        printf("%d", bubble(v));
    }
    else {
        if (x==2){
            printf("%d", selection(v));
        }
        else {
            if (x==3){
                printf("%d", insertion(v));
            }
            else {
                if (x==4){
                    printf("\n Digite o valor a ser encontrado");
                    scanf("%d", &y);
                    printf("%d", busB(v, y));
                }
                else {
                    if (x==5){
                        printf("\n Digite o valor a ser encontrado");
                        scanf("%d", &y);
                        printf("%d", busL(v, y));
                    }
                    else {
                        printf("Opcao nao existe");
                    }
                }
            }
        }
    }
}

void bubble (int v[]){
    int x, i, j, aux;
    printf("\n 1. Para ordem crescente \n 2. Para ordem decrescente");
    scanf("%d", &x);
    if (x == 1){
        for(i=0; i<N-1; i++){
            for (j=0; j<N-i-1; j++){
                if (v[j] > v[j+1]){
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }
    else{
        for(i=0; i<N-1; i++){
            for (j=0; j<N-i-1; j++){
                if (v[j] < v[j+1]){
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }
}


void selection (int v[]){
    int x, i, j, menor, aux;
    printf("\n 1. Para ordem crescente \n 2. Para ordem decrescente");
    scanf("%d", &x);
    if(x == 1){
        for(i=0; i<N; i++){
			menor = i;
			for(j=i; j<N; j++){
				if(v[menor] > v[j]){
					menor = j;
				}
			}
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
    }
    else{
        for(i=0; i<N; i++){
			menor=i;
			for(j=i; j<N; j++){
				if(v[menor] < v[j]){
					menor = j;
				}
			}
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
    }
}

void insertion (int v[]){
    int x, i, j, aux;
    printf("\n 1. Para ordem crescente \n 2. Para ordem decrescente");
    scanf("%d", &x);
    if (x == 1){
        for(i=1; i<N; i++){
            aux = v[i];
            j = i-1;
            while((aux < v[j]) && (j >= 0)){
                v[j+1] = v[j];
                j = j-1;
            }
            v[j+1] = aux;
        }
    }
    else{
        for(i=1; i<N; i++){
            aux = v[i];
            j = i-1;
            while((aux > v[j]) && (j >= 0)){
                v[j+1] = v[j];
                j = j-1;
            }
            v[j+1] = aux;
        }
    }
}

int busB (int v[], int x){
    int i, j, k;
    i=0; j=N-1;
    while(i <= j){
        k = (i+j)/2;
        if (v[k] == x){
            return k;
        }
        if (v[k] < N){
            i = k+1;
        }
        else{
            j = k-1;
        }
   }
   return -1;
}

int busL (int v[], int x){
    int i;
    for(i=0;i<=N;i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}
