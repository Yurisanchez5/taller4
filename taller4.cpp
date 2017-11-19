#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define reservar_memoria_simple (NodoSimple *)malloc(sizeof(NodoSimple))
#define reservar_memoria_doble (NodoDoble *)malloc(sizeof(NodoDoble))

struct NodoSimple{
	int dato;
	NodoSimple * siguiente;
};

struct NodoDoble{
	int dato;
	NodoDoble * siguiente;
	NodoDoble * anterior;
};


int pedirDatos(){
	int dato;
	
	printf("Ingrese un dato\n");
	scanf("%d", &dato);
	
	return dato;
}

//*****************************************************************//
void insertarElementoSimplementeOrdenadas(int n, NodoSimple *&cab){
	
	NodoSimple * nuevo = reservar_memoria_simple;
	nuevo->dato = n;
	NodoSimple *aux1 = cab;
	NodoSimple *aux2;
	//new->siguiente = NULL;
	
	while(aux1!=NULL && aux1->dato<n){
		
		aux2 = aux1;
		aux1 = aux1->siguiente;
		
	}
	if(aux1 == cab){
		
		nuevo->siguiente = aux1;
		cab = nuevo;
	}else{
		aux2->siguiente = nuevo;
		nuevo->siguiente = aux1;
		
	}
}

bool listaSimplementeVacia(NodoSimple *inicio){
	return (inicio == NULL) ? true:false;
}

void editarElementoSimplementeOrdenado(NodoSimple *&lista, int n){
	
	int nuevo_dato;
	NodoSimple *aux = lista;
	
	if(listaSimplementeVacia(lista)){
		printf("lista Vacia");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				nuevo_dato = pedirDatos();
				aux -> dato = nuevo_dato;
				printf("dato encontrado"); break;
			}
			aux = aux->siguiente;
		}
		printf("dato no encontrado");
	}
}

void eliminarElementoSimplementeOrdenada(NodoSimple *& lista,int n){
	
	int encontrado = 0;
	NodoSimple * aux = lista;
	NodoSimple *aux2 = NULL;
	if(listaSimplementeVacia(lista)){
		printf("lista Vacia");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				if(aux == lista){
					lista = aux ->siguiente;
				}else{
					aux2->siguiente = aux ->siguiente;
				}
				encontrado=1;
				break;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}if(encontrado == 0){
			printf("dato no encontrado");
		}
		
	}
	free(aux);
}

void listarElementosSimplementeOrdenados(NodoSimple *lista){
	
	NodoSimple *aux = lista;
	if(listaSimplementeVacia(lista)){
		printf("La Lista esta vacia\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux->dato);
			aux = aux->siguiente;
		}
		printf("\n");
	}
	
	getch();
}

void buscarElementoSimplementeOrdenado(int n, NodoSimple  *lista)
{
	int encontrado = 0;
	NodoSimple *aux = lista;
	
	if(listaSimplementeVacia(lista)){
		
		printf("lista Vacia");
		
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				
				encontrado = 1;
				printf("Dato encontrado");
				break;
			}
			aux = aux->siguiente;
		}
		if(encontrado == 0){
			printf("dato no encontrado");
		}
	}
	getch();
}

void menuListaSimplementeEnlazadasOrdenada()
{
	int opcion=1;
	NodoSimple * inicio = NULL;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----S U B M E N U----\n");
		printf("1. Insertar Elementos \n");
		printf("2. Editar Elementos \n");
		printf("3. Eliminar Elementos \n");
		printf("4. Mostrar Elementos \n");
		printf("5. Buscar Elementos \n");
		printf("0. Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			int dato = pedirDatos();
			insertarElementoSimplementeOrdenadas(dato, inicio);
			
			break;
		}          
		case 2: 
		{
			int dato = pedirDatos();
			editarElementoSimplementeOrdenado(inicio, dato);
			
			break;
		}        
		
		case 3: 
		{
			int dato = pedirDatos();
			eliminarElementoSimplementeOrdenada(inicio, dato);
			
			break;
		}  
		
		case 4: 
		{
			listarElementosSimplementeOrdenados(inicio);
			
			break;
		}  
		
		case 5: 
		{
			int dato = pedirDatos();
			buscarElementoSimplementeOrdenado(dato, inicio);
			
			break;
		}  
		
		default:{
			system("CLS");
			
			break;
		}          
		}
	}
	
}

