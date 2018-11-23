#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "containers.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

class CntrMASistema
{
private:
    IAUsuario *cntrMAUsuario;
    IAAcomodacao *cntrMAAcomodacao;
    IAAutenticacao *cntrMAAutenticacao;

    bool resultado;
    // Menu principal
    const static int CADASTRAR_USUARIO = 0;
    const static int FAZER_LOGIN = 1;
    const static int SAIR = 2;
    // Menu de login
    const static int MENU_ACOMODACAO = 0;
    const static int MENU_USUARIO = 1;

public:
    bool menuPrincipal( Identificador* );
    bool menuLogin( const Identificador & );
    void setCntrMAUsuario( IAUsuario *cntrMAUsuario );
    void setCntrMAAcomodacao( IAAcomodacao *cntrMAAcomodacao );
    void setCntrMAAutenticacao( IAAutenticacao *cntrMAAutenticacao );
};

void inline CntrMASistema::setCntrMAUsuario( IAUsuario *cntrMAUsuario )
{
    this->cntrMAUsuario = cntrMAUsuario;
}

void inline CntrMASistema::setCntrMAAcomodacao( IAAcomodacao *cntrMAAcomodacao )
{
    this->cntrMAAcomodacao = cntrMAAcomodacao;
}

void inline CntrMASistema::setCntrMAAutenticacao( IAAutenticacao *cntrMAAutenticacao )
{
    this->cntrMAAutenticacao = cntrMAAutenticacao;
}

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

	bool autenticar( Identificador* );
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

    // Variaveis Usuario
    string nomeStr;
    string identificadorStr;
    string senhaStr;
    Senha senhaTemp;
    Identificador idTemp;
    Nome nomeTemp;
    Usuario novoUsuario;

    // Variaveis conta
    string numContaStr;
    string agenciaStr;
    string bancoStr;
    NumContaCorr contaTemp;
    Agencia agenciaTemp;
    Banco bancoTemp;
    ContaCorrente novaConta;

    // Variaveis cartao
    string numCartStr;
    string valiCartStr;
    NumCartaoCred numCartTemp;
    DataValidade valiTemp;
    CartaoCredito novoCartao;

    // Menu do usuario
    const static int DESCADASTRAR = 1;
    const static int CADASTRAR_CARTAO = 2;
    const static int CADASTRAR_CONTA = 3;
    const static int SAIR = 4;

public:
    bool cadastrarUsuario();
    bool descadastrarUsuario( const Identificador & );
    bool cadastrarConta( const Identificador & );
    bool cadastrarCartao( const Identificador & );
    bool iniciarMenuUsuario( const Identificador & );
    void setCntrMSUsuario( ISUsuario *cntrMSUsuario );
};

void inline CntrMAUsuario::setCntrMSUsuario(ISUsuario *cntrMSUsuario)
{
    this->cntrMSUsuario = cntrMSUsuario;
}

class CntrMSUsuario : public ISAutenticacao, public ISUsuario
{
private:

	ContainerUsuario *containerUsuario;
	ContainerAcomodacao *containerAcomodacao;
	Senha senhaTemp;
	list<Usuario>::iterator usuario;

public:

	bool autenticar( const Identificador&, const Senha& );
	bool validarUsuario( const Identificador &, const Senha & );
	bool incluirUsuario( const Usuario & );
	bool removerUsuario( const Identificador & );
	bool incluirConta( const ContaCorrente & );
	bool incluirCartao( const CartaoCredito & );
	void setContainerUsuario( ContainerUsuario *container );
	void setContainerAcomodacao( ContainerAcomodacao *container );
};

void inline CntrMSUsuario::setContainerUsuario( ContainerUsuario *container )
{
	this->containerUsuario = container;
}
void inline CntrMSUsuario::setContainerAcomodacao( ContainerAcomodacao *container )
{
	this->containerAcomodacao = container;
}


class CntrMAAcomodacao : public IAAcomodacao
{
private:
	ISAcomodacao *cntrMSAcomodacao;
    const static int EXIBIR           = 1;
    const static int CADASTRAR        = 2;
    const static int DESCADASTRAR     = 3;
    const static int DISPONIBILIDADE  = 4;
    const static int FAZER_RESERVA    = 5;
    const static int CANCELAR_RESERVA = 6;
    const static int SAIR             = 7;
    const static int SIM			  = 1;
    const static int NAO              = 0;
    const static int SUCESSO          = 1;
    const static int FALHA            = 0;

    void exibirAcomodDisp( const Identificador &);
    void cadastrarAcomodacao( const Identificador &);
    void descadastrarAcomodacao( const Identificador&);
    void cadastrarDisponibilidade(const Identificador&);
    void fazerReserva(const Identificador&);
    void cancelarReserva(const Identificador&);
public:
    void setCntrMSAcomodacao( ISAcomodacao *cntrMSAcomodacao );
	void iniciarMenuAcomodacao( const Identificador & );
};

void inline CntrMAAcomodacao::setCntrMSAcomodacao( ISAcomodacao *cntrMSAcomodacao )
{
    this->cntrMSAcomodacao = cntrMSAcomodacao;
}

class CntrMSAcomodacao : public ISAcomodacao
{
private:
	ContainerAcomodacao *containerAcomodacao;
	ContainerUsuario *containerUsuario;
public:
	void setContainerAcomodacao( ContainerAcomodacao *container );
	void setContainerUsuario( ContainerUsuario *container );
    ResultadoAcomodacao AcomodacoesDisp( const Acomodacao &);
    bool cadastrarAcomodacao( const Acomodacao & );
    bool descadastrarAcomodacao( const Identificador &idUsuario, const Identificador &idAcomodacao );
    bool cadastrarDisponibilidade( const Identificador &idUsuario, Disponibilidade disponibilidade );
    bool verificarCartao(const Identificador&);
    bool verificarConta(const Identificador&);
    bool fazerReserva( Reserva reserva);
    bool cancelarReserva( Reserva reserva );
};

void inline CntrMSAcomodacao::setContainerAcomodacao( ContainerAcomodacao *containerAcomodacao )
{
	this->containerAcomodacao = containerAcomodacao;
}
void inline CntrMSAcomodacao::setContainerUsuario( ContainerUsuario *containerUsuario )
{
	this->containerUsuario = containerUsuario;
}
#endif // CONTROLADORAS_H_INCLUDED
