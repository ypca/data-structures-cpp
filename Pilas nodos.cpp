#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct nodo{
    int dato;
    struct nodo *sgte;
};
 
typedef nodo *ptrPila;  
 
void poner( ptrPila &p, int valor );

int desap( ptrPila &p );

void eliminar( ptrPila &p);

void imprimir( ptrPila p );

int main(){
	system("color F0");
    ptrPila p = NULL;  
    int dato;
    int op;
    int x ; 

    do{
    cout<<endl<<"LA PILA ES: "<<endl<<endl;

                 if(p!=NULL) {
				 imprimir(p);
				 cout<<endl<<endl;
			     }
				 else   cout<<"LA PILA ESTA VACIA"<<endl<<endl;
	
	cout<<" 1. insertar en la cima "<<endl;

    cout<<" 2. quitar cima  ..desapilar  "<<endl;
    
    cout<<" 3. desapilar todo  "<<endl;

    cout<<" 4. salir                  "<<endl;
    			 
    cout<<endl<<"Ingrese una opcion: ";
	
	cin>> op;
 	if(op==1||2||3||4||5){
        switch(op)
        {
            case 1:
 
                 cout<<endl<<"NUMERO A APILAR: "; 
				 cin>> dato;
                 poner(p, dato);
                 cout<<"Numero " << dato <<" colocado";
            break;
 
            case 2:
                 x = desap(p);
                 cout<<"Numero "<< x <<" desapilado\n";
            break;
                
            case 3:
 				 if(p!=NULL) {
				  eliminar( p );
				  cout<<"PILA ELIMINADA";
				 cout<<endl<<endl;
			     }
				 else cout<<"LA PILA YA ESTABA VACIA"<<endl<<endl; 
            break;
           
         }
 }
        system("pause");  
		system("cls");
    }while(op!=4);
    return 0;
}

void poner(ptrPila &p, int valor){
     ptrPila aux;
     aux = new(struct nodo);  
     aux->dato = valor;
     
     aux->sgte = p ;
     p = aux ;
}
 
int desap( ptrPila &p ){
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->dato;   
     
     p = aux->sgte ;
     delete(aux);
     
     return num;
}
 
void imprimir (ptrPila p ){
     ptrPila aux;
     aux = p;     
     while( aux !=NULL ){
     cout<<"\t"<< aux->dato <<endl;
     aux = aux->sgte;
     }    
}

void eliminar( ptrPila &p){
     ptrPila aux;
     
     while( p != NULL) {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}