//***********************************************************************//
void insertarElementoSimplementeDesordenado(int n, NodoSimple *& cab){
	NodoSimple * nuevo = reservar_memoria_simple;
	
	nuevo->dato = n;
	NodoSimple *aux1 = cab;
	
	if(aux1 == NULL)
	{
		aux1 = nuevo;
	}
	else
	{
		while(aux1->siguiente != NULL)
		{
			aux1 = aux1->siguiente;
		}
		aux1->siguiente = nuevo;
	}
}

void editarElementoSimplementeDesordenado(NodoSimple *& lista, int n){
	
	int nuevo_dato = 0;
	NodoSimple *aux = lista;
	
	if(listaSimplementeVacia(lista)){
		printf("lista Vacia");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				nuevo_dato = pedirDatos();
				aux -> dato = nuevo_dato;
				printf("dato encontrado"); break;
			}
			aux = aux->siguiente;
		}
		printf("dato no encontrado");
	}
}

void eliminarElementoSimplementeDesordenado(NodoSimple *& lista,int n){
	
	int encontrado = 0;
	NodoSimple * aux = lista;
	NodoSimple *aux2 = NULL;
	if(listaSimplementeVacia(lista)){
		printf("lista Vacia");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				if(aux == lista){
					lista = aux ->siguiente;
				}else{
					aux2->siguiente = aux ->siguiente;
				}
				encontrado=1;
				break;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}if(encontrado == 0){
			printf("dato no encontrado");
		}
		
	}
	free(aux);	
}

void listarElementosSimplementeDesordenado(NodoSimple *lista){
	
	NodoSimple *aux = lista;
	if(listaSimplementeVacia(lista)){
		printf("La Lista esta vacia\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux->dato);
			aux = aux->siguiente;
		}
		printf("\n");
	}
	getch();
}

void buscarElementoSimplementeDesordenado(int n, NodoSimple  *lista)
{
	int encontrado = 0;
	NodoSimple *aux = lista;
	
	if(listaSimplementeVacia(lista)){
		
		printf("lista Vacia");
		
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				
				encontrado = 1;
				printf("Dato encontrado");
				break;
			}
			aux = aux->siguiente;
		}
		if(encontrado == 0){
			printf("dato no encontrado");
		}
	}
}

void menuListaSimplementeEnlazadasDesordenada()
{
	int opcion=1;
	NodoSimple * inicio = NULL;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----S U B M E N U----\n");
		printf("1. Insertar Elementos \n");
		printf("2. Editar Elementos \n");
		printf("3. Eliminar Elementos \n");
		printf("4. Mostrar Elementos \n");
		printf("5. Buscar Elementos \n");
		printf("0. Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			int dato = pedirDatos();
			insertarElementoSimplementeDesordenado(dato, inicio);
			
			break;
		}          
		case 2: 
		{
			int dato = pedirDatos();
			editarElementoSimplementeDesordenado(inicio, dato);
			
			break;
		}        
		
		case 3: 
		{
			int dato = pedirDatos();
			eliminarElementoSimplementeDesordenado(inicio, dato);
			
			break;
		}  
		
		case 4: 
		{
			listarElementosSimplementeDesordenado(inicio);
			
			break;
		}  
		
		case 5: 
		{
			int dato = pedirDatos();
			buscarElementoSimplementeDesordenado(dato, inicio);
			
			break;
		}  
		
		default:{
			system("CLS");
			
			break;
		}             
		}
	}
	
}

//***********************************************************************//
void insertarElementoDoblementeOrdenadas(NodoDoble *&inicio, NodoDoble *&fin, int n){
	
	NodoDoble *nuevo = reservar_memoria_doble;
	nuevo->dato = n;
	
	NodoDoble * aux = inicio;
	
	// Si la lista está vacía o el primer miembro es mayor que el nuevo /
	if(aux == NULL || aux->dato > n) {
		nuevo->siguiente = aux; 
		nuevo->anterior = NULL;
		if(aux != NULL) 
		{
			aux->anterior = nuevo;
		}
		
		if(inicio == NULL) 
		{
			inicio = nuevo;
		}
	}
	else {
		// se recorre hasta llegar al final o encontrar un valor mayor al del parametro
		while(aux->siguiente != NULL && aux->siguiente->dato<= n) 
		{
			aux = aux->siguiente;
		}
		
		// Agregamos el nuevo nodo después del nodo anterior /
		nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
		nuevo->anterior = aux;
		
		if(nuevo->siguiente != NULL) 
		{
			nuevo->siguiente->anterior = nuevo;
		}
	}
	
	// colocamos el nodo inicio apuntando al primero
	NodoDoble * aux2 = inicio;
	while(aux2 != NULL)
	{
		inicio =  aux2;
		aux2 = aux2->anterior;		
	}
	
	// colocamos el nodo fin apuntando al ultimo
	NodoDoble * aux3 = inicio;
	fin = NULL;
	
	while(aux3 != NULL)
	{
		fin =  aux3;
		aux3 = aux3->siguiente;
		
	}
	
}

