#ifndef TESTES_DOMINIOS_HPP
#define TESTES_DOMINIOS_HPP

#include "dominios.hpp"

using namespace std;

/// Classe de testes de unidade para a classe Agência.
/** Este módulo faz testes como a verificação do número de uma agência. */
class TUAgencia
{
public:
    static const int SUCESSO = 1; ///< Indica sucesso nos testes
    static const int FALHA = -1; ///< Indica fracasso nos testes

    /// Roda todos os testes do módulo
    /** Inicializa o objeto de teste, chama as funções de testes e então
    finaliza.
        \param void Não possui parâmetros de entrada
        \return void Não possui retorno
    */
    int rodarTestes();

private:
    string AGENCIA_VALIDA = "12345"; ///< Sequência de 5 dígitos válida
    string AGENCIA_INVALIDA = "123456"; ///< Sequência de 6 dígitos inválida

    Agencia *agenciaTeste; ///< Objeto a ser testado

    int estado; ///< Indica se houve falha ou não

    /// Prepara tudo para a realização dos testes
    void inicializar( );

    /// Finaliza tudo depois da realização dos testes
    void finalizar( );

    /// Testa a exceção de argumento inválido.
    /** Este teste procura colocar um nome válido para o objeto a ser
    testado e espera que a função não lance uma exceção.
        \param void Não possui parâmetros
        \return void não possui retorno
    */
    void testarCenarioSucesso( );

    /// Testa a ezceção de argumento inválido.
    /** Aqui há uma tentativa de colocar um nome inválido na agência,
    espera-se que a função retorne uma exceção de argumento inválido para
    este caso.
        \param void Não possui parâmetros de entrada
        \return void Não possui retorno
    */
    void testarCenarioFalha();
}; // TUAgencia

/// Classe de testes para a classe Banco
/** Este módulo faz testes para para a classe Banco */
class TUBanco
{
public:
    static const int SUCESSO = 1; ///< Indica sucesso nos testes
    static const int FALHA = -1; ///< Indica fracasso nos testes

    /// Roda todos os testes para a classe Banco
    /** \param void Não tem parâmetros
        \return estado Um valor que indica se os testes foram um sucesso ou falhos */
    int rodarTestes();

private:
    string BANCO_VALIDO = "123"; ///< Valor permitido para um valor de Banco
    string BANCO_INVALIDO = "1234"; ///< Valor não permitido para um valor de Banco

    Banco *bancoTeste; ///< Objeto de teste

    int estado; ///< Indica o estado dos testes

    /// Função que inicializa um ambiente para os testes
    /** Esta função faz tarefas simples como criar um objeto de testes
        \param void
        \return void */
    void inicializar();

    /// Função responsável por finlizar o ambiente de testes desta unidade.
    /** Ela irá realizar ações como liberar o espaço alocado para a realização
        dos testes
        */
    void finalizar();

    /// Faz um teste de um valor válido para Banco
    void testarCenarioSucesso();

    /// Faz um teste de um valor inválido para Banco
    void testarCenarioFalha();
}; //TUBanco

/// Classe de testes para a classe CapAcomodacao
/** Este módulo faz testes básicos para a classe CaoAcomodacao */
class TUCapAcomodacao
{
public:
    static const int SUCESSO = 1; ///< Indica sucesso
    static const int FALHA = -1; ///< Indica falha

    /// Função que irá rodar todos os testes desta unidade
    int rodarTestes();

private:
    int CAP_ACOMODACAO_VALIDA = 6; ///< Valor permitido para capacidade
    int CAP_ACOMODACAO_INVALIDA = -3; ///< Valor não permitido para capacidade

    CapAcomodacao *capacidade; ///< Objeto de teste
    int estado; ///< Indica se houve sucesso ou falha nos testes

    /// Função que inicializa o ambiente de testes
    void inicializar();

    /// Função que finaliza o ambiente de testes
    void finalizar();

    /// Esta função ira testar um valor válido
    void testarCenarioSucesso();

    /// Esta função irá testar um valor inválido
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
    string DATA_INVALIDA = "29/fev/2018"; //não é bissexto

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
