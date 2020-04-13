#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    struct Registro * primeiro_elemento;
}Lista;



typedef struct Registro{
    char valor;
    struct Registro * proximo_elemento;
}Registro;

    Lista * cria_lista();
    Registro * cria_registro();
    void push(Lista * l, char x);
    char pop(Lista * l);
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

void push(Lista * l, char x){
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

char pop(Lista * l){
    Registro * aux = NULL;
    char retorna_ultimo;

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
    char *parenteses;
    parenteses = (char * )malloc(sizeof(char) * 50);
    int i, j=0, x, fechado = 0;

    printf("Qual expressão quer verificar?\n");
    scanf("%s", parenteses);

    for(i=0; i<strlen(parenteses); i++){
        if (parenteses[i] == '('){
            push(l1, parenteses[i]);
        }else{
            if(parenteses[i] == ')' && pop(l1) != '(' && l1->primeiro_elemento ==NULL){
                printf("manito como q tu começa abrindo um parenteses assim?\n");
                fechado = 1;
                break;
            }
        }
    }
    if(l1->primeiro_elemento == NULL && fechado == 0){
        printf("sua expressao esta corretissima man, tds os parenteses fecham\n");
    }else{
        printf("ta faltando parenteses ai campeão\n");
    }
}
// isso foi oq eu consegui fazer