#include "dominios.hpp"

void Agencia::validar( string agencia ) throw ( invalid_argument )
{
    if ( agencia.size() != TAM )
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i=0; i < TAM; i++ )
    {
        if ( agencia[i] < LIMITE_INF || agencia[i] > LIMITE_SUP )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
}

void Agencia::setAgencia( string agencia ) throw ( invalid_argument )
{
    validar( agencia );
    this->agencia = agencia;
}

void Banco::validar( string banco ) throw ( invalid_argument )
{
        if ( banco.size() != TAM)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i=0; i < TAM; i++)
    {
        if ( banco[i] < LIMITE_INF || banco[i] > LIMITE_SUP )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
}

void Banco::setBanco( string banco ) throw ( invalid_argument )
{
    validar( banco );
    this->banco = banco;
}

void CapAcomodacao::validar( int capAcomodacao ) throw ( invalid_argument )
{
    if ( capAcomodacao < MIN_VALOR || capAcomodacao > MAX_VALOR)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
}

void CapAcomodacao::setCapAcomodacao( int capAcomodacao ) throw ( invalid_argument ){
    validar( capAcomodacao );
    this->capAcomodacao = capAcomodacao;
}
