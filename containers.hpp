#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <list>

class ContainerAcomodacao
{
private:
    list<Acomodacao> containerAcomodacoes;
    list<Reserva> containerReservas;
    list<Disponibilidade> containerDisponibilidades;
public:
    ResultadoAcomodacao incluirAcomodacao( Acomodacao acomodacao );
    ResultadoAcomodacao removerAcomodacao( Identificador idAcomodacao );
    /* Parametro da busca ainda pode mudar */
    ResultadoAcomodacao buscarAcomodacao( Identificador idAcomodacao );
    ResultadoDisponib incluirDisponib( Disponibilidade disponibilidade );
    ResultadoDisponib removerDisponib( Disponibilidade disponibilidade );
    ResultadoDisponib buscarDisponib( Identificador idAcomodacao );
    ResultadoReserva incluirReserva( Reserva reserva );
    ResultadoReserva removerReserva( Reserva reserva );
    ResultadoReserva buscarReservaAcomodacao( Identificador idAcomodacao );
    ResultadoReserva buscarReservaUsuario( Identificador idUsuario );
};

class ContainerUsuario
{
private:
    list<Usuario> containerUsuarios;
    list<ContaCorrente> containerContas;
    list<CartaoCredito> containerCartoes;
public:
    ResultadoUsuario incluirUsuario( Usuario usuario );
    ResultadoUsuario removerUsuario( Identificador idUsuario );
    ResultadoUsuario buscarUsuario( Identificador idUsuario );
    ResultadoConta incluirConta( ContaCorrente conta );
    ResultadoConta removerConta( Identificador idUsuario );
    ResultadoConta buscarConta( Identificador idUsuario );
    ResultadoCartao incluirCartao( CartaoCredito cartao );
    ResultadoCartao removerCartao( Identificador idUsuario );
    ResultadoCartao buscarCartao( Identificador idUsuario );
};

#endif // CONTAINERS_HPP_INCLUDED
