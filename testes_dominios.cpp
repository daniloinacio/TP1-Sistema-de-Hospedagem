#include "testes_dominios.hpp"

// Funções de teste da classe Agência
void TUAgencia::Inicializar()
{
    agencia_teste = new Agencia();
    estado = SUCESSO;
}

void TUAgencia::Finalizar()
{
    delete agencia_teste;
}

int TUAgencia::RodarTestes()
{
    Inicializar();

    TestarNumeroValido();

    TestarNumeroInvalido();

    Finalizar();

    return estado;
}

void TUAgencia::TestarNumeroValido()
{
    try
    {
        agencia_teste->setAgencia(numero_valido);
        if(agencia_teste->getAgencia()!= numero_valido)
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUAgencia::TestarNumeroInvalido()
{
    try
    {
        agencia_teste->setAgencia( numero_invalido );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

// Funções de teste da classe Banco
void TUBanco::Inicializar()
{
    estado = SUCESSO;
    banco_teste = new Banco();
}

void TUBanco::Finalizar()
{
    delete banco_teste;
}

int TUBanco::RodarTestes()
{
    Inicializar();
    Finalizar();

    return estado;
}

void TUBanco::TestarNumeroValido()
{
    try
    {
        banco_teste->setBanco(numero_valido);
        if( banco_teste->getBanco() != numero_valido )
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUBanco::TestarNumeroInvalido()
{
    try
    {
        banco_teste->setBanco( numero_invalido );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}
