#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int push_back(node *head, int new_value)
{
    node *x = NULL;
    node *nuevo = NULL;

    x = head;
    while (x->next != NULL)
    {
        x = x->next;
    }
    nuevo = (node *)malloc(sizeof(node));
    if (nuevo == NULL)
    {
        return 1;
    }
    nuevo->data = new_value;
    nuevo->next = NULL;
    x->next = nuevo;
    return 0;
}

int push_front(node **head, int new_value)
{
    node *nuevo = (node *)malloc(sizeof(node));

    if (nuevo == NULL)
    {
        return 1;
    }
    nuevo->data = new_value;
    nuevo->next = *head;
    *head = nuevo;
    return 0;
}

void printElement(int value)
{
    printf("%d ", value);
}

node *readList(const char *filePath)
{
    int data = 0;
    node *cabeza = NULL;
    node *x = NULL;
    node *y = NULL;
    FILE *F = fopen(filePath, "rb");

    if (F != NULL)
    {
        cabeza = (node *)malloc(sizeof(node));
        fread(&cabeza->data, sizeof(int), 1, F);
        cabeza->next = NULL;
        y = cabeza;
        printf("dato leido: %d\n", cabeza->data);
        while (!feof(F))
        {
            fread(&data, sizeof(int), 1, F);
            if (!feof(F))
            {
                printf("dato leido: %d\n", data);
                x = (node *)malloc(sizeof(node));
                x->data = data;
                x->next = NULL;
                y->next = x;
                y = x;
            }
        }
        fclose(F);
    }
    return cabeza;
}

void writeList(node *head, const char *filePath)
{
    node *x = NULL;
    FILE *F = fopen(filePath, "wb");

    if (F != NULL)
    {
        x = head;
        while (x != NULL)
        {
            fwrite(&x->data, sizeof(int), 1, F);
            printf("dato escrito: %d\n", x->data);
            x = x->next;
        }
        fflush(F);
        fclose(F);
    }
}

node *createList(int first_value)
{
    node *nuevo = NULL;

    nuevo = (node*)malloc(sizeof(node));
    if (nuevo != NULL)
    {
        nuevo->data = first_value;
        nuevo->next = NULL;
    }
    return nuevo;
}

void insertElement(node **phead, int pos, int new_value)
{
    node *nuevo = NULL;
    node *reco = *phead;
    node *siguiente = NULL;
    int cant = 0;

    while (reco != NULL)
    {
        cant++;
        reco = reco->next;
    }
    if (pos <= cant + 1)
    {
        nuevo=NULL;
        nuevo=createList(new_value);
        if (pos == 1)
        {
            nuevo->next = *phead;
            *phead = nuevo;
        }
        else
        {
            if (pos == cant+ 1)
            {
                reco = *phead;
                while (reco->next != NULL)
                {
                    reco = reco->next;
                }
                reco->next = nuevo;
                nuevo->next = NULL;
            }
            else
            {
                reco = *phead;
                int f;
                for (f = 1; f <= pos - 2; f++)
                {
                    reco = reco->next;
                }
                siguiente = reco->next;
                reco->next = nuevo;
                nuevo->next = siguiente;
            }
        }
    }
}

void printList(node *head)
{
    int contador = 0;
    node *n = head;

    while (n != NULL)
    {
        printElement(n->data);
        ++contador;
        printf("contador: %d\n", contador);
        n = n->next;
    }
    printf("\n");
}

void freeList(node *head)
{
    node *reco = head;
    node *bor = NULL;

    while (reco != NULL)
    {
        bor = reco;
        reco = reco->next;
        free(bor);
    }
}

void sort(node *head, char dir)
{
    node *f=head;
    int *x = NULL;
    node *reco = head;
    int cant = 0;
    int aux = 0;

    while (reco != NULL)
    {
        cant++;
        reco = reco->next;
    }
    x = (int *)malloc(cant*sizeof(int));
    for (int i=0;i<cant;i++)
    {
        x[i]=f->data;
        f=f->next;
    }
    if (dir =='a')
    {
        // ordenamiento por metodo burbuja con punteros
        for (int i=0;i<cant;i++)
        {
            for (int j=0;j<cant-1;j++)
            {
                if (*(x+j+1) > *(x+j))
                {
                    aux = *(x+j);
                    *(x+j) = *(x+j+1);
                    *(x+j+1) = aux;
                }
            }
        }
    }
    else if (dir=='b')
    {
        // ordenamiento por metodo burbuja con punteros
        for (int i=0;i<cant;i++)
        {
            for (int j=0;j<cant-1;j++)
            {
                if (*(x+j+1) < *(x+j))
                {
                    aux = *(x+j);
                    *(x+j) = *(x+j+1);
                    *(x+j+1) = aux;
                }
            }
        }
    }
    for (int i=0;i<cant;i++)
    {
        printf("%i ",x[i]);
    }
    free(x);
    x=NULL;
    printf("\n");
}

int pop_front(node **phead)
{
    int informacion = (*phead)->data;
    node *aux = (*phead)->next;
    free(*phead);
    *phead = aux;
    return informacion;
}

int pop_back(node *head)
{
    node *x = NULL;
    int cant = 0;
    int data = 0;

    if (head != NULL)
    {
        x = head;
        while (x != NULL)
        {
            cant++;
            x = x->next;
        }
        if (cant == 1)
        {
            data = head->data;
            free(head);
            return data;
        }
        else if (cant > 1)
        {
            x = head;
            while (x->next->next != NULL)
            {
                x = x->next;
            }
            data = x->next->data;
            free(x->next);
            x->next = NULL;
            return data;
        }
    }
    return -1;
}

int removeElement(node **phead, int pos)
{
    int f = 0;
    int cant = 0;
    int informacion;
    node *bor = NULL;
    node *prox = NULL;
    node *reco = *phead;

    while (reco != NULL)
    {
        cant++;
        reco = reco->next;
    }
    if (pos <= cant)
    {
        if (pos == 1)
        {
            return pop_front(phead);
        }
        else
        {
            reco = *phead;
            for (f = 1; f <= pos - 2; f++)
            {
                reco = reco->next;
            }
            prox = reco->next;
            reco->next = prox->next;
            informacion = prox->data;
            bor = prox;
            free(bor);
            return informacion;
        }
    }
    else
    {
        return -1;
    }
}

int getElement(node *head, int index, int *valid)
{
    node *nAux = head;
    int y = 0;

    for (int i =0;i<index;i++)
    {
        y=nAux->data;
        nAux=nAux->next;
    }
    while (nAux != NULL)
    {
        if (nAux->data == y)
        {
            *valid = 0;
        }
        nAux = nAux->next;
    }
    *valid= 1;
    return y;
}
