#include <stdio.h>

// Protótipos das funções
void mergeSort(int array[], int inicio, int fim);
void merge(int array[], int inicio, int meio, int fim);

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original: \n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", array[i]);
    printf("\n");

    mergeSort(array, 0, tamanho - 1);

    printf("Array ordenado: \n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

// Implementação da função mergeSort
void mergeSort(int array[], int inicio, int fim) {    
    if (inicio < fim) {        
        int meio = inicio + (fim - inicio) / 2;        
        mergeSort(array, inicio, meio);        
        mergeSort(array, meio + 1, fim);        
        merge(array, inicio, meio, fim);    
    }
}

// Implementação da função merge
void merge(int array[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    
    int subarrayEsquerdo[n1], subarrayDireito[n2];
    
    for (int i = 0; i < n1; i++) 
        subarrayEsquerdo[i] = array[inicio + i];
    for (int i = 0; i < n2; i++) 
        subarrayDireito[i] = array[meio + 1 + i];
    
    int i = 0, j = 0, k = inicio;
    
    while (i < n1 && j < n2) {
        if (subarrayEsquerdo[i] <= subarrayDireito[j]) {
            array[k] = subarrayEsquerdo[i];
            i++;
        } else {
            array[k] = subarrayDireito[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        array[k] = subarrayEsquerdo[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = subarrayDireito[j];
        j++;
        k++;
    }
}
