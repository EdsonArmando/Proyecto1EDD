#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "NodoAVL.cpp"
#include "NodoImagenUsuario.cpp"
#pragma once
using namespace std;
static NodoAvl *primer;
class ArbolAVL {
public:
	string inicio = "digraph grafica{\nrankdir=TB;\n label=\"Arbol AVL Usuarios\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
	string nodes;
	string rela;
	string relaIm;
	void insertar(string nombre) {
		insertarNodo(nombre, primer);
	}
	int alt(NodoAvl *N)
	{
		if (N == NULL)
			return 0;
		return N->altura;
	}
	void mostrarArbol() {
		ofstream file;
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/ArbAvl.dot");
		file << inicio + nodes + rela + relaIm+ "\n}";
		file.close();
		system("dot -Tpng ArbAvl.dot -o graf5.png");
		system("graf5.png");
		nodes = "";
		rela = "";
		relaIm = "";
	}
	void graficarAVL(NodoAvl *raiz) {
		NodoAvl *temp = raiz;
		if (raiz != NULL) {
			nodes = nodes + "nodo" + raiz->nombreUsuar + " " + "[ label = \"<C0>|" + raiz->nombreUsuar+ "|<C1>\"" + "];\n";
			if (raiz->izquierda != NULL) {
				rela = rela + "nodo" + raiz->nombreUsuar + ":C0->" + "nodo" + raiz->izquierda->nombreUsuar + "\n";
			}
			if (raiz->derecha != NULL) {
				rela = rela + "nodo" + raiz->nombreUsuar + ":C1->" + "nodo" + raiz->derecha->nombreUsuar + "\n";
			}
			graficarAVL(raiz->izquierda);
			graficarAVL(raiz->derecha);
		}
	}
	void graficarAVLeImagenes(NodoAvl *raiz) {
		NodoImagenUsuario *temp2 = NULL;
		NodoAvl *temp = raiz;
		if (raiz != NULL) {
			temp2 = temp->list->primero;
			nodes = nodes + "nodo" + raiz->nombreUsuar + " " + "[ label = \"<C0>|" + raiz->nombreUsuar + "|<C1>\"" + "];\n";
			if (temp2!=NULL) {
				relaIm = relaIm + "\n" + raiz->nombreUsuar + "->" + temp2->nombreImagen;
			}
			
			while (temp2!=NULL)
			{
				if (temp2->siguiente!=NULL) {
					relaIm = relaIm + "\n" + temp2->nombreImagen + "->" + temp2->siguiente->nombreImagen;
				}
				temp2 = temp2->siguiente;
			}
			if (raiz->izquierda != NULL) {
				rela = rela + "nodo" + raiz->nombreUsuar + ":C0->" + "nodo" + raiz->izquierda->nombreUsuar + "\n";
			}
			if (raiz->derecha != NULL) {
				rela = rela + "nodo" + raiz->nombreUsuar + ":C1->" + "nodo" + raiz->derecha->nombreUsuar + "\n";
			}
			graficarAVLeImagenes(raiz->izquierda);
			graficarAVLeImagenes(raiz->derecha);
		}
	}
	NodoAvl * rotacionSimpleIzquierda(NodoAvl *nodo) {
		NodoAvl *temp;
		temp = nodo->izquierda;
		nodo->izquierda = temp->derecha;
		temp->derecha = nodo;
		
		nodo->altura = maxValor(alt(nodo->izquierda), alt(nodo->derecha))+1;
		temp->altura = maxValor(alt(temp->izquierda), nodo->altura) + 1;
		return temp;
	}
	int maxValor(int valorUno, int Valor2) {
		if (valorUno>Valor2) {
			return valorUno;
		}
		else if (Valor2>valorUno) {
			return Valor2;
		}
	}
	void insertarNodo(string nombre,NodoAvl* &rai) {
		if (rai==NULL) {
			rai = new NodoAvl(nombre);
		}
		else if(nombre<rai->nombreUsuar) {
			insertarNodo(nombre,rai->izquierda);
			if ((alt(rai->izquierda)-alt(rai->derecha))==2) {
				if (nombre<rai->izquierda->nombreUsuar) {
					rai = rotacionSimpleIzquierda(rai);
				}
				else {
					rai = dobleIzquiere(rai);
				}
			}
		}
		else if (nombre > rai->nombreUsuar) {
			insertarNodo(nombre, rai->derecha);
			if ((alt(rai->derecha) - alt(rai->izquierda)) == 2) {
				if (nombre < rai->derecha->nombreUsuar) {
					rai = rotaSimpleDerecha(rai);
				}
				else {
					rai = dobleDerecha(rai);
				}
			}
		}
		int d, i, m;
		d = alt(rai->derecha);
		i = alt(rai->izquierda);
		m = maxValor(d,i);
		rai->altura = m + 1;
	}
	NodoAvl *rotaSimpleDerecha(NodoAvl *nodo) {
		NodoAvl *temp;
		temp = nodo->derecha;
		nodo->derecha = temp->izquierda;
		temp->izquierda = nodo;

		nodo->altura = maxValor(alt(nodo->izquierda), alt(nodo->derecha)) + 1;
		temp->altura = maxValor(alt(temp->derecha), nodo->altura) + 1;
		return temp;
	}
	NodoAvl *dobleIzquiere(NodoAvl *nodo) {
		nodo->izquierda = rotaSimpleDerecha(nodo->izquierda);
		return rotacionSimpleIzquierda(nodo);
	}
	NodoAvl * dobleDerecha(NodoAvl *nodo) {
		nodo->derecha = rotacionSimpleIzquierda(nodo->derecha);
		return rotaSimpleDerecha(nodo);
	}

	NodoAvl * devNodo(NodoAvl *raiz, string n) {
		if (raiz == NULL) {

		}
		else if (raiz->nombreUsuar == n) {
			return raiz;
		}
		else if (n < raiz->nombreUsuar) {
			return devNodo(raiz->izquierda, n);
		}
		else {
			return devNodo(raiz->derecha, n);
		}
	}
};