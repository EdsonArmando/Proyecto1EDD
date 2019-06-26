#include "pch.h"
#include <iostream>
#include <string>
#include "ListaHorizontal.cpp"
#include <fstream>
#include "NodoLateral.cpp"
#pragma once
using namespace std;
class listaLate {
public:
	NodoLateral *primero;
	NodoLateral *ultimo;
	listaLate() {
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
	void insertar(NodoLateral *nuevo) {
		if (esVacia()) {
			primero = ultimo = nuevo;
		}
		else {
			if (nuevo->y < primero->y) {
				insertarAlInicio(nuevo);
			}
			else if (nuevo->y > ultimo->y) {
				insertarAlFinal(nuevo);
			}
			else {
				insertarMedio(nuevo);
			}
		}
	}
	void insertarAlInicio(NodoLateral *nuevo) {
		primero->anterior = nuevo;
		nuevo->siguiente = primero;
		primero = primero->anterior;
	}
	void insertarAlFinal(NodoLateral *nuevo) {
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;
		ultimo = ultimo->siguiente;
	}
	void insertarMedio(NodoLateral *nuevo) {
		NodoLateral *temp1;
		NodoLateral *temp2;
		temp1 = primero;
		while (temp1->y < nuevo->y)
		{

			temp1 = temp1->siguiente;
		}
		temp2 = temp1->anterior;
		temp2->siguiente = nuevo;
		temp1->anterior = nuevo;
		nuevo->siguiente = temp1;
		nuevo->anterior = temp2;
	}
	void mostrarDatos() {
		if (!esVacia()) {
			NodoLateral *temp = primero;
			while (temp != NULL)
			{
				
				temp = temp->siguiente;
			}
		}

	}
	vector<int> retListaFila() {
		vector<int> y;
		if (!esVacia()) {
			NodoLateral *temp = primero;
			while (temp != NULL)
			{
				y.push_back(temp->y);
				
				temp = temp->siguiente;
			}
			return y;
		}
		
	}
	
	bool buscar(int y) {
		if (esVacia()) {
			
			return false;
		}
		else {
			NodoLateral *temp = primero;
			while (temp != NULL)
			{
				if (temp->y == y) {
					
					return true;
				}
				else if (temp->siguiente == NULL) {
				
					return false;
				}
				temp = temp->siguiente;
			}
		}
	}
	NodoLateral* buscarNodo(int y) {
		NodoLateral *temp = primero;
		while (temp != NULL)
		{
			if (temp->y == y) {
				return temp;
			}
			else {

			}
			temp = temp->siguiente;
		}
		
		return (new NodoLateral(-1));
	}
};