#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

void bubblesort(long int *vet, long int qtd);
void mergesort(long int *vet, int inicio, int final);
void merge(long int *vet, int inicio, int meio, int final);
void selectionSort(long int *vet, int tamanho);
void insertionSort(long int *vet, int tamanho);
void quicksort(long int *vet, int inicio, int final);
long int *aloca_vetor_randomico(long int qtd);
long int *aloca_vetor_um_rand(long int qtd);

int main(int argc, char *argv[])
{
    long int tam;
    long int *vetor, *vetor_uni;
    double t1, t2;

    printf("\n Qual tamanho do vetor: ");
    scanf("%ld", &tam);

    printf("bubbleSort\n");

    t1 = omp_get_wtime();
    vetor = aloca_vetor_randomico(tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para gerar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    bubblesort(vetor, tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    vetor = aloca_vetor_um_rand(tam);
    bubblesort(vetor, tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor com apenas um fora de ordem: %lf\n", t2 - t1);

    printf("\ninsertionSort\n");

    t1 = omp_get_wtime();
    vetor = aloca_vetor_randomico(tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para gerar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    insertionSort(vetor, tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    vetor_uni = aloca_vetor_um_rand(tam);
    insertionSort(vetor_uni, tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor com apenas um fora de ordem: %lf\n", t2 - t1);

    printf("\nSelectionSort\n");

    t1 = omp_get_wtime();
    vetor = aloca_vetor_randomico(tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para gerar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    selectionSort(vetor, tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    vetor_uni = aloca_vetor_um_rand(tam);
    selectionSort(vetor_uni, tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor com apenas um fora de ordem: %lf\n", t2 - t1);

    printf("\nMergeSort\n");

    t1 = omp_get_wtime();
    vetor = aloca_vetor_randomico(tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para gerar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    mergesort(vetor, 0, tam - 1);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    vetor_uni = aloca_vetor_um_rand(tam);
    mergesort(vetor_uni, 0, tam - 1);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor com apenas um fora de ordem: %lf\n", t2 - t1);

    printf("\nQuickSort\n");

    t1 = omp_get_wtime();
    vetor = aloca_vetor_randomico(tam);
    t2 = omp_get_wtime();
    printf("\n Tempo para gerar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    quicksort(vetor, 0, tam - 1);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor: %lf", t2 - t1);

    t1 = omp_get_wtime();
    vetor_uni = aloca_vetor_um_rand(tam);
    quicksort(vetor_uni, 0, tam - 1);
    t2 = omp_get_wtime();
    printf("\n Tempo para ordenar vetor com apenas um fora de ordem: %lf\n", t2 - t1);

    return 0;
}

void bubblesort(long int *vet, long int qtd)
{
    long int aux, pass, i;
    int trocou = 1;
    for (pass = 0; pass < qtd - 1 && trocou == 1; pass++)
    {
        trocou = 0;
        for (i = 0; i < qtd - 1 - pass; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou = 1;
            }
        }
    }
}

void mergesort(long int *vet, int inicio, int final)
{
    int m;
    if (inicio < final)
    {
        m = (inicio + final) / 2;
        mergesort(vet, inicio, m);
        mergesort(vet, m + 1, final);
        merge(vet, inicio, m, final);
    }
    return;
}

void merge(long int *vet, int inicio, int meio, int final)
{
    int i, j, k, *auxiliar;
    auxiliar = (int *)calloc(sizeof(int), final - inicio + 1);
    i = inicio;
    j = meio + 1;
    k = 0;
    while (i <= meio && j <= final)
    {
        if (vet[i] <= vet[j])
        {
            auxiliar[k] = vet[i];
            i++;
        }
        else
        {
            auxiliar[k] = vet[j];
            j++;
        }
        k++;
    }
    while (i <= meio)
    {
        auxiliar[k] = vet[i];
        i++;
        k++;
    }
    while (j <= final)
    {
        auxiliar[k] = vet[j];
        j++;
        k++;
    }
    for (i = 0; i < (final - inicio) + 1; i++)
    {
        vet[inicio + i] = auxiliar[i];
    }
    free(auxiliar);
    return;
}

void selectionSort(long int *vet, int tamanho)
{
    int i, j, minimo, aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        minimo = i;
        for (j = i + 1; j < tamanho; j++)
        {
            if (vet[j] < vet[minimo])
            {
                minimo = j;
            }
        }
        aux = vet[minimo];
        vet[minimo] = vet[i];
        vet[i] = aux;
    }
}

void insertionSort(long int *vet, int tamanho)
{
    int i, aux, j;
    for (i = 1; i < tamanho; i++)
    {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > aux)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

void quicksort(long int *vet, int inicio, int final)
{
    int i, j, meio, aux;

    i = inicio;
    j = final;
    meio = vet[(inicio + final) / 2];

    do
    {
        while (vet[i] < meio)
            i++;

        while (vet[j] > meio)
            j--;

        if (i <= j)
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (inicio < j)
        quicksort(vet, inicio, j);

    if (i < final)
        quicksort(vet, i, final);
}

long int *aloca_vetor_randomico(long int qtd)
{
    long int *vetor;
    long int i;
    long int i_aux, aux;
    vetor = (long int *)malloc(sizeof(long int) * qtd);

    for (i = 0; i < qtd; i++)
    {
        vetor[i] = i + 1;
    }
    srand(time(NULL));

    for (i = 0; i < qtd; i++)
    {
        i_aux = rand() % qtd;
        aux = vetor[i];
        vetor[i] = vetor[i_aux];
        vetor[i_aux] = aux;
    }
    return vetor;
}
long int *aloca_vetor_um_rand(long int qtd)
{
    long int *vetor;
    long int i;
    long int i_aux, aux;
    vetor = (long int *)malloc(sizeof(long int) * qtd);

    for (i = 0; i < qtd; i++)
    {
        vetor[i] = i + 1;
    }
    srand(time(NULL));
    i_aux = rand() % qtd;
    aux = vetor[i];
    vetor[i] = vetor[i_aux];
    vetor[i_aux] = aux;
    return vetor;
}
