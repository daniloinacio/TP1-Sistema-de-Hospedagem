#ifndef TESTES_ENTIDADES_HPP
#define TESTES_ENTIDADES_HPP

#include "entidades.hpp"

class TUCartaoCred
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    string NumValido = "6011111111111117";
    string NumInvalido = "6011111111";
    string DataValida = "11/03";
    string DataInvalida = "13/18";

    CartaoCredito *CartaoTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

#endif // TESTES_ENTIDADES_HPP
