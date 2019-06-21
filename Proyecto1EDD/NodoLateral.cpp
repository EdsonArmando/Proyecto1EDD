#include "pch.h"
#include <iostream>
#include <string>
#include "ListaHorizontal.cpp"
#pragma once
using namespace std;
class NodoLateral {
public:
	int y;
	NodoLateral *siguiente;
	NodoLateral *anterior;
	ListaHorizontal *fila;
	NodoLateral(int y) {
		this->y = y;
		fila = new ListaHorizontal();
		siguiente = NULL;
		anterior = NULL;
	}
};