#include <stdio.h>
#include <stdlib.h>

void menu(int tam);
long int *aloca_vetor(long int tam);
void incluir(long int *vet, int num, int tam);
void mostrar(long int *vet, int tam);
void buscar(long int *vet, int x, int tam);

int main()
{
    int n;

    printf("tamanho do vetor: \n");
    scanf("%d", &n);

    menu(n);
}

void menu(int tam)
{
    long int *vetor;
    int numero, opcao, x;

    vetor = aloca_vetor(tam);
    do
    {
        printf("\nDigite sua opcao\n");
        printf("0 - sair\n");
        printf("1 - inserir\n");
        printf("2 - buscar\n");
        printf("3 - mostrar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            printf("Numero: \n");
            scanf("%d", &numero);
            incluir(vetor, numero, tam);
            break;
        case 2:
            printf("buscar qual numero: \n");
            scanf("%d", &x);
            buscar(vetor, x, tam);
            break;
        case 3:
            mostrar(vetor, tam);
            break;
        }
    } while (opcao != 0);
}

long int *aloca_vetor(long int tam)
{
    long int *vetor;
    long int i;
    long int i_aux, aux;
    vetor = (long int *)malloc(sizeof(long int) * tam);

    for (i = 0; i < tam * 2; i++)
    {
        vetor[i] = -1;
    }

    return vetor;
}

void incluir(long int *vet, int num, int tam)
{
    if (vet[0] == -1)
    {
        vet[0] = num;
    }
    else
    {
        for (int i = 0; i < tam * 2; i++)
        {
            if (num < vet[i] && vet[i * 2 + 1] == -1)
            {
                vet[i * 2 + 1] = num;
                break;
            }
            else if (num > vet[i] && vet[i * 2 + 2] == -1)
            {
                vet[i * 2 + 2] = num;
                break;
            }
            else
            {
                continue;
            }
        }
    }
}

void mostrar(long int *vet, int tam)
{
    if (vet[0] == -1)
    {
        printf("arvore vazia");
    }
    else
    {
        for (int i = 0; i < tam * 2; i++)
        {
            if (vet[i] == -1)
            {
                continue;
            }
            else
            {
                printf("\nvetor[%d] = %ld\n", i, vet[i]);
            }
        }
    }
}

void buscar(long int *vet, int x, int tam)
{
    if (vet[0] == -1)
    {
        printf("arvore vazia");
    }
    else
    {
        for (int i = 0; i < tam * 2; i++)
        {
            if (x == vet[i])
            {
                printf("\nvetor[%d] = %ld numero encontrado\n", i, vet[i]);
                break;
            }
            else
            {
                continue;
            }
        }
    }
}
