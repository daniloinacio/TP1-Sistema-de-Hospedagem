#ifndef TESTES_DOMINIOS_HPP
#define TESTES_DOMINIOS_HPP

#include "dominios.hpp"

using namespace std;

class TUAgencia
{
    public:
        static const int SUCESSO = 1;
        static const int FALHA = -1;

        int run();

    private:
        string numero_valido = "12345";
        string numero_invalido = "123456";

        Agencia *agencia_teste; ///< Objeto a ser testado

        int estado; ///< Indica se houve falha ou não

        void Inicializar( );
        void Finalizar( );

        void TestarNumeroValido( );
};

#endif // TESTES_DOMINIOS_HPP
