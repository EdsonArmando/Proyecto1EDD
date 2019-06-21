#include "pch.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;
class DatoMatriz {
public:
	DatoMatriz *izquierda;
	DatoMatriz *derecha;
	string color_hexadecimal;
	int fila;
	int columna;
};