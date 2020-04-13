#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int qtd_elementos;
    struct Registro * primeiro_elemento;
}Lista;



typedef struct Registro{
    int valor;
    struct Registro * proximo_elemento;
}Registro;

Lista * cria_lista();
Registro * cria_registro();
void mostrar(Lista * l1);
void adiciona_lista(Lista * l1, int x);
void remove_ultimo(Lista * l1);
void remove_especifico(Lista * l1, int x);
void mostrar(Lista * l1);
void verificaOrdem(Lista * l1);
void mostraPosteriorAnterior(Lista * l1, int x);

void menu(Lista * l1){
    int opcao;
    int valor;
    do{
        printf("menu\n");
        printf("0-SAIR\n");
        printf("1-ADICIONAR\n");
        printf("2-REMOVER ULTIMO\n");
        printf("3-REMOVER ESPECIFICO\n");
        printf("4-MOSTRAR\n");
        printf("5-MOSTRAR POSTERIOR E ANTERIOR\n");
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
            printf("qual valor quer remover?\n");
            scanf("%d", &valor);
            remove_especifico(l1, valor);
            break;
        case 4:
            mostrar(l1);
            break;
        case 5:
            printf("qual valor quer ver o posterior e anterior?\n");
            scanf("%d", &valor);
            mostraPosteriorAnterior(l1, valor);
            
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
    Retorno -> qtd_elementos = 0;

    return Retorno;
}

Registro * cria_registro(){
    Registro * registro_criado = (Registro *)malloc(sizeof(Registro));

    registro_criado->valor = 0;
    registro_criado->proximo_elemento = NULL;

    return registro_criado;
}

void adiciona_lista(Lista * l1, int x){
    Registro * criado = cria_registro();
    criado->valor = x;

    // lista vazia
    if(l1->primeiro_elemento == NULL){
        l1->primeiro_elemento = criado;
        l1->qtd_elementos++;
        printf("Adicionei meu patrao\n");
        printf("%d\n", l1->qtd_elementos);
    }else{
        Registro * aux = l1->primeiro_elemento;

        while(aux->proximo_elemento != NULL){
            aux = aux->proximo_elemento;
        }
        aux->proximo_elemento = criado;
        printf("adicionei mais um meu patrao\n");
        l1->qtd_elementos++;
    }

}
void remove_ultimo(Lista * l1){
    if (l1->primeiro_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l1->primeiro_elemento;
        Registro * ant = NULL;

        while(aux->proximo_elemento->proximo_elemento != NULL){
            aux = aux->proximo_elemento;
        }
        ant = aux;
        aux = aux->proximo_elemento;
        ant->proximo_elemento = NULL;
        free(aux);
        printf("apaguei o ultimo aqui, agr vaza\n");
        l1->qtd_elementos--;
    }
}
void remove_especifico(Lista * l1, int x){

    if (l1->primeiro_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l1->primeiro_elemento;
        Registro * ant = NULL;
        while(aux->valor != x){
            if(aux->proximo_elemento !=NULL){
            ant = aux;
            aux = aux->proximo_elemento;
            }
        }
        if(aux == l1->primeiro_elemento){
            l1->primeiro_elemento = aux->proximo_elemento;
            free(aux);
            printf("apagou e se nao queria se foldeu\n");
            l1->qtd_elementos--;
        }else{
            if(aux->proximo_elemento == NULL){
                remove_ultimo(l1);
            }else{
                ant->proximo_elemento = aux->proximo_elemento;
                free(aux);
                printf("se foudeu se foudeu o problema é seu (apaguei hehe).\n"); 
                l1->qtd_elementos--;
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
void mostraPosteriorAnterior(Lista * l1, int x){
    if (l1->primeiro_elemento == NULL){
        printf("tem nada aqui nao, entao nao me enche o saco\n");
    }else{
        Registro * aux = l1->primeiro_elemento;
        Registro * ant = NULL;

        while(aux->valor != x){
            if(aux->proximo_elemento !=NULL){
            ant = aux;
            aux = aux->proximo_elemento;
            }
        }
        printf("%d", aux->proximo_elemento->valor);
    printf("elemento atual: %d\n", x);
    if(aux->valor == l1->primeiro_elemento->valor  && l1->qtd_elementos != 1){
        printf("nao tem anterior\n");
        printf("posterior: %d\n", aux->proximo_elemento->valor);
    }if (aux->proximo_elemento == NULL && l1->qtd_elementos !=1){
        printf("anterior: %d\n", ant->valor);
        printf("nao tem posterior\n");
    }if (l1->qtd_elementos == 1){
        printf("nao tem anterior\n");
        printf("nao tem posterior\n");
    }else{
        printf("anterior: %d\n", ant->valor);
        printf("posterior: %d\n", aux->proximo_elemento->valor);
    }
    
}
}
