#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <list>

class ContainerAcomodacao
{
private:
    list<Acomodacao> containerAcomodacoes;

public:
    bool incluirAcomodacao( Acomodacao acomodacao );
    bool removerAcomodacao( Identificador acomodacao );
    ResultadoAcomodacao buscar( Identificador acomodacao );
};

class ContainerUsuario
{
private:
    list<Usuario> containerUsuarios;
    list<ContaCorrente> containerContas;
    list<CartaoCredito> containerCartoes;
    Senha senhaNull;
public:
    bool incluirUsuario ( Usuario usuario );
    bool incluitConta ( ContaCorrente conta );
    bool incluirCartao ( CartaoCredito cartao );
    bool removerUsuario( Identificador idUsuario );
    ResultadoUsuario buscarUsuario( Identificador idUsuario );
   // Senha checarSenha( Identificador idUsuario );
};

#endif // CONTAINERS_HPP_INCLUDED
