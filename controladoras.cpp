#include "controladoras.hpp"
#include "dominios.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

bool CntrMAAutenticacao::autenticar( Identificador *identificador )
{

	cout << "Insira o Identificador:" << endl;
	cin >> identificadorStr >> endl;
	cout << "Insira a senha:" << endl;
	cin >> senhaStr >> endl;

	try
	{
	identificadorTemp.setIdentificador( identificadorStr );
	senha.setSenha( senhaTemp );
	}
	catch( invalid_argument excecao )
	{
		cout << "Identificador ou senha em formato errado." << endl;
		return FALSE;
	}

	resultadoOperacao = cntrMSAutenticacao->autenticacao( &identificadorTemp, &senha );

	if ( resultadoOperacao == TRUE )
	{
		cout << "Atenticacao bem sucedida." << endl;
		identificador->setIdentificador(identificadorTemp.getIdentificador());S
	}
	else
	{
		cout << "Falha na autenticacao. Identificador ou senha incorretos." << endl;
	}
	return resultadoOperacao;
}

bool CntrMSAutenticacao::autenticar( const Identificador &id, const Senha &senha)
{

}