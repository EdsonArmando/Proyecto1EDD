#include "pch.h"
#include <iostream>
#include <string>
#include "NodoArbol.cpp"
#include "MatrizDispersa.cpp"
#include "NodoLateral.cpp"
using namespace std;
#pragma once
static NodoArbol *raiz;

class ArbolBinarioBusqueda {
public:
	NodoLateral *no;
	NodoCabecera *noCa;
	void insertarNodo(NodoArbol *&raiz,int n) {
		if (raiz==NULL) {
			NodoArbol *nuevo = new NodoArbol(n);
			//nuevo->matrix = matrix;
			nuevo->izq = NULL;
			nuevo->dere = NULL;
			/*no = matrix->listlat->buscarNodo(0);
			string dato = no->fila->primero->color;
			cout << dato << endl;
			noCa = matrix->listaCab->buscarNodo(1);
			string datos = noCa->colum->primero->abajo->color;
			cout << datos << endl;*/
			raiz = nuevo;
		}else{
			int valRaiz = raiz->valor;
			if (n<valRaiz) {
				insertarNodo(raiz->izq,n);
			}
			else {
				insertarNodo(raiz->dere,n);
			}
		}
	}
	void mostrarArbol(NodoArbol *raiz,int cont) {
		NodoArbol *temp=raiz;
		if (raiz==NULL) {
			return;
		}
		else {
			mostrarArbol(raiz->dere,cont+1);
			for (int i = 0; i < cont; i++)
			{
				cout << "  ";
			}
			cout << raiz->valor << endl;
			mostrarArbol(raiz->izq,cont+1);
		}
	}
	bool esVacio() {
		return (raiz == NULL);
	}
	NodoArbol *mostrarArbole(NodoArbol *raiz,int n) {
		if (raiz==NULL) {
		
		}
		else if (raiz->valor==n) {
			return raiz;
		}
		else if (n<raiz->valor) {
			return mostrarArbole(raiz->izq,n);
		}
		else {
			return mostrarArbole(raiz->dere, n);
		}
		
	}
};