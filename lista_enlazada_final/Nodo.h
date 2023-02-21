#pragma once
#include "Alumno.h"

class Nodo
{
public:
	Alumno alumno;
	Nodo* sig;
	Nodo();
	Nodo(Alumno, Nodo*);
};

