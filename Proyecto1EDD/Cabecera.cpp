#include "pch.h"
#include <iostream>
#include <string>
#include "ListaVertical.cpp"
#include "NodoCabecera.cpp"
#pragma once
class Cabecera {
public:
	NodoCabecera *primero;
	NodoCabecera *ultimo;
	Cabecera() {
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
	void insertar(NodoCabecera *nuevo) {
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
	void insertarAlInicio(NodoCabecera *nuevo) {
		primero->anterior = nuevo;
		nuevo->siguiente = primero;
		primero = primero->anterior;
	}
	void insertarAlFinal(NodoCabecera *nuevo) {
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;
		ultimo = ultimo->siguiente;
	}
	void insertarMedio(NodoCabecera *nuevo) {
		NodoCabecera *temp1;
		NodoCabecera *temp2;
		temp1 = primero;
		while (temp1->x < nuevo->x)
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
			NodoCabecera *temp = primero;
			while (temp != NULL)
			{
				cout << "x" << temp->x << endl;
				temp = temp->siguiente;
			}
		}

	}
	bool buscar(int x) {
		if (esVacia()) {
			cout << "No Existe" << endl;
			return false;
		}
		else {
			NodoCabecera *temp=primero;
			while (temp!=NULL)
			{
				if (temp->x==x) {
					cout << "Existe" << endl;
					return true;
				}
				else if (temp->siguiente==NULL) {
					cout << "No se encontro" << endl;
					return false;
				}
				temp = temp->siguiente;
			}
		}
	}
	NodoCabecera* buscarNodo(int x) {
		NodoCabecera *temp=primero;
		while (temp!=NULL)
		{
			if (temp->x==x) {
				return temp;
			}
			else {
				
			}
			temp = temp->siguiente;
		}
		cout << "No se encontro" << endl;
		return (new NodoCabecera(-1));
	}
};