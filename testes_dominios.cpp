#include "testes_dominios.hpp"

void TUAgencia::Inicializar()
{
    agencia_teste = new Agencia();
    estado = SUCESSO;
}

void TUAgencia::Finalizar()
{
    delete agencia_teste;
}

int TUAgencia::run()
{
    Inicializar();

    TestarNumeroValido();

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
