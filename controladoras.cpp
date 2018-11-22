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

bool CntrMAUsuario::cadastrarUsuario( Identificador *identificador )
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
        identificador->setIdentificador( idTemp.getIdentificador() );
        novoUsuario.setIdentificador( idTemp );
        novoUsuario.setSenha( senhaTemp );
        novoUsuario.setNome( nomeTemp );
        resultadoOperacao = cntrMSUsuario->incluirUsuario(novoUsuario);
        cout << "Operacao bem sucedida." << endl;
    }
    return resultadoOperacao;
}

bool CntrMAUsuario::descadastrarUsuario( Identificador *idUsuario )
{
    resultadoOperacao = cntrMSUsuario->removerUsuario( *idUsuario );
    if( resultadoOperacao == false )
    {
        cout << "Nao foi possivel realizar o descadastro." << endl;
        return false;
    }
    else
    {
        cout << "Descadastramento realizado com sucesso." << endl;
        return true;
    }
}

bool CntrMAUsuario::cadastrarConta( Identificador *idUsuario)
{
    cout << "Insira a agencia:" << endl;
    cin >> agenciaStr;
    cout << "Insira o banco:" << endl;
    cin >> bancoStr;
    cout << "Insira o numero da conta:" << endl;
    cin >> numContaStr;

    try
    {
        agenciaTemp.setAgencia(agenciaStr);
        bancoTemp.setBanco(bancoStr);
        contaTemp.setNumContaCorr(numContaStr);
    }
    catch( invalid_argument excecao )
    {
        cout << "Agencia, banco ou numero da conta em formato invalido" << endl;
        return false;
    }

    novaConta.setAgencia(agenciaTemp);
    novaConta.setBanco(bancoTemp);
    novaConta.setNumero(contaTemp);
    novaConta.setIdUsuario(*idUsuario);

    resultadoOperacao = cntrMSUsuario->incluirConta( novaConta );

    if( resultadoOperacao == true )
    {
        cout << "Cadastro de conta realizado com sucesso" << endl;
        return true;
    }
    else
    {
        cout << "Nao foi possivel realizar o cadastro da conta" << endl;
        return false;
    }
}

bool CntrMAUsuario::cadastrarCartao( Identificador *idUsuario )
{
    cout << "Insira o numero do cartao:" << endl;
    cin >> numCartStr;
    cout << "Insira a data de validade:" << endl;
    cin >> valiCartStr;

    try
    {
        valiTemp.setDataValidade(valiCartStr);
        numCartTemp.setNumCartaoCred(numCartStr);
    }
    catch( invalid_argument excecao )
    {
        cout << "Numero ou validade do cartao em formato invalido." << endl;
        return false;
    }

    novoCartao.setIdUsuario( *idUsuario );
    novoCartao.setNumero( numCartTemp );
    novoCartao.setValidade( valiTemp );

    resultadoOperacao = cntrMSUsuario->incluirCartao( novoCartao );

    if( resultadoOperacao == true )
    {
        cout << "Cadastro realizado com sucesso." << endl;
        return true;
    }
    else
    {
        cout << "Nao foi possivel terminar o cadastro." << endl;
        return false;
    }
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

bool CntrMSUsuario::incluirConta(const ContaCorrente &novaConta)
{
    ResultadoConta resultado;
    resultado = container->incluirConta( novaConta );
    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::incluirCartao(const CartaoCredito &novoCartao)
{
    ResultadoCartao resultado;
    resultado = container->incluirCartao( novoCartao );
    if(resultado.getValor() == Resultado::SUCESSO)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::removerUsuario(const Identificador &idUsuario)
{
    ResultadoUsuario resultadoUsuario;
    ResultadoAcomodacao resultadoAcomodacao;
    ResultadoReserva resultadoReserva;

    resultadoAcomodacao = containerAcomodacoes->buscarAcomodacao( idUsuario );
    resultadoReserva = containerAcomodacoes->buscarReservaUsuario( idUsuario );

    if( (resultadoAcomodacao.getAcomodacoes().empty() == true) && (resultadoReserva.getReservas().empty() == true) )
    {
        resultadoUsuario = container->removerUsuario( idUsuario );
        container->removerCartao( idUsuario );
        container->removerConta( idUsuario );
        if( resultadoUsuario.getValor() == Resultado::SUCESSO)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool CntrMAUsuario::iniciarMenuUsuario(Identificador *idUsuario)
{
    int opcao = -1;
    int resultado = false;

    cout << endl << "Menu do usuario." << endl << endl;
    cout << "Descadastrar usuario     - " << DESCADASTRAR << endl;
    cout << "Cadastrar cartao         - " << CADASTRAR_CARTAO << endl;
    cout << "Cadastrar conta corrente - " << CADASTRAR_CONTA << endl;
    cout << "Sair                     - " << SAIR << endl;

    do
    {
        cout << "Selecione uma opcao: ";
        cin >> opcao;
    } while( opcao < DESCADASTRAR || opcao > SAIR );

    switch( opcao )
    {
    case DESCADASTRAR:
        resultado = descadastrarUsuario( idUsuario );
        break;

    case CADASTRAR_CARTAO:
        resultado = cadastrarCartao( idUsuario );
        break;

    case CADASTRAR_CONTA:
        resultado = cadastrarConta( idUsuario );
        break;
    }

    return resultado;
}
