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
void verifica_ordem(Lista * l1);

void menu(Lista * l1){
    int opcao;
    int valor;
    do{
        printf("menu\n");
        printf("0-SAIR\n");
        printf("1-ADICIONAR\n");
        printf("2-REMOVER ULTIMO\n");
        printf("3-REMOVER ESPECIFICO\n");
        printf("4-BUSCAR\n");
        printf("5-MOSTRAR\n");
        printf("6-ORDEORDENADO\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
           printf("saindo do programa\n");
            break;
        case 1:
            printf("adiciona um valor ai meu patrao\n");
            scanf("%d", &valor);
            adiciona_lista(l1,valor);        
            break;
        case 2:
            remove_ultimo(l1);
            break;
        case 3:
            printf("qual valor quer remover, ein arrombadinho?\n");
            scanf("%d", &valor);
            remove_especifico(l1, valor);
            break;
        case 4: 
            printf("essa funcao nao existe no momento\n");
            break;
        case 5:
            mostrar(l1);
            break;
        case 6:
            verifica_ordem(l1);
            break;
        default:
            printf("e quem te disse q essa opcao existe\n");
            break;
        }
    }while(opcao == 0);
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
        while(aux->proximo_elemento != NULL){
            if(aux->valor = x){
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
void verifica_ordem(Lista * l1){
    if (l1->ultimo_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l1->primeiro_elemento;
        while(aux != NULL){

            if(aux->elemento_anterior == NULL){
            aux = aux->proximo_elemento;
            continue;    
            }
            if(aux->elemento_anterior->valor>aux->valor){
                printf("nao, esse trem nao ta crescente\n");
                break;
            }
            aux = aux->proximo_elemento;
        }
        if(aux->proximo_elemento==NULL){
            printf("sim, esse trem ta ordenado\n");
        }
    }
}

