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

bool ContainerUsuario::incluir_usuario(Usuario usuario)
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

bool ContainerUsuario::incluit_conta(ContaCorrente conta)
{
    string numero = conta.getNumero().getNumContaCorr();
    list<ContaCorrente>::iterator elemento;

    for(elemento = container_contas.begin(); elemento != container_contas.end(); elemento++)
    {
        if(elemento->getNumero().getNumContaCorr() == numero)
        {
            return false;
        }
    }

    container_contas.push_back(conta);
    return true;
}

bool ContainerUsuario::incluir_cartao(CartaoCredito cartao)
{
    string numero = cartao.getNumero().getNumCartaoCred();
    list<CartaoCredito>::iterator elemento;

    for(elemento = container_cartoes.begin(); elemento != container_cartoes.end(); elemento++)
    {
        if(elemento->getNumero().getNumCartaoCred() == numero)
        {
            return false;
        }
    }

    container_cartoes.push_back(cartao);
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
