#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "containers.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

class CntrMAAutenticacao:public IAAutenticacao
{
private:

	bool resultadoOperacao;
	ISAutenticacao *cntrMSAutenticacao;
	Senha senha;
	string senhaStr;
	Identificador identificadorTemp;
	string identificadorStr;

public:

	bool autenticar( Identificador *id );
    void setCntrMAAutenticacao( ISAutenticacao *cntrMSAutenticacao );

};

void inline void CntrMAAutenticacao::setCntrMAAutenticacao( ISAutenticacao *cntrMSAutenticacao )
{
        this->cntrMSAutenticacao = cntrMSAutenticacao;
}

class CntrMSAutenticacao:public ISAutenticacao
{
private:

	ContainerUsuario *container;

public:

	bool autenticar( const Identificador&, const Senha& );
	void setContainer( ContainerUsuario *container );
};

void inline void CntrMSAutenticacao::setContainer( ContainerUsuario *container )
{
	this->container = container;
}

#endif // CONTROLADORAS_H_INCLUDED