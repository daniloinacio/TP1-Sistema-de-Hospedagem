#include "containers.hpp"

bool ContainerAcomodacao::incluir(Acomodacao acomodacao)
{
    string identificador = acomodacao.getIdentificador().getIdentificador();
    list<Acomodacao>::iterator elemento;

    for(elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if(elemento->getIdentificador().getIdentificador() == identificador)
        {
            return false;
        }
    }

    container.push_back(acomodacao);
    return true;
}

bool ContainerUsuario::incluir(Usuario usuario)
{
    string identificador = usuario.getIdentificador().getIdentificador();
    list<Usuario>::iterator elemento;

    for(elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if(elemento->getIdentificador().getIdentificador() == identificador)
        {
            return false;
        }
    }

    container.push_back(usuario);
    return true;
}

bool ContainerUsuario::buscar(Identificador idUsuario)
{
    string identificador = idUsuario.getIdentificador();
    list<Usuario>::iterator elemento;

    for(elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if(elemento->getIdentificador().getIdentificador() == identificador)
        {
            return true;
        }
    }

    return false;
}
