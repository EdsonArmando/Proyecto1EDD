#include "pch.h"
#include <iostream>
#include <string>
#include "NodoContenido.cpp"
#pragma once
using namespace std;
class ListaHorizontal {
public:
	NodoContenido *primero;
	NodoContenido *ultimo;
	ListaHorizontal() {
		primero = NULL;
		ultimo = NULL;
	}
	bool esVacia() {
		if (primero == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void insertar(NodoContenido *nuevo) {
		if (esVacia()) {
			primero = ultimo = nuevo;
		}
		else {
			if (nuevo->x < primero->x) {
				insertarAlInicio(nuevo);
			}
			else if (nuevo->x > ultimo->x) {
				insertarAlFinal(nuevo);
			}
			else {
				insertarMedio(nuevo);
			}
		}
	}
	void insertarAlInicio(NodoContenido *nuevo) {
		primero->izqui = nuevo;
		nuevo->derech = primero;
		primero = primero->izqui;
	}
	void insertarAlFinal(NodoContenido *nuevo) {
		ultimo->derech = nuevo;
		nuevo->izqui = ultimo;
		ultimo = ultimo->derech;
	}
	void insertarMedio(NodoContenido *nuevo) {
		NodoContenido *temp1;
		NodoContenido *temp2;
		temp1 = primero;
		while (temp1->x < nuevo->x)
		{

			temp1 = temp1->derech;
		}
		temp2 = temp1->izqui;
		temp2->derech = nuevo;
		temp1->izqui = nuevo;
		nuevo->derech = temp1;
		nuevo->izqui = temp2;
	}
	void mostrarDatos() {
		if (!esVacia()) {
			NodoContenido *temp = primero;
			while (temp != NULL)
			{
				cout << "x" << temp->x << endl;
				temp = temp->derech;
			}
		}

	}

};