#include "pch.h"
#include <iostream>
#include <string>
#include "ListaImagenesUsuariocpp.cpp"
#pragma once
using namespace std;
class NodoAvl {
public:
	ListaImagenesUsuario *list;
	string nombreUsuar;
	NodoAvl *izquierda;
	NodoAvl *derecha;
	int altura;
	NodoAvl(string nombre) {
		this->nombreUsuar = nombre;
		list = new ListaImagenesUsuario();
		izquierda = NULL;
		derecha = NULL;
		altura = 0;
	}

};