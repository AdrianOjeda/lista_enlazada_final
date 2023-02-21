#pragma once
class Alumno
{
	
public:
	char nombre[30] = {};
	int edad = 0;
	Alumno();
	Alumno(int, char*);
	void setNombre(char*);
	void setEdad(int);
	char getNombre(void);
	int getEdad(void);

};

