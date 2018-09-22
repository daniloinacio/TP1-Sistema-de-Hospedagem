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
        data->setData( DATA_INVALIDA );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

//Métodos de teste da classe DataValidade

void TUDataValidade::inicializar()
{
    estado = SUCESSO;
    dataValidade = new DataValidade();
}

void TUDataValidade::finalizar()
{
    delete dataValidade;
}

int TUDataValidade::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUDataValidade::testarCenarioSucesso()
{
    try
    {
         dataValidade->setDataValidade(DATA_VALIDA);
         if( dataValidade->getDataValidade() != DATA_VALIDA )
         {
             estado = FALHA;
         }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}


void TUDataValidade::testarCenarioFalha()
{
    try
    {
        dataValidade->setDataValidade( DATA_INVALIDA );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

//Métodos de teste da classe DataValidade

void TUNumCartaoCred::inicializar()
{
    estado = SUCESSO;
    numCartaoCred = new NumCartaoCred();
}

void TUNumCartaoCred::finalizar()
{
    delete numCartaoCred;
}

int TUNumCartaoCred::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUNumCartaoCred::testarCenarioSucesso()
{
    try
    {
         numCartaoCred->setNumCartaoCred(NUMERO_VALIDO);
         if( numCartaoCred->getNumCartaoCred() != NUMERO_VALIDO )
         {
             estado = FALHA;
         }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}


void TUNumCartaoCred::testarCenarioFalha()
{
    try
    {
        numCartaoCred->setNumCartaoCred( NUMERO_INVALIDO );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

// Testes para a classe Senha
void TUSenha::inicializar()
{
    estado = SUCESSO;
    SenhaTeste = new Senha();
}

void TUSenha::finalizar()
{
    delete SenhaTeste;
}

void TUSenha::testarCenarioSucesso()
{
    try
    {
        SenhaTeste->setSenha(SenhaValida);
        if (SenhaTeste->getSenha() != SenhaValida)
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha()
{
    try
    {
        SenhaTeste->setSenha(SenhaInvalida);
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

int TUSenha::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}


// Testes para a classe Estado
void TUEstado::inicializar()
{
    EstadoTeste = new Estado();
    estado = SUCESSO;
}

void TUEstado::finalizar()
{
    delete EstadoTeste;
}

void TUEstado::testarCenarioSucesso()
{
    try
    {
        EstadoTeste->setEstado(EstadoValido);
        if (EstadoTeste->getEstado() != EstadoValido)
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUEstado::testarCenarioFalha()
{
    try
    {
        EstadoTeste->setEstado(EstadoInvalido);
        estado = FALHA;
    }
    catch ( invalid_argument excecao )
    {
        return;
    }
}

int TUEstado::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

// Testes para a classe Identificador
void TUIdentificador::inicializar()
{
    IdentificadorTeste = new Identificador();
    estado = SUCESSO;
}

void TUIdentificador::finalizar()
{
    delete IdentificadorTeste;
}


void TUIdentificador::testarCenarioSucesso()
{
    try
    {
        IdentificadorTeste->setIdentificador(IdValido);
        if (IdentificadorTeste->getIdentificador() != IdValido)
        {
            estado = FALHA;
        }
    }
    catch ( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUIdentificador::testarCenarioFalha()
{
    try
    {
        IdentificadorTeste->setIdentificador(IdInvalido);
        estado = FALHA;
    }
    catch ( invalid_argument excecao )
    {
        return;
    }
}

int TUIdentificador::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

// Testes para a classe TpAcomodacao
void TUTpAcomodacao::inicializar()
{
    TpTeste = new TpAcomodacao();
    estado = SUCESSO;
}

void TUTpAcomodacao::finalizar()
{
    delete TpTeste;
}

void TUTpAcomodacao::testarCenarioSucesso()
{
    try
    {
        TpTeste->setTpAcomodacao(TipoValido);
        if (TpTeste->getTpAcomodacao() != TipoValido)
        {
            estado = FALHA;
        }
    }
    catch ( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUTpAcomodacao::testarCenarioFalha()
{
    try
    {
        TpTeste->setTpAcomodacao(TipoInvalido);
        estado = FALHA;
    }
    catch (invalid_argument excecao)
    {
        return;
    }
}

int TUTpAcomodacao::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

//Métodos de teste da classe Diaria

void TUDiaria::inicializar()
{
    estado = SUCESSO;
    diaria = new Diaria();
}

void TUDiaria::finalizar()
{
    delete diaria;
}

int TUDiaria::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUDiaria::testarCenarioSucesso()
{
    try
    {
         diaria->setDiaria(DIARIA_VALIDA);
         if( diaria->getDiaria() != DIARIA_VALIDA )
         {
             estado = FALHA;
         }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUDiaria::testarCenarioFalha()
{
    try
    {
        diaria->setDiaria( DIARIA_INVALIDA );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

//Métodos de teste da classe NumContaCorr

void TUNumContaCorr::inicializar()
{
    estado = SUCESSO;
    numContaCorr = new NumContaCorr();
}

void TUNumContaCorr::finalizar()
{
    delete numContaCorr;
}

int TUNumContaCorr::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUNumContaCorr::testarCenarioSucesso()
{
    try
    {
        numContaCorr->setNumContaCorr(NUMERO_VALIDO);
        if( numContaCorr->getNumContaCorr() != NUMERO_VALIDO )
        {
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUNumContaCorr::testarCenarioFalha()
{
    try
    {
        numContaCorr->setNumContaCorr( NUMERO_INVALIDO );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}

//Métodos de teste da classe Nome

void TUNome::inicializar()
{
    estado = SUCESSO;
    nome = new Nome();
}

void TUNome::finalizar()
{
    delete nome;
}

int TUNome::rodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}

void TUNome::testarCenarioSucesso()
{
    try
    {
        nome->setNome(NOME_VALIDO);
        if( nome->getNome() != NOME_VALIDO )
        {
            
            estado = FALHA;
        }
    }
    catch( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha()
{
    try
    {
        nome->setNome( NOME_INVALIDO );
        estado = FALHA;
    }
    catch( invalid_argument excecao )
    {
        return;
    }
}