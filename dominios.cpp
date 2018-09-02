#include "dominios.hpp"

void Agencia::validar( string numero ) throw ( invalid_argument )
{
    if ( numero.size() != TAM)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i=0; i < TAM; i++)
    {
        if ( numero[i] < LIMITE_INF || numero[i] > LIMITE_SUP )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
}

void Banco::validar( string numero ) throw ( invalid_argument )
{
        if ( numero.size() != TAM)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i=0; i < TAM; i++)
    {
        if ( numero[i] < LIMITE_INF || numero[i] > LIMITE_SUP )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
}

void CapAcomodacao::validar( int quantidade )
{
    if ( quantidade < LIMITE_INF || quantidade > LIMITE_SUP)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
}
