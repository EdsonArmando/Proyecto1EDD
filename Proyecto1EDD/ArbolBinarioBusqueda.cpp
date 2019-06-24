#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "NodoArbol.cpp"
#include "MatrizDispersa.cpp"
#include "NodoLateral.cpp"
using namespace std;
#pragma once
static NodoArbol *raiz;

class ArbolBinarioBusqueda {
private:
	string inicio = "digraph grafica{\nrankdir=TB;\n label=\"Arbol Binario de Capas\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
	string nodes;
	string rela;
public:
	NodoLateral *no;
	NodoCabecera *noCa;
	void insertarNodo(NodoArbol *&raiz,int n) {
		if (raiz==NULL) {
			NodoArbol *nuevo = new NodoArbol(n);
			//nuevo->matrix = matrix;
			nuevo->izq = NULL;
			nuevo->dere = NULL;
			/*no = matrix->listlat->buscarNodo(0);
			string dato = no->fila->primero->color;
			cout << dato << endl;
			noCa = matrix->listaCab->buscarNodo(1);
			string datos = noCa->colum->primero->abajo->color;
			cout << datos << endl;*/
			raiz = nuevo;
		}else{
			int valRaiz = raiz->valor;
			if (n<valRaiz) {
				insertarNodo(raiz->izq,n);
			}
			else {
				insertarNodo(raiz->dere,n);
			}
		}
	}
	void mostrarArbol() {
		ofstream file;
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/Arbol.dot");
		file <<inicio+nodes+rela+"\n}";
		file.close();
		system("dot -Tpng Arbol.dot -o graf2.png");
		system("graf2.png");
	}
	void graficarArbol(NodoArbol *raiz) {
		
		NodoArbol *temp = raiz;
		if (raiz!=NULL) {
			nodes = nodes + "nodo" + std::to_string(raiz->valor) + " " + "[ label = \"<C0>|" + std::to_string(raiz->valor) + "|<C1>\"" + "];\n";
			if (raiz->izq!=NULL) {
				rela = rela + "nodo"+std::to_string(raiz->valor)+":C0->"+"nodo"+std::to_string(raiz->izq->valor)+"\n";
			}
			if (raiz->dere != NULL) {
				rela = rela + "nodo" + std::to_string(raiz->valor) + ":C1->" + "nodo" + std::to_string(raiz->dere->valor) + "\n";
			}
			graficarArbol(raiz->izq);
			graficarArbol(raiz->dere);
		}
	}
	bool esVacio() {
		return (raiz == NULL);
	}
	NodoArbol *mostrarArbole(NodoArbol *raiz,int n) {
		if (raiz==NULL) {
		
		}
		else if (raiz->valor==n) {
			return raiz;
		}
		else if (n<raiz->valor) {
			return mostrarArbole(raiz->izq,n);
		}
		else {
			return mostrarArbole(raiz->dere, n);
		}
		
	}
	void reccorrerListaHorizontal(int n,int x) {
		NodoArbol *temp = mostrarArbole(raiz,n);
		string dibujoMatriz = "digraph D {\n node [shape=plaintext]\n some_node [\n label=<\n <table ALIGN=\"CENTER\" border=\"0\" cellborder=\"0\" cellspacing=\"0\">\n";
		ofstream file;
		string matGraficar[10][10];
		string tr = dibujoMatriz + "\n";
		string td = "";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				matGraficar[i][j] = "<td bgcolor=\"white\">     </td>";
			}
		}
		for (int i = 0; i < 5; i++)
		{

		}
		if (!temp->matrix->listlat->esVacia()) {
			NodoLateral *tempo = temp->matrix->listlat->primero;
			NodoContenido *nodo = NULL;
			while (tempo != NULL)
			{
				nodo = tempo->fila->primero;
				while (nodo!=NULL)
				{
					matGraficar[nodo->y][nodo->x-1] = "<td bgcolor=\""+nodo->color+"\">     </td>";
					nodo = nodo->derech;
				}
				tempo = tempo->siguiente;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			td += "<tr>\n";
			for (int j = 0; j < 10; j++)
			{
				td += matGraficar[i][j];
			}
			td += "</tr>\n";
		}
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/Prueba1.dot");
		file << tr + td + "\n</table>>\n];\n}";
		file.close(); 
		system("dot -Tpng Prueba1.dot -o graf1.png");
		system("graf1.png");
	}
	void reccorrerListaHorizontal(vector<int> capas) {
		NodoArbol *temp;
		string dibujoMatriz = "digraph D {\n node [shape=plaintext]\n some_node [\n label=<\n <table ALIGN=\"CENTER\" border=\"0\" cellborder=\"0\" cellspacing=\"0\">\n";
		ofstream file;
		string matGraficar[15][15];
		string tr = dibujoMatriz + "\n";
		string td = "";
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				matGraficar[i][j] = "<td bgcolor=\"white\">     </td>";
			}
		}
		for (int o = 0; o < capas.size();o++) {
			temp = mostrarArbole(raiz, capas[o]);
			if (!temp->matrix->listlat->esVacia()) {
				NodoLateral *tempo = temp->matrix->listlat->primero;
				NodoContenido *nodo = NULL;
				while (tempo != NULL)
				{
					nodo = tempo->fila->primero;
					while (nodo != NULL)
					{
						matGraficar[nodo->y][nodo->x - 1] = "<td bgcolor=\"" + nodo->color + "\">     </td>";
						nodo = nodo->derech;
					}
					tempo = tempo->siguiente;
				}
			}
		}
		for (int i = 0; i < 15; i++)
		{
			td += "<tr>\n";
			for (int j = 0; j < 15; j++)
			{
				td += matGraficar[i][j];
			}
			td += "</tr>\n";
		}
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/Prueba1.dot");
		file << tr + td + "\n</table>>\n];\n}";
		file.close();
		system("dot -Tpng Prueba1.dot -o graf1.png");
		system("graf1.png");
	}
};