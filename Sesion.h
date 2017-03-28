#ifndef __Sesion__H__
#define __Sesion__H__

#include <iostream>

#include <string>

class Sesion
{
public:
	Sesion( std::string idClase, std::string numero, std::string dia, std::string horaInicio, 
		std::string horaFin, std::string salon );
	virtual ~Sesion( );

	void SetNumero( const std::string& numero );
	void SetDia( const std::string& dia );
	void SetHoraInicio( const std::string& horaInicio );
	void SetHoraFin( const std::string& horaFin );
	void SetSalon( const std::string& salon );

	const std::string& GetNumero( ) const;
	const std::string& GetDia( ) const;
	const std::string& GetHoraInicio( ) const;
	const std::string& GetHoraFin( ) const;
	const std::string& GetSalon( ) const;

protected:
	std::string idClase;
	std::string numero;
	std::string dia;
	std::string horaInicio;
	std::string horaFin;
	std::string salon;
};


#endif