bool listaDoblementeVacia(NodoDoble *inicio){
	return (inicio == NULL) ? true:false;
}

void editarElementoDoblementeOrdenado(NodoDoble *&lista, int n){
	
	int nuevo_dato;
	NodoDoble *aux = lista;
	
	if(listaDoblementeVacia(lista)){
		printf("lista Vacia");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				nuevo_dato = pedirDatos();
				aux -> dato = nuevo_dato;
				printf("dato encontrado"); break;
			}
			aux = aux->siguiente;
		}
		printf("dato no encontrado");
	}
}

void eliminarElementoDoblementeOrdenada(NodoDoble *& inicio,NodoDoble *& fin, int dato){
	
	NodoDoble * aux = inicio;
	
	// Buscar el nodo de valor igual al dato /
	while(aux != NULL && aux->dato < dato) 
	{
		aux = aux->siguiente;
	}
	
	while(aux != NULL && aux->dato > dato)
	{
		aux = aux->anterior;
	}
	
	// El dato no está en la lista /
	if(aux == NULL || aux->dato != dato) 
	{
		printf("dato no encontrado o la lista esta vacia\n");
		return;
		
	}
	
	// quitamos el nodo que contiene el dato enviado por parametro
	if(aux == inicio)
	{
		if(aux->anterior != NULL) 
		{
			inicio = aux->anterior;
		}
		else 
		{
			inicio = aux->siguiente;
		}
	}
	
	if(aux->anterior != NULL) // no es el primer nodo 
	{
		aux->anterior->siguiente = aux->siguiente;
	}
	
	if(aux->siguiente != NULL) // no el el último nodo
	{
		aux->siguiente->anterior = aux->anterior;
	}
	
	// borramos el nodo
	free(aux);
	aux = NULL;
	
	
	// Se coloca el nodo fin apuntando al ultimo nodo
	NodoDoble * aux2 = inicio;
	fin = NULL;// En caso de que la lista esté vacía entonces ya fin apuntaria a NULL 
	
	while(aux2 != NULL)
	{
		fin =  aux2;
		aux2 = aux2->siguiente;
		
	}
}

void listarElementosDoblementeOrdenados(NodoDoble *lista, int n){
	
	NodoDoble *aux = lista;
	if (aux == NULL){
		printf("lista Vacia\n");
	}
	
	while(aux != NULL){
		printf("%d ", aux->dato);
		if(n == 1){
			aux = aux->siguiente;
		}else{
			aux = aux->anterior;
		}
	}
	
	getch();
}

void buscarElementoDoblementeOrdenado(int n, NodoDoble  *lista)
{
	int encontrado = 0;
	NodoDoble *aux = lista;
	
	if(listaDoblementeVacia(lista)){
		
		printf("lista Vacia");
		
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				
				encontrado = 1;
				printf("Dato encontrado");
				break;
			}
			aux = aux->siguiente;
		}
		if(encontrado == 0){
			printf("dato no encontrado");
		}
	}
	getch();
}


void menuListaDoblementeEnlazadasOrdenada()
{
	int opcion=1;
	int n;
	NodoDoble * inicio = NULL;
	NodoDoble * fin = NULL;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----S U B M E N U----\n");
		printf("1. Insertar Elementos \n");
		printf("2. Editar Elementos \n");
		printf("3. Eliminar Elementos \n");
		printf("4. Mostrar de adelante hacia atras\n");
		printf("5. Mostrar de atras hacia adelante\n");
		printf("6. Buscar Elementos \n");
		printf("0. Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			int dato = pedirDatos();
			insertarElementoDoblementeOrdenadas(inicio, fin, dato);
			
			break;
		}          
		case 2: 
		{
			int dato = pedirDatos();
			editarElementoDoblementeOrdenado(inicio, dato);
			
			break;
		}        
		
		case 3: 
		{
			int dato = pedirDatos();
			eliminarElementoDoblementeOrdenada(inicio, fin, dato);
			
			break;
		}  
		
		case 4: 
		{
			n = 1;
			listarElementosDoblementeOrdenados(inicio, n);
			
			break;
		}  
		
		case 5: 
		{
			n = -1;
			listarElementosDoblementeOrdenados(fin, n);
			
			break;
		} 
		
		case 6: 
		{
			int dato = pedirDatos();
			buscarElementoDoblementeOrdenado(dato, inicio);
			
			break;
		}  
		
		default:{
			system("CLS");
			
			break;
		}          
		}
	}
	
}


