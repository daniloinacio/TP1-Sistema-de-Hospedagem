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
