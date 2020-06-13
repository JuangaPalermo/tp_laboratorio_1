#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void);

/*Le paso como paramtero la lista que quiero contar, me devuelve un int con la cantidad de elementos que posee*/
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//1
/*le paso como parametro primero la lista y despues el elemento que quiero agregar a la misma*/
int ll_add(LinkedList* this, void* pElement);
/*recibe la lista que le doy como parametro, y el inidice que le indique. Me devuelve un puntero a void (en este caso deberia castearlo como puntero a empleado)*/
void* ll_get(LinkedList* this, int index);
/*recibe la lista que le doy como parametro, y el indice que le indique. La funcion saca de la lista al elemento que matchee con el indice*/
int ll_remove(LinkedList* this,int index);
/*recibe como parametro la lista que quiero limpiar. Limpia el linkedlist, pero sigue existiendo en memoria (pero vacia)*/
int ll_clear(LinkedList* this);
/*recibe como parametro la lista que quiero eliminar. En este caso, hace que deje de existir en memoria*/
int ll_deleteLinkedList(LinkedList* this);
/*Le paso un elemento que se encuentra en memoria, y me dice en que posicion esta dentro de la lista*/
int ll_indexOf(LinkedList* this, void* pElement);
/*Me dice si la lista esta vacia*/
int ll_isEmpty(LinkedList* this);

/*recibe la lista, despues el criterio de ordenamiento, y despues el orden (0 descendente / 1 ascendente)*/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);


/*Push y set sirven para agregar uno al final, pero la diferencia con respecto del add es:*/
/*El set, si le paso una posicion que ya estaba ocupada, reemplaza uno por otro*/
int ll_set(LinkedList* this, int index,void* pElement);
/*El push, si le paso una posicion que ya estaba ocupada, pone el dato que le paso en esa posicion y corre los demas hacia la derecha*/
int ll_push(LinkedList* this, int index, void* pElement);

/*Funciona similar a lremove, solo que en este caso, me devuelve el dato que elimino (por lo cual puedo utilizarlo para asignarlo en otro lugar)*/
void* ll_pop(LinkedList* this,int index);

/*me dice si el elemento que le estoy pasando a la lista esta contenido dentro de esa misma lista (parecido a indexOf, solo que este me devuelve si esta o no esta, y el indexOf me devuelve el indice)*/
int ll_contains(LinkedList* this, void* pElement);
/*me dice si una lista esta contenida en otra lista (la segunda en la primera*/
int ll_containsAll(LinkedList* this,LinkedList* this2);

/*Me sirve para obetener un rango dentro de una lista, desde el from hacia el to (no se sabe si son inclusivos o no)*/
LinkedList* ll_subList(LinkedList* this,int from,int to);
/*Me da una copia exacta de la lista que le paso como parametro*/
LinkedList* ll_clone(LinkedList* this);