//***********************************************************************//
void insertarElementoDoblementeDesordenadas(NodoDoble *&inicio, NodoDoble *&fin, int n){
	
	NodoDoble *nuevo = reservar_memoria_doble;
	nuevo->dato = n;
	if(inicio == NULL){
		inicio = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior = NULL;
		fin = nuevo;
	}else{
		nuevo->siguiente = NULL;
		nuevo->anterior = fin;
		fin->siguiente = nuevo;
		fin = nuevo;
	}
	
}

void editarElementoDoblementeDesordenado(NodoDoble *&lista, int n){
	
	int nuevo_dato;
	NodoDoble *aux = lista;
	
	if(listaDoblementeVacia(lista)){
		printf("lista Vacia");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				nuevo_dato = pedirDatos();
				aux -> dato = nuevo_dato;
				printf("dato encontrado"); break;
			}
			aux = aux->siguiente;
		}
		printf("dato no encontrado");
	}
}

void eliminarElementoDoblementeDesordenada(NodoDoble *& inicio,NodoDoble *& fin, int dato){
	
	NodoDoble * aux = inicio;
	
	// Buscar el nodo de valor igual al dato 
	while(aux != NULL && aux->dato != dato) 
	{
		aux = aux->siguiente;
	}
	
	
	// El dato no está en la lista /
	if(aux == NULL) 
	{
		printf("dato no encontrado o la lista esta vacia\n");
		return;
		
	}
	
	// quitamos el nodo que contiene el dato enviado por parametro
	if(aux == inicio)
	{
		inicio = aux->siguiente;
		//inicio->anterior = NULL;
	}
	
	if(aux->anterior != NULL) // no es el primer nodo 
	{
		aux->anterior->siguiente = aux->siguiente;
	}
	
	if(aux->siguiente != NULL) // no el el último nodo
	{
		aux->siguiente->anterior = aux->anterior;
	}
	
	// borramos el nodo
	free(aux);
	aux = NULL;
	
	
	// Se coloca el nodo fin apuntando al ultimo nodo
	NodoDoble * aux2 = inicio;
	fin = NULL;// En caso de que la lista esté vacía entonces ya fin apuntaria a NULL 
	
	while(aux2 != NULL)
	{
		fin =  aux2;
		aux2 = aux2->siguiente;
		
	}
}

void listarElementosDoblementeDesordenados(NodoDoble *lista, int n){
	
	NodoDoble *aux = lista;
	
	if (aux == NULL){
		printf("lista Vacia\n");
	}
	
	while(aux != NULL){
		printf("%d ", aux->dato);
		if(n == 1){
			aux = aux->siguiente;
		}else{
			aux = aux->anterior;
		}
	}
	
	getch();
}

void buscarElementoDoblementeDesordenado(int n, NodoDoble  *lista)
{
	int encontrado = 0;
	NodoDoble *aux = lista;
	
	if(listaDoblementeVacia(lista)){
		
		printf("lista Vacia");
		
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				
				encontrado = 1;
				printf("Dato encontrado");
				break;
			}
			aux = aux->siguiente;
		}
		if(encontrado == 0){
			printf("dato no encontrado");
		}
	}
	getch();
}

void menuListaDoblementeEnlazadasDesordenada()
{
	int opcion=1;
	int n;
	NodoDoble * inicio = NULL;
	NodoDoble * fin = NULL;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----S U B M E N U----\n");
		printf("1. Insertar Elementos \n");
		printf("2. Editar Elementos \n");
		printf("3. Eliminar Elementos \n");
		printf("4. Mostrar de adelante hacia atras\n");
		printf("5. Mostrar de atras hacia adelante\n");
		printf("6. Buscar Elementos \n");
		printf("0. Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			int dato = pedirDatos();
			insertarElementoDoblementeDesordenadas(inicio, fin, dato);
			
			break;
		}          
		case 2: 
		{
			int dato = pedirDatos();
			editarElementoDoblementeDesordenado(inicio, dato);
			
			break;
		}        
		
		case 3: 
		{
			int dato = pedirDatos();
			eliminarElementoDoblementeDesordenada(inicio, fin, dato);
			
			break;
		}  
		
		case 4: 
		{
			n = 1;
			listarElementosDoblementeDesordenados(inicio, n);
			
			break;
		}  
		
		case 5: 
		{
			n = -1;
			listarElementosDoblementeDesordenados(fin, n);
			
			break;
		} 
		
		
		case 6: 
		{
			int dato = pedirDatos();
			buscarElementoDoblementeDesordenado(dato, inicio);
			
			break;
		}  
		
		default:{
			system("CLS");
			
			break;
		}          
		}
	}
	
}

