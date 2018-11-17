#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

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
	virtual bool autenticar( const Identificador&, const Senha &) = 0;
};

#endif // INTERFACES_H_INCLUDED
