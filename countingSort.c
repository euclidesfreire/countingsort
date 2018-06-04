#include <stdio.h>
#include <stdlib.h>

int countingSort(int *vet, int maior, int N);


int main(){
    int *vet, N=1, i, maior;

    while(N){
        maior = 0;
		
		printf("Digite N: ");
		
        scanf("%d", &N);

        if(!N) return 0;

        N += 1;

        vet = (int *) malloc(N*sizeof(int));

        for(i=1; i<N; i++){
        	printf("Digite o numero %d: ", i);
            scanf("%d", &vet[i]);
            if(vet[i]>maior) maior = vet[i];
        }

        countingSort(vet, maior+1, N);

        for(i=1; i<N; i++)
            printf("%d ", vet[i]);

        printf("\n");
    }

    return 0;
}

int countingSort(int *vet, int maior, int N){
    int *vet2, i, j=1, aux;

    vet2 = (int *) malloc(maior*sizeof(int)); //ALOCA MEMORIA PARA O VET2

    for(i=1; i<maior; i++) {
            vet2[i] = 0; //INICIALIZAR O VETOR COM 0;
    }

    for(i=1; i<N; i++) {
        vet2[vet[i]] += 1;
    }

    for(i=1; i<maior; i++){
        while(vet2[i]){
            vet[j++] = i;
            vet2[i] -= 1;
        }
    }
}
