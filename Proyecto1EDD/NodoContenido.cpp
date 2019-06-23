#include "pch.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodoContenido {
public:
	int x, y;
	string color;
	NodoContenido *arriba;
	NodoContenido *abajo;
	NodoContenido *izqui;
	NodoContenido *derech;
	NodoContenido(string color, int y,int x) {
		this->color = color;
		this->x = x;
		this->y = y;
		arriba = NULL;
		abajo = NULL;
		izqui = NULL;
		derech = NULL;
	}
};