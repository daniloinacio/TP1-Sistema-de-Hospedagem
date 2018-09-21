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

int TUCartaoCred::RodarTestes()
{
    inicializar();

    testarCenarioSucesso();

    finalizar();

    return estado;
}
