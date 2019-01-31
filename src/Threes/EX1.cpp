#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void ingresargrafo();
void imprimirgrafo();
int w =0;
int n;
typedef struct nodo{
	int dato;
	struct nodo *sgte;
	}nodo;
	
	nodo *vector[20],*actual;
	
	main(){
		int opcion;
		do{
		
			system("color f0");
			cout<<"\n 1.- Ingresar nodo";
			cout<<"\n 2.- Imprimir:";
			cout<<"\n 3.- SALIR"<<endl;
			cout<<"Ingrese una opcion: "<<endl;
			cin>>opcion;
			
			
			switch(opcion){
				case 1:
						ingresargrafo();
					break;
				case 2:
						imprimirgrafo();
					break;
 
				case 3:
					opcion=0;
			}
		}while(opcion!=0);
		
		getch();
	}
	
	void ingresargrafo(){
		
		
		int i,m,j,valor, x[20],y[20];
		cout<< "Ingrese el nodo : ";
		cin>>n;
		for(i=0;i<n;i++)
		
		adyacente:{
			
			y[i]=i+1;
			if(i==n-1){
				cout<<"\n\nNodo final\n";
			}
			cout<<"Ingrese numero de vertices adyacentes a "<<i+1<<": ";
			
			cin>>m;
			if(i==n-1){
				m=0;
				cout<<"No Se Puede Poner Un Nodo Adyacente Al NodoFinal\n\n";
				getch();
			}
			if(m==0 && i!=n-1){
				cout<<"Debe a Un Nodo\n\n";
	
				getch();
				goto adyacente;
			}
			for(j=0;j<m;j++){
				inicio:cout<<"Ingrese vertice:";
				cin>>valor;
				if(valor==i+1){
					cout<<"No se ha podido apuntar al mismo nodo\n\n";
					goto inicio;
				}x[j]=valor; 
				
				if(valor==1){
					cout<<"No se ha podido apuntar al nodo de inicio\n\n";
					goto inicio;
				}
				if(valor>n||valor<1){
					cout<<"No se ha podido insertar mas nodos\n\n";
					goto inicio;
				}
				for(int h=0 ;h!=j;h++){
					if(x[h]==x[j]){
						cout<<"el arista ya existe\n\n";
						goto inicio;
					}
				}
				if(i>2){
					for(int h=i ;h>2;h--){
						for(int hh=0;hh!=j;h++){
							if(y[h]==x[hh]){
								cout<<" \n\n";
								goto inicio;
							}
						}
					}
				}
				actual = (nodo *) malloc(sizeof(nodo));
				actual->dato = valor;
				actual->sgte = vector[i];
				vector[i] = actual;
			}
		}
	
		w=n;
	}
	
void imprimirgrafo(){
	int i;
	for(i=0;i<w;i++){
		cout<<"\nAdyacente al nodo "<<i+1<<":";
		actual=vector[i];
		while(actual != NULL){
			cout<<actual->dato;
			getch();
			actual = actual->sgte;
		}
	}
}
