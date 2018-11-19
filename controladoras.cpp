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

bool CntrMAUsuario::cadastrarUsuario(Nome nome, Identificador id, Senha senha)
{
    cout << "Insira o nome do usuario:" << endl;
    cin >> nomeStr;
    cout << "Insira o identificador do usuario:" << endl;
    cin >> identificadorStr;
    cout << "Insira a senha do usuario:" << endl;
    cin >> senhaStr;

    try
    {
        idTemp.setIdentificador( identificadorStr );
        nomeTemp.setNome( nomeStr );
        senhaTemp.setSenha( senhaStr );
    }
    catch( invalid_argument excecao )
    {
        cout << "Identificador, nome ou senha em formato errado." << endl;
        return false;
    }

    resultadoOperacao = cntrMSUsuario->validarUsuario(idTemp, senhaTemp);
    if( resultadoOperacao == false )
    {
        cout << "Erro, usuario ja existe." << endl;
    }
    else
    {
        novoUsuario.setIdentificador( idTemp );
        novoUsuario.setSenha( senhaTemp );
        novoUsuario.setNome( nomeTemp );
        cntrMSUsuario->incluirUsuario(novoUsuario);
        cout << "Operacao bem sucedida." << endl;
    }
    return resultadoOperacao;
}

bool CntrMSUsuario::autenticar( const Identificador &identificador, const Senha &senha)
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

bool CntrMSUsuario::validarUsuario( const Identificador &identificador, const Senha &senha )
{
    ResultadoUsuario resultado;
    resultado = container->buscarUsuario( identificador );

    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return false;
    }

    return true;
}

bool CntrMSUsuario::incluirUsuario(const Usuario &novoUsuario)
{
    ResultadoUsuario resultado;
    resultado = container->incluirUsuario( novoUsuario );

    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return true;
    }
    else
    {
        return false;
    }
}
