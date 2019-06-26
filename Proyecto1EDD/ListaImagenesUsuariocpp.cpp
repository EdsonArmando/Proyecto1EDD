#include "pch.h"
#include <iostream>
#include <string>
#include "NodoImagenUsuario.cpp"
#pragma once
using namespace std;
class ListaImagenesUsuario {
public:
	NodoImagenUsuario *primero;
	ListaImagenesUsuario() {
		primero = NULL;
	}
	void insertar(string nombre) {
		NodoImagenUsuario *nuevo = new NodoImagenUsuario(nombre);
		if (primero==NULL) {
			primero = nuevo;
		}
		else {
			nuevo->siguiente = primero;
			primero = nuevo;
			
		}
	}
	void recorrerLista() {
		NodoImagenUsuario* temp=primero;
		while (temp!=NULL)
		{
			cout << temp->nombreImagen << endl;
			temp = temp->siguiente;
		}
	}
	bool verificarImagen(string nombre) {
		NodoImagenUsuario* temp = primero;
		if (primero==NULL) {
			return false;
		}
		while (temp != NULL)
		{
			if (temp->nombreImagen==nombre) {
				return true;
			}
			cout << temp->nombreImagen << endl;
			temp = temp->siguiente;
		}
		return false;
	}
};
