#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista
{
    struct Registro *primeiro_elemento;
} Lista;

typedef struct Registro
{
    int valor;
    struct Registro *proximo_elemento;
} Registro;

Lista *cria_lista();
Registro *cria_registro();
void push(Lista *l, int x);
int pop(Lista *l);
int empty(Lista *l);
void verificaTempo(Lista *l);

int main()
{

    Lista *l1;
    l1 = cria_lista();
    verificaTempo(l1);
    return 0;
}

Lista *cria_lista()
{
    Lista *Retorno = (Lista *)malloc(sizeof(Lista));

    Retorno->primeiro_elemento = NULL;

    return Retorno;
}

Registro *cria_registro()
{
    Registro *Registro_criado = (Registro *)malloc(sizeof(Registro));

    Registro_criado->proximo_elemento = NULL;
    Registro_criado->valor = -1;
}

int empty(Lista *l)
{
    if (l->primeiro_elemento == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Lista *l, int x)
{
    Registro *novo_elemento, *aux;
    novo_elemento = cria_registro();
    novo_elemento->valor = x;

    if (empty(l))
    {
        l->primeiro_elemento = novo_elemento;
    }
    else
    {
        Registro *aux = l->primeiro_elemento;

        while (aux->proximo_elemento != NULL)
        {
            aux = aux->proximo_elemento;
        }
        aux->proximo_elemento = novo_elemento;
    }
}

int pop(Lista *l)
{
    Registro *aux = NULL;
    int retorna_ultimo;

    if (empty(l))
    {
        printf("fila vazia\n");
        return 0;
    }
    else
    {
        aux = l->primeiro_elemento;
        l->primeiro_elemento = aux->proximo_elemento;
        retorna_ultimo = aux->valor;
        free(aux);
        return retorna_ultimo;
    }
}

void verificaTempo(Lista *l)
{
    int n, tempo, aux = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempo);
        push(l, tempo);
    }

    for (int i = 0; i < n; i++)
    {
        tempo = pop(l);
        tempo = tempo + aux;
        aux = tempo;
    }


    printf("%d\n", tempo);
}
