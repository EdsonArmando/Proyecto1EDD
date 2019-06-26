#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include "ArbolBinarioBusqueda.cpp"
#include "MatrizDispersa.cpp"
#include "NodoLateral.cpp"
#include "ListaIm.cpp"
#include "ListaImagenes.cpp"
#include "ListaHorizontal.cpp"
#include "NodoCabecera_Imagen.cpp"
#include "ArbolAVL.cpp"
#include "NodoAVL.cpp"
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
	ListaIm *listaI = new ListaIm();
	ListaImagenes *im;
	NodoArbol *espe;
	ArbolBinarioBusqueda ar;
	ArbolAVL arb;
	int idCapa;
	string arbolBinario="";
	int noCapas;
	string capass,imag,nomIm,usuario,nuevoNombre;
	vector<int> capas;

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
			leerArchivo(ruta, "usuario");
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
			switch (opcion)
			{
			case 1:
				cout << "1. Preorden" << endl;
				cout << "2. Inorden" << endl;
				cout << "3. PostOrden" << endl;
				cin >> opcion;
				switch (opcion)
				{
				case 1:
					
					cout << "Ingrese no Capas" << endl;
					cin >> noCapas;
					ar.recorridoPreOrden(raiz,noCapas);
					capass = ar.retCapas();
					ar.reccorrerListaHorizontal(capass,noCapas);
					ar.limpiarString();
					break;
				case 2:
					cout << "Ingrese no Capas" << endl;
					cin >> noCapas;
					ar.recorridoEnOrden(raiz,noCapas);
					capass = ar.retCapas();
					cout << capass << endl;
					ar.reccorrerListaHorizontal(capass, noCapas);
					ar.limpiarString();
					break;
				case 3:
					cout << "Ingrese no Capas" << endl;
					cin >> noCapas;
					ar.recorridoPostOrden(raiz,noCapas);
					capass = ar.retCapas();
					cout << capass << endl;
					ar.reccorrerListaHorizontal(capass, noCapas);
					ar.limpiarString();
					break;
				default:
					break;
				}
				break;
			case 2:
				cout << "Ingrese el nombre de la Imagen" << endl;
				cin >> imag;
				cout << listaI->cabeceraIm->listaCapas(imag) << endl;
				ar.reccorrerListaHorizontal(listaI->cabeceraIm->listaCapas(imag), listaI->cabeceraIm->noCapas(imag));
				break;
			case 3:
				cout << "Ingrese el idCapa" << endl;
				cin >> idCapa;
				ar.reccorrerListaHorizontal(idCapa, 2);
				break;
			case 4:
				cout << "Ingrese el nombre Usuario" << endl;
				cin >> usuario;
				imag=arb.imaUsuario(usuario);
				ar.reccorrerListaHorizontal(listaI->cabeceraIm->listaCapas(imag), listaI->cabeceraIm->noCapas(imag));
				break;
			default:
				break;
			}
			system("cls");
			iniciarMenu();
			break;
		case 3:
			cout << "Menu de ABC" << endl;
			cout << "1. Usuarios" << endl;
			cout << "2. Imagenes" << endl;
			cin >> opcion;
			switch (opcion)
			{
			case 1:
				cout << "Menu de Usuario" << endl;
				cout << "1. IngresarUsuario" << endl;
				cout << "2. EditarUsuario" << endl;
				cin >> opcion;
				switch (opcion)
				{
				case 1:
					cout << "Ingrese el nombre Usuario " << endl;
					cin >> usuario;
					arb.insertar(usuario);
					break;
				case 2:
					cout << "Ingrese el nombre Usuario a Modificar" << endl;
					cin >> usuario;
					cout << "Nuevo Nombre del Usuario" << endl;
					cin >> nuevoNombre;
					arb.cambiarNombre(primer,usuario,nuevoNombre);
					break;
				default:
					break;
				}
				break;
			case 2:
				cout << "Ingrese el nombre Usuario " << endl;
				cin >> usuario;
				cout << "Ingrese el idImagen " << endl;
				cin >> opcion;
				arb.ingersarImagenUsuario(usuario,"Imagen"+std::to_string(opcion));
				break;
			default:

				break;
			}
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
			switch (opcion)
			{
			case 3:
				ar.arbolEsp(raiz);
				ar.Graficar2(raiz);
				ar.mostrarArbol2();
				break;
			case 5:
				cout << "Ingrese nombre Imagen" << endl;
				cin >> nomIm;
				listaI->cabeceraIm->imagenArbol(nomIm,arbolBinario);
				break;
			case 1:
				listaI->cabeceraIm->recorrerLista();
				break;
			case 2:
				ar.graficarArbol(raiz);
				arbolBinario= ar.mostrarArbol();
				break;
			case 6:
				arb.graficarAVLeImagenes(primer);
				arb.mostrarArbol();
				break;
			default:
				break;
			}
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
		NodoAvl *avlN;
		NodoCabecera *no;
		NodoArbol *temp;
		NodoLateral *lateral;
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
						temp = ar.mostrarArbole(raiz, std::stoi(idCapa));
						temp->matrix->insertar(std::stoi(fila), std::stoi(columna), color);
						//matrix->insertar(std::stoi(columna), std::stoi(fila),color);	
						//no = temp->matrix->listaCab->buscarNodo(std::stoi(columna));
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
		}
		else if (tipo=="imagen") {
		
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
		archivo = "";
		texto = "";
		tipo = "";
		linea = "";
		op = 0;
		}
		else if (tipo=="usuario") {
		string nombreUser,imagen;
		for (int i = 0; i < lon; i++)
		{
			letra = archivo[i];
			switch (letra)
			{
			case ' ':
			case '\n':
			case '\t':
				break;
			case ',':
				avlN = arb.devNodo(primer, nombreUser);
				avlN->list->insertar("Imagen"+imagen);
				imagen = "";
				break;
			case ';':
				if (imagen=="") {
				
				}
				else {
					avlN = arb.devNodo(primer, nombreUser);
					avlN->list->insertar("Imagen" + imagen);
					imagen = "";
					nombreUser = "";
				}
				break;
			case ':':
				arb.insertar(nombreUser);
				break;
			default:	
				if (isdigit(letra)) {
					imagen +=letra;
				}
				else {
					nombreUser += letra;
				}
				
				break;
			}
		}
		/*avlN = arb.devNodo(primer, "userA");
		avlN->list->recorrerLista();*/
		archivo = "";
		texto = "";
		tipo = "";
		linea = "";
		op = 0;
		}
	}
};