#include "pch.h"
#include <iostream>
#include <string>
#include "NodoCapa.cpp"
#pragma once
class ListaCapas {
public:
	NodoCapa *primero;
	NodoCapa *ultimo;
	ListaCapas() {
		primero = NULL;
	}
	void insertarCapa(int id) {
		NodoCapa *nuevo = new NodoCapa(id);
		if (primero==NULL) {
			primero = nuevo;
			ultimo = nuevo;
			nuevo->siguiente = NULL;
		}
		else {
			primero->siguiente = nuevo;
			primero = nuevo;
		}
	}
	void recorrerLista() {
		NodoCapa *temp = new NodoCapa(0);
		temp = ultimo;
		while (temp!=NULL)
		{
			cout << temp->idCapa << endl;
			temp = temp->siguiente;
		}

	}
};