#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

	struct nodo{
        int dato;
        nodo *siguiente; 
		};


nodo *crear_nodo(int x);//inicializar
void imprimir(nodo *inicio);
nodo *list(int x, nodo *inicio);

	int main(){
	nodo *cabeza=NULL;
	nodo *cabeza2=NULL;
	
	
    cabeza=list(3,  cabeza);
	cabeza=list(5,  cabeza);
	cabeza=list(6,  cabeza);
	cabeza=list(7,  cabeza);
	cabeza=list(8,  cabeza);
	
	
	cabeza2=list(1,  cabeza2);
	cabeza2=list(4,  cabeza2);
	cabeza2=list(5,  cabeza2);
	cabeza2=list(8,  cabeza2);
	cout<<"EL CONJUNTO A ES"<<endl<<endl;
	
    imprimir(cabeza); //mostrar la la cabeza de la lista y la lista
    
    imprimir(cabeza2); 
    system("pause");
    return 0;
    
	}

    nodo * crear_nodo(int x){
     
      nodo *n;
      n=(nodo*)malloc(sizeof(nodo));
      n->dato=x;
      n->siguiente=NULL;
      return n;
      
      }
      
       
       
	nodo* list(int x, nodo* cabeza){
 	 nodo *nuevo;
 	 nuevo=crear_nodo(x);
 	 
	  if(==NULL){// Si la cabeza de lista esta vacia llenar
		return nuevo;
      }          
    
	  else if (n->dato > nuevo->dato){// inicio mayor que nuevo si no la cabeza seria mayor que nuevo
     	nuevo->siguiente=n; // en ese caso nuevo siguiente seria la cabeza
   	   	n=nuevo;
  		return n;
     }



	  else {
     	nodo *aux; // auxiliar para no perder el valor de inicio 
     	for (aux=n; aux->siguiente != NULL; aux=aux->siguiente){
               
     	 if(aux->dato < nuevo->dato && aux->siguiente->dato > nuevo->dato){
                  
    	  nuevo->siguiente=aux->siguiente;
		  aux->siguiente=nuevo;
    	  return n;

          }
	     }         
         
      aux->siguiente=nuevo;
	  }
	}
    
	void imprimir(nodo *inicio){// funcion imprimir

	 for(; inicio!=NULL; inicio=inicio->siguiente){
        cout<<inicio->dato<<endl;
     }
    }

