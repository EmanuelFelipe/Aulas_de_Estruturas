#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    struct Registro * primeiro_elemento;
}Lista;



typedef struct Registro{
    int valor;
    struct Registro * proximo_elemento;
}Registro;




Lista * cria_lista();
Registro * cria_registro();
void mostrar(Lista * l1);
int adiciono_registro(int valor_do_registro, Lista *l1);
int procura_registro(int x, Lista * l1);
int remove_registro(int opcao, Lista * l1);
int remove_especifico(int x, Lista * l1);
void menu(Lista * l1);


int main() {
    Lista * l1 = cria_lista();
    //l1->primeiro_elemento;

    menu(l1);

    return 0;
}

Lista * cria_lista(){
    Lista * lista_criada = (Lista *)malloc(sizeof(Lista));

    lista_criada->primeiro_elemento = NULL;
    
    return lista_criada;
}

Registro * cria_registro(){
    Registro * registro_criado = (Registro *)malloc(sizeof(Registro));

    registro_criado->valor = 0;
    registro_criado->proximo_elemento = NULL;

    return registro_criado;
}

int adiciono_registro(int valor_do_registro, Lista *l1){
    Registro * criado = cria_registro();
    criado->valor = valor_do_registro;

    // lista vazia, ou com elementos

    if(l1->primeiro_elemento == NULL){
        l1->primeiro_elemento = criado;
        return 1;

    }else{
        Registro * aux = l1->primeiro_elemento;

        while(aux->proximo_elemento != NULL){
            aux = aux->proximo_elemento;
        }
        aux->proximo_elemento = criado;
        return 1;
    }

    return 0;
}

void mostrar(Lista * l1){
    if(l1->primeiro_elemento == NULL){
        printf("\n Lista vazia");
    }else{
        Registro * elemento_a_mostrar = l1->primeiro_elemento;
        while (elemento_a_mostrar!= NULL)
        {
            printf("%d ->", elemento_a_mostrar->valor);
            elemento_a_mostrar = elemento_a_mostrar->proximo_elemento;
        }
        printf("\n");
    }
}

int remove_registro(int opcao, Lista * l1){
    
    if(opcao == 1){// significa tirar do começo
        if(l1->primeiro_elemento != NULL){ // confere se a lista esta com elementos
            Registro * aux = l1->primeiro_elemento;
            l1->primeiro_elemento = aux->proximo_elemento;
            free(aux);
            printf("removi \n");
            return 1;
        }else{
            printf("lista vazia\n");
            return 0;
        }
    }else{
        if(l1->primeiro_elemento != NULL){
            Registro * aux = l1->primeiro_elemento;
            Registro * anterior = NULL;
            while(aux->proximo_elemento != NULL){
                anterior = aux;
                aux = aux->proximo_elemento;
            }
            anterior->proximo_elemento = NULL;
            free(aux);
            printf("removi \n");
            return 1;
        }else{
            printf("lista vazia\n");
            return 0;
        }
    }
}

int remove_especifico(int x, Lista * l1){
    if(l1->primeiro_elemento != NULL){
        Registro * anterior = NULL;
        Registro * aux = l1->primeiro_elemento;
        if(aux->valor == x){
            l1->primeiro_elemento = aux->proximo_elemento;
            free(aux);
            return 1;
        }
        else{
            while (aux->valor != x){
                if(aux->proximo_elemento != NULL){
                    anterior = aux;
                    aux = aux->proximo_elemento;
                }
            }
            if(aux->valor == x){
                if(aux->proximo_elemento==NULL){
                    anterior->proximo_elemento = NULL;
                    free(aux);
                    return 1;
                }else
                {
                    anterior = aux->proximo_elemento;
                    free(aux);
                    return 1;
                }
            }else{
                printf("Não encontrei esse elemento \n");
                return 0;
            }
        }
    }
    else{
        printf("lista vazia\n");
        return 0;
    }
}

int procura_registro(int x, Lista * l1){
    if(l1->primeiro_elemento == NULL){
        printf("lista vazia\n");
        return 0;
    }else{
        Registro * aux = l1->primeiro_elemento;
        while(aux->valor != x){
            if(aux->proximo_elemento != NULL){
                aux = aux->proximo_elemento;
            }else{
                printf("não encontrei\n");
                return 0;
            }
        }

        if(aux->valor == x){
            printf("encontrei \n");
            return 1;
        }
    }
}

void menu(Lista * l1){
    int opcao;
    int valor;
    int retorno;

    do{
        printf("Digite sua opcao\n");
        printf("0 - sair\n");
        printf("1 - adiciono registro\n");
        printf("2 - procuro registro\n");
        printf("3 - remove registro\n");
        printf("4 - remove registro especifico\n");
        printf("5 - mostrar\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("saindo do programa");
            break;
            
            case 1:
                printf("Digite um valor para adicionar\n");
                scanf("%d",&valor);
                adiciono_registro(valor, l1);
                printf("%d foi adicionado\n", valor);
                break;
            case 2:
                printf("Digite um valor para adicionar\n");
                scanf("%d",&valor);
                retorno = procura_registro(valor, l1);

                break;
            case 3:
                printf("1 - remover no inicio\n2 - remover no fim");
                scanf("%d", &valor);
                retorno = remove_registro(valor, l1);
                break;
            case 4:
                printf("Digite um valor para remover\n");
                scanf("%d",&valor);
                retorno = remove_especifico(valor, l1);
                break;
            case 5:
                mostrar(l1);
                system("pause");
                break;
            default:
                printf("Digite uma opção valida\n");
                break;
        }
    }while(opcao != 0);
}