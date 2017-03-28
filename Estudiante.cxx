#include "Estudiante.h"

// -------------------------------------------------------------------------
Estudiante::Estudiante( std::string nombre, std::string idEstudiante )
{
	this->nombre = nombre;
	this->idEstudiante = idEstudiante;
	Clases horario;
	this->horario = horario;;
}

// -------------------------------------------------------------------------
Estudiante::~Estudiante( )
{
}

// -------------------------------------------------------------------------
void Estudiante::SetNombre( const std::string& nombre )
{
	this->nombre = nombre;
}

// -------------------------------------------------------------------------
void Estudiante::SetIdEstudiante( const std::string& idEstudiante )
{
	this->idEstudiante = idEstudiante;
}

// -------------------------------------------------------------------------
const std::string& Estudiante::GetNombre( ) const
{
	return( this->nombre );
}

// -------------------------------------------------------------------------
const std::string& Estudiante::GetIdEstudiante( ) const
{
	return( this->idEstudiante );
}

// -------------------------------------------------------------------------
bool Estudiante::inscribirEstudianteClase(const std::string& idClase)
{
	bool exito = false;
	Clases::iterator it = this->horario.begin();
	bool flag = true;
	while( it != this->horario.end() && flag)
	{
		if((*it)==idClase)
		{
			std::cout<<"Ya inserto esta clase"<<std::endl;
			exito = false;
			flag=false;
		}
		it++;
	}
	if(flag)
	{
		this->horario.push_back(idClase);
		std::cout<<"Clase asociada a estudiante"<<std::endl;
		exito = true;
	}
	return exito;
}

std::deque< std::string > Estudiante::imprimirHorario()
{
	return(this->horario);

}
