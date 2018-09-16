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
    if (ano < 2000 || ano > 2099)
    {
        throw invalid_argument{ "Argumeto Invalido." }; 
    }

    //verifica se é um mês válido e se o dia é valido
    //para esse mês
    if (mes == "jan" || mes == "mar" || mes == "mai" || mes == "ago" ||
     mes == "out" || mes == "dez")
    {
        if(dia < 1 || dia > 31)
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
    else if ( mes == "fev" )
    {
        if( dia < 1 || ( dia > 28 && bissexto == false ) ||
            ( dia > 29 && bissexto == true ) )
        {
            throw invalid_argument{ "Argumeto Invalido." }; 
        }

    }
    else if (mes == "abr" || mes == "jul" )
    {
        if(dia < 1 || dia > 29 )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
    else if (mes == "jun" || mes == "set" || mes == "nov" )
    {
        if(dia < 1 || dia > 30 )
        {
            throw invalid_argument{ "Argumeto Invalido." };
        }
    }
    else
    {
            throw invalid_argument{ "Argumeto Invalido." };        
    }
    
    cout << "dia: " << dia << " mes: " << mes << " ano: " << ano << endl;
}

void Data::setData( string data ) throw ( invalid_argument )
{
    validar( data );
    this->data = data;
}