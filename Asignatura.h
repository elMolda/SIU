#ifndef __Asignatura__H__
#define __Asignatura__H__

#include <iostream>

#include <string>
#include <deque>
#include <ostream>
#include "Clase.h"


class Asignatura
{
 public:
	Asignatura( std::string nombre, std::string idAsignatura );
	virtual ~Asignatura( );

	void SetNombre( const std::string& nombre );
	void SetIdAsignatura( const std::string& idAsignatura );
	
	bool insertarClase( const std::string idClase, const std::string numero, 
			 const std::string dia, const std::string horaInicio, const std::string horaFin,
			 const std::string salon );
	bool inscribirAlumnoClase(const std::string idClase,const std::string idEstudiante);
	
	void imprimirHorario(const std::string idClase);

	const std::string& GetNombre( ) const;
	const std::string& GetIdAsignatura( ) const;
	
 protected:
	typedef std::deque<Clase> Clases;

 protected:
	std::string nombre;
	std::string idAsignatura;
	Clases clasesOfertadas;
};

#endif
