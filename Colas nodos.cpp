#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct nodo{
	int nro;
    struct nodo *sgte;
};
struct cola{
    nodo *delantero;
    nodo *atras;
};

void colocarcola( struct cola &p, int valor );
int sacar(struct cola &p);
void eliminar( struct cola &p);
void imprimir( struct cola p);

int main(){
    system("color F0");
    struct cola Q;
    Q.delantero = NULL;
    Q.atras   = NULL;
    int dato,op,x;
    do{
    
    cout<<endl<<"LA FILA CONTIENE: ";

                 if(Q.delantero!=NULL) {
				 imprimir(Q);
				 cout<<endl<<endl;
			     }
                 
				 else   cout<<"LA FILA ESTA VACIA"<<endl<<endl;
	
	cout<<" 1. insertar en la cola   "<<endl;

    cout<<" 2. quitar elemento        "<<endl;
    
    cout<<" 3. eliminar todo          "<<endl;

    cout<<" 4. salir                  "<<endl;
    			 
    cout<<endl<<"Ingrese una opcion: ";
	cin>> op;
      if(op==1||2||3||4||5){
      
        switch(op){

            case 1:
                 cout<<"Insertar en la cola: "; cin>> dato;

                 colocarcola(Q, dato );

                 cout<<"NUMERO " << dato << " INSERTADO\n\n";
            break;

            case 2:
				if(Q.delantero!=NULL)	{
                 x = sacar(Q);
                 cout<<"SU SACO DE LA FILA EL NUMERO "<<x;
				}
				
				else   cout<<"NO SE PUEDE DESAPILAR ELEMENTOS ...LA FILA ESTA VACIA"<<endl;
            break; 

  
            case 3:
				if(Q.delantero!=NULL) {
				 eliminar( Q );
				 cout<<"LA FILA HA SIDO VACIADA"<<endl;
			     }
                 
				 else   cout<<"LA FILA YA ESTABA VACIA"<<endl;	
                 

                
            break;
			
			
         }
			}
        system("pause");  
		system("cls");

    }
    while(op!=4);
    return 0;
}

void colocarcola( struct cola &p, int valor ){
     struct nodo *aux = new(struct nodo);
     aux->nro = valor;
     aux->sgte = NULL;
     if( p.delantero == NULL)
         p.delantero = aux;  
     else
         (p.atras)->sgte = aux;
     				p.atras = aux;       
}

int sacar( struct cola &p ){
     int num ;
     struct nodo *aux ;
     aux = p.delantero;    
     num = aux->nro;
     p.delantero = (p.delantero)->sgte;
     delete(aux);       
     return num;
}
void eliminar( struct cola &p){
     struct nodo *aux;
     while( p.delantero != NULL){
            aux = p.delantero;

            p.delantero = aux->sgte;

            delete(aux);
     }

     p.delantero = NULL;

     p.atras   = NULL;
}
void imprimir( struct cola p){
     struct nodo *aux;
     aux = p.delantero;
     while(aux!=NULL){
            cout<<" "<< aux->nro;
            aux = aux->sgte;
     }    
}


