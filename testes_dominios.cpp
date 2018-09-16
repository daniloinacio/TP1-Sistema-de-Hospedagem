#include "testes_dominios.hpp"

// Funções de teste da classe Agência
void TUAgencia::inicializar()
{
    agenciaTeste = new Agencia();
    estado = SUCESSO;
}

void TUAgencia::finalizar()
{
    delete agenciaTeste;
}

int TUAgencia::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUAgencia::testarCenarioSucesso()
{
    try
    {
        agenciaTeste->setAgencia(AGENCIA_VALIDA);
        if(agenciaTeste->getAgencia()!= AGENCIA_VALIDA)
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUAgencia::testarCenarioFalha()
{
    try
    {
        agenciaTeste->setAgencia( AGENCIA_INVALIDA );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

// Funções de teste da classe Banco
void TUBanco::inicializar()
{
    estado = SUCESSO;
    bancoTeste = new Banco();
}

void TUBanco::finalizar()
{
    delete bancoTeste;
}

int TUBanco::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUBanco::testarCenarioSucesso()
{
    try
    {
        bancoTeste->setBanco(BANCO_VALIDO);
        if( bancoTeste->getBanco() != BANCO_VALIDO )
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUBanco::testarCenarioFalha()
{
    try
    {
        bancoTeste->setBanco( BANCO_INVALIDO );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

// Funções de teste da classe CapAcomodacao
void TUCapAcomodacao::inicializar()
{
    estado = SUCESSO;
    capacidade = new CapAcomodacao();
}

void TUCapAcomodacao::finalizar()
{
    delete capacidade;
}

int TUCapAcomodacao::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUCapAcomodacao::testarCenarioSucesso()
{
    try
    {
         capacidade->setCapAcomodacao(CAP_ACOMODACAO_VALIDA);
         if( capacidade->getCapAcomodacao() != CAP_ACOMODACAO_VALIDA )
         {
             estado = FALHA;
         }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}


void TUCapAcomodacao::testarCenarioFalha()
{
    try
    {
        capacidade->setCapAcomodacao( CAP_ACOMODACAO_INVALIDA );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}
