#include "pch.h"
#include <iostream>
#include "ArbolBinarioBusqueda.cpp"
#include "Menu.cpp"
#include "DatoMatriz.cpp"
#include "ListaVertical.cpp"
#include "ListaHorizontal.cpp"
#include "NodoCabecera.cpp"
#include "NodoContenido.cpp"
#include "Cabecera.cpp"
#include "ListaLate.cpp"
#include "NodoLateral.cpp"
#include "MatrizDispersa.cpp"
#include "ListaCapas.cpp"
#include "ListaImagenes.cpp"
#include "NodoCabecera_Imagen.cpp"
#include "ListaIm.cpp"
#pragma once
using namespace std;
int main()
{
	Menu menu;
	ListaIm *lista = new ListaIm();
	NodoCabecera_Imagen *no;
	//ArbolBinarioBusqueda ar;
	/*NodoLateral *no;
	
	cout << dato << endl;
	/*;*/
	/*NodoLateral *no;
	MatrizDispersa *matrix = new MatrizDispersa();
	matrix->llenado_Matriz(3, 3, "#ss5#");
	no = matrix->listlat->buscarNodo(0);
	string dato = no->fila->primero->abajo->derech->color;
	cout << dato <<endl ;*/
	lista->insertar("Imagen1", 1);
	lista->insertar("Imagen2", 2);
	lista->insertar("Imagen1", 3);
	no = lista->cabeceraIm->retNodo("Imagen2");
	no->lista->recorrerLista();
	menu.iniciarMenu();

}
