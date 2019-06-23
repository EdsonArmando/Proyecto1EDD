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
	void mostrarArbol(NodoArbol *raiz,int cont) {
		NodoArbol *temp=raiz;
		if (raiz==NULL) {
			return;
		}
		else {
			mostrarArbol(raiz->dere,cont+1);
			for (int i = 0; i < cont; i++)
			{
				cout << "  ";
			}
			cout << raiz->valor << endl;
			mostrarArbol(raiz->izq,cont+1);
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
		string dibujoMatriz = "digraph D {\n node [shape=plaintext]\n some_node [\n label=<\n <table ALIGN=\"CENTER\" border=\"0\" cellborder=\"0\" cellspacing=\"0\">\n";
		ofstream file;
		string matGraficar[10][10];
		vector<int> num;
		vector<int> fila;
		vector<string> v;
		NodoArbol *temp = mostrarArbole(raiz,n);
		NodoLateral *lateral = temp->matrix->listlat->buscarNodo(x);
		num = lateral->fila->retorX();
		fila = temp->matrix->listlat->retListaFila();
		string tr = dibujoMatriz+ "\n";
		string td = "";
		int tempX = temp->matrix->listaCab->retorPrimer();
	
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				matGraficar[i][j] = "<td bgcolor=\"#f0e3ff\">     </td>";
			}
		}
		for (int j = 0; j<fila.size(); j++) {
			NodoLateral *lateral = temp->matrix->listlat->buscarNodo(fila[j]);
			num = lateral->fila->retorX();
			for (int i = 0; i < num.size(); i++)
			{
				//cout << num[i] - tempX << endl;
				//td = td + "<td bgcolor=\"#f0e3ff\">  "+std::to_string(num[i])+"  </td>";
				//tempX = num[i];
				matGraficar[j+1][num[i] - 1] = "<td bgcolor=\"yellow\">     </td>";
			}
		}
		for (int i = 0; i < 10; i++)
		{
			td+= "<tr>\n";
			for (int j = 0; j < 10; j++)
			{
				td += matGraficar[i][j];
			}
			td += "</tr>\n";
		}
		file.open("C:/Users/EG/source/repos/Proyecto1EDD/Proyecto1EDD/Prueba.dot");
		file << tr + td + "\n</table>>\n];\n}";
		file.close(); 
		system("dot -Tpng Prueba.dot -o graf.png");
		system("graf.png");
	}
};