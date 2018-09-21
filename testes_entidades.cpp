#include "testes_entidades.hpp"

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
        CartaoTeste->setCartaoCredito(NumValido, DataValida);
    }
    catch ( invalid_argument excecao )
    {
        estado = FALHA;
    }
}

void TUCartaoCred::testarCenarioFalha()
{
    try
    {
        CartaoTeste->setCartaoCredito(NumInvalido, DataInvalida);
        estado = FALHA;
    }
    catch ( invalid_argument excecao )
    {
        return;
    }
}

int TUCartaoCred::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();
    testarCenarioFalha();

    finalizar();

    return estado;
}
