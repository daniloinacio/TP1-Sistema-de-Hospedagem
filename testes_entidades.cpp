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
    IDENTIFICADOR_VALIDO.setIdentificador( ID );
    acomodacaoTeste->setIdentificador( IDENTIFICADOR_VALIDO );
    if( acomodacaoTeste->getIdentificador().getIdentificador() != IDENTIFICADOR_VALIDO.getIdentificador() )
    {
        estado = FALHA;
    }
    TIPO_VALIDO.setTpAcomodacao( TIPO );
    acomodacaoTeste->setTipo( TIPO_VALIDO );
    if( acomodacaoTeste->getTipo().getTpAcomodacao() != TIPO_VALIDO.getTpAcomodacao() )
    {
        estado = FALHA;
    }
    CAPACIDADE_VALIDA.setCapAcomodacao( CAP_ACOMODACAO );
    acomodacaoTeste->setCapacidade( CAPACIDADE_VALIDA );
    if( acomodacaoTeste->getCapacidade().getCapAcomodacao() != CAPACIDADE_VALIDA.getCapAcomodacao() )
    {
        estado = FALHA;
    }
    DATA_INICIO_VALIDA.setData( DATA );
    acomodacaoTeste->setDataInicio( DATA_INICIO_VALIDA );
    if( acomodacaoTeste->getDataInicio().getData() != DATA_INICIO_VALIDA.getData() )
    {
        estado = FALHA;
    }
    DATA_TERMINO_VALIDA.setData( DATA );
    acomodacaoTeste->setDataTermino( DATA_TERMINO_VALIDA );
    if( acomodacaoTeste->getDataTermino().getData() != DATA_TERMINO_VALIDA.getData() )
    {
        estado = FALHA;
    }
    CIDADE_VALIDA.setNome( NOME );
    acomodacaoTeste->setCidade( CIDADE_VALIDA );
    if( acomodacaoTeste->getCidade().getNome() != CIDADE_VALIDA.getNome() )
    {
        estado = FALHA;
    }
    ESTADO_VALIDO.setEstado( ESTADO );
    acomodacaoTeste->setEstado( ESTADO_VALIDO );
    if( acomodacaoTeste->getEstado().getEstado() != ESTADO_VALIDO.getEstado() )
    {
        estado = FALHA;
    }
    DIARIA_VALIDA.setDiaria( DIARIA );
    acomodacaoTeste->setDiaria( DIARIA_VALIDA );
    if( acomodacaoTeste->getDiaria().getDiaria() != DIARIA_VALIDA.getDiaria() )
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
    NUMERO_VALIDO.setNumContaCorr( NUMERO_CONTA_CORR );
    contaCorrenteTeste->setNumero( NUMERO_VALIDO );
    if( contaCorrenteTeste->getNumero().getNumContaCorr() != NUMERO_VALIDO.getNumContaCorr() )
    {
        estado = FALHA;
    }
    AGENCIA_VALIDA.setAgencia( NUMERO_AGENCIA );
    contaCorrenteTeste->setAgencia( AGENCIA_VALIDA );
    if( contaCorrenteTeste->getAgencia().getAgencia() != AGENCIA_VALIDA.getAgencia() )
    {
        estado = FALHA;
    }
    BANCO_VALIDO.setBanco( NUMERO_BANCO );
    contaCorrenteTeste->setBanco( BANCO_VALIDO );
    if( contaCorrenteTeste->getBanco().getBanco() != BANCO_VALIDO.getBanco() )
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