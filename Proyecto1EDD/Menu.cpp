#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "ArbolBinarioBusqueda.cpp"
#include "MatrizDispersa.cpp"
#include "NodoLateral.cpp"
using namespace std;
class Menu {
private:
	int opcion = 0;
	NodoLateral *no;
	string ruta,linea,texto;
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
		MatrizDispersa *matrix=new MatrizDispersa();
		char letra;
		int contNum = 0;
		string idCapa,color, columna, fila;
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
						ar.insertarNodo(raiz, std::stoi(idCapa),matrix);
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
						cout << fila << " " << columna << " " << color << endl;
						matrix->insertar(std::stoi(columna), std::stoi(fila),color);						
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
			ar.mostrarArbol(raiz, 0);
		}
	}
};