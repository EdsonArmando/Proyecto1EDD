#include "pch.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodoImagenUsuario {
public:
	string nombreImagen;
	NodoImagenUsuario *siguiente;
	NodoImagenUsuario(string name) {
		this->nombreImagen = name;
		siguiente = NULL;
	}
};