#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    struct Registro * primeiro_elemento;
}Lista;



typedef struct Registro{
    int valor;
    struct Registro * proximo_elemento;
}Registro;

    Lista * cria_lista();
    Registro * cria_registro();
    void push(Lista * l, int x);
    int pop(Lista * l);
    int empty(Lista * l);
    void verificaCondicao(Lista * l1);

int main(){

    Lista * l1;
    l1 = cria_lista();
    verificaCondicao(l1);
    return 0;
}

Lista * cria_lista(){
    Lista * Retorno = (Lista *)malloc(sizeof(Lista));

    Retorno -> primeiro_elemento = NULL;

    return Retorno;
}

Registro * cria_registro(){
    Registro * Registro_criado = (Registro *)malloc(sizeof(Registro));

    Registro_criado->proximo_elemento = NULL;
    Registro_criado->valor = -1;
}

int empty(Lista * l){
    if(l->primeiro_elemento == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Lista * l, int x){
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

int pop(Lista * l){
    Registro * aux = NULL;
    int retorna_ultimo;

    if(empty(l)){
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

void verificaCondicao(Lista * l1){
    char x[100];
    int tam, qtdE=0, qtdI=0;

    scanf("%s", x);

    for(int i=0; i<strlen(x); i++){
        if (x[i] == 'I'){
            qtdI++;
            push(l1, x[i]);
        }else if(x[i] == 'E'){
            if(empty(l1)){
                printf("situação invalida\n");
            }else{
            qtdE++;
            pop(l1);
            }
        }
    }
    if(qtdI == qtdE){
        printf("valido\n");
    }else{
        printf("invalido\n");
    }
}