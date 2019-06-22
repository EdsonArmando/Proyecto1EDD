#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "ArbolBinarioBusqueda.cpp"
#include "MatrizDispersa.cpp"
#include "NodoLateral.cpp"
#include "ListaIm.cpp"
#include "NodoCabecera_Imagen.cpp"
#pragma once
using namespace std;
class Menu {
private:
	int opcion = 0;
	NodoLateral *no;
	string ruta,linea,texto;
	NodoCabecera_Imagen *nod;
	ifstream archivoEntrada;
	MatrizDispersa matrix;
	ArbolBinarioBusqueda ar;

public:
	
	void iniciarMenu() {
		cout << "Bienvenido al sistema" << endl;
		cout << "1. Carga de datos" << endl;
		cout << "2. Generacion de imagenes" << endl;
		cout << "3. ABC" << endl;
		cout << "4. Estado de la memoria" << endl;
		cout << "5. Otros reportes" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:

			cout << "Ingrese ruta para Capas" << endl;
			cin >> ruta;
			leerArchivo(ruta,"capa");
			cout << "Ingrese ruta para Imagenes" << endl;
			cin >> ruta;
			leerArchivo(ruta, "imagen");
			cout << "Ingrese ruta para Usuarios" << endl;
			cin >> ruta;
			system("cls");
			iniciarMenu();
			break;
		case 2:
			cout << "Menu de generacion de Imagenes" << endl;
			cout << "1. Por recorrido Limitado" << endl;
			cout << "2. Por lista de Imagenes" << endl;
			cout << "3. Por Capa" << endl;
			cout << "4. Por Usuario" << endl;
			cin >> opcion;
			system("cls");
			iniciarMenu();
			break;
		case 3:
			cout << "Menu de ABC" << endl;
			cout << "1. Usuarios" << endl;
			cout << "2. Imagenes" << endl;
			cin >> opcion;
			system("cls");
			iniciarMenu();
			break;
		case 4:
			cout << "Menu de Estado de la Memoria" << endl;
			cout << "1. Ver lista de imagenes" << endl;
			cout << "2. Ver arbol de capas" << endl;
			cout << "3. Ver arbol de capas espejo" << endl;
			cout << "4. Ver capa" << endl;
			cout << "5. Ver imagen y arbol de capas" << endl;
			cout << "6. Ver arbol de usuarios" << endl;
			cin >> opcion;
			system("cls");
			iniciarMenu();
			break;
		case 5:
			cout << "Menu de Otros Reportes" << endl;
			cout << "1. Top 5 imagenes con mas numero de capas" << endl;
			cout << "2. Todas las capas que son hojas" << endl;
			cout << "3. Profundidad de arbol de capas" << endl;
			cout << "4. Mostrar capas en post-orden" << endl;
			cout << "5. Listar las capas en: preorden,inorden,postorden" << endl;
			cout << "6. Top 5 usuarios con mas imagenes" << endl;
			cout << "7. Arbol espejo de usuarios" << endl;
			cout << "8. Listar usuarios en recorrido: preorden,inorden,postorden,por niveles" << endl;
			cin >> opcion;
			system("cls");
			iniciarMenu();
			break;
		default:
			break;
		}
	}
	void leerArchivo(string ruta,string tipo) {
		archivoEntrada.open(ruta);
		if (archivoEntrada.is_open()) {
			while (archivoEntrada.good())
			{
				getline(archivoEntrada, linea);
				texto += linea + "\n";
			}
		}
		archivoEntrada.close();
		leerDatos(texto,tipo);
	}
	void leerDatos(string archivo,string tipo) {
		NodoLateral *no;
		MatrizDispersa *matrix = new MatrizDispersa();
		char letra;
		int contNum = 0;
		string idCapa,color, columna, fila,idImagen;
		int op = 0;
		int lon = archivo.length();
		if (tipo=="capa") {
			for (int i = 0; i < lon; i++) {
				letra = archivo[i];
				switch (op)
				{
				case 0:
					switch (letra)
					{
					case '\n':
					case '\t':
					case ' ':
						op = 0;
						break;
					case '}':
						contNum = 0;
						idCapa = "";
						op = 0;
						break;
					default:
						if (isdigit(letra)) {
							if (contNum==0) {
								op = 1;
								i = i - 1;
								contNum++;
							}
							else if (contNum==1) {
								op = 2;
								i = i - 1;
								contNum++;
							}
							else if (contNum == 2) {
								op = 3;
								i = i - 1;
								contNum++;
							}
						}
						else {
							op = 4;
							i = i - 1;
						}
						break;
					}
					break;
				case 1:
					if (letra== '{') {
						//idCapa = "";
						ar.insertarNodo(raiz, std::stoi(idCapa));
						op = 0;
					}
					else {
						idCapa += letra;
					}
					break;
				case 2:
					if (letra == ',') {
						
						op = 0;
					}
					else {
						fila += letra;
					}
					break;
				case 3:
					if (letra == ',') {
						
						op = 0;
					}
					else {
						columna += letra;
					}
					break;
				case 4:
					if (letra == ';') {
						//cout << fila << " " << columna << " " << color << endl;
						NodoArbol *temp = ar.mostrarArbole(raiz, std::stoi(idCapa));
						temp->matrix->insertar(std::stoi(columna), std::stoi(fila), color);
						//matrix->insertar(std::stoi(columna), std::stoi(fila),color);	
						no = temp->matrix->listlat->buscarNodo(std::stoi(fila));
						string dato = no->fila->primero->color;
						cout << dato << endl;
						color = "";
						fila = "";
						contNum = 1;
						columna = "";
						op = 0;
					}
					else {
						color += letra;
					}
					break;
				default:
					op = 0;
					break;
				}
				//
				//else if (letra == '\t'||letra== '\n' || letra == ' ') {
			}
			archivo = "";
			texto = "";
			tipo = "";
			linea = "";
			op = 0;
			ar.mostrarArbol(raiz, 0);
		}
		else if (tipo=="imagen") {
		ListaIm *listaI = new ListaIm();
		for (int i = 0; i < lon; i++)
		{
			letra = archivo[i];
			switch (op)
			{
			case 0:
				switch (letra)
				{
				case ' ':
				case '\n':
				case '\t':
					op = 0;
					break;
				case '{':
					op = 0;
					contNum=1;
					//listaI->insertar();
					break;
				case '}':
					if (idCapa=="") {
						listaI->insertar("Imagen" + idImagen,0);
					}
					else {
						listaI->insertar("Imagen" + idImagen, std::stoi(idCapa));
					}
					idCapa = "";
					idImagen = "";
					contNum = 0;
					op = 0;
					//listaI->insertar();
					break;
				case ',':
					listaI->insertar("Imagen"+idImagen,std::stoi(idCapa));
					idCapa = "";
					op = 0;
					//listaI->insertar();
					break;
				default:
					if (isdigit(letra)&&contNum==0) {
						idImagen += letra;
					}
					else if (contNum==1) {
						idCapa += letra;
					}
					break;
				}
				break;
			default:

				break;
			}
			
		}
		nod = listaI->cabeceraIm->retNodo("Imagen1");
		nod->lista->recorrerLista();
		nod = listaI->cabeceraIm->retNodo("Imagen2");
		nod->lista->recorrerLista();
		nod = listaI->cabeceraIm->retNodo("Imagen3");
		nod->lista->recorrerLista();
		}
	}
};