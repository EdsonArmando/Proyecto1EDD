#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "ListaVertical.cpp"
#include "NodoCabecera_Imagen.cpp"
#pragma once
class ListaImagenes {
public:
	NodoCabecera_Imagen *primero;
	NodoCabecera_Imagen *ultimo;
	string graph = "digraph Sparce_Matrix {\n node [shape=box] \n e0[ shape = point, width = 0 ];\n  e1[ shape = point, width = 0 ];\n";
	string listaIma;
	string rank="{rank = same;";
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
	void imagenListaImagenes() {
		ofstream file;
		NodoCabecera_Imagen *temp = ultimo;
		NodoCapa *inicio=NULL;
		do {
			inicio = temp->lista->ultimo;
			listaIma = listaIma + temp->nombreImagen + "->" + "capa" + std::to_string(inicio->idCapa) + "\n";
			while (inicio!=NULL)
			{
				listaIma = listaIma + "capa"+std::to_string(inicio->idCapa) + "[label = \"capa"+std::to_string(inicio->idCapa)+"\"width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n";
				if (inicio->siguiente!=NULL) {
					listaIma = listaIma + "capa" + std::to_string(inicio->idCapa) + "->" + "capa" + std::to_string(inicio->siguiente->idCapa) + "\n";
				}
				inicio = inicio->siguiente;
			}
			
			temp = temp->siguiente;

		} while (temp != ultimo);
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/ListaImagenes.dot");
		file << graph + listaIma + rank + "\n}";
		file.close();
		system("dot -Tpng ListaImagenes.dot -o graf2.png");
		system("graf2.png");

	}
	void recorrerLista() {
		NodoCabecera_Imagen *temp=ultimo;
		do {
			listaIma = listaIma+temp->nombreImagen + "[label = \"" + temp->nombreImagen + "\" width = 1.5 style = filled, fillcolor = lightskyblue, group = 2 ];";
			listaIma += temp->nombreImagen + "->" + temp->siguiente->nombreImagen + "\n";
			listaIma += temp->siguiente->nombreImagen + "->" + temp->nombreImagen + "\n";
			rank = rank + temp->nombreImagen + "; ";

			temp = temp->siguiente;
		} while (temp!= ultimo);
		rank = rank + "}";
		imagenListaImagenes();
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