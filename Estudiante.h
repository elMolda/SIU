#ifndef __Estudiante__H__
#define __Estudiante__H__

#include <iostream>

#include <string>
#include <deque>
#include <ostream>



class Estudiante
{
 public:
	Estudiante( std::string nombre, std::string idEstudiante);
	virtual ~Estudiante( );

	void SetNombre( const std::string& nombre );
	void SetIdEstudiante( const std::string& idEstudiante );
	bool agregarClase( const std::string& idClase );
	bool inscribirEstudianteClase(const std::string& idClase);
	
	
	const std::string& GetNombre( ) const;
	const std::string& GetIdEstudiante( ) const;

	std::deque< std::string > imprimirHorario();
	
 protected:
	typedef std::deque< std::string > Clases;

 protected:
	std::string nombre;
	std::string idEstudiante;
	Clases horario;
};


#endif