//******************************************************************//
void insertarElementoCircularesDoblesOrdenadas(NodoDoble *&inicio, int dato){
	
	NodoDoble *actual = NULL;
	NodoDoble *nuevo = (NodoDoble*)malloc(sizeof (NodoDoble)); //crea un nuevo nodo reservando memoria
	
	nuevo->dato = dato;
	
	// Colocamos actual en la primera posición de la lista
	actual = inicio;
	
	// Si la lista está vacía o el primer nodo es mayor que el nuevo
	if(!actual){
		inicio = nuevo;
		inicio->anterior = inicio;
		inicio->siguiente = inicio;
	}
	else if(actual->dato > dato){
		
		NodoDoble *ultimo = actual->anterior;
		
		// Añadimos la lista despues del nuevo nodo
		nuevo->siguiente = actual; 		
		actual->anterior = nuevo;		
		
		// Se hace circular
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;	
		
		inicio = nuevo;
	}
	else {
		// Avanzamos hasta el último elemento o hasta que el siguiente tenga 
		//un valor mayor que dato
		while(actual->siguiente != inicio && actual->siguiente->dato <= dato) 
		{
			actual = actual->siguiente;
		}		
		
		//Insertamos el nuevo nodo después del nodo anterior
		nuevo->siguiente = actual->siguiente;
		actual->siguiente = nuevo;
		nuevo->anterior = actual;
		
		nuevo->siguiente->anterior = nuevo;		
	}
}

bool listaCircularesVacia(NodoSimple *inicio){
	return (inicio == NULL) ? true:false;
}

void editarElementoCircularesDoblesOrdenado(NodoDoble *&inicio, int valor){
	
	NodoDoble *aux = inicio;
	int nuevoDato = 0;
	
	if(aux == NULL)
	{
		printf("Lista vacia\n");
	}
	
	while (aux != NULL) {
		if(aux->dato == valor)
		{
			printf("Digite el nuevo valor: \n");
			scanf("%d", &nuevoDato);
			aux->dato = nuevoDato;
			break;
		}
		
		aux = aux->siguiente;
		if(aux == inicio)
		{
			printf("Valor %d no encontrado\n", valor);
			break;
		}
	}
	
	getchar();
	getchar();
}

void eliminarElementoCircularesDoblesOrdenada(NodoDoble *&inicio, int valor){
	
	NodoDoble *aux1 = inicio;
	NodoDoble *aux2 = NULL;
	int i = 0;
	
	if (aux1 == NULL)
	{
		printf("Lista vacia, valor no encontrado\n");
		return;
	}
	
	while (aux1 != NULL && i == 0) { 
		if (aux1->dato == valor) { //si encuentra el nodo a eliminar           
			aux2 = aux1->anterior; //ubica el nodo anterior
			if(aux2 != aux1){ //si no es el único nodo
				aux2->siguiente = aux1->siguiente;
				aux1->siguiente->anterior = aux2;
				if(aux1 == inicio) //si el nodo a eliminar es el inicio de la lista
					inicio = aux2->siguiente; //apunta el inicio al nodo siguiente
			}else{ //si es el único nodo
				inicio = NULL; //pone la lista en nulo
			}
			free(aux1);
			printf("Valor %d eliminado\n", valor);
			return;
		}
		aux1 = aux1->siguiente; //avanza al siguiente nodo
		
		// Como la lista es circular, si llegamos al inicio nos salimos del while ...
		if(aux1 == inicio){
			printf("Valor %d no encontrado\n", valor);
			i++;
		}
	}
	
	getchar();
	getchar();
}

void listarElementosCircularesDoblesOrdenados(NodoDoble *&inicio){
	
	NodoDoble *aux1 = inicio;
	
	if (aux1 == NULL)
	{
		printf("Lista vacia\n");
	}
	
	int i=0;
	while (aux1 != NULL && i == 0) {
		printf("%d ", aux1->dato);
		aux1 = aux1->siguiente;
		if(aux1 == inicio)
		{
			i++;
		}
	}
	printf("\n");
	getchar();
	getchar();
	
}

