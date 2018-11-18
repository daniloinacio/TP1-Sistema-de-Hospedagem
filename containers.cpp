#include "containers.hpp"

bool ContainerAcomodacao::incluirAcomodacao( Acomodacao acomodacao )
{
    string identificador = acomodacao.getIdentificador().getIdentificador();
    list<Acomodacao>::iterator elemento;

    for( elemento = containerAcomodacoes.begin(); elemento != containerAcomodacoes.end(); elemento++ )
    {
        if( elemento->getIdentificador().getIdentificador() == identificador )
        {
            return false;
        }
    }

    containerAcomodacoes.push_back(acomodacao);
    return true;
}

bool ContainerUsuario::incluirUsuario( Usuario usuario )
{
    string identificador = usuario.getIdentificador().getIdentificador();
    list<Usuario>::iterator elemento;

    for ( elemento = containerUsuarios.begin(); elemento != containerUsuarios.end(); elemento++ )
    {
        if ( elemento->getIdentificador().getIdentificador() == identificador )
        {
            return false;
        }
    }

    containerUsuarios.push_back( usuario );
    return true;
}

bool ContainerUsuario::incluitConta( ContaCorrente conta )
{
    string numero = conta.getNumero().getNumContaCorr();
    list<ContaCorrente>::iterator elemento;

    for ( elemento = containerContas.begin(); elemento != containerContas.end(); elemento++ )
    {
        if ( elemento->getNumero().getNumContaCorr() == numero )
        {
            return false;
        }
    }

    containerContas.push_back( conta );
    return true;
}

bool ContainerUsuario::incluirCartao( CartaoCredito cartao )
{
    string numero = cartao.getNumero().getNumCartaoCred();
    list<CartaoCredito>::iterator elemento;

    for ( elemento = containerCartoes.begin(); elemento != containerCartoes.end(); elemento++ )
    {
        if ( elemento->getNumero().getNumCartaoCred() == numero )
        {
            return false;
        }
    }

    containerCartoes.push_back( cartao );
    return true;
}

ResultadoUsuario ContainerUsuario::buscarUsuario( Identificador idUsuario )
{
    ResultadoUsuario resultado;
    string identificador = idUsuario.getIdentificador();
    list<Usuario>::iterator elemento;

    for ( elemento = containerUsuarios.begin(); elemento != containerUsuarios.end(); elemento++ )
    {
        if ( elemento->getIdentificador().getIdentificador() == identificador )
        {
            resultado.setUsuario( *elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }

    resultado.setValor( Resultado::FALHA );
    return resultado;
}

