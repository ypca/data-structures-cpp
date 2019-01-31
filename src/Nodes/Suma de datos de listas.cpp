#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

struct nodo{   
       int dato;
       nodo* sig;
       nodo* ant;
       };
       
void sumar(nodo* uno, nodo*dos);
void imprimir(nodo* n);
nodo* crear(int x);
nodo* insertar_ini(int d, nodo* n);
nodo* insertar_fin(int d, nodo* n);

using namespace std;
int main(){
    system ("color f0");
    int a=0,c=0,size=0;
    
    nodo* uno = NULL;
    nodo* dos = NULL;
    
	cout<<"TamaNo de las listas: "<<endl;
	cin>>size;
	
	system("cls");
    for(c=0;c<size;c++ ){
       cout<<"ingrese dato del nodo "<<c<<" de la 1er lista"<<endl;
       cin>>a;
       /*if(a<10 && a>=0)*/uno = insertar_fin(a,uno);
	}	
    system("cls");

     for(c=0;c<size;c++ ){
       cout<<"ingrese dato del nodo "<<c<<" de la 2da lista"<<endl;
       cin>>a;
	  /* if(a<10 && a>=0)*/dos = insertar_fin(a,dos);
    }
    system("cls");
    
    sumar(uno,dos);
    system("pause");
    return 0;
    
}


void sumar(nodo* uno, nodo*dos){
     
     nodo* aux=uno;
     int a=0;
     while(aux!=NULL){
        aux=aux->sig;
        a++;
     }
     aux=dos;
     int b=0;
     while(aux!=NULL){
        aux=aux->sig;
        b++;
     }
     
     if(a<b){
       aux=uno;
       uno=dos;
       dos=aux;        
     }
     
     nodo* aux2=dos;
     aux=uno;
     
     while(aux->sig!=NULL) aux=aux->sig;
     while(aux2->sig!=NULL) aux2=aux2->sig;
     nodo* nuevo = NULL;
     int c=0;
     int d=0;
     while(aux!=NULL){
       if(aux2 != NULL)c= aux->dato + aux2->dato +d;
       else c=aux->dato+d;
        
	    d=0;
       
       nuevo=insertar_ini(c,nuevo); 
       aux=aux->ant;
       if(aux2!=NULL)aux2=aux2->ant;       
     }
     cout<<"Lista 1: ";
     imprimir(uno);
     cout<<"Lista 2: ";
     imprimir(dos);
     cout<<"Lista de suma: ";
     imprimir(nuevo);//IMPRIMIR NUEVA LISTA
     
     }

void imprimir(nodo* n){
     nodo* aux=n;
     while(aux!=NULL){
     cout<<" "<<aux->dato;
     aux=aux->sig;               
                 
     }
     cout<<endl;
}

nodo*crear(int x){
                
  nodo* nuevo;
  nuevo = (nodo*)malloc(sizeof(nodo));
  nuevo->dato=x;
  nuevo->sig=NULL;
  nuevo->ant=NULL;
  
  return nuevo;
                
}

nodo* insertar_fin(int d, nodo* n){
      
  nodo* nuevo;
  nuevo = (nodo*)malloc(sizeof(nodo));
  nuevo=crear(d);
  nodo* aux=n;
  
  if(n==NULL){
    return nuevo;            
  }
  else{
       while(aux->sig!=NULL) aux=aux->sig;
    aux->sig = nuevo;
    nuevo->ant = aux;
  
  } 
   
      return n;
      
      }
      
nodo* insertar_ini(int d, nodo* n){
      
  nodo* nuevo;
  nuevo = (nodo*)malloc(sizeof(nodo));
  nuevo=crear(d);
  nodo* aux=n;
  
  if(n==NULL){
    return nuevo;            
  }
  else{
      nuevo->sig=n;
      n->ant=nuevo;
  
  } 
      return nuevo;
      
      }      