void buscarElementoCircularesDoblesOrdenado(NodoDoble *& inicio, int dato)
{
	NodoDoble *aux = inicio;
	
	
	if(aux == NULL)
	{
		printf("Lista vacia\n");
	}
	
	while (aux != NULL) {
		if(aux->dato == dato)
		{
			printf("Valor %d encontrado\n", dato);   
			break;
		}
		
		aux = aux->siguiente;
		if(aux == inicio)
		{
			printf("Valor %d no encontrado\n", dato);
			break;
		}
	}
}

void menuListaCircularDobleOrdenada()
{
	int opcion=1;
	NodoDoble * inicio = NULL;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----S U B M E N U----\n");
		printf("1. Insertar Elementos \n");
		printf("2. Editar Elementos \n");
		printf("3. Eliminar Elementos \n");
		printf("4. Mostrar Elementos \n");
		printf("5. Buscar Elementos \n");
		printf("0. Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			int dato = pedirDatos();
			insertarElementoCircularesDoblesOrdenadas(inicio, dato);
			
			break;
		}          
		case 2: 
		{
			int dato = pedirDatos();
			editarElementoCircularesDoblesOrdenado(inicio, dato);
			
			break;
		}        
		
		case 3: 
		{
			int dato = pedirDatos();
			eliminarElementoCircularesDoblesOrdenada(inicio, dato);
			
			break;
		}  
		
		case 4: 
		{
			
			listarElementosCircularesDoblesOrdenados(inicio);
			
			break;
		}  
		
		case 5: 
		{
			int dato = pedirDatos();
			buscarElementoCircularesDoblesOrdenado(inicio, dato);
			
			break;
		}  
		
		default:{
			system("CLS");
			
			break;
		}          
		}
	}
	
}
//******************************************************************//
void insertarElementoCircularDoblesDesordenado(NodoDoble *&inicio, int dato){
	
	NodoDoble *nuevo = (NodoDoble*)malloc(sizeof (NodoDoble)); //crea un nuevo nodo reservando memoria
	if (nuevo != NULL) { //si se pudo conseguir memoria
		nuevo->dato = dato; //asigna el nuevo valor
		if(inicio != NULL){
			nuevo->anterior = inicio->anterior;
			nuevo->siguiente = inicio;
			inicio->anterior->siguiente = nuevo;
			inicio->anterior = nuevo;
		}else{
			nuevo->anterior = nuevo;
			nuevo->siguiente = nuevo;
		}
		inicio = nuevo; //apunta el principio de la lista hacia el nuevo nodo
	}
}

void editarElementoCircularDoblesDesordenado(NodoDoble *&inicio, int valor){
	
	NodoDoble *aux = inicio;
	int nuevoDato = 0;
	
	if(aux == NULL)
	{
		printf("Lista vacia\n");
	}
	
	while (aux != NULL) {
		if(aux->dato == valor)
		{
			printf("Digite el nuevo valor: \n");
			scanf("%d", &nuevoDato);
			aux->dato = nuevoDato;
			break;
		}
		
		aux = aux->siguiente;
		if(aux == inicio)
		{
			printf("Valor %d no encontrado\n", valor);
			break;
		}
	}
	
	getchar();
	getchar();
	
}

void eliminarElementoCircularDoblesDesordenado(NodoDoble *&inicio, int valor){
	
	NodoDoble *aux1 = inicio;
	NodoDoble *aux2 = NULL;
	int i = 0;
	while (aux1 != NULL && i == 0) { 
		if (aux1->dato == valor) { //si encuentra el nodo a eliminar           
			aux2 = aux1->anterior; //ubica el nodo anterior
			if(aux2 != aux1){ //si no es el único nodo
				aux2->siguiente = aux1->siguiente;
				aux1->siguiente->anterior = aux2;
				if(aux1 == inicio) //si el nodo a eliminar es el inicio de la lista
					inicio = aux2->siguiente; //apunta el inicio al nodo siguiente
			}else{ //si es el único nodo
				inicio = NULL; //pone la lista en nulo
			}
			free(aux1);
			return;
		}
		aux1 = aux1->siguiente; //avanza al siguiente nodo
		if(aux1 == inicio){
			i++;
		}
	}
}

