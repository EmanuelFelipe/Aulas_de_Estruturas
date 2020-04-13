#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    struct Registro * primeiro_elemento;
    struct Registro *ultimo_elemento;
}Lista;



typedef struct Registro{
    int valor;
    struct Registro * proximo_elemento;
}Registro;

Lista * cria_lista();
Registro * cria_registro();
int empty(Lista * l);
void push(Lista * l, char x);
void pop(Lista *l);
void mostrar(Lista * l);
void menu(Lista * l);

int main(){
    Lista * l1 = cria_lista();
    menu(l1);
    return 0;
}

void menu(Lista * l){
    int opcao, valor;

    do{
        printf("menu\n");
        printf("0-SAIR\n");
        printf("1-PUSH\n");
        printf("2-POP\n");
        printf("3-ESTA VAZIA?\n");
        printf("4-MOSTRAR\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("qual valor deseja colocar meu patrao?\n");
                scanf("%d", &valor);
                push(l, valor);
                break;
            case 2:
                pop(l);
                break;
            case 3:
                if(empty(l)){
                    printf("Fila vazia mermao\n");
                }else{
                    printf("existem elementos na fila cara\n");
                }
                break;
            case 4:
                mostrar(l);
                break;
            case 0:
            printf("saindo\n");
            break;
            default:
                printf("ah nao man, bota um numero q tem ai pf\n");
                break;
        }
    }while(opcao!=0);
}

Lista * cria_lista(){
    Lista * Retorno = (Lista *)malloc(sizeof(Lista));

    Retorno -> primeiro_elemento = NULL;
    Retorno -> ultimo_elemento = NULL;

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
        l->ultimo_elemento = novo_elemento;
        printf("adicionei o primeiro aqui man\n");
    }
    else
    {
       Registro * aux = l->ultimo_elemento;

        aux->proximo_elemento = novo_elemento;
        novo_elemento->proximo_elemento= l->primeiro_elemento;
        l->ultimo_elemento = novo_elemento;
        printf("adicionei outro cara\n");
    }
}
void pop(Lista *l){
    Registro * aux = NULL;
    if(empty(l)){
        printf("fila vazia\n");
    }else{
        aux = l->primeiro_elemento;
        l->primeiro_elemento = aux->proximo_elemento;
        l->ultimo_elemento->proximo_elemento = l->primeiro_elemento;
        printf("Dei pop no %d, campeao\n", aux->valor);
        free(aux);
    }
}
void mostrar(Lista * l){
    if(empty(l)){
        printf("pilha vazia\n");
    }else{
        Registro * aux = l->primeiro_elemento;
        int contador=0;

        while(aux->proximo_elemento != l->primeiro_elemento ){
            contador++;
            printf("%d - %d\n", contador, aux->valor);
            aux = aux->proximo_elemento;
        }
    }
}

