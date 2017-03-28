#include "Sesion.h"

// -------------------------------------------------------------------------
Sesion::Sesion( std::string idClase,std::string numero, std::string dia, std::string horaInicio,
		 std::string horaFin, std::string salon )
{
	this->idClase = idClase;
	this->numero = numero;
	this->dia = dia;
	this->horaInicio = horaInicio;
	this->horaFin = horaFin;
	this->salon =salon;
}

// -------------------------------------------------------------------------
Sesion::~Sesion( )
{
}

// -------------------------------------------------------------------------
void Sesion::SetNumero( const std::string& numero )
{
	this->numero = numero;
}

// -------------------------------------------------------------------------
void Sesion::SetDia( const std::string& dia )
{
	this->dia = dia;
}

// -------------------------------------------------------------------------
void Sesion::SetHoraInicio( const std::string& horaInicio )
{
	this->horaInicio = horaInicio;
}

// -------------------------------------------------------------------------
void Sesion::SetHoraFin( const std::string& horaFin )
{
	this->horaFin = horaFin;
}

// -------------------------------------------------------------------------
void Sesion::SetSalon( const std::string& salon )
{
	this->salon = salon;
}

// -------------------------------------------------------------------------
const std::string& Sesion::GetNumero( ) const
{
	return( this->numero );
}

// -------------------------------------------------------------------------
const std::string& Sesion::GetDia( ) const
{
	return( this->dia );
}

// -------------------------------------------------------------------------
const std::string& Sesion::GetHoraInicio( ) const
{
	return( this->horaInicio );
}

// -------------------------------------------------------------------------
const std::string& Sesion::GetHoraFin( ) const
{
	return( this->horaFin );
}

// -------------------------------------------------------------------------
const std::string& Sesion::GetSalon( ) const
{
	return( this->salon );
}