void listarElementosCircularDobleDesordenado(NodoDoble *&inicio){
	
	NodoDoble *aux1 = inicio;
	int i=0;
	while (aux1 != NULL && i == 0) {
		printf("%d ", aux1->dato);
		aux1 = aux1->siguiente;
		if(aux1 == inicio)
		{
			i++;
		}
	}
	printf("\n");
	getchar();
	getchar();
}

void intercambiar(int *izq, int *der)
{
	int temp = *izq;
	*izq = *der;
	*der = temp;
}

void ordenamientoBurbuja(int arreglo[], int tamano)
{
	int i, j;
	for (i = 0; i < tamano-1; i++)      
	{ 
		for (j = 0; j < tamano-i-1; j++) 
		{
			if (arreglo[j] > arreglo[j+1])
				intercambiar(&arreglo[j], &arreglo[j+1]);
		}
	}
}

void ordenar(NodoDoble *& inicio)
{
	NodoDoble *aux1 = inicio;
	int i=0;
	int tamano = 0;
	
	// Calculando el tamaño de la lista
	while (aux1 != NULL && i == 0) {
		aux1 = aux1->siguiente;
		tamano++;
		if(aux1 == inicio)
		{
			i++;
		}
	}
	
	int *arreglo = new int[tamano];
	aux1 = inicio;
	i = 0;
	// Guardando la lista en un arreglo
	int posicion = 0;
	while (aux1 != NULL && i == 0) {
		arreglo[posicion] = aux1->dato;
		aux1 = aux1->siguiente;
		posicion++;
		if(aux1 == inicio)
		{
			i++;
		}
	}
	
	// Ordenando la lista
	ordenamientoBurbuja(arreglo, tamano);
	
	// Colocando los valores ordenados en la lista
	aux1 = inicio;
	i = 0;
	posicion = 0;
	
	// Guardando la lista en un arreglo	
	while (aux1 != NULL && i == 0) {
		aux1->dato = arreglo[posicion];
		aux1 = aux1->siguiente;
		posicion++;
		if(aux1 == inicio)
		{
			i++;
		}
	}
}

void buscarElementoCircularDobleDesordenado(NodoDoble *& inicio, int dato)
{
	NodoDoble *aux = inicio;
	
	
	if(aux == NULL)
	{
		printf("Lista vacia\n");
	}
	
	while (aux != NULL) {
		if(aux->dato == dato)
		{
			printf("Valor %d encontrado\n", dato);   
			break;
		}
		
		aux = aux->siguiente;
		if(aux == inicio)
		{
			printf("Valor %d no encontrado\n", dato);
			break;
		}
	}
}

void menuListaCircularDobleDesordenada()
{
	int opcion=1;
	NodoDoble * inicio = NULL;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----S U B M E N U----\n");
		printf("1. Insertar Elementos \n");
		printf("2. Editar Elementos \n");
		printf("3. Eliminar Elementos \n");
		printf("4. Mostrar Elementos \n");
		printf("5. Ordenar Elementos \n");
		printf("6. Buscar Elementos \n");
		printf("0. Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			int dato = pedirDatos();
			insertarElementoCircularDoblesDesordenado(inicio, dato);
			
			break;
		}          
		case 2: 
		{
			int dato = pedirDatos();
			editarElementoCircularDoblesDesordenado(inicio, dato);
			
			break;
		}        
		
		case 3: 
		{
			int dato = pedirDatos();
			eliminarElementoCircularDoblesDesordenado(inicio, dato);
			
			break;
		}  
		
		case 4: 
		{
			listarElementosCircularDobleDesordenado(inicio);
			
			break;
		}  
		
		case 5: 
		{
			ordenar(inicio);
			
			break;
		}  
		
		
		case 6: 
		{
			int dato = pedirDatos();
			buscarElementoCircularDobleDesordenado(inicio, dato);
			
			break;
		}  
		
		default:{
			system("CLS");
			
			break;
		}             
		}
	}
	
}

//Josefo
void insertarListaCircularSimplementeDesordenada(NodoSimple *&inicio, int dato) {
	
	NodoSimple * aux1 = inicio;
	
	// Creamos un nodo para el nuvo valor a insertar
	NodoSimple *nuevo = (NodoSimple*)malloc(sizeof(NodoSimple));
	nuevo->dato = dato;
	
	// Si la lista esta vacia
	if(inicio== NULL) {
		inicio = nuevo;
		inicio->siguiente = inicio;
	}
	else {
		nuevo->siguiente = inicio;
		
		// Se recorre la lista hasta llegar al ultimo nodo
		while(aux1->siguiente != inicio) {
			aux1 = aux1->siguiente;
		}
		
		// Hacemos que el siguiente del ultimo nodo apunte al primero
		// Para asi hacerla circular
		aux1->siguiente = nuevo;
		inicio = nuevo;
	}
	
}

