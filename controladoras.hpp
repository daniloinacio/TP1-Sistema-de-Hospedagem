#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>

using namespace std;

class CntrMAAutenticacao:public IAAutenticacao
{
private:
	ISAutenticacao *cntrMSAutenticacao;
	
public:
	bool autenticar( Identificador id )
    void setCntrLNAutenticacao( ILNAutenticacao* );

};

class CntrMSAutenticacao:public ISAutenticacao
{
public:

};

#endif // CONTROLADORAS_H_INCLUDED