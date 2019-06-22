#include "pch.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodoCapa {
public:
	int idCapa;
	NodoCapa *siguiente;
	NodoCapa(int idCapa) {
		this->idCapa = idCapa;
		siguiente = NULL;	
	}

};