#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    struct Registro *primeiro_elemento;
} Lista;

typedef struct Registro
{
    int P, C, T;
    struct Registro *proximo_elemento;
} Registro;

Lista *cria_lista();
Registro *cria_registro();
void mostrar(Lista *l1);
int adiciono_registro(int p, int c, int t, Lista *l1);
void verificaCondicao(Lista *l1);

int main()
{
    Lista *l1 = cria_lista();

    verificaCondicao(l1);

    return 0;
}

Lista *cria_lista()
{
    Lista *lista_criada = (Lista *)malloc(sizeof(Lista));

    lista_criada->primeiro_elemento = NULL;

    return lista_criada;
}

Registro *cria_registro()
{
    Registro *registro_criado = (Registro *)malloc(sizeof(Registro));

    registro_criado->P = 0;
    registro_criado->C = 0;
    registro_criado->T = 0;
    registro_criado->proximo_elemento = NULL;

    return registro_criado;
}

int adiciono_registro(int p, int c, int t, Lista *l1)
{
    Registro *criado = cria_registro();
    criado->P = p;
    criado->C = c;
    criado->T = t;

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

int somaValores(Lista *l1, int valor, int i)
{   
    int soma, aux = 0;
    if (l1->primeiro_elemento == NULL)
    {
        printf("\n Lista vazia");
        return 0;
    }
    else
    {
            Registro * elemento_a_somar = l1->primeiro_elemento;
        while(elemento_a_somar->proximo_elemento != NULL){
            soma = elemento_a_somar->T + elemento_a_somar->proximo_elemento->T + aux;
            aux = soma;
        }
        return soma;
    }
    
}

int converteHoras(int x){
    int horas;
    for(int i; i<x; i++){
        horas= 24 * x;
    }
    return horas;
}

void verificaCondicao(Lista *l1)
{
    int q, k, exec, p, c, t, i, horas;

    scanf("%d %d", &q, &k);

    horas = converteHoras(k);

    for (i = 0; i < q; i++)
    {
        scanf("%d %d %d", &p, &c, &t);
        adiciono_registro(p, c, t, l1);
    }
    exec = somaValores(l1, t, i);
    if (exec > horas)
    {
        printf("%d", exec);
    }else{
        printf("%d", exec);
    }
    

    
}