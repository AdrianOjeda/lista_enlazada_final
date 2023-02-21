#include "ListaAlumno.h"
#include <iostream>
using namespace std;


ListaAlumno::ListaAlumno() {
	header = nullptr;


}
ListaAlumno::ListaAlumno(Nodo* ptr) {
	header = ptr;


}


void ListaAlumno::insertarInicio(Alumno alumno) {
	Nodo* temp = new Nodo(alumno, nullptr);
	if (!header) {
		header = temp;
		cout << "Alumno ingresado con exito!" << endl;
	}
	else {
		temp->sig = header;
		header = temp;
	}
}

void ListaAlumno::mostrar() {
	Nodo* aux = header;

	if (header) {
		while (aux != nullptr) {
			cout << "Nombre: " << aux->alumno.nombre << " | Edad: " << aux->alumno.edad << endl;
			aux = aux->sig;
		}
		cout << endl;
	}
	else {
		cout << endl << "Lista vacia" << endl;
	}

}

void ListaAlumno::eliminarTodo() {

	Nodo* aux = header;
	while (aux != nullptr) {
		Nodo* temp = aux;
		aux = aux->sig;
		delete temp;
	}
	header = nullptr;
	delete aux;
	cout << "Lista eliminada con exito!" << endl;
}

void ListaAlumno::insertarFinal(Alumno alumno) {
	Nodo* temp = new Nodo(alumno, nullptr);
	Nodo* ultimo = header;
	while (ultimo->sig != nullptr) {
		ultimo = ultimo->sig;
	}
	ultimo->sig = temp;

}

void ListaAlumno::eliminar(Alumno alumno) {

	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	if (header != nullptr) {
		while (aux && bandera) {
			if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
				bandera = false;
			}
			else {
				auxAnterior = aux;
				aux = aux->sig;

			}
		}
		if (aux == nullptr) {
			cout << "No se encontro el Alumno" << endl;

		}
		else if (aux == header) {
			header = header->sig;
			delete aux;
			cout << "Alumno eliminado con exito!" << endl;

		}
		else if (aux->sig == nullptr) {
			auxAnterior->sig = nullptr;
			delete aux;
			cout << "Alumno eliminado con exito!" << endl;

		}
		else {
			auxAnterior->sig = aux->sig;
			delete aux;
			cout << "Alumno eliminado con exito!" << endl;
		}

	}
}

bool ListaAlumno::vacia() {

	if (header) {

		return false;
	}
	else {
		cout << endl << "Lista vacia" << endl;
		return true;
	}

}

int ListaAlumno::tamanoLista() {
	int contador = 0;
	Nodo* aux = header;
	while (aux != nullptr) {
		aux = aux->sig;
		contador++;

	}
	return contador;
}

void ListaAlumno::insertarPosicion(int posicion, Alumno alumno) {
	int contador = 0;
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	Nodo* temp = new Nodo(alumno, nullptr);
	if (posicion == 1) {
		temp = header;
		temp->sig = aux;
		cout << "Alumno ingresado con exito!" << endl;
	}
	else {
		while (contador < posicion - 1) {
			auxAnterior = aux;
			aux = aux->sig;
			contador++;

		}
		auxAnterior->sig = temp;
		temp->sig = aux;
		cout << "Alumno ingresado con exito!" << endl;
	}

}

int ListaAlumno::buscar(Alumno alumno) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	int contador = 1;
	bool bandera = true;
	while (aux && bandera) {
		if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
			contador++;
		}
	}
	return contador;

}

void ListaAlumno::primerElemento() {
	Nodo* aux = header;
	cout << "Nombre: " << aux->alumno.nombre << " | edad: " << aux->alumno.edad << endl;

}
void ListaAlumno::ultimoElemento() {
	Nodo* aux = header;
	while (aux->sig != nullptr) {
		aux = aux->sig;

	}
	cout << "Nombre: " << aux->alumno.nombre << " | edad: " << aux->alumno.edad << endl;

}

void ListaAlumno::siguiente(Alumno alumno) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	while (aux && bandera) {
		if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;

		}
	}
	if (aux->sig == nullptr) {
		cout << "El alumno ingresado ya es el ultimo de la lista!" << endl;
	}
	else {
		cout << "El Alumno que sigue de " << alumno.nombre << " es: " << endl;
		cout << "Nombre: " << aux->sig->alumno.nombre << " | edad: " << aux->sig->alumno.edad << endl;
	}


}

void ListaAlumno::anterior(Alumno alumno) {

	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	while (aux && bandera) {
		if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;

		}
	}
	if (aux == header) {
		cout << "El alumno ingresado es el primero de la lista!" << endl;
	}
	else {
		cout << "El Alumno que esta antes de " << alumno.nombre << " es: " << endl;
		cout << "Nombre: " << auxAnterior->alumno.nombre << " | edad: " << auxAnterior->alumno.edad << endl;
	}

}
