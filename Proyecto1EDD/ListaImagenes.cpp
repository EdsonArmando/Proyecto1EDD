#include "pch.h"
#include <iostream>
#include <string>
#include "ListaVertical.cpp"
#include "NodoCabecera_Imagen.cpp"
#pragma once
class ListaImagenes {
public:
	NodoCabecera_Imagen *primero;
	NodoCabecera_Imagen *ultimo;
	ListaImagenes() {
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
	void insertarImg(NodoCabecera_Imagen *nuevo) {
		if (esVacia()) {
			primero = nuevo;
			primero->siguiente = primero;
			primero->anterior = primero;
			ultimo = nuevo;
		}
		else {
			primero->siguiente = nuevo;
			nuevo->anterior = primero;
			nuevo->siguiente = ultimo;
			ultimo->anterior = nuevo;
			primero = nuevo;
		}

	}
	void recorrerLista() {
		NodoCabecera_Imagen *temp=ultimo;
		do {
			cout << temp->nombreImagen << endl;
			temp = temp->siguiente;
		} while (temp!= ultimo);
		
	}
	bool buscar(string nombre) {
		if (esVacia()==true) {
			return false;
		}
		else {
			NodoCabecera_Imagen *temp = ultimo;
			do {
				if (temp->nombreImagen == nombre) {
					return true;
				}
				temp = temp->siguiente;
			} while (temp != ultimo);
			return false;
		}
		
	}
	NodoCabecera_Imagen* retNodo(string name) {
		NodoCabecera_Imagen *temp = ultimo;
		do {
			if (temp->nombreImagen == name) {
				return temp;
			}
			temp = temp->siguiente;
		} while (temp != ultimo);
	}
};