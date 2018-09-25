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

class TUAcomodacao
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    Identificador IDENTIFICADOR_VALIDO;
    IDENTIFICADOR_VALIDO.setIdentificador("nubia");
    TpAcomodacao TIPO_VALIDO.setTpAcomodacao("apartamento");
    CapAcomodacao CAPACIDADE_VALIDA.setCapAcomodacao(3);
    Data DATA_INICIO_VALIDA.setData("01/jun/2007");
    Data DATA_TERMINO_VALIDA.setData("07/jun/2007");
    Nome CIDADE_VALIDA.setNome("Brasilia");
    Estado ESTADO_VALIDO.setEstado("DF");
    Diaria DIARIA_VALIDA.setDiaria(1.0);

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

    NumContaCorr NUMERO_VALIDO.setNumContaCorr("123456");
    Agencia AGENCIA_VALIDA.setAgencia("12345");
    Banco BANCO_VALIDO.setBanco("123");

    ContaCorrente *contaCorrenteTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();
};

#endif // TESTES_ENTIDADES_HPP
