#ifndef __Semestre__H__
#define __Semestre__H__

#include <iostream>

#include <string>
#include <deque>
#include <ostream>
#include "Asignatura.h"
#include "Estudiante.h"


class Semestre
{

 //friend: std::ostream& operator<<( std::ostream& os, const Semestre& s );
 public:
	Semestre( std::string idSemestre );
	virtual ~Semestre( );

	void SetIdSemestre( const std::string& idSemestre );
	
	bool insertarAsignatura( const std::string nombre,const std::string idAsignatura, 
			      const std::string idClase, const std::string numero, const std::string dia, 
			      const std::string horaInicio, const std::string horaFin, const std::string salon );

	bool agregarEstudiante( const std::string nombre, const std::string idAsignatura, 				  	 					const std::string idClase,  const std::string idEstudiante );
	bool inscribirEstudianteClase(const std::string idAsignatura,const std::string idClase,  const std::string idEstudiante );
	const std::string& GetIdSemestre( ) const;

	void imprimirHorario(const std::string idEstudiante);

	
 protected:
	typedef std::deque<Asignatura> Asignaturas;
	typedef std::deque<Estudiante> Alumnos;

 protected:
	std::string idSemestre;
	Asignaturas asignaturas;
	Alumnos alumnos;
};

#endif
