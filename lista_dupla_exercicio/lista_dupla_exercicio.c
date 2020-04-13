#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    struct Registro * primeiro_elemento;
    struct Registro * ultimo_elemento;
}Lista;



typedef struct Registro{
    int valor;
    struct Registro * proximo_elemento;
    struct Registro * elemento_anterior;
}Registro;

Lista * cria_lista();
Registro * cria_registro();
void mostrar(Lista * l1);
void adiciona_lista(Lista * l1, int x);
void remove_ultimo(Lista * l1);
void remove_especifico(Lista * l1, int x);
void mostrar(Lista * l1);
void removePrimo(Lista * l);
int isPrimo(int x);

void menu(Lista * l1){
    int opcao;
    int x;
    do{
        printf("menu\n");
        printf("0-SAIR\n");
        printf("1-ADICIONAR\n");
        printf("2-REMOVER ULTIMO\n");
        printf("3-REMOVER ESPECIFICO\n");
        printf("4-MOSTRAR\n");
        printf("5-REMOVE PRIMO\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("saindo do programa\n");
            break;
        case 1:
            printf("adiciona um valor ai meu patrao\n");
            scanf("%d", &x);
            adiciona_lista(l1,x);        
            break;
        case 2:
            remove_ultimo(l1);
            break;
        case 3:
            printf("qual valor quer remover?\n");
            scanf("%d", &x);
            remove_especifico(l1, x);
            break;
        case 4:
            mostrar(l1);
            break;
        case 5:
            removePrimo(l1);
            break;
        default:
            printf("e quem te disse q essa opcao existe\n");
            break;
        }
    }while(opcao != 0);
}

int main(){
    Lista * l1 = cria_lista();
    menu(l1);
    return 0;

}

Lista * cria_lista(){
    Lista * Retorno = (Lista *)malloc(sizeof(Lista));

    Retorno -> primeiro_elemento = NULL;
    Retorno -> ultimo_elemento = NULL;

    return Retorno;
}

Registro * cria_registro(){
    Registro * registro_criado = (Registro *)malloc(sizeof(Registro));

    registro_criado->valor = 0;
    registro_criado->proximo_elemento = NULL;
    registro_criado->elemento_anterior = NULL;

    return registro_criado;
}

void adiciona_lista(Lista * l1, int x){
    Registro * criado = cria_registro();
    criado->valor = x;

    // lista vazia
    if(l1->primeiro_elemento == NULL){
        l1->primeiro_elemento = criado;
        l1->ultimo_elemento=criado;
        printf("Adicionei meu patrao\n");
    }else{
        Registro * aux = l1->ultimo_elemento;

        l1->ultimo_elemento = criado;
        criado->elemento_anterior = aux;
        aux->proximo_elemento = criado;  
        printf("adicionei mais um meu patrao\n");
    }

}
void remove_ultimo(Lista * l1){
    if (l1->ultimo_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l1->ultimo_elemento;

        l1->ultimo_elemento = aux->elemento_anterior;
        aux->elemento_anterior->proximo_elemento = NULL; 
        free(aux);
        printf("apaguei o ultimo aqui, agr vaza\n");
    }
}
void remove_especifico(Lista * l1, int x){

    if (l1->ultimo_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l1->primeiro_elemento;
        while(aux != NULL){
            if(aux->valor == x){
                printf("elemento encontrado\n");
                break;
            }
            aux = aux->proximo_elemento;
        }
        if(aux == l1->primeiro_elemento){
            l1->primeiro_elemento = aux->proximo_elemento;
            aux->proximo_elemento->elemento_anterior = NULL;
            free(aux);
            printf("apagou e se nao queria se foldeu\n");
        }else{
            if(aux == l1->ultimo_elemento){
                remove_ultimo(l1);
            }else{
                aux->elemento_anterior->proximo_elemento = aux->proximo_elemento;
                aux->proximo_elemento->elemento_anterior = aux->elemento_anterior;
                free(aux);
                printf("se foudeu se foudeu o problema é seu (apaguei hehe).\n"); 
            }
        }
    }
}
void mostrar(Lista * l1){
    if(l1->primeiro_elemento == NULL){
        printf("\n Lista vazia");
    }else{
        Registro * elemento_a_mostrar = l1->primeiro_elemento;
        while (elemento_a_mostrar!= NULL)
        {
            printf("%d-> ", elemento_a_mostrar->valor);
            elemento_a_mostrar = elemento_a_mostrar->proximo_elemento;
        }
        printf("\n");
    }
}
void removePrimo(Lista * l){
    if (l->ultimo_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l->primeiro_elemento;
        
        while(aux != NULL){
            if(isPrimo(aux->valor)){
            remove_especifico(l, aux->valor);
            }
            aux = aux->proximo_elemento;
        }
    }
}
int isPrimo(int x){
    int i, isPrimoValor=0;
    if(x==1){
        return 0;
    }
    for (i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            isPrimoValor++;
        }
    }if(isPrimoValor == 1){
        return 0;
    }else{
        return 1;
    }
}
