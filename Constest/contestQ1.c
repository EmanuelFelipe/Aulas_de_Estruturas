#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista
{
    struct Registro *primeiro_elemento;
} Lista;

typedef struct Registro
{
    char valor;
    struct Registro *proximo_elemento;
} Registro;

Lista *cria_lista();
Registro *cria_registro();
void push(Lista *l, char x);
char pop(Lista *l);
int empty(Lista *l);
void verificaCondicao(Lista *l1);

int main()
{

    Lista *l1;
    l1 = cria_lista();
    verificaCondicao(l1);
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

void push(Lista *l, char x)
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
        novo_elemento->proximo_elemento = l->primeiro_elemento;
        l->primeiro_elemento = novo_elemento;
    }
}

char pop(Lista *l)
{
    Registro *aux = NULL;
    char retorna_ultimo;

    if (empty(l))
    {
        printf("pilha vazia\n");
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
void verificaCondicao(Lista *l1)
{
    char popTeste1;
    int i, j, qtd, fechado = 0;

    scanf("%d", &qtd);
    char documentosfelipe[qtd];

    for (i = 0; i < qtd; i++)
    {
        scanf("%s", &documentosfelipe[i]);
    }
        
    for (i = qtd; i >= 0; i--){
        push(l1, documentosfelipe[i]);
    }
    

    for (i = 0; i < qtd; i++)
    {
            popTeste1 = pop(l1);

            if (popTeste1 == documentosfelipe[i+1])
            {
                fechado = 1;
                break;
            }
            else if (popTeste1 == '{' && documentosfelipe[i+1] == '}')
            {
                fechado = 1;
                break;
            }
            else if (popTeste1 == '(' && documentosfelipe[i+1] == ')')
            {
                fechado = 1;
                break;
            }
        
    }
    if (fechado == 0)
    {
        printf("rasta\n");
    }
    else
    {
        printf("lascou\n");
    }
}
