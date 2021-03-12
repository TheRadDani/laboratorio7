/**
 * @file lista.h
 * @version 1.0
 * @date 24/02/2021
 * @brief Funcion principal
 * @details Funcion principal que llama a las funciones de la biblioteca lista. para asi ejecutar los metodos sobre l lista enlazada que se crea a a partir del puntero a lista llamado cabeza en el main.
 * Se crean condicionales para comprobar si los eleemntos estan en la lista o si la operacion es valida en la lista actual.
 * @param Argumentos de entrada
 * @return Retorno de entero 0
 * @code
 int main(int argc, char **argv, char const **envp)
{
    (void) argc;
    (void) argv;
    (void) envp;

    int elemento=1;
    int valid;
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
    printf("\nLista luego de eliminar el ultimo elemento\n");
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
 * @endcode
 */

#ifndef LISTA_H
#define LISTA_H

#define NOMBRE "listaEnlazada.bin"

typedef struct node
{
    int data; //!< data
    struct node *next; //!< pointer to next element
} node;

/**
 * @brief Lectura del archivo binario que se escribe con la lista
 * @details lee el archivo binario del disco duro y hace una lectura de elemento uno a uno hasta llegar al final de la llinea y se indica mediante un string explicitamente que es el contenido del archivo el que se esta leyendo y se imprime.
 * se crea la condicion que sea mientra no se llegue a eol para que se lean todos los elementos y que ademas se reserva la memoria para que se recorrael documento una vez y no se imprima ningun elemento mas de una vez.
 * @param filePath: nombre del archivo binario con la ruta
 * @return returna un puntero a estructura con el primer elemento leido por la funcion
 */
node *readList(const char *filePath);

/**
 * @brief Escritura de lista enlazada dentro de archivo binario
 * @details Funcion recorre cada elemento dentro de la lista hasta llegar al ultimo elemento y por cada elemento lo escribe en la lista usando el metodo de escritura binaria con fwrite
 * @param head: Puntero de la cabeza de la lista
 * @param filePath: Nombre del archivo binario con ruta
 * @return no tiene retorno
 */
void writeList(node *head, const char *filePath);

/**
 * @brief Funcion elimina el primer elemento de la lista y sustiitute el elemento del dato del primero por el siguiente para que siga siendo una lista en lazada
 * @details Se crea una variable de tipo entero que seaa igual al elemeto que apunta el primer elemento en la lista y se retorna este valor llamado informacion para saber cual era ese valor eliminado.
 * Para que la lista siga siendo valida, es siguiente elemento, se guarda en una variable de tipo puntero el dato apuntarpo por el next de phead y este sustituye al phead que fue liberado anteriormente.
 * @param phead recibe puntero doble del primer elemento de la lista
 * @return funcion no tiene retorno
 */
int pop_front(node **phead);

/**
 * @brief Funcion que elimina el ultimo elemento de la lista
 * @details elimina el último elemento de la lista y asigna al penúltimo elemento como el nuevo elemento del final y se suprimen posibles erreroes como el hecho que la lista cuente con un solo elemento y por ende no sea valido eliminar el ultimo.
 * @param head: recibe el puntero cabeza de la lista
 * @return Retorna el valor entero del ultiomo elemento elimindao en la lista y si la lista esta vacia, se retorna un 1
 */
int pop_back(node *head);

/**
 * @brief Retorna valor para indicar si la insercion de un elemento al final de la lista fue exitosa
 * @details Se recorre el puntero x que es igual a head y mientras este no sea nulo se recore todo, finalmente si luego de recorrer toa lista es NULL implica que no se pudo reservar la memoria y se retorna un 1.
 * Si se pudo ingresar elemento al final es porque el final contiene data y el next wes NULL.
 * @param head puntero a la cabeza de la lista
 * @param new_value Valor que se anade al final de la lista
 * @return Retorna un 0 si se pudo insertar un elemento de manera exitosa en la lista y un 1 si no es de esta manera
 */
int push_back(node *head, int new_value);

/**
 * @brief Retorna entero que indica si a insercion de un elemento en la cabeza de la lista fue correcta
 * @details Esta funcion, crea un puntero nuevo que es al que se le reserva la lmemoria dinamica para asi hacer la revision y si este es NULL es porque no se pudo seservar memoria para este elemento y se hace el retorno de un 1.
 * Caso contrario, el data apunta dentro de este del puntero cabeza, quire decir que se pudo reservar la memoria para que el puntero apunte a la estructura y se devuelve un 0.
 * @param head: puntero al puntero del pirmer elemento de la lista
 * @param new_value Elemento que se inserta en la lista
 * @return Retorna un 0 si se pudo insertar un elemento de manera exitosa en la lista y un 1 si no es de esta manera
 */
int push_front(node **head, int new_value);

