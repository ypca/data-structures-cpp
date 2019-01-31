#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct nodo{
    int dato;
    int fe;
    nodo *izquierda;
    nodo *derecha;
};

nodo * crearNodo(int x);
nodo * insertarNodoArbolRecursivo(int x, nodo *raiz);
void actualizarAltura( struct nodo **arbol);
int calculaAltura(struct nodo *arbol);
void imprimirFE(nodo *arbol);
void izqizq(nodo **n, nodo **n1);
nodo * izqizq(nodo * n, nodo * n1);
nodo * izqder(nodo *n, nodo *n1, nodo *n2);
nodo * derder(nodo *n, nodo *n1);
nodo * derizq(nodo *n, nodo *n1, nodo *n2);
void verificarAVL(nodo **avl);


int main(){

nodo * avl=NULL; 
int opc, x, out;


do{
		system("color f0");
		system("cls");
     	printf(" MENU\n");
		printf("\n1.Insertar Nodos");
		printf("\n2.Ver Arbol AVL") ;
		printf("\n3.Salir \n");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 1:
				
				
				do{
				system("cls");
				printf("Valor del nodo: ");
				scanf("%d", &x);
				avl=insertarNodoArbolRecursivo(x, avl);
				verificarAVL(&avl);
				printf("\n\n1.Insertar nuevo nodo");
				printf("\n\n2.Regresar\n\n");
				scanf("%d", &out);
				}while(out!=2);
				break;
				
			case 2:
				
     			printf("\n\n");
     			imprimirFE(avl);
     			printf("\n\n");
     			system("pause");
     			
				break;
				
				
			case 3:
				break;
			default:
				printf("\nOpcion invalida\n");
				break;
		}
}while(opc!=3);
     	
system("pause");
return 0;
}




nodo * crearNodo(int x){

    nodo *p;
    p=(nodo *)malloc(sizeof(nodo));
    p->dato=x;
    p->izquierda=NULL;
    p->derecha=NULL;
    return p;
}

nodo * insertarNodoArbolRecursivo(int x, nodo *raiz){ 
     
    nodo * arbol;
    nodo * aux=raiz;
    arbol=crearNodo(x);
    
    if(raiz){         
             if(raiz->dato <= x){  
                           if(raiz->derecha==NULL){
                     
                             raiz->derecha=arbol;
                             return aux;                                                  
                           }
                           else{
                           
                          
                           aux->derecha=insertarNodoArbolRecursivo(x, raiz->derecha);
                           return aux;
                       	   }
             }
             else 		   
			 			   if(raiz->izquierda==NULL){ 
                           
                     			raiz->izquierda=arbol;
                     			return aux;                                                  
              				}
              				else{
              				
                  				
								aux->izquierda=insertarNodoArbolRecursivo(x, raiz->izquierda);
								return aux;
							}        
    }
    else{
         return arbol;
    }   
}

void verificarAVL(nodo **avl){
     	actualizarAltura(&(*avl));
		nodo *aux;			
     
          if(*avl){
          	  verificarAVL(&(*avl)->izquierda);
          	  actualizarAltura(&(*avl));
              verificarAVL(&(*avl)->derecha);
              actualizarAltura(&(*avl));
                  
              printf("\n %d ", (*avl)->dato); 
              printf(" <%d> ", (*avl)->fe);
              
              if((*avl)->fe == -1 || (*avl)->fe == 0 || (*avl)->fe == 1){
              
                printf("  : %d ", (*avl)->dato);                                                                           
              }
              else{
                   if((*avl)->fe < 0){ 
					
					cout<<"Izquierdo ";
					
                   		if((*avl)->izquierda->fe < 0){
                   			(*avl)=izqizq(*avl, (*avl)->izquierda);
                   			
                   		}
                   		if((*avl)->izquierda->fe > 0){
                   			(aux)=(*avl)->izquierda;
							printf("  %d , ", (*avl)->dato);
							printf("  %d , ", (*avl)->izquierda->dato);
							printf("  %d  ", (aux)->derecha->dato);
                   			
                   			(*avl)=izqder((*avl), (*avl)->izquierda, (aux)->derecha);
                   		}
                   }
                   
                   if((*avl)->fe > 0){ 
                   
                   cout<<"Derecho ";								
                   	
                   	    if((*avl)->derecha->fe > 0){
                
                   			(*avl)=derder(*avl, (*avl)->derecha);
                   				printf("  %d , ", (*avl)->dato);
                   				printf("  %d , ", (*avl)->izquierda->dato);
                   				printf("  %d  ", (*avl)->derecha->dato);
                   			
                   		}
                   		if((*avl)->derecha->fe < 0){
                   			
                   			(aux)=(*avl)->derecha;
							printf("  %d , ", (*avl)->dato);
							printf("  %d , ", (*avl)->derecha->dato);
							printf("  %d  ", (aux)->izquierda->dato);
                   			
                   			(*avl)=derizq((*avl), (*avl)->derecha, (aux)->izquierda);
                   			printf("  %d , ", (*avl)->dato);
                   			printf("  %d , ", (*avl)->izquierda->dato);
                   			printf("  %d  ", (*avl)->derecha->dato);
                   		}

                   }
                  printf(" no es AVL ", (*avl)->dato);
              }
     	  }             
}

void actualizarAltura( struct nodo **arbol){
     
     if(*arbol){
               
               (*arbol)->fe=calculaAltura((*arbol)->derecha) - calculaAltura((*arbol)->izquierda);
               actualizarAltura(&((*arbol)->izquierda));
               actualizarAltura(&((*arbol)->derecha));
               }

}

int calculaAltura(struct nodo *arbol){
    
    if(arbol){
              
              if(calculaAltura(arbol->izquierda) > calculaAltura(arbol->derecha)){
              
                     return calculaAltura(arbol->izquierda)+1;
              }
              else{
              
                     return calculaAltura(arbol->derecha)+1;
              }
    }
    else
        return 0;    
}



//IZQUIERDA-IZQUIERDA
nodo * izqizq(nodo * n, nodo * n1){
	n->izquierda=n1->derecha;
	n1->derecha=n;
	n=n1;
	printf(" ( %d ) ", (n)->dato);
	printf(" ( %d ) ", (n)->izquierda->dato);
	printf(" ( %d ) ", (n)->derecha->dato);
	return n;
}
// IZQUIERDA-DERECHA
nodo * izqder(nodo *n, nodo *n1, nodo *n2){
n1->derecha=n2->izquierda;
n2->izquierda=n1;
n->izquierda=n2->derecha;
n2->derecha=n;
n=n2;

return n;
}

// DERECHA-DERECHA
nodo * derder(nodo *n, nodo *n1){
n->derecha=n->izquierda;
n1->izquierda=n;
n=n1;
return n;
}
// DERECHA-IZQUIERDA
nodo * derizq(nodo *n, nodo *n1, nodo *n2){
n1->izquierda=n2->derecha;
n2->derecha=n1;
n->derecha=n2->izquierda;
n2->izquierda=n;
n=n2;
return n;
}

void imprimirFE(nodo *arbol){
     
          if(arbol){
             
              printf(" %d ", arbol->dato); // NODO
              printf(" <%d> ", arbol->fe);
			  imprimirFE(arbol->izquierda); 
              imprimirFE(arbol->derecha);   
     	  }  
}

