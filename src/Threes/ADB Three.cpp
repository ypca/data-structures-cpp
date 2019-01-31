#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//estructura
struct nodo{
     int numero;
     struct nodo *izq, *der;
};

//inician funciones

nodo* crearNodo(int x) //funcion principal que creara el nodo
{
     nodo* nuevoNodo = new(struct nodo); //crea un nuevo nodo y lo inicializa adecuadamente
     nuevoNodo->numero = x; //le asigna el dato recibido
     nuevoNodo->izq = NULL; //pone en null los nodos izquierda y derecha
     nuevoNodo->der = NULL;

     return nuevoNodo; //retorna el nodo
}
void insertar(nodo* &arbol, int x) //recibe una direccion de nodo arbol y un numero
{
	
     if(arbol==NULL) //si la direccion esta vacia creara un nuevo nodo
     {
           arbol = crearNodo(x); //retorna el nodo creado y lo asigna a arbol
           cout<<"\nNuevo nodo creado"<<endl<<endl;
     }
     else if(x < arbol->numero){
     	  //cout<<"menor-";
          insertar(arbol->izq, x);
      }
     else if(x > arbol->numero){
     	  //cout<<"mayor-";
          insertar(arbol->der, x);
      }
}

void preOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->numero <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->numero << " ";
          enOrden(arbol->der);
     }
}

void postOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->numero << " ";
     }
}



bool busquedaRec(nodo* arbol, int dato)
{
     int r=0;   // sera 0 hasta que se encuentre

     if(arbol==NULL)
        return r; //si ya no hay nada, y ya acabo

     if(dato<arbol->numero)
         r = busquedaRec(arbol->izq, dato);

     else if(dato> arbol->numero)
         r = busquedaRec(arbol->der, dato);

     else
        r = 1;   // indica que son iguales

     return r;
}


nodo* unir(nodo* izq, nodo* der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    nodo* eliminado = unir(izq->der, der->izq);
    izq->der = eliminado;
    der->izq = izq;
    return der;
}
void eliminar(nodo* &arbol, int x){
     if(arbol==NULL) return;

     if(x<arbol->numero)
         eliminar(arbol->izq, x);
     else if(x>arbol->numero)
         eliminar(arbol->der, x);

     else{
         nodo* p = arbol;
         arbol = unir(arbol->izq, arbol->der);
         delete p;
     }
}




void imprimirarbol_anchura(nodo *arbol,int x){
     if(x==0)
     {
     cout<<arbol->numero<<" ";
     imprimirarbol_anchura(arbol,++x);
     }
     else if(x>0)
          {
          if(arbol)
             {
               if(arbol->izq!=NULL)
               cout<<arbol->izq->numero<<" ";
               if(arbol->der!=NULL)
               cout<<arbol->der->numero<<" ";
               imprimirarbol_anchura(arbol->izq,++x);
               imprimirarbol_anchura(arbol->der,++x);
             }
          
          
          }
     }//fin imprimirarbol_anchura
void imprimir_anchura(nodo *arbol, int s)
{
     if(s==0)
     cout<<arbol->numero<<" ";
     else if(s>0){
     if(arbol)
     {
             
             if(arbol->izq != NULL)
             cout<<arbol->izq->numero<<" ";
             if(arbol->der != NULL)
             cout<<arbol->der->numero<<" ";
             
             s++;
             cout << "******** izq           \n";
             imprimir_anchura(arbol->izq,s);
             cout << "******** der           \n";
             imprimir_anchura(arbol->der,s);
             
             }
}
}

void menu()
{
	
     system("cls");
     cout << "******** 1-  Insertar elemento                 \n";
     cout << "******** 2-  Buscar elemento     	       	  	 \n";
     cout << "******** 3-  Recorrer profundidad 3 casos      \n";
     cout << "******** 4-  Recorrer anchura                  \n";
     cout << "******** 5-  Eliminar elemento                 \n";
     cout << "******** 6-  Salir                             \n";

     cout << "\nOpcion: ";
}



int main()
{
    nodo* arbol = NULL;
    int x, s;
    int op, op2;


    system("color f0"); 
    do
    {
          menu();  cin>> op;
          cout << endl;

          switch(op)
          {
               case 1:
                    cout << "Ingresar numero: ";  cin>> x;
                    insertar(arbol, x);
                    system("pause");
                    break;

               

               case 2:
                      bool band;
                    enOrden(arbol); 
                    cout<<" \n Buscar: "; cin>> x;

                    band = busquedaRec(arbol,x);

                    if(band==1)
                       cout << "\n\tSe encuentra dentro del arbol";
                    else
                       cout << "\n\tNo se encuentra dentro del arbol";
                       system("pause");
                    break;
                          

               case 3:
                      cout<< " Orden     ";
                            cout<<"\n";
                            enOrden(arbol);      
                            cout << "\n\nPreOrden  "; 
                                cout<<"\n";
                            preOrden(arbol); 
                            cout << " \n\nPostOrden   "; 
                                cout<<"\n";
                            postOrden(arbol);
                             system("pause");    
                     
                    
                    break;        
               case 4:
                   cout << " \n\nRecorrido por anchura";	
                                 cout<<"\n";
                                 imprimirarbol_anchura(arbol,0);
                             system("pause");    
                     break;    
                    
               case 5:
                    
                    enOrden(arbol); 
                    cout<<"\nNumero a eliminar: "; 
                    cin>> x;
                    eliminar(arbol, x);
                    cout << "\nEliminado \n";
                    enOrden(arbol); 
                    system("pause");   
                    break;
                    
               case 6:
                    exit(0);
                    break;     
          }

          cout<<"\n\n\n";
          
    }while(op!=11);

}