/**
 * @brief Imprime cada elemento del nodo que contiene la lista
 * @details Se crea la funcion de imprimir que recibe el valor que se desea imprimir de la lista.
 * @param value: posicion del nodo que se quiere imprimir elemento
 * @return no tiene retorno
 */
void printElement(int value);

/**
 * @brief Crea un nodo en la lista
 * @details Se crea el nodo cabeza, al cual se le inserta en data el primer valor y el siguiente seria el NULL, ya que por definicion el ultimo elmento de una lista enlazada es el NULL para establecer condicion de parada.
 * Este funciona para insertar mas nodos y crear la lista.
 * @param first_value: Primer valor que contine el primer elemeto, es decir, la cabeza de la lista
 * @return Devuelve un puntero a estructura node que corresponde a la definicion del nodo cabeza
 */
node *createList(int first_value);

/**
 * @brief Inserta elementos en lista segun valor y posicion
 * @details Si la posocion es uno, y lo sera en caso que no haya un elemnto ya en la lista, entonces inserta la estructura a node devuelta por create list y su ya esta creada, seguira insertando los elemntos y el ultimo sera NULL
 * @param pehead recibe puntero al puntero de la cabeza de la lista
 * @param pos: posicion donde se quiere insertar el elemento en la lista
 * @return No tiene retorno
 */
void insertElement(node **phead, int pos, int new_value);

/**
 * @brief Funcion imprime todos los elementos de la lista
 * @details Mediante el puntero cabeza que se recibe como parametro, se guarda en n su  contenido y se recorre n hasta que no sea nulo y por cada elemento se imprime el elemento segun la posicion de la lista.
 * para esto se llama a la funcion printElement y se indica la posicion el elemento que se esta imprimiendo mediante un cantador.
 * @param head: Puntero del primer elemento de la lista
 * @return No tiene retorno
 */
void printList(node *head);

/**
 * @brief Libera la memoria reservada por la lista
 * @details Se crean dos punteros que apuntan a la estructura de tipo node y se llaman bor y reco, donde se recorre reco que es igual a head hasta que este no sea nulo y se recorre al siguiente y la primera instruccion correspode a liberar reco que la primera vez es la cabeza y luego el siguiente hasta liberar toda la memoria de la lista
 * @param head: recibe el puntero del primer elememto de la lista
 * @return no tiene retorno
 */
void freeList(node *head);

/**
 * @brief Ordenamiento de la lista en orden ascentente o descendente
 * @details Se hace reserva dinamica con malloc al puntero x que es un arreglo para la cantidad de enteros que contiene la lista y mediante un bucle, se le asigna a este el valor que contiene cada elemeto la lista.
 * con el arreglo x[cant] listo con todos los elementos almacendos, se pone inserta el metodo burbuja para ordenar los elementos de x de forma descendete si el caracter de paramentro a si es b, se forma ascendentes.
 * Esto se crea con un condicional, finalmente cuando los elementos ya estan ordenados, se imprimen enpantalla, separados por espacios y finalmente se libera la memoria.
 * @param head: puntero al primer elemento de la lista
 * @param dir variable tipo caracter que siendo a ordena la lista de forma descendente y si es b, la ordena de forma ascendente.
 * @return no tiene retorno
 */
void sort(node *head, char dir);

/**
 * @brief Elimina un elemento segun la posicion que se le indique
 * @details Se crea un contador para revisar la posicion del elemento que se quiere crear, ademas remueve elementos si y solo si la posicion indicada es menor o igual a la cantidad total de elementos en la lista.
 * En caso de ser la primera posicon, se llama a la funcion pop_front.
 * Si no es no es primero, se busca si es el ultimo o si esta en una posicion de en medio.
 * si esta en medio, el siguiente sera el el elemnento que tenia el siguiente del eliminado y asi hasta llegar al ultimo elemento. Si es el ultimo, se remueve su valor y el siguiente del anterior sera NULL.
 * @param phead: puntero al puntero de la cabeza de la lista
 * @param pos: posicion del elemento que se quiere eliminar en la lista
 * @return Retorn el valor del dato que se elimino en la lista y en caso de no poderse realizar la operacion, devuelve un -1
 */
int removeElement(node **phead, int pos);

/**
 * @brief Returna valor de la lista segun la posicion que se indique
 * @details Se crea un bucle que finaliza al llegar a la posicion del indice que corresponde a la posicion de la lista que se desea ontener el valor y al ser ese valor, el puntero nAux es igual a este ultimo  y se obtene el valor del dato llamado y, al hacer que nAux apunte al dato de este puntero
 * @param head: puntero al primer elemento de la lista
 * @param index: Posicion entera del elemento que se desea consultar en la lista.
 * @param valid: Recibe la direccion de una variable entera para modificarla a 1 si la posicion del elemento de la lista es exitosa, en caso contrario se retorna un 0 en caso que la posicion no exista o que la lista este vacia
 * @return Retorna el valor de la lista segun la posicion
 */
int getElement(node *head, int index, int* valid);

#endif // LISTA_H
