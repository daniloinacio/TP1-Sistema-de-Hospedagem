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
        int run();

    private:
        string numero_valido = "12345"; ///< Sequência de 5 dígitos válida
        string numero_invalido = "123456"; ///< Sequência de 6 dígitos inválida

        Agencia *agenceia_teste; ///< Objeto a ser testado

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
};

#endif // TESTES_DOMINIOS_HPP
