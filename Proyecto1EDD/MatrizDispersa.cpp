#include "pch.h"
#include <iostream>
#include <string>
#include "DatoMatriz.cpp"
#include "ListaVertical.cpp"
#include "ListaHorizontal.cpp"
#include "Cabecera.cpp"
#include "ListaLate.cpp"
#include "NodoCabecera.cpp"
#include "NodoContenido.cpp"
#pragma once
class MatrizDispersa {
public:
	Cabecera *listaCab;
	listaLate *listlat;
	MatrizDispersa() {
		listaCab = new Cabecera();
		listlat = new listaLate();
	}
	
	void llenado_Matriz(int x, int y,string color) {
		string c=color;
		for (int i = 0; i < y;i++) {
			for (int j = 0; j < x;j++) {
				insertar(j,i,c);
			}
		}
	}
	void insertar(int x, int y, string color) {
		NodoContenido *nuevo = new NodoContenido(color,x,y);
		if (listaCab->buscar(x)==false) {
			listaCab->insertar(new NodoCabecera(x));
		}
		if (listlat->buscar(y)==false) {
			listlat->insertar(new NodoLateral(y));
		}
		NodoCabecera *temp1;
		NodoLateral *temp2;
		temp1 = listaCab->buscarNodo(x);
		temp2 = listlat->buscarNodo(y);
		temp1->colum->insertar(nuevo);
		temp2->fila->insertar(nuevo);
		//cout << "Inserto" << color << "en" << x << " ," << y << endl;
		/*Se inserto el nodo*/
	}
};