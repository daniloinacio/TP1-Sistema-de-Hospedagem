#include "controladoras.hpp"
#include "dominios.hpp"
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

bool CntrMAAutenticacao::autenticar( Identificador *identificador )
{

	cout << "Insira o Identificador:" << endl;
	cin >> identificadorStr;
	cout << "Insira a senha:" << endl;
	cin >> senhaStr;

	try
	{
        identificadorTemp.setIdentificador( identificadorStr );
        senha.setSenha( senhaStr );
	}
	catch( invalid_argument excecao )
	{
		cout << "Identificador ou senha em formato errado." << endl;
		return false;
	}

	resultadoOperacao = cntrMSAutenticacao->autenticar( identificadorTemp, senha );

	if ( resultadoOperacao == true )
	{
		cout << "Atenticacao bem sucedida." << endl;
		identificador->setIdentificador(identificadorTemp.getIdentificador());
	}
	else
	{
		cout << "Falha na autenticacao. Identificador ou senha incorretos." << endl;
	}
	return resultadoOperacao;
}

bool CntrMSAutenticacao::autenticar( const Identificador &identificador, const Senha &senha)
{
    ResultadoUsuario resultado;
    resultado = container->buscarUsuario( identificador );

	if ( ( resultado.getValor() == Resultado::SUCESSO ) &&
	 (resultado.getUsuario().getSenha().getSenha() == senha.getSenha() ) )
	{
        return true;
	}

    return false;
}
