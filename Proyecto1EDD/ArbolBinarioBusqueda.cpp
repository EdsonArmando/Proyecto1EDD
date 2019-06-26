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
	string inicio = "digraph grafica{\nrankdir=TB;\n subgraph cluster_0{\n label=\"Arbol Binario de Capas\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
	string inicio2 = "digraph grafica{\nrankdir=TB;\n subgraph cluster_0{\n label=\"Arbol Binario de Espejo\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
	string nodes,nodess;
	string rela,relass;
	string capas,capass;
public:
	NodoLateral *no;
	NodoCabecera *noCa;
	void insertarNodo(NodoArbol *&raiz,int n) {
		if (raiz ==NULL) {
			NodoArbol *nuevo = new NodoArbol(n);
			raiz = nuevo;
			raiz->izq = NULL;
			raiz->dere = NULL;
		}else if (n < raiz->valor) 
			insertarNodo(raiz->izq, n);
		
		else if (n > raiz->valor) 
			insertarNodo(raiz->dere, n);
	}
	string mostrarArbol() {
		ofstream file;
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/Arbol.dot");
		file <<inicio+nodes+rela+"\n}\n}";
		file.close();
		system("dot -Tpng Arbol.dot -o graf2.png");
		system("graf2.png");
		return inicio + nodes + rela;
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
		string matGraficar[45][45];
		string tr = dibujoMatriz + "\n";
		string td = "";
		for (int i = 0; i < 45; i++)
		{
			for (int j = 0; j < 45; j++)
			{
				matGraficar[i][j] = "<td bgcolor=\"white\">     </td>";
			}
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
		for (int i = 0; i < 45; i++)
		{
			td += "<tr>\n";
			for (int j = 0; j < 45; j++)
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
	void reccorrerListaHorizontal(string cp,int no) {
		NodoArbol *temp;

		string dibujoMatriz = "digraph D {\n node [shape=plaintext]\n some_node [\n label=<\n <table ALIGN=\"CENTER\" border=\"0\" cellborder=\"0\" cellspacing=\"0\">\n";
		ofstream file;
		string matGraficar[45][45];
		string tr = dibujoMatriz + "\n";
		string td = "";
		string delim = ",";
		int vecto[20];
		string idC="";
		char ik;
		
		int cont = 0;
		for (int i = 0; i < cp.length(); i++)
		{
			ik = cp[i];
			if (ik==',') {
				vecto[cont] = std::stoi(idC);
				cont++;
				idC = "";
			}
			else {
				idC += ik;
			}
		}
		int limite = (sizeof(vecto) / sizeof(vecto[0]));
		for (int i = 0; i < 45; i++)
		{
			for (int j = 0; j < 45; j++)
			{
				matGraficar[i][j] = "<td bgcolor=\"white\">     </td>";
			}
		}
		for (int o = 0; o < limite;o++) {
			temp = mostrarArbole(raiz, vecto[o]);
			no--;
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
			if (no==0) {
				break;
			}
		}
		for (int i = 0; i < 45; i++)
		{
			td += "<tr>\n";
			for (int j = 0; j < 45; j++)
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
	void arbolEsp(NodoArbol *raiz) {
		
		if (raiz!=NULL) {
			NodoArbol *tm;
			cout << raiz->valor << " ";
			arbolEsp(raiz->izq);
			arbolEsp(raiz->dere);
			tm = raiz->izq;
			raiz->izq = raiz->dere;
			raiz->dere = tm;
		 
		}
		
	}

	void Graficar2( NodoArbol* raiz)
	{
		if (raiz == NULL) {
			return;
		}
		else {
			nodess = nodess + "nodo" + std::to_string(raiz->valor) + " " + "[ label = \"<C0>|" + std::to_string(raiz->valor) + "|<C1>\"" + "];\n";
			if (raiz->izq != NULL) {
				relass = relass + "nodo" + std::to_string(raiz->valor) + ":C0->" + "nodo" + std::to_string(raiz->izq->valor) + "\n";
			}
			if (raiz->dere != NULL) {
				relass = relass + "nodo" + std::to_string(raiz->valor) + ":C1->" + "nodo" + std::to_string(raiz->dere->valor) + "\n";
			}
			Graficar2(raiz->izq);
			Graficar2(raiz->dere);
		}
	}
	void mostrarArbol2() {
		ofstream file;
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/ArbolEpejo.dot");
		file << inicio2 + nodess + relass + "\n}\n}";
		file.close();
		system("dot -Tpng ArbolEpejo.dot -o graf7.png");
		system("graf7.png");
		
	}
	void recorridoPreOrden(NodoArbol *raiz,int noCapas) {
		if (raiz==NULL) {
			
		}
		else {
			cout << raiz->valor << " ";
			if (noCapas!=0) {
				capas =capas+ std::to_string(raiz->valor) + ",";
			}
			recorridoPreOrden(raiz->izq,noCapas--);
			recorridoPreOrden(raiz->dere,noCapas--);
		}
		
	}
	string retCapas() {
		return capas;
	}
	void limpiarString() {
		capas = "";
	}
	void recorridoEnOrden(NodoArbol *raiz,int noCapas) {
		if (raiz == NULL) {

		}
		else {
			recorridoEnOrden(raiz->izq,noCapas--);
			if (noCapas != 0) {
				capas = capas + std::to_string(raiz->valor) + ",";
			}
			cout << raiz->valor << " ";
			
			recorridoEnOrden(raiz->dere,noCapas--);
		}
	}

	void recorridoPostOrden(NodoArbol *raiz,int noCapas) {
		if (raiz == NULL) {

		}
		else {
			recorridoPostOrden(raiz->izq,noCapas--);
			recorridoPostOrden(raiz->dere,noCapas--);
			if (noCapas != 0) {
				capas = capas + std::to_string(raiz->valor) + ",";
			}
			cout << raiz->valor << " ";
		}
	}
	void recoPost(NodoArbol *raiz) {
		if (raiz == NULL) {

		}
		else {
			recoPost(raiz->izq);
			recoPost(raiz->dere);
			cout << raiz->valor << " ";
		}
	}
	void recoIn(NodoArbol *raiz) {
		if (raiz == NULL) {

		}
		else {
			recoIn(raiz->izq);
			cout << raiz->valor << " ";
			recoIn(raiz->dere);
		}
	}
	int alt;
	void recoPre(NodoArbol *raiz) {
		if (raiz == NULL) {

		}
		else {
			cout << raiz->valor << " ";
			recoPre(raiz->izq);
			recoPre(raiz->dere);
		}
	}

	int profundidad(NodoArbol *raiz) {
		int alt2,alt;
		if (raiz == NULL) {
			return -1;
		}
		else {
			alt = profundidad(raiz->izq);
			alt2 = profundidad(raiz->dere);

			/*if (raiz->izq == NULL) {
				return alt;
				

			}*/
			if (alt>alt2) {
				return alt + 1;
			}
			else {
				return alt2 + 1;
			}
			//profundidad(raiz->izq);
			
			//profundidad(raiz->dere);
		}
	}
};