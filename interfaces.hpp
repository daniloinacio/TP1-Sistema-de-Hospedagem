#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <stdexcept>

using namespace std;

class IAAutenticacao
{
public:
	virtual bool autenticar( Identificador* ) = 0;
};

class ISAutenticacao
{
public:
	virtual bool autenticar( const Identificador &, const Senha &) = 0;
};

class IAUsuario
{
public:
    virtual bool iniciarMenuUsuario( const Identificador & ) = 0;
    virtual bool cadastrarUsuario() = 0;
};

class ISUsuario
{
public:
    virtual bool validarUsuario( const Identificador &, const Senha & ) = 0;
    virtual bool incluirUsuario( const Usuario & ) = 0;
    virtual bool removerUsuario( const Identificador & ) = 0;
    virtual bool incluirConta(const ContaCorrente &novaConta) = 0;
    virtual bool incluirCartao( const CartaoCredito & ) = 0;
};

class IAAcomodacao
{
private:

public:
    virtual void iniciarMenuAcomodacao( const Identificador & ) = 0;
};

class ISAcomodacao
{
public:
    virtual ResultadoAcomodacao AcomodacoesDisp(const Acomodacao &) = 0;
    virtual bool cadastrarAcomodacao( const Acomodacao & ) = 0;
    virtual bool descadastrarAcomodacao( const Identificador &idUsuario, const Identificador &idAcomodacao ) = 0;
    virtual bool cadastrarDisponibilidade( const Identificador &idUsuario,  Disponibilidade disponibilidade ) = 0;
    virtual bool verificarCartao(const Identificador&) = 0;
    virtual bool verificarConta(const Identificador&) = 0;
    virtual bool fazerReserva( Reserva reserva) = 0;
    virtual bool cancelarReserva( Reserva reserva ) = 0;

};


#endif // INTERFACES_H_INCLUDED
