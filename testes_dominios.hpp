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
    int RodarTestes();

private:
    string numero_valido = "12345"; ///< Sequ�ncia de 5 d�gitos v�lida
    string numero_invalido = "123456"; ///< Sequ�ncia de 6 d�gitos inv�lida

    Agencia *agencia_teste; ///< Objeto a ser testado

    int estado; ///< Indica se houve falha ou n�o

    /// Prepara tudo para a realiza��o dos testes
    void Inicializar( );

    /// Finaliza tudo depois da realiza��o dos testes
    void Finalizar( );

    /// Testa a exce��o de argumento inv�lido.
    /** Este teste procura colocar um nome v�lido para o objeto a ser
    testado e espera que a fun��o n�o lance uma exce��o.
        \param void N�o possui par�metros
        \return void n�o possui retorno
    */
    void TestarNumeroValido( );

    /// Testa a ezce��o de argumento inv�lido.
    /** Aqui h� uma tentativa de colocar um nome inv�lido na ag�ncia,
    espera-se que a fun��o retorne uma exce��o de argumento inv�lido para
    este caso.
        \param void N�o possui par�metros de entrada
        \return void N�o possui retorno
    */
    void TestarNumeroInvalido();
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
    int RodarTestes();

private:
    string numero_valido = "123"; ///< Valor permitido para um valor de Banco
    string numero_invalido = "1234"; ///< Valor n�o permitido para um valor de Banco

    Banco *banco_teste; ///< Objeto de teste

    int estado; ///< Indica o estado dos testes

    /// Fun��o que inicializa um ambiente para os testes
    /** Esta fun��o faz tarefas simples como criar um objeto de testes
        \param void
        \return void */
    void Inicializar();

    /// Fun��o respons�vel por finlizar o ambiente de testes desta unidade.
    /** Ela ir� realizar a��es como liberar o espa�o alocado para a realiza��o
        dos testes
        */
    void Finalizar();

    /// Faz um teste de um valor v�lido para Banco
    void TestarNumeroValido();

    /// Faz um teste de um valor inv�lido para Banco
    void TestarNumeroInvalido();
}; //TUBanco

#endif // TESTES_DOMINIOS_HPP
