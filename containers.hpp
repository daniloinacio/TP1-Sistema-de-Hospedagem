#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <list>

class ContainerAcomodacao
{
private:
    list<Acomodacao> container;

public:
    bool incluir(Acomodacao acomodacao);
    bool remover(Identificador acomodacao);
};

class ContainerUsuario
{
private:
    list<Usuario> container;

public:
    bool incluir(Usuario usuario);
    bool remover(Identificador idUsuario);
    bool buscar(Identificador idUsuario);
};

#endif // CONTAINERS_HPP_INCLUDED
