#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this !=NULL){

    	this->pFirstNode=NULL;
    	this->size=0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux= this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode=NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode= this->pFirstNode;//asigno la direc de memoria de pfirsNode para luego iterar

		for(int i=0; i< nodeIndex; i++){// tomo indice para que me recorra y tome la direcc de memoria del indice q le paso como parametro

			pNode=pNode->pNextNode;// accedo al Nodo siguiente porq en p Node estoy parado en el nodo (si quiero el 3 recorro hasta es dos q tiene el puntero del siguiente)
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* unNodoNuevo=NULL;
    Node* auxNode=NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
    	unNodoNuevo= (Node*)malloc(sizeof(Node));// malloc xq agrego un nodo nuevo

    	if(unNodoNuevo != NULL){

    		if(nodeIndex== 0){

    			//linea 110 el primer nodo pasa a ser el siguiente
    			//linea 112 el nodo que agregas pasa a ser el primero
    			unNodoNuevo->pNextNode=this->pFirstNode;// asigno a p next node la direccion de memoria de p first node (anterior)
    			// le asigno                 //null
    			this->pFirstNode=unNodoNuevo;// y ahora mi pfirst node apunta a mi nuevo nodo creado
    			unNodoNuevo->pElement=pElement;// le asigno el puntero al elemento a mi nuevo noso
    			this->size++; // aumento el size porq agregue un nodo
    			returnAux=0;
    		}
    		else{//ultimo elemento o el del medio
    			 auxNode=getNode(this, nodeIndex -1);// obtengo axuobtengo el nodo anterior q tiene la direccion de memoria del next node
    			 if(auxNode !=NULL){
    				 unNodoNuevo->pNextNode= auxNode->pNextNode;// a mi nuvo nodo (next node) le asigno la direc de nex node q tenia me nodo anterior
    				 auxNode->pNextNode= unNodoNuevo;//y a mi nodo anterior  (next node) le asigno mi nuevo nodo

    				 unNodoNuevo->pElement=pElement;
					 this->size++;
					 returnAux=0;

    			 }
    		}

    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux=addNode(this,ll_len(this),pElement);//le paso como indice el len porq agrego uno mas al final

    }

    return returnAux;
}

/** \brief Permite obtener el element del nodo
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode=NULL;

    if(this !=NULL && index >=0 && index < ll_len(this)){

    	pNode=getNode(this, index);// llamo a get node para almacenar el pNode la direcc de memoria del nodo y acceder al elemento
    	if(pNode != NULL){
    	returnAux=pNode->pElement;// retorno el elemento

    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

        if(this !=NULL && index >=0 && index < ll_len(this)){

        	pNode=getNode(this, index);
        	if(pNode != NULL){
        	pNode->pElement=pElement;
        	returnAux=0;
        	}
        }

     return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

        Node* auxNode=NULL;
        Node* pAuxNodeDos=NULL;

        if(this != NULL && index >= 0 && index < ll_len(this)){

        	auxNode=getNode(this, index);// obtengo el nodo q quiero borra para obtener el next node (direccion de memo del proximo)

        	if(auxNode != NULL){

        		if(index== 0){

        		this->pFirstNode= auxNode->pNextNode;// le asigno a pfirst node la direc de memoria de next node q tenia el nodo a eliminar

        		}
        		else{// si no es el primero uso un aux para guardarme el nodo anterior al q quiero borrar
        			pAuxNodeDos=getNode(this, index -1);
        			 if(pAuxNodeDos !=NULL){
        				 pAuxNodeDos->pNextNode=auxNode->pNextNode;// le asigno nex node de q vamosa a borrar al next node del indice anterior

        			 }
        		}
        		this->size--;
				free(auxNode);
				returnAux=0;

        	}
        }
        return returnAux;
}


/** \brief Elimina todos los elementos de la lista/nodos
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int size;

    if(this !=NULL){

    	size=ll_len(this);
    	if(size>0){
    		for(int i=0; i< size; i++){

    			ll_remove(this, i);

    		}
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this !=NULL && ll_clear(this)==0){

    	free(this);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size;
    void* pAuxElement=NULL;

    if(this !=NULL){
    	size=ll_len(this);
    	for(int i=0; i< size; i++){
    		pAuxElement=ll_get(this, i);
    		if(pAuxElement == pElement){
    			returnAux=i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
    	if(ll_len(this)>0){
    		returnAux=0;
    	}
    	else{
    		returnAux=1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this)){

    	returnAux=addNode(this,index, pElement);// llama a la funcion add Node y agrega el elemene a la lista en la posicion eindicada(add se encargard de crear el nuevo nodo)

    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

    	returnAux=ll_get(this, index);// retorna el puntero al elemento q quiero eliminar

    	ll_remove(this, index);// desp lo elimino

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!= NULL){

    	if(ll_indexOf(this, pElement)!= -1){

    		returnAux=1;
    	}else{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int size;
    void* pElement;

    if(this != NULL && this2 != NULL){
    	size=ll_len(this2);
    	returnAux=1;
    	for(int i=0; i<size; i++){// recorro la segunda

    		pElement=ll_get(this2, i); // tomo cada elemento
    		if(ll_contains(this, pElement)==0){// pregunto si ese elemento esta en this1(direcciones de memoria)
    			returnAux=0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
				o (si el indice from es menor a 0 o mayor al len de la lista)
				o (si el indice to es menor o igual a from o mayor al len de la lista)
		 (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* clonesublista = NULL;
    void* pAuxElement=NULL;

    if(this != NULL && from >=0  && from < ll_len(this) && to >from && to <= ll_len(this)){
    	clonesublista=ll_newLinkedList();// creo la sublist
    	if(clonesublista != NULL){
    		for(int i=from;i < to; i++){// y recorro del from hasta to sin incluirlo
    			pAuxElement=ll_get(this, i);// tomo el direcc del elemente
    			ll_add(clonesublista, pAuxElement);//agrego el elemento a la nueva lista
    		}
    	}
    }

    return clonesublista;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clone = NULL;
    if(this !=NULL){
    	clone= ll_subList(this, 0, ll_len(this));// copio la lista entera
    }

    return clone;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * (retorna <0 si el primero es mayor q el de la segundo , mayor a >0 si el segundo es mayor q el primero y 0 si son iguales
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 *///>0 y 1 ascendente// <0 y 0 desendete
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int estaOrdenado;
    int size;
    void* pAuxElement=NULL;
    void* pAuxElementDos=NULL;

    if(this!= NULL && (order == 0|| order ==1) && pFunc != NULL){
    	size=ll_len(this);
    	do{
    		estaOrdenado=1;
    		size--;

    		for(int i= 0; i< size; i++){
    			pAuxElement=ll_get(this, i);// obtengo el elemento
    			pAuxElementDos=ll_get(this, i+1);// obtengo el elemento de la posicion siguiente
    			if((pFunc(pAuxElement,pAuxElementDos)> 0 && order ==1)||(pFunc(pAuxElement,pAuxElementDos) < 0 && order == 0)){
					//pfuc me dice q el segundo elemeto es mayor
    				ll_set(this, i, pAuxElementDos);// coloco la direcc de memoria del elemento dos a i
					ll_set(this, i+1, pAuxElement);//coloco la direcc de memoria del elemento uno en la posicion siguiente
    				estaOrdenado=0;
    			}
       		}


    	}while(estaOrdenado== 0);
    	returnAux=0;
    }

   return returnAux;

}

