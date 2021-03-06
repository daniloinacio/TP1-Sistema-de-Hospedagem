#ifndef TESTES_DOMINIOS_HPP
#define TESTES_DOMINIOS_HPP

#include "dominios.hpp"

using namespace std;

// Classe de testes classe Ag�ncia.
class TUAgencia
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();

private:
    string AGENCIA_VALIDA = "12345";
    string AGENCIA_INVALIDA = "123456";

    Agencia *agenciaTeste;

    int estado;

    void inicializar( );
    void finalizar( );

    void testarCenarioSucesso( );

    void testarCenarioFalha();
}; // TUAgencia

// Classe de testes classe Banco
class TUBanco
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();

private:
    string BANCO_VALIDO = "123";
    string BANCO_INVALIDO = "1234";

    Banco *bancoTeste;

    int estado;

    void inicializar();
    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
}; //TUBanco

// Classe de testes classe CapAcomodacao
class TUCapAcomodacao
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();

private:
    int CAP_ACOMODACAO_VALIDA = 6;
    int CAP_ACOMODACAO_INVALIDA = -3;

    CapAcomodacao *capacidade;
    int estado;

    void inicializar();
    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUData
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();
private:
    string DATA_VALIDA = "11/set/2003";
    string DATA_INVALIDA = "29/fev/2018"; //n�o � bissexto

    Data *data;
    int estado;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};


class TUDataValidade
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();
private:
    string DATA_VALIDA = "09/18";
    string DATA_INVALIDA = "20/100";

    DataValidade *dataValidade;
    int estado;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUNumCartaoCred
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();
private:
    string NUMERO_VALIDO = "6011111111111117";
    string NUMERO_INVALIDO = "123456789101112";

    NumCartaoCred *numCartaoCred;
    int estado;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUSenha
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    string SenhaValida = "Kall30!#";
    string SenhaInvalida = "DanInic.";

    int estado;
    Senha* SenhaTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUEstado
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado; // Indica se � sucesso ou se � falha

    string EstadoValido = "AM";
    string EstadoInvalido = "AV";

    Estado *EstadoTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUIdentificador
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    string IdValido = "nubia";
    string IdInvalido = "kal13";

    Identificador *IdentificadorTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();

};

class TUTpAcomodacao
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int RodarTestes();

private:
    int estado;

    string TipoValido = "apartamento";
    string TipoInvalido = "mansao";

    TpAcomodacao *TpTeste;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUDiaria
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();
private:
    float DIARIA_VALIDA = 5425.0;
    float DIARIA_INVALIDA = 1000000.0;

    Diaria *diaria;
    int estado;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUNumContaCorr
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();
private:
    string NUMERO_VALIDO = "123456";
    string NUMERO_INVALIDO = "&#$123";

    NumContaCorr *numContaCorr;
    int estado;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

class TUNome
{
public:
    static const int SUCESSO = 1;
    static const int FALHA = -1;

    int rodarTestes();
private:
    string NOME_VALIDO = "Danilo";
    string NOME_INVALIDO = "Dan .lo";

    Nome *nome;
    int estado;

    void inicializar();

    void finalizar();

    void testarCenarioSucesso();

    void testarCenarioFalha();
};

#endif // TESTES_DOMINIOS_HPP
