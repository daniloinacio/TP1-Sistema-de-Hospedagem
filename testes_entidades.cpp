#include "testes_entidades.hpp"

// Testes da classe de Cartão de crédito
void TUCartaoCred::inicializar()
{
    CartaoTeste = new CartaoCredito();
    estado = SUCESSO;
}
void TUCartaoCred::finalizar()
{
    delete CartaoTeste;
}

void TUCartaoCred::testarCenarioSucesso()
{
    try
    {
        CartaoTeste->setNumero(NumValido);
        CartaoTeste->setValidade(DataValida);

        if ( CartaoTeste->getNumero() != NumValido )
        {
            estado = FALHA;
        }

        if ( CartaoTeste->getValidade() != DataValida )
        {
            estado = FALHA;
        }
    }
    catch ( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

int TUCartaoCred::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();

    finalizar();

    return estado;
}

// Testes da classe Usuário
void TUUsuario::inicializar()
{
    UsuarioTeste = new Usuario();
    estado = SUCESSO;
}

void TUUsuario::finalizar()
{
    delete UsuarioTeste;
}


void TUUsuario::testarCenarioSucesso()
{
    try
    {
        UsuarioTeste->setNome(NomeValido);
        if ( UsuarioTeste->getNome() != NomeValido )
        {
            estado = FALHA;
        }

        UsuarioTeste->setIdentificador(Idvalido);
        if ( UsuarioTeste->getIdentificador() != Idvalido )
        {
            estado = FALHA;
        }

        UsuarioTeste->setSenha(SenhaValida);
        if ( UsuarioTeste->getSenha() != SenhaValida )
        {
            estado = FALHA;
        }
    }
    catch ( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

int TUUsuario::RodarTestes()
{
    inicializar();
    testarCenarioSucesso();
    finalizar();

    return estado;
}

//Testes da classe Acomodacao

void TUAcomodacao::inicializar()
{
    acomodacaoTeste = new Acomodacao();
    estado = SUCESSO;
}

void TUAcomodacao::finalizar()
{
    delete acomodacaoTeste;
}


void TUAcomodacao::testarCenarioSucesso()
{
    acomodacaoTeste->setIdentificador( IDENTIFICADOR_VALIDO );
    if( acomodacaoTeste->getIdentificador() != IDENTIFICADOR_VALIDO )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setTipo( TIPO_VALIDO );
    if( acomodacaoTeste->getTipo() != TIPO_VALIDO )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setCapacidade( CAPACIDADE_VALIDA );
    if( acomodacaoTeste->getCapacidade() != CAPACIDADE_VALIDA )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setDataInicio( DATA_INICIO_VALIDA );
    if( acomodacaoTeste->getDataInicio() != DATA_INICIO_VALIDA )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setDataTermino( DATA_TERMINO_VALIDA );
    if( acomodacaoTeste->getDataTermino() != DATA_TERMINO_VALIDA )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setCidade( CIDADE_VALIDA );
    if( acomodacaoTeste->getCidade() != CIDADE_VALIDA )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setEstado( ESTADO_VALIDO );
    if( acomodacaoTeste->getEstado() != ESTADO_VALIDO )
    {
        estado = FALHA;
    }
    acomodacaoTeste->setDiaria( DIARIA_VALIDA );
    if( acomodacaoTeste->getDiaria() != DIARIA_VALIDA )
    {
        estado = FALHA;
    }       
}

int TUAcomodacao::RodarTestes()
{
    inicializar();
    testarCenarioSucesso();
    finalizar();

    return estado;
}

//Testes da classe ContaCorrente

void TUContaCorrente::inicializar()
{
    contaCorrenteTeste = new ContaCorrente();
    estado = SUCESSO;
}

void TUContaCorrente::finalizar()
{
    delete contaCorrenteTeste;
}


void TUContaCorrente::testarCenarioSucesso()
{
    contaCorrenteTeste->setNumero( NUMERO_VALIDO );
    if( contaCorrenteTeste->getNumero() != NUMERO_VALIDO )
    {
        estado = FALHA;
    }
    contaCorrenteTeste->setAgencia( AGENCIA_VALIDA );
    if( contaCorrenteTeste->getAgencia() != AGENCIA_VALIDA )
    {
        estado = FALHA;
    }
    contaCorrenteTeste->setBanco( BANCO_VALIDO );
    if( contaCorrenteTeste->getBanco() != BANCO_VALIDO )
    {
        estado = FALHA;
    }     
}

int TUContaCorrente::RodarTestes()
{
    inicializar();
    testarCenarioSucesso();
    finalizar();

    return estado;
}