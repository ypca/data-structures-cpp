#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct nodo{     
       bool b[8];
       nodo* der;
       nodo* izq;
       };
int enBinario(nodo* n);       
void imprimirnodo(nodo* n);
void imprimirarbol2(nodo* cabeza);
void imprimirarbol(nodo* cabeza);
nodo* crearnodo(int n);
void recuperar2(nodo* cabeza);
void recuperar(nodo* cabeza);

int main(){
    system("color f0");
    cout<<" PALABRA A CONVERTIR: ";

    char x;
    cin>>x;
    int n=x;
    nodo* arbol=crearnodo(n);
    cin>>x; 
    n=x;
    arbol->izq = crearnodo(n);   
    cin>>x; 
    n=x;
    arbol->der = crearnodo(n);   
    cin>>x; 
    n=x;
    arbol->izq->izq = crearnodo(n);  
    
   cout<<"\n\n EN BINARIO; ";        
   imprimirarbol(arbol);
   cout<<endl<<endl;
   system("color f2");
   
   cout<<"\n\n RECUPERAR BINARIO; ";
   recuperar(arbol);
   cout<<endl<<endl;
        
 system("pause");
 return 0;   
}

nodo* crearnodo(int n){
      
      nodo* aux = (nodo*)malloc(sizeof(nodo));
      for(int x=0;x<8;x++) aux->b[x] = 0;
      int x=0;
      while(n>=1){
        if(n%2 != 0)aux->b[7-x]=1;
        n=n/2;     
        x++;
      }
      
      aux->der=NULL;
      aux->izq=NULL;
      return aux;
      
      }

int enBianrio(nodo* n){

 int c=0;
  int num;
 
 for(int x=7;x>=0;x--){
 
  if( n->b[x] ) num=1;
  else num=0;
  c = c+num*(int)pow(2,7-x); 
         }   
  return c;
    
}

void imprimirnodo(nodo* n){
     
     for(int x=0;x<8;x++)
     cout<<n->b[x];
     cout<<" ";
          }
     
     void imprimirarbol(nodo* cabeza){
     
     if(cabeza!=NULL){if(enBianrio(cabeza)!=0)
     imprimirnodo(cabeza);}
     
     if(cabeza->izq != NULL) 
     imprimirnodo(cabeza->izq);   
     
     if(cabeza->der != NULL) 
     imprimirnodo(cabeza->der);
     
     imprimirarbol2(cabeza->izq);
     
     imprimirarbol2(cabeza->der);
     
     }
  
     
void imprimirarbol2(nodo* cabeza){
     
     if(cabeza!=NULL){
          if(cabeza->izq != NULL)
          imprimirnodo(cabeza->izq);   
          
          if(cabeza->der != NULL) 
          imprimirnodo(cabeza->der);               
     }
     
     }


void recuperar2(nodo* cabeza){
     
     if(cabeza!=NULL){
          if(cabeza->izq != NULL) 
          cout<<(char)enBianrio(cabeza->izq);   
          
          if(cabeza->der != NULL) 
          cout<<(char)enBianrio(cabeza->der);               
     }
     }

void recuperar(nodo* cabeza){
     if(cabeza!=NULL){
                      if(enBianrio(cabeza)!=0)
                      cout<<(char)enBianrio(cabeza);
                      }
                      
     if(cabeza->izq != NULL) 
     
     cout<<(char)enBianrio(cabeza->izq);   
     
     if(cabeza->der != NULL) cout<<(char)
     
     enBianrio(cabeza->der);
     
     recuperar2(cabeza->izq);
     
     recuperar2(cabeza->der);
     }
