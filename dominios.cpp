#include "dominios.hpp"
#include <string>
#include <iostream>

using namespace std;

void Agencia::validar( string agencia ) throw ( invalid_argument )
{
    if ( agencia.size() != TAMANHO_AGENCIA )
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i=0; i < TAMANHO_AGENCIA; i++ )
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
        if ( banco.size() != TAMANHO_BANCO)
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i=0; i < TAMANHO_BANCO; i++)
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
    if ( data.size() != TAMANHO_DATA ){
        throw invalid_argument{ "Argumeto Invalido." };
    }
    // extrai o dia o mes e o ano da string
    dia = atoi( data.substr( POSICAO_DIA, TAMANHO_DIA ).c_str( ) );
    ano = atoi( data.substr( POSICAO_ANO, TAMANHO_ANO ).c_str( ) );
    mes = data.substr( POSICAO_MES, TAMANHO_MES );

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

void DataValidade::validar( string dataValidade ) throw ( invalid_argument )
{
    if ( dataValidade.size() != TAMANHO_DATA_VALIDADE ){
        throw invalid_argument{ "Argumeto Invalido." };
    }
    // separa mes e ano e converte para valores inteiros
    mes = atoi( dataValidade.substr( POSICAO_MES, TAMANHO_MES ).c_str( ) );
    ano = atoi( dataValidade.substr( POSICAO_ANO, TAMANHO_ANO ).c_str( ) );

    if ( mes < MES_MIN || mes > MES_MAX )
    {
        throw invalid_argument{ "Argumento Invalido. "};
    }
    else if ( ano < ANO_MIN || ano > ANO_MAX )
    {
        throw invalid_argument{ "Argumento Invalido. "};   
    }
}

void DataValidade::setDataValidade( string dataValidade ) throw ( invalid_argument )
{
    validar( dataValidade );
    this->dataValidade = dataValidade;
}

void NumCartaoCred::validar( string numCartaoCred ) throw ( invalid_argument )
{   
    if ( numCartaoCred.size() != TAMANHO_NUMERO )
    {
        throw invalid_argument{ "Argumeto Invalido."};
    }

    for (int i = 0; i < TAMANHO_NUMERO; i++ )
    {
        if ( numCartaoCred[i] < LIMITE_INF || numCartaoCred[i] > LIMITE_SUP)
        {
            throw invalid_argument{ "Argumeto Invalido."};
        }
    }

    int nDigits = numCartaoCred.size();            //INCOMPLETO
    int shuma = 0;
    for (int i = 0; i < nDigits; i++)
    {
        int   digit = numCartaoCred[i] - '0';   // Char to number
        if  (i & 1)  // Digit 1, 3, 5 not 0, 2, 4 - "even digits" starting at 1
            if  ((digit <<= 1) >= 10) //  Double it, check >= 10
                digit -= 9;           //  Same as summing the digits
        shuma += digit;
    }
    if (shuma % 10 != 0)
    {
        throw invalid_argument{ "Argumento Invalido."};
    }

}

void NumCartaoCred::setNumCartaoCred( string numCartaoCred ) throw ( invalid_argument )
{
    validar( numCartaoCred );
    this->numCartaoCred = numCartaoCred;
}