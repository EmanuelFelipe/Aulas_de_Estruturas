#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pilha{
    struct pilhaReg * primeiro_elemento;
}pilha;

typedef struct pilhaReg{
    int valor;
    struct pilhaReg * proximo_elemento;
}pilhaReg;

typedef struct fila{
    struct filaReg * primeiro_elemento;
}fila;

typedef struct filaReg{
    int valor;
    struct filaReg * proximo_elemento;
}filaReg;

pilha *cria_pilha();
fila *cria_fila();
pilhaReg *cria_pilhaReg();
filaReg *cria_filaReg();
void pushPilha(pilha * l, int x);
int emptyPilha(pilha * p);
int popPilha(pilha * l);
void pushfila(fila * l, int x);
int popFila(fila *l);
void verificaCondicao(pilha *p, fila *f);

int main()
{
    pilha *p1 = cria_pilha();
    fila *f1 = cria_fila();

    verificaCondicao(p1, f1);

    return 0;
}

pilha *cria_pilha()
{
    pilha *lista_criada = (pilha *)malloc(sizeof(pilha));

    lista_criada->primeiro_elemento = NULL;

    return lista_criada;
}

fila *cria_fila()
{
    fila *lista_criada = (fila *)malloc(sizeof(fila));

    lista_criada->primeiro_elemento = NULL;

    return lista_criada;
}

pilhaReg *cria_pilhaReg()
{
    pilhaReg *registro_criado = (pilhaReg *)malloc(sizeof(pilhaReg));

    registro_criado->valor = 0;
    registro_criado->proximo_elemento = NULL;

    return registro_criado;
}

filaReg *cria_filaReg()
{
    filaReg *registro_criado = (filaReg *)malloc(sizeof(filaReg));

    registro_criado->valor = 0;
    registro_criado->proximo_elemento = NULL;

    return registro_criado;
}

int emptyPilha(pilha * p){
    if(p->primeiro_elemento == NULL){
        return 1;
    }else{
        return 0;
    }
}

int emptyFila(fila * f){
    if(f->primeiro_elemento == NULL){
        return 1;
    }else{
        return 0;
    }
}

void pushPilha(pilha * l, int x){
    pilhaReg *novo_elemento, *aux;
    novo_elemento = cria_pilhaReg();
    novo_elemento->valor = x;

    if (emptyPilha(l)) 
    {
        l->primeiro_elemento = novo_elemento;
    }
    else
    {
        novo_elemento->proximo_elemento = l->primeiro_elemento;
        l->primeiro_elemento = novo_elemento;
    }
}

int popPilha(pilha * l){
    pilhaReg * aux = NULL;
    int retorna_ultimo;

    if(emptyPilha(l)){
        printf("pilha vazia\n");
        return 0;
    }else{
        aux = l->primeiro_elemento;
        l->primeiro_elemento = aux->proximo_elemento;
        retorna_ultimo = aux->valor;
        free(aux);
        return retorna_ultimo;
    }
}

void pushfila(fila * l, int x){
    filaReg *novo_elemento, *aux;
    novo_elemento = cria_filaReg();
    novo_elemento->valor = x;

    if (emptyFila(l)) 
    {
        l->primeiro_elemento = novo_elemento;
    }
    else
    {
        filaReg *elemento_a_botar = l->primeiro_elemento;
        
        while (elemento_a_botar->proximo_elemento != NULL)
        {
            elemento_a_botar = elemento_a_botar->proximo_elemento;
        }
        elemento_a_botar->proximo_elemento = novo_elemento;
    }
}

int popFila(fila * l){
    filaReg * aux = NULL;
    int retorna_primeiro;

    if(emptyFila(l)){
        printf("fila vazia\n");
        return 0;
    }else{
        aux = l->primeiro_elemento;
        l->primeiro_elemento = aux->proximo_elemento;
        retorna_primeiro = aux->valor;
        free(aux);
        return retorna_primeiro;
    }
}

void verificaCondicao(pilha *p, fila *f){
    int tam, x[100],i , j, aux, teste;

    printf("tamanho do vetor\n");
    scanf("%d", &tam);

    for(i = 0; i<tam; i++){
        scanf("%d", &teste);
        pushfila(f, teste);
    }for(j = 0; j<tam; j++){
        aux = popFila(f);
        pushPilha(p, aux);
    }for(i = 0; i<tam; i++){
        aux = popPilha(p);
        printf("%d, ", aux);
    }
}
