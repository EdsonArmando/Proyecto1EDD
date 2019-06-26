#include "pch.h"
#include <iostream>
#include <string>
#include "NodoContenido.cpp"
#pragma once
using namespace std;
class ListaVertical {
public:
	NodoContenido *primero;
	NodoContenido *ultimo;
	ListaVertical() {
		primero = NULL;
		ultimo = NULL;
	}
	bool esVacia() {
		if (primero==NULL) {
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
			if (nuevo->y<primero->y) {
				insertarAlInicio(nuevo);
			}
			else if (nuevo->y>ultimo->y) {
				insertarAlFinal(nuevo);
			}
			else {
				insertarMedio(nuevo);
			}
		}
	}
	void insertarAlInicio(NodoContenido *nuevo) {
		primero->arriba = nuevo;
		nuevo->abajo = primero;
		primero = primero->arriba;
	}
	void insertarAlFinal(NodoContenido *nuevo) {
		ultimo->abajo = nuevo;
		nuevo->arriba = ultimo;
		ultimo = ultimo->abajo;
	}
	void insertarMedio(NodoContenido *nuevo) {
		NodoContenido *temp1;
		NodoContenido *temp2;
		temp1 = primero;
		while (temp1->y<nuevo->y)
		{

			temp1 = temp1->abajo;
		}
		temp2 = temp1->arriba;
		temp2->abajo = nuevo;
		temp1->arriba = nuevo;
		nuevo->abajo = temp1;
		nuevo->arriba = temp2;
	}
	void mostrarDatos() {
		if (!esVacia()) {
			NodoContenido *temp = primero;
			while (temp != NULL)
			{
				
				temp = temp->abajo;
			}
		}
		
	}
};