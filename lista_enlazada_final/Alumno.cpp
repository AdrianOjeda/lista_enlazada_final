#include "Alumno.h"
#include <string.h>

Alumno::Alumno() {

	edad = 0;
	*nombre = {};
}

Alumno::Alumno(int edad, char* nombre) {
	this->edad = edad;
	strcpy_s(this->nombre, nombre);
}

void Alumno::setNombre(char* nuevoNombre) {
	nuevoNombre = nombre;

}
void Alumno::setEdad(int nuevaEdad) {
	nuevaEdad = edad;

}
char Alumno::getNombre(void) {
	return *nombre;

}
int Alumno::getEdad(void) {
	return edad;

}
