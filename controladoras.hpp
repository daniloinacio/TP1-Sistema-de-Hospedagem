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
    void setCntrMSAutenticacao( ISAutenticacao *cntrMSAutenticacao );

};

void inline CntrMAAutenticacao::setCntrMSAutenticacao( ISAutenticacao *cntrMSAutenticacao )
{
        this->cntrMSAutenticacao = cntrMSAutenticacao;
}

class CntrMAUsuario:public IAUsuario
{
private:
    bool resultadoOperacao;
    ISUsuario *cntrMSUsuario;
    string nomeStr;
    string identificadorStr;
    string senhaStr;
    Senha senhaTemp;
    Identificador idTemp;
    Nome nomeTemp;
    Usuario novoUsuario;

public:
    bool cadastrarUsuario( Identificador *identificador );
    void setCntrMSUsuario( ISUsuario *cntrMSUsuario );
};

void inline CntrMAUsuario::setCntrMSUsuario(ISUsuario *cntrMSUsuario)
{
    this->cntrMSUsuario = cntrMSUsuario;
}

class CntrMSUsuario : public ISAutenticacao, public ISUsuario
{
private:

	ContainerUsuario *container;
	Senha senhaTemp;
	list<Usuario>::iterator usuario;

public:

	bool autenticar( const Identificador&, const Senha& );
	void setContainer( ContainerUsuario *container );
	bool validarUsuario( const Identificador &, const Senha & );
	bool incluirUsuario( const Usuario & );
};

void inline CntrMSUsuario::setContainer( ContainerUsuario *container )
{
	this->container = container;
}

#endif // CONTROLADORAS_H_INCLUDED
