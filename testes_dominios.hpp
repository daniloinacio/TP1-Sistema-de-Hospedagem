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
    int RodarTestes();

private:
    string numero_valido = "12345"; ///< Sequência de 5 dígitos válida
    string numero_invalido = "123456"; ///< Sequência de 6 dígitos inválida

    Agencia *agencia_teste; ///< Objeto a ser testado

    int estado; ///< Indica se houve falha ou não

    /// Prepara tudo para a realização dos testes
    void Inicializar( );

    /// Finaliza tudo depois da realização dos testes
    void Finalizar( );

    /// Testa a exceção de argumento inválido.
    /** Este teste procura colocar um nome válido para o objeto a ser
    testado e espera que a função não lance uma exceção.
        \param void Não possui parâmetros
        \return void não possui retorno
    */
    void TestarNumeroValido( );

    /// Testa a ezceção de argumento inválido.
    /** Aqui há uma tentativa de colocar um nome inválido na agência,
    espera-se que a função retorne uma exceção de argumento inválido para
    este caso.
        \param void Não possui parâmetros de entrada
        \return void Não possui retorno
    */
    void TestarNumeroInvalido();
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
    int RodarTestes();

private:
    string numero_valido = "123"; ///< Valor permitido para um valor de Banco
    string numero_invalido = "1234"; ///< Valor não permitido para um valor de Banco

    Banco *banco_teste; ///< Objeto de teste

    int estado; ///< Indica o estado dos testes

    /// Função que inicializa um ambiente para os testes
    /** Esta função faz tarefas simples como criar um objeto de testes
        \param void
        \return void */
    void Inicializar();

    /// Função responsável por finlizar o ambiente de testes desta unidade.
    /** Ela irá realizar ações como liberar o espaço alocado para a realização
        dos testes
        */
    void Finalizar();

    /// Faz um teste de um valor válido para Banco
    void TestarNumeroValido();

    /// Faz um teste de um valor inválido para Banco
    void TestarNumeroInvalido();
}; //TUBanco

#endif // TESTES_DOMINIOS_HPP
