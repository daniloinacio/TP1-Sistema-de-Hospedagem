#include "dominios.hpp"
#include <string>
#include <iostream>

using namespace std;

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

void Data::validar( string data ) throw ( invalid_argument )
{
    // extrai o dia o mes e o ano da string
    dia = atoi(data.substr(0, 2).c_str());
    ano = atoi(data.substr(7, 4).c_str());
    mes = data.substr(3, 3);

    // verifica se é uma ano bissexto
    if ( ano % 400 == 0 || ( ano % 4 == 0 && ano % 100 != 0 ))
    {
        bissexto = true;
    }
    // verifica se é um ano válido
    if (ano < ANO_MIN || ano > ANO_MAX)
    {
        throw invalid_argument{ "Argumeto Invalido." }; 
    }

    //verifica se é um mês válido e se o dia é valido
    //para esse mês

    //meses de 31 dias
    if (mes == "jan" || mes == "mar" || mes == "mai" || mes == "ago" ||
     mes == "out" || mes == "dez")
    {
        if(dia < DIA_MIN || dia > DIA_MAX4)
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
    else if ( mes == "fev" )
    {
        if( dia < DIA_MIN || ( dia > DIA_MAX1 && bissexto == false ) ||
            ( dia > DIA_MAX2 && bissexto == true ) )
        {
            throw invalid_argument{ "Argumeto Invalido." }; 
        }

    }
    //meses de 29 dias
    else if (mes == "abr" || mes == "jul" )
    {
        if(dia < DIA_MIN || dia > DIA_MAX2 )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
    //meses de 30 dias
    else if (mes == "jun" || mes == "set" || mes == "nov" )
    {
        if(dia < DIA_MIN || dia > DIA_MAX3 )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
    else
    {
            throw invalid_argument{ "Argumeto Invalido." };        
    }

}

void Data::setData( string data ) throw ( invalid_argument )
{
    validar( data );
    this->data = data;
}