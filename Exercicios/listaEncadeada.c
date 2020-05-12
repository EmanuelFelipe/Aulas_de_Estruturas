#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Lista
{
    struct Registro *primeiro_elemento;
} Lista;

typedef struct Registro
{
    char valor;
    struct Registro *proximo_elemento;
} Registro;

typedef struct pilha{
    struct pilhaReg * primeiro_elemento;
}pilha;

typedef struct pilhaReg{
    char letra;
    struct pilhaReg * proximo_elemento;
}pilhaReg;

typedef struct fila{
    struct filaReg * primeiro_elemento;
}fila;

typedef struct filaReg{
    int valor;
    struct filaReg * proximo_elemento;
}filaReg;

Lista *cria_lista();
Registro *cria_registro();
pilha *cria_pilha();
fila *cria_fila();
pilhaReg *cria_pilhaReg();
filaReg *cria_filaReg();
void mostrar(Lista *l1);
char adiciono_registro(char valor_do_registro, Lista *l1);
void verificaCondicao(Lista *l, pilha *p, fila *f);
void pushPilha(pilha * l, char x);
int emptyPilha(pilha * p);
char popPilha(pilha * l);
void pushfila(fila * l, int x);
int popFila(fila *l);


int main()
{
    pilha *p1 = cria_pilha();
    Lista *l1 = cria_lista();
    fila *f1 = cria_fila();

    verificaCondicao(l1, p1, f1);

    return 0;
}

Lista *cria_lista()
{
    Lista *lista_criada = (Lista *)malloc(sizeof(Lista));

    lista_criada->primeiro_elemento = NULL;

    return lista_criada;
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

Registro *cria_registro()
{
    Registro *registro_criado = (Registro *)malloc(sizeof(Registro));

    registro_criado->valor = 0;
    registro_criado->proximo_elemento = NULL;

    return registro_criado;
}

pilhaReg *cria_pilhaReg()
{
    pilhaReg *registro_criado = (pilhaReg *)malloc(sizeof(pilhaReg));

    registro_criado->letra = 0;
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

char adiciono_registro(char valor_do_registro, Lista *l1)
{
    Registro *criado = cria_registro();
    criado->valor = valor_do_registro;

    // lista vazia, ou com elementos

    if (l1->primeiro_elemento == NULL)
    {
        l1->primeiro_elemento = criado;
        return 1;
    }
    else
    {
        Registro *aux = l1->primeiro_elemento;

        while (aux->proximo_elemento != NULL)
        {
            aux = aux->proximo_elemento;
        }
        aux->proximo_elemento = criado;
        return 1;
    }

    return 0;
}

void mostrar(Lista *l1)
{
    if (l1->primeiro_elemento == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        Registro *elemento_a_mostrar = l1->primeiro_elemento;
        while (elemento_a_mostrar != NULL)
        {
            printf("%d ->", elemento_a_mostrar->valor);
            elemento_a_mostrar = elemento_a_mostrar->proximo_elemento;
        }
        printf("\n");
    }
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

void pushPilha(pilha * l, char x){
    pilhaReg *novo_elemento, *aux;
    novo_elemento = cria_pilhaReg();
    novo_elemento->letra = x;

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

char popPilha(pilha * l){
    pilhaReg * aux = NULL;
    char retorna_ultimo;

    if(emptyPilha(l)){
        printf("pilha vazia\n");
        return 0;
    }else{
        aux = l->primeiro_elemento;
        l->primeiro_elemento = aux->proximo_elemento;
        retorna_ultimo = aux->letra;
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
        printf("pilha vazia\n");
        return 0;
    }else{
        aux = l->primeiro_elemento;
        l->primeiro_elemento = aux->proximo_elemento;
        retorna_primeiro = aux->valor;
        free(aux);
        return retorna_primeiro;
    }
}

void verificaCondicao(Lista *l, pilha *p, fila *f){
    char texto[100];
    int i, j;

    scanf("%s", texto);

    for(i = 0; i<strlen(texto); i++){
        adiciono_registro(texto[i], l);
    }
    for(j = strlen(texto); j>=0; j--){
        if(!(isdigit(texto[j]))){
            pushPilha(p, texto[j]);
        }
    }
    for(int k = 0; k<strlen(texto); k++){
        if(isdigit(texto[k])){
            pushfila(f, texto[k]);
        }
    }
    i = 0;
    while(p->primeiro_elemento != NULL){
        texto[i] = popPilha(p);
        i++;
    }
    
    while(f->primeiro_elemento != NULL){
        texto[i] = popFila(f);
    }
    for (j = 0; j<strlen(texto); j++){
        printf("%d", texto[j]);
    }
}
