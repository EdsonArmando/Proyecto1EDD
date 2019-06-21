#include "pch.h"
#include <iostream>
#include <string>
#include "ListaVertical.cpp"
#pragma once
using namespace std;
/*Nodos Cab*/
class NodoCabecera {
public:
	int x;
	NodoCabecera *siguiente;
	NodoCabecera *anterior;
	ListaVertical *colum;
	NodoCabecera(int x) {
		this->x = x;
		colum = new ListaVertical();
		siguiente = NULL;
		anterior = NULL;
	}
};