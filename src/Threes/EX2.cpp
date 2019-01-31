
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct arco{
	char datoArcoChar;
	int datoArcoInt;
	arco *next;	
};
struct nodo{
    char datoChar;
	int datoInt;
    nodo *next;
    struct arco *right;
};

nodo * crearNodo(char c);
arco * crearArco(char c);
arco * insertarArcos(char x, arco *arcos);
nodo * insertarVertices(char x, nodo *vertice);
bool buscarVertices(char x, nodo *vertices);
nodo * entrarVerticesArcos(char x, char m, nodo *vertices, int marcos);
void imprimir(nodo * cabeza);
void imprimir2(arco * cabeza);
void imprimirLi(nodo * cabeza);

nodo * crearNodo(char c){

    nodo *p;
    p=(nodo *)malloc(sizeof(nodo));
    p->datoChar=c;
    p->next=NULL;
    p->right=NULL;
    return p;
}


arco * crearArco(char c){

    arco *p;
    p=(arco *)malloc(sizeof(arco));
    p->datoArcoChar=c;
    p->next=NULL;
    return p;
}

arco * insertarArcos(char x, arco *arcos){
     
    arco * nuevo;
    arco * aux;
    nuevo=crearArco(x);
    
    if(arcos==NULL) 
    return nuevo;
    else{
	    for(aux=arcos;aux->next!=NULL; aux=aux->next);
	                aux->next=nuevo;
	                
	                return arcos;
    }
}


nodo * insertarVertices(char x, nodo *vertice){
	
    arco*newArco=NULL;
    nodo * nuevo;
    nodo * aux;
    nuevo=crearNodo(x);
    
    if(vertice==NULL){
	    return nuevo;
	}
    else{
         
    for(aux=vertice;aux->next!=NULL; aux=aux->next);
    			
				aux->next=nuevo;
    
                return vertice;
    }
}


void imprimir(nodo * cabeza){
     
     for(;cabeza!=NULL; cabeza=cabeza->next){
	     printf("\n %c 	", cabeza->datoChar);
	     if(cabeza->right){
	     	imprimir2(cabeza->right);
	     }
 	}
}
void imprimir2(arco * cabeza){
     
     for(;cabeza!=NULL; cabeza=cabeza->next){
	     //cout<<cabeza->dato;
	     printf(" %c ", cabeza->datoArcoChar);
 	}
}

void imprimirLi(nodo * cabeza){
     
     for(;cabeza!=NULL; cabeza=cabeza->next){
	     //cout<<cabeza->dato;
	     printf(" %c ", cabeza->datoChar);
 	}
}

bool buscarVertices(char x, nodo *vertices){ 

    nodo * aux;
    
    if(vertices==NULL){
	   return false;
	}
	else{
	         
	    for(aux=vertices;aux!=NULL; aux=aux->next){

	    	if(aux->datoChar == x){
	    			return true;
	    	}			
	    }
        return false;        
    }
}


nodo * entrarVerticesArcos(char x, char m, nodo *vertices,int marcos){ 

    nodo * aux;
    arco * apo;
    
    if(vertices==NULL){
	   return vertices;
	}
	else{
	         
	    for(aux=vertices;aux!=NULL; aux=aux->next){

	    	if(aux->datoChar == x && marcos==1){
	    			
	    			apo=aux->right;
	    			//printf("(%c)",apo->datoArcoChar);
	    			aux->right=insertarArcos(m,apo);
	    			//imprimir2(aux->right);
	    			return vertices;
	    	}			
	    }        
    }
}


nodo * buscaElimina(char x, nodo * cabeza){
	
	nodo * aux, *aux2;
	nodo * nuevo;
	
	if(cabeza==NULL){
		
		printf("\nNo hay Vertices\n");
		return cabeza;
	}
	else{
		
		if(cabeza->datoChar==x){ //Se elimina el primer dato
			
			aux=cabeza;
			cabeza=aux->next;
			free(aux);
			return cabeza;
		}
		else{ //Se eliminan los datos de en medio
			
					for(aux=cabeza;aux->next!=NULL; aux=aux->next);
					char i=aux->datoChar;
					for(aux=cabeza;aux->next!=NULL; aux=aux->next){ // Recorre la lista hasta que encuentre un null
							
							aux2=aux->next;
						
							if(aux2->datoChar==x){
								aux->next=aux2->next;
								free(aux2);
								return cabeza;
								
							}		
					}
					
					if(i==aux->datoChar){
						
							printf("\nNo se han encontrado resultados para tu busqueda\n ");
							return cabeza;	
					}			
		}	
	}	
}
//----------------------Funcion Main-------------------------------
int main(){
	
nodo * vertice=NULL;
char v, d, h, m, e;
int opc;
	
do{
	system("color f0");
	printf("\nSeleccione Opcion:\n");
	printf("\n1.- Insertar nodos");
	printf("\n2.- Agregar Arco ");
	printf("\n3.- Imprimir  ");
	printf("\n4.- Eliminar nodo ");

	fflush(stdin);
	scanf("%d",&opc);
	
	switch(opc){
		
		case 1:
			
			printf("\nIngrese Vertices:");
			fflush(stdin);
			scanf("%c", &v);
			if(buscarVertices(v,vertice)){
				printf("\nYa existe el Vertice");
			}
			else{
			
			vertice=insertarVertices(v,vertice);
			}
			
			
			getch();
			break;
			
		case 3:
			printf("\nNodos	Arcos\n");
			imprimir(vertice);
			printf("\n\n");
			getch();
			//system("pause");
			break;
		case 2:
			printf("\nSeleccione el vertice:\n");
			imprimirLi(vertice);
			printf("\n");
			fflush(stdin);
			scanf("%c", &h);
			if(buscarVertices(h,vertice)){
				printf("\nIngrese el Arco:");
				fflush(stdin);
				scanf("%c",&m);
				if(buscarVertices(m,vertice)){
					entrarVerticesArcos(h,m,vertice,1);
				}
				else{
					printf("\nVertice NO existe");
				}
			}
			else{
				printf("\nVertice Invalido");
			}
			getch();
			break;
		case 4:
			printf("\Ingrese el Vertice a Eliminar: ");
			fflush(stdin);
			scanf("%c", &e);
			if(buscarVertices(v,vertice)){
               	buscaElimina(e,vertice);     
                entrarVerticesArcos(h,m,vertice,2);                                                                         				
			}
			else{
			     printf("\nNo existe el Vertice");
			}

			getch();
			break;
		case 5:
			break;
		default:
			break;
	}
	
}while(opc!=5);

system("\npause");	
return 0;
}
