#include "pch.h"
#include <iostream>
#include <string>
#include "MatrizDispersa.cpp"
#pragma once
using namespace std;
class NodoArbol {
public:
	MatrizDispersa *matrix;
	int valor;
	NodoArbol *izq;
	NodoArbol *dere;

};