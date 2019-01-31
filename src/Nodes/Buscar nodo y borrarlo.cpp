#include <stdio.h>
#include <iostream>
#include <conio.h>
#include<stdlib.h>

struct nodo{
       int dato;
       nodo *siguiente;
       };

nodo * CreaeNodo(int x);
nodo * insertar(int x,nodo* cabeza);
void  imprimir(nodo *cabeza);
nodo* borrar(nodo* cabeza,int x);

using namespace std;

int main(){
    system ("color f0");
    nodo * cabeza;
    cabeza=NULL;
    cabeza=insertar(5 ,cabeza);
    cabeza=insertar(20,cabeza);
    cabeza=insertar(1 ,cabeza);
    cabeza=insertar(30,cabeza);
    cout<<"La lista es: "<<endl;
    imprimir(cabeza);
    int x = 0;
	cout<<"Ingresa el numero del nodo a borrar "<<endl;
    cin>>x;
    cout<<endl;    
    cabeza=borrar(cabeza,x);
    cout<<"La lista es: "<<endl;  
    imprimir(cabeza);
    system("pause");
    }
    
nodo * CrearNodo(int x){
     nodo *n;
     n=(nodo*)malloc(sizeof(nodo));
     n->dato=x;
     n->siguiente=NULL;
     return n;
     }
     
nodo* insertar(int x, nodo* cabeza){
      nodo * nuevo;
      nuevo = CrearNodo(x);
     if(cabeza==NULL)
     return nuevo;
     else{
      nuevo->siguiente = cabeza;      
     cabeza=nuevo;
     return cabeza;     
      }
      }

nodo* borrar(nodo* cabeza,int x){
     nodo* cabeza2; //creamos nodo cabeza 2
     cabeza2 = cabeza;     //guardamos cabeza recibida
     int b = 0;      
     while(cabeza->siguiente!=NULL){
     nodo* aux1;      //creamos auxiliares
     nodo* aux2;
           aux1 = cabeza;        //guardamos nodo cabeza en aux 1
           aux2 = cabeza->siguiente; //guardamos siguiente de cabeza en nodo aux 2
         if(cabeza->dato==x){    //si el dato ingresado esta en el final de la lista
             cabeza=cabeza->siguiente;  //colocamos siguiente en cabeza
             free(aux1);               
             return cabeza;
             b=1;
             break;
         }
         else if(aux2->dato==x){ //si el dato es intermedio	
               cabeza->siguiente=aux2->siguiente;  //guardamos cabeza para no perderla
               free(aux2);
               return cabeza2;
               break;
               b=1;
         }   
               cabeza = cabeza->siguiente;                   
     }
     if(b!=1){
     cout<<"dato no encontrado \n";
     return cabeza2;}
     
     }

void imprimir(nodo *cabeza){
        while (cabeza!=NULL){
          
          cout<<cabeza->dato<<endl;
          cabeza=cabeza->siguiente;
        }
      }
