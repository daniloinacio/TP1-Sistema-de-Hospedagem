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

    // Algoritimo de Luhn para verificar se o número é válido
    int nDigits = numCartaoCred.length(); 
    int nSum = 0; 
    bool isSecond = false; 
    for (int i = nDigits - 1; i >= 0; i--) { 
  
        int d = numCartaoCred[i] - 'a'; 
  
        if (isSecond == true)
        {
            d = d * 2; 
        }

        nSum += d / 10; 
        nSum += d % 10; 
  
        isSecond = !isSecond; 
    } 

    if (nSum % 10 != 0)
    {
        throw invalid_argument{ "Argumento Invalido."};
    }

}

void NumCartaoCred::setNumCartaoCred( string numCartaoCred ) throw ( invalid_argument )
{
    validar( numCartaoCred );
    this->numCartaoCred = numCartaoCred;
}

void Senha::validar( string senha ) throw ( invalid_argument )
{
    int i;

    // Se o tamanho nao for permitido nao precisa verificar o resto
    if (senha.size() != TamanhoMaximo)
    {
        throw invalid_argument( "Senha invalida." );
    }

    // Verificando letra a letra
    for (i = 0; i < TamanhoMaximo; i++)
    {
        if (senha[i] >= 'A' && senha[i] <= 'Z')
        {
            continue;
        }
        else if (senha[i] >= 'a' && senha[i] <= 'z')
        {
            continue;
        }
        else if (senha[i] >= '#' && senha[i] <= '&') // sequencia ascii: # $ % &
        {
            continue;
        }
        else if (senha[i] == '!')
        {
            continue;
        }
        else if (senha[i] >= '0' && senha[i] <= '9')
        {
            continue;
        }
        else
        {
            throw invalid_argument ( "Senha invalida." );
        }
    }
}

void Senha::setSenha(string senha) throw ( invalid_argument )
{
    validar(senha);
    this->senha = senha;
}

void Estado::validar(string estado) throw ( invalid_argument )
{
    int i;
    for (i = 0; i < NumEstados; i++)
    {
        if ( estado == LSTEstados[i] )
        {
            return;
        }
    }

    throw invalid_argument ( "Estado invalido" );
}

void Estado::setEstado(string estado) throw ( invalid_argument )
{
    validar(estado);
    this->estado = estado;
}

void Identificador::validar(string identificador) throw ( invalid_argument )
{
    int i;

    if (identificador.size() != tamanho)
    {
        throw invalid_argument ( "Identificador invalido" );
    }

    for(i = 0; i < tamanho; i++)
    {
        if(identificador[i] < 'a' || identificador[i] > 'z')
        {
            throw invalid_argument ( "Identificador invalido" );
        }
    }
}

void Identificador::setIdentificador( string identificador ) throw ( invalid_argument )
{
    validar(identificador);
    this->identificador = identificador;
}


void TpAcomodacao::validar(string tpAcomodacao) throw ( invalid_argument )
{
    int i;
    for (i = 0; i < qtdTipos; i++)
    {
        if ( tpAcomodacao == LstTipos[i] )
        {
            return;
        }
    }
    throw invalid_argument ( "Tipo de acomodacao invalido" );
}

void TpAcomodacao::setTpAcomodacao( string tpAcomodacao ) throw ( invalid_argument )
{
    validar(tpAcomodacao);
    this->tpAcomodacao = tpAcomodacao;
}

void Diaria::validar( float diaria ) throw ( invalid_argument )
{
    if ( diaria < DIARIA_MIN || diaria > DIARIA_MAX )
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
}

void Diaria::setDiaria( float diaria ) throw ( invalid_argument )
{
    validar(diaria);
    this->diaria = diaria;
}

void NumContaCorr::validar( string numContaCorr ) throw ( invalid_argument )
{
    if ( numContaCorr.size() != TAMANHO_NUMERO )
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i = 0; i < TAMANHO_NUMERO; i++ )
    {
        if ( numContaCorr[i] < LIMITE_INF || numContaCorr[i] > LIMITE_SUP )
        {
            throw invalid_argument{ "Argumento Invalido." };
        }
    }
}

void NumContaCorr::setNumContaCorr( string numContaCorr ) throw ( invalid_argument )
{
    validar( numContaCorr );
    this->numContaCorr = numContaCorr;
}

void Nome::validar( string nome ) throw ( invalid_argument )
{
    letra = false;
    if ( nome.size() < TAMANHO_NOME_MIN || nome.size() > TAMANHO_NOME_MAX )
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
    for ( int i = 0; i < nome.size(); i++ ){
        //caracter diferente de letra, ponto e espaço
        if ( ( nome[i] < MIN_LETRA_MAIUSCULA || ( nome[i] > MAX_LETRA_MAIUSCULA && nome[i] < MIN_LETRA_MINUSCULA ) || 
            nome[i] > MAX_LETRA_MINUSCULA ) && nome[i] != PONTO && nome[i] != ESPACO )
        {
                throw invalid_argument{ "Argumento Invalido." };
        }
        //verifica se é uma letra
        if ((nome[i] >= MIN_LETRA_MAIUSCULA && nome[i] <= MAX_LETRA_MAIUSCULA) || (nome[i] >= MIN_LETRA_MINUSCULA && 
            nome[i]<= MAX_LETRA_MINUSCULA))
        {
            letra = true;
        }
        // ponto não precedido por letra
        if ( ( nome[i] == PONTO && i == 0 ) || ( nome[i] == PONTO && ( nome[i-1] < MIN_LETRA_MAIUSCULA || 
            ( nome[i-1] > MAX_LETRA_MAIUSCULA && nome[i-1] < MIN_LETRA_MINUSCULA ) || nome[i-1] > MAX_LETRA_MINUSCULA ) ) )
        {
            throw invalid_argument{ "Argumento Invalido." };
        }
        // espaços seguidos
        if ( i > 0 && nome[i] == ESPACO && nome[i - 1] == ESPACO )
        {
            throw invalid_argument{ "Argumento Invalido." }; 
        }

    }
    //não tem pelo menos uma letra
    if ( letra == false )
    {
        throw invalid_argument{ "Argumento Invalido." };
    }
}

void Nome::setNome( string nome ) throw ( invalid_argument )
{
    
    validar( nome );
    this->nome = nome;
}