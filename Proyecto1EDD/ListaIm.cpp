#include "pch.h"
#include <iostream>
#include <string>
#include "ListaCapas.cpp"
#include "ListaImagenes.cpp"
#include "NodoCapa.cpp"
#pragma once
class ListaIm {
public:
	ListaImagenes *cabeceraIm;
	ListaIm() {
		cabeceraIm = new ListaImagenes();
	}
	void insertar(string img,int idCapa) {
		NodoCapa *nuevo = new NodoCapa(idCapa);
		if (cabeceraIm->buscar(img)==false) {
			cabeceraIm->insertarImg(new NodoCabecera_Imagen(img));
		}
		NodoCabecera_Imagen *temp;
		temp = cabeceraIm->retNodo(img);
		temp->lista->insertarCapa(idCapa);
	}
};