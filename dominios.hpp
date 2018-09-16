#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <stdexcept>

using namespace std;

/// Classe que representa numericamente uma Agência.
/** Representa uma Agência com um valor numérico de 5 dígitos em que
cada dígito é um número de 0 a 9. */

class Agencia
{
private:
    string agencia;             ///< Representação numérica da Agência.
    const int TAM = 5;          ///< Tamanho válido da representação.
    const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    /// Método que valida uma representação numérica de uma Agência.
    /** Verifica se a representação contém 5 caracteres e se cada um deles
    está no intervalo 0-9.
        \param Uma representação numérica de uma Agência.
        \return Void.
    */

    void validar( string ) throw ( invalid_argument );

public:

    /// Método que atribui um numero à Agência.
    /** Valida o número recebido e atribui à Agência.
        \param Uma representação numérica válida.
        \return Void.
    */

    void setAgencia( string agencia ) throw ( invalid_argument );

    /// Método que obtém o número da Agência.
    /** Retorna a representação numérica da Agência.
        \param Void.
        \return A representação numérica da Agência.
    */

    string getAgencia( ) const
    {
        return agencia;
    }

};

/// Classe que representa numericamente um Banco.
/** Representa um banco com um valor numérico de 3 dígitos em que
cada dígito é um número de 0 a 9. */

class Banco
{
private:

    string banco;               ///< Representação numérica do Banco.
    const int TAM = 3;          ///< Tamanho válido da representação.
    const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    /// Método que valida uma representação numérica de um Banco.
    /** Verifica se a representação contém 3 caracteres e se cada um deles
    está no intervalo 0-9.
        \param Uma representação numérica de um Banco.
        \return Void.
    */

    void validar( string ) throw ( invalid_argument );

public:

    /// Método que atribui um número ao Banco;
    /** Valida o número recebido e atribui ao Banco;
        \param Uma representação numérica válida.
        \return Void.
    */
    void setBanco( string ) throw ( invalid_argument );

    /// Método que obtém o atributo número.
    /** Retorna a representação numérica do Banco.
        \param Void.
        \return A representação numérica do Banco.
    */
    string getBanco( ) const
    {
        return banco;
    }
};

/// Classe que representa o valor numérico de uma capacidade de acomodação.
/** Representa uma capacidade de acomodação com um valor numérico de 0 a 9. */

class CapAcomodacao
{
private:

    int capAcomodacao;         ///< Valor da capacidade.
    const int MIN_VALOR = 0;   ///< Valor mínimo de capacidade.
    const int MAX_VALOR = 9;   ///< Valor máximo de capacidade.

    /// Método que valida um valor de capacidade de acomodação.
    /** Verifica se o valor é um inteiro no intervalo 0-9.
        \param Um valor inteiro.
        \return Void.
    */

    void validar( int ) throw ( invalid_argument );

public:

    /// Método que atribui um valor válido à capacidade de acomodação;
    /** Valida o valor recebido e atribui à capacidade de acomodação;
        \param Um valor inteiro válido;
        \return Void.
    */

    void setCapAcomodacao( int ) throw ( invalid_argument );

    /// Método que btém o valor da capacidade de acomodação.
    /** Retorna o valor da capacidade de acomodação.
        \param Void.
        \return O valor capacidade de acomodação.
    */
    int getCapAcomodacao( )
    {
        return capAcomodacao;
    }
};

#endif // DOMINIOS_HPP_INCLUDED
