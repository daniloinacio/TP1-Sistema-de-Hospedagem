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

void CapAcomodacao::validar( int valor ) throw ( invalid_argument )
{
    if ( valor < MIN_VALOR || valor > MAX_VALOR)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
}