void eliminarListaCircularSimplementeDesordenada(NodoSimple *&lista, int dato) {
	NodoSimple *nodo = lista;
	
	if (lista == NULL)
	{
		printf("Lista vacia, valor no encontrado\n");		
	}else {
		// Hacemos que inicio apunte al nodo anterior al de dato
		do {
			if(lista->siguiente->dato != dato) {
				lista = lista->siguiente;
			}
		} while(lista->siguiente->dato != dato && lista != nodo);
		
		// Si existe un nodo con el valor igual a dato:
		if(lista->siguiente->dato == dato) {
			// Si la lista solo tiene un nodo
			if(lista == lista->siguiente) {
				// Borramos la lista
				free(lista);
				lista = NULL;
			}
			else {
				// Borramos el nodo  de valor igual al dato
				nodo = lista->siguiente;
				lista->siguiente = nodo->siguiente;
				lista = lista->siguiente;
				free(nodo);
			}
		}
	}
}

int brincar(NodoSimple *&nodoActual, int cantidadBrincos)
{
	NodoSimple *nodo = nodoActual;
	int i = 0;
	
	if (nodoActual == NULL){
		printf("Lista vacia\n");
		// Lista estaba vacia
		return -1;
	}else {
		printf("Brincando a los soldados:\n");
		for(i = 0; i < cantidadBrincos; i++) {
			printf("%d ", nodo->dato);
			nodo = nodo->siguiente;
		}
		printf("\n");
		return nodo->dato;
	}	
}

void insertarSoldados(NodoSimple *&inicio, int cantidad)
{
	int i = 0;
	for (i = 0; i < cantidad; i++)
	{
		insertarListaCircularSimplementeDesordenada(inicio, i);
	}
}

//*****************************************************************//

void menuJosefo()
{
	system("cls");
	
	NodoSimple *lista = NULL;
	NodoSimple *nodoActual = NULL;
	
	int numSoldados, tamanoBrinco;
	
	printf("Cuantos soldados quiere agregar?:\n");
	scanf("%d", &numSoldados);
	insertarSoldados(lista, numSoldados);
	nodoActual = lista;
	printf("De que tamano quiere hacer el brinco?\n");
	scanf("%d", &tamanoBrinco);
	do {
		int posicionAEliminar = brincar(nodoActual, tamanoBrinco);
		// Si hay algun soldado a eliminar
		if (posicionAEliminar != -1)
		{
			printf("Soldado eliminado: %d\n", posicionAEliminar);
			eliminarListaCircularSimplementeDesordenada(nodoActual, posicionAEliminar);
			lista = nodoActual; 
			// si la lista esta vacia o solo queda un soldado vivo
			if (lista != NULL && lista == lista->siguiente)
			{
				printf("\nEl Soldado en la posicion %d gana\n", lista->dato);
				getchar();
				break;
			}
		}				
		
	} while (lista != NULL && lista != lista->siguiente);
}

int main (int argc, char *argv[]) 
{
	int opcion=1;
	
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.Listas Simplemente Enlazadas Ordenadas: \n");
		printf("2.Listas Simplemente Enlazadas Desordenadas: \n");
		printf("3.Listas Doblemente Enlazadas Ordenadas: \n");
		printf("4.Listas Doblemente Enlazadas Desordenadas: \n");
		printf("5.Listas Circular Simple(El problema de Josefo): \n");
		printf("6.Listas Circular Doblemente Ordenada: \n");
		printf("7.Listas Circular Doblemente Desordenada: \n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		case 1: 
		{
			menuListaSimplementeEnlazadasOrdenada();
			
			break;
		}          
		case 2: 
		{
			menuListaSimplementeEnlazadasDesordenada();
			
			break;
		}        
		
		case 3: 
		{
			menuListaDoblementeEnlazadasOrdenada();
			
			break;
		}  
		
		case 4: 
		{
			menuListaDoblementeEnlazadasDesordenada();
			
			break;
		}  
		
		case 5: 
		{ 
			menuJosefo();
			getchar();
			break;
		}  
		
		case 6: 
		{
			menuListaCircularDobleOrdenada();
			
			break;
		}
		
		case 7: 
		{
			menuListaCircularDobleDesordenada();
			
			break;
		}
		default:{
			system("CLS");
			
			break;
		}          
		}
	}
	
	
	return 0;
}
