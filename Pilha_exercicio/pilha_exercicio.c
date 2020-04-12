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
    void mostrar(Lista * l1);
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
void mostrar(Lista * l1){
    int x;
    char y;
    if(l1->primeiro_elemento == NULL){
        printf("\n Pilha vazia");
    }else{
        Registro * elemento_a_mostrar = l1->primeiro_elemento;
        while (elemento_a_mostrar!= NULL){   
            x++;
            y = elemento_a_mostrar->valor;
            printf("%s ", y);
            elemento_a_mostrar = elemento_a_mostrar->proximo_elemento;
        }
    }
}

void verificaCondicao(Lista * l1){
    char *caracteres;
    caracteres = (char * )malloc(sizeof(char) * 50);
    int i, j, x;

    printf("quais caracteres deseja comparar?\n");
    scanf("%s", caracteres);

    for (i = 0; i < strlen(caracteres); i++){
        if (caracteres[i] == 'C'){
            j = 1;
        }
        else{
            if (j == 0){
                push(l1, caracteres[i]);
            }
            else{
                //auxiliar = pop(l1);
                //x = strcmp(caracteres[i], auxiliar[i]);
                // if (x != 0){
                if(pop(l1) != caracteres[i]){
                    printf("Nao condiz com xCy!\n");
                    break;
                }else{
                    printf("condiz com xCy\n");
                }
            }
        }
    }
}
// isso foi oq eu consegui fazer