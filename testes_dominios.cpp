#include "testes_dominios.hpp"

// Métodos de teste da classe Agência
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

// Métodos de teste da classe Banco
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

// Métodos de teste da classe CapAcomodacao
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

//Métodos de teste da classe Data

void TUData::inicializar()
{
    estado = SUCESSO;
    data = new Data();
}

void TUData::finalizar()
{
    delete data;
}

int TUData::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUData::testarCenarioSucesso()
{
    try
    {
         data->setData(DATA_VALIDA);
         if( data->getData() != DATA_VALIDA )
         {
             estado = FALHA;
         }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}


void TUData::testarCenarioFalha()
{
    try
    {
        capacidade->setCapAcomodacao( DATA_INVALIDA );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}
