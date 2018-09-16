#ifndef TESTES_DOMINIOS_HPP
#define TESTES_DOMINIOS_HPP

#include "dominios.hpp"

using namespace std;

/// Classe de testes de unidade para a classe Ag�ncia.
/** Este m�dulo faz testes como a verifica��o do n�mero de uma ag�ncia. */
class TUAgencia
{
public:
    static const int SUCESSO = 1; ///< Indica sucesso nos testes
    static const int FALHA = -1; ///< Indica fracasso nos testes

    /// Roda todos os testes do m�dulo
    /** Inicializa o objeto de teste, chama as fun��es de testes e ent�o
    finaliza.
        \param void N�o possui par�metros de entrada
        \return void N�o possui retorno
    */
    int rodarTestes();

private:
    string AGENCIA_VALIDA = "12345"; ///< Sequ�ncia de 5 d�gitos v�lida
    string AGENCIA_INVALIDA = "123456"; ///< Sequ�ncia de 6 d�gitos inv�lida

    Agencia *agenciaTeste; ///< Objeto a ser testado

    int estado; ///< Indica se houve falha ou n�o

    /// Prepara tudo para a realiza��o dos testes
    void inicializar( );

    /// Finaliza tudo depois da realiza��o dos testes
    void finalizar( );

    /// Testa a exce��o de argumento inv�lido.
    /** Este teste procura colocar um nome v�lido para o objeto a ser
    testado e espera que a fun��o n�o lance uma exce��o.
        \param void N�o possui par�metros
        \return void n�o possui retorno
    */
    void testarCenarioSucesso( );

    /// Testa a ezce��o de argumento inv�lido.
    /** Aqui h� uma tentativa de colocar um nome inv�lido na ag�ncia,
    espera-se que a fun��o retorne uma exce��o de argumento inv�lido para
    este caso.
        \param void N�o possui par�metros de entrada
        \return void N�o possui retorno
    */
    void testarCenarioFalha();
}; // TUAgencia

/// Classe de testes para a classe Banco
/** Este m�dulo faz testes para para a classe Banco */
class TUBanco
{
public:
    static const int SUCESSO = 1; ///< Indica sucesso nos testes
    static const int FALHA = -1; ///< Indica fracasso nos testes

    /// Roda todos os testes para a classe Banco
    /** \param void N�o tem par�metros
        \return estado Um valor que indica se os testes foram um sucesso ou falhos */
    int rodarTestes();

private:
    string BANCO_VALIDO = "123"; ///< Valor permitido para um valor de Banco
    string BANCO_INVALIDO = "1234"; ///< Valor n�o permitido para um valor de Banco

    Banco *bancoTeste; ///< Objeto de teste

    int estado; ///< Indica o estado dos testes

    /// Fun��o que inicializa um ambiente para os testes
    /** Esta fun��o faz tarefas simples como criar um objeto de testes
        \param void
        \return void */
    void inicializar();

    /// Fun��o respons�vel por finlizar o ambiente de testes desta unidade.
    /** Ela ir� realizar a��es como liberar o espa�o alocado para a realiza��o
        dos testes
        */
    void finalizar();

    /// Faz um teste de um valor v�lido para Banco
    void testarCenarioSucesso();

    /// Faz um teste de um valor inv�lido para Banco
    void testarCenarioFalha();
}; //TUBanco

/// Classe de testes para a classe CapAcomodacao
/** Este m�dulo faz testes b�sicos para a classe CaoAcomodacao */
class TUCapAcomodacao
{
public:
    static const int SUCESSO = 1; ///< Indica sucesso
    static const int FALHA = -1; ///< Indica falha

    /// Fun��o que ir� rodar todos os testes desta unidade
    int rodarTestes();

private:
    int CAP_ACOMODACAO_VALIDA = 6; ///< Valor permitido para capacidade
    int CAP_ACOMODACAO_INVALIDA = -3; ///< Valor n�o permitido para capacidade

    CapAcomodacao *capacidade; ///< Objeto de teste
    int estado; ///< Indica se houve sucesso ou falha nos testes

    /// Fun��o que inicializa o ambiente de testes
    void inicializar();

    /// Fun��o que finaliza o ambiente de testes
    void finalizar();

    /// Esta fun��o ira testar um valor v�lido
    void testarCenarioSucesso();

    /// Esta fun��o ir� testar um valor inv�lido
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

#endif // TESTES_DOMINIOS_HPP
