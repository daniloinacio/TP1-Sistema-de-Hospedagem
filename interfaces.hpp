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
    virtual bool iniciarMenuUsuario( Identificador *identificador ) = 0;
    virtual bool cadastrarUsuario( Identificador *identificador ) = 0;
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
//    virtual bool AcomodacoesDisp() = 0;
    virtual bool cadastrarAcomodacao( const Acomodacao & ) = 0;
    virtual bool descadastrarAcomodacao( const Identificador &idUsuario, const Identificador &idAcomodacao ) = 0;
//    virtual bool cadastrarDisponibilidade( const Identificador &idUsuario, const Disponibilidade &disponibilidade ) = 0;
//    virtual bool descadastrarDisponibilidade( const Identificador &idUsuario, const Disponibilidade &disponibilidade) = 0;
//    virtual bool reservarAcomodacao( const Reserva &reserva ) = 0;
//    virtual bool cancelarReserva( const Reserva &reserva ) = 0;

};


#endif // INTERFACES_H_INCLUDED
