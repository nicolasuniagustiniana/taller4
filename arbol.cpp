#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;  

struct Nodo{
 int dato;
 Nodo *Derecha;
 Nodo *Izquierda;
};
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);
Nodo *arbol=NULL;

int main(){
	
	
	
	menu();
	getch();
	return 0;
}

void menu(){
 int dato,opcion,contador=0;
 
 do{
  cout<<"\t.:MENU:."<<endl;;
  cout<<"1.Insertar un nuevo nodo."<<endl;;
  cout<<"2.Mostrar Arbol."<<endl;;
  cout<<"3.Salir"<<endl;;
  cout<<"Opcion: ";
  cin>>opcion;
  
  switch (opcion){
   case 1: cout<<"\nDigite un numero: ";
     cin>>dato;
     insertarNodo(arbol,dato);
     cout<<"\n";
     system("pause");
     break;
   case 2: cout<<"\nMostrando El Arbol:\n\n";
   mostrarArbol(arbol,contador);
   cout<<"\n";
   system("pause");
   break;
  }
  system("cls");
 }while(opcion!=3);
}

Nodo *crearNodo(int n){
	Nodo *nuevo_Nodo=new Nodo();
	
	nuevo_Nodo->dato=n;
	nuevo_Nodo->Derecha=NULL;
	nuevo_Nodo->Izquierda=NULL;
	
	return nuevo_Nodo;
	
}

void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){
		Nodo *nuevo_Nodo=crearNodo(n);
		arbol=nuevo_Nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->Izquierda,n);
		}
		else{
			insertarNodo(arbol->Derecha,n);
		}
	}
}
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol== NULL){
		return;
	}else{
		mostrarArbol(arbol->Derecha,cont+1);
		for (int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->Izquierda,cont+1);
	}
}



