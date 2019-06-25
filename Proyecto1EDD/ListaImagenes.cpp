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
	void imagenArbol(string nombre,string abb) {
		string img = "subgraph cluster_1 {\n label=\"Imagen\";\n  ";
		string lis;
		string rela;
		ofstream file;
		NodoCabecera_Imagen *temp = ultimo;
		NodoCapa *inicio = NULL;
		do {
			if (temp->nombreImagen==nombre) {
				inicio = temp->lista->ultimo;
				lis = lis+temp->nombreImagen + " [shape=record]\n";
				lis = lis + temp->nombreImagen + "->" + "capa" + std::to_string(inicio->idCapa) + "\n";
				while (inicio != NULL)
				{
					lis = lis  +"capa" + std::to_string(inicio->idCapa)+" [shape=circle]\n";
					if (inicio->siguiente != NULL) {
						lis = lis + "capa" + std::to_string(inicio->idCapa) + "->" + "capa" + std::to_string(inicio->siguiente->idCapa) + "\n";
						rela = rela +"capa" + std::to_string(inicio->idCapa) +"->" + "nodo"+ std::to_string(inicio->idCapa)+"\n";
					}
					if (inicio->siguiente == NULL) {
						rela = rela + "capa" + std::to_string(inicio->idCapa) + "->" + "nodo" + std::to_string(inicio->idCapa) + "\n";
					}
					inicio = inicio->siguiente;
				}

			}
			temp = temp->siguiente;

		} while (temp != ultimo);
		abb.erase(abb.length()-1);
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/ImagenYArbol.dot");
		file << abb+"\n}"+img + lis + rela+ "\n}\n}";
		file.close();
		system("dot -Tpng ImagenYArbol.dot -o ImagenYaRBOL.png");
		system("ImagenYaRBOL.png");
	}
	void recorrerLista() {
		listaIma = "";
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
	string listaCapas(string imagen) {
		string capas;
		NodoCabecera_Imagen *temp = ultimo;
		NodoCapa *inicio = NULL;
		do {
			inicio = temp->lista->ultimo;
			if (temp->nombreImagen==imagen) {
				while (inicio != NULL)
				{
					
						capas = capas + std::to_string(inicio->idCapa)+",";
						inicio = inicio->siguiente;
				}
			}
			temp = temp->siguiente;

		} while (temp != ultimo);
		return capas;
	}
	int noCapas(string imagen) {
		int capas=0;
		NodoCabecera_Imagen *temp = ultimo;
		NodoCapa *inicio = NULL;
		do {
			inicio = temp->lista->ultimo;
			if (temp->nombreImagen == imagen) {
				while (inicio != NULL)
				{
					
						capas++;
					
					inicio = inicio->siguiente;
				}
			}
			temp = temp->siguiente;

		} while (temp != ultimo);
		return capas;
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