#include "pch.h"
#include <iostream>
#include <string>
#include "ListaCapas.cpp"
#pragma once
using namespace std;
class NodoCabecera_Imagen {
public:
	string nombreImagen;
	NodoCabecera_Imagen *siguiente;
	NodoCabecera_Imagen *anterior;
	ListaCapas *lista;
	NodoCabecera_Imagen(string nombre) {
		this->nombreImagen = nombre;
		siguiente = NULL;
		anterior = NULL;
		lista = new ListaCapas();
	}

};