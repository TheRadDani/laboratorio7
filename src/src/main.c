#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char const **envp)
{
    (void) argc;
    (void) argv;
    (void) envp;

    int elemento=1;
    int valid = 0;
    node *cabeza = NULL;
    insertElement(&cabeza, 1, 10);
    insertElement(&cabeza, 2, 7);
    insertElement(&cabeza,3,9);

    writeList(cabeza, NOMBRE);
    node *nuevaLista = readList(NOMBRE);
    printf("lista leida del archivo\n");
    printList(nuevaLista);

    printf("lista creada con codigo en main\n");
    push_back(cabeza, 100);
    push_front(&cabeza, 500);
    printList(cabeza);

    printf("\nEl elemento en la posicion %i es %i\n",elemento,getElement(cabeza, elemento, &valid));
    if(valid==0)
    {
        printf("Elemento no valido\n");
    }
    else if(valid==1)
    {
        printf("Elemento valido\n");
    }

    printf("\nLista luego de eliminar elemento\n");
    int a=removeElement(&cabeza, 3);
    printList(cabeza);
    printf("\nEl elemento eliminado fue: %i\n",a);
    printf("Lista luego de eliminar el ultimo elemento\n");
    int b=pop_back(cabeza);
    if(b!=-1)
    {
        printList(cabeza);
        printf("El ultimo elemento en eliminarse fue %i\n",b);
    }
    else
    {
        printf("La lista esta vacia\n");
    }
    printf("La lista ordenada de manera descendente es: \n");
    //fflush(stdout);
    sort(cabeza, 'a');
    printf("\nLa lista ordenada de manera ascendente es: \n");
    sort(cabeza, 'b');
    freeList(cabeza);
    return 0;
}
