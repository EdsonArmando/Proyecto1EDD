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
	void insertarNodo(NodoArbol *&raiz,int n,MatrizDispersa *matrix) {
		if (raiz==NULL) {
			NodoArbol *nuevo = new NodoArbol();
			nuevo->valor = n;
			nuevo->matrix = matrix;
			//nuevo->matrix = matrix;
			nuevo->izq = NULL;
			nuevo->dere = NULL;
			no = matrix->listlat->buscarNodo(0);
			string dato = no->fila->primero->color;
			cout << dato << endl;
			noCa = matrix->listaCab->buscarNodo(1);
			string datos = noCa->colum->primero->abajo->color;
			cout << datos << endl;
			raiz = nuevo;
		}else{
			int valRaiz = raiz->valor;
			if (n<valRaiz) {
				insertarNodo(raiz->izq,n,matrix);
			}
			else {
				insertarNodo(raiz->dere,n,matrix);
			}
		}
	}
	void mostrarArbol(NodoArbol *raiz,int cont) {
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
};