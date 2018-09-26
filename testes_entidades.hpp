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

    Nome NOME_VALIDO;
    Identificador ID_VALIDO;
    Senha SENHA_VALIDA;

    string NOME = "Wilkerson";
    string ID = "joaop";
    string SENHA = "Kall30!#";

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

    NumCartaoCred NUM_VALIDO;
    DataValidade DATA_VALIDA;

    string NUM = "6011111111111117";
    string DATA = "11/03";

    CartaoCredito *CartaoTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();
};

class TUAcomodacao
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    Identificador IDENTIFICADOR_VALIDO;
    TpAcomodacao TIPO_VALIDO;
    CapAcomodacao CAPACIDADE_VALIDA;
    Data DATA_INICIO_VALIDA;
    Data DATA_TERMINO_VALIDA;
    Nome CIDADE_VALIDA;
    Estado ESTADO_VALIDO;
    Diaria DIARIA_VALIDA;

    string ID = "nubia";
    string TIPO = "apartamento";
    int CAP_ACOMODACAO = 6;
    string DATA = "11/set/2003";
    string NOME = "Danilo";
    string ESTADO = "AM";
    float DIARIA = 5425.0;

    Acomodacao *acomodacaoTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();
};

class TUContaCorrente
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    NumContaCorr NUMERO_VALIDO;
    Agencia AGENCIA_VALIDA;
    Banco BANCO_VALIDO;
    string NUMERO_CONTA_CORR = "123456";
    string NUMERO_AGENCIA = "12345";
    string NUMERO_BANCO = "123";

    ContaCorrente *contaCorrenteTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();
};

#endif // TESTES_ENTIDADES_HPP
