#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <stdexcept>

using namespace std;

class IAAutenticacao
{
public:
	virtual bool autenticar( Identificador *id ) = 0;
};

class ISAutenticacao
{
public:
	virtual bool autenticar( const Identificador &, const Senha &) = 0;
};

class IAUsuario
{
public:
    virtual bool cadastrarUsuario( Nome nome, Identificador id, Senha senha ) = 0;
};

class ISUsuario
{
public:
    virtual bool validarUsuario( const Identificador &, const Senha & ) = 0;
    virtual bool incluirUsuario( const Usuario & ) = 0;
};

#endif // INTERFACES_H_INCLUDED
