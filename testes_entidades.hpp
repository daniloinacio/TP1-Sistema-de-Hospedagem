#ifndef TESTES_ENTIDADES_HPP
#define TESTES_ENTIDADES_HPP

#include "entidades.hpp"

class TUUsuario
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    string NomeValido = "Wilkerson";
    string Idvalido = "joaop";
    string SenhaValida = "Kall30!#";

    Usuario *UsuarioTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();
};

class TUCartaoCred
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    string NumValido = "6011111111111117";
    string DataValida = "11/03";

    CartaoCredito *CartaoTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();
};

#endif // TESTES_ENTIDADES_HPP
