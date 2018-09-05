#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <stdexcept>

using namespace std;

/// Representação numérica de uma Agência.
/** Representa uma Agência com um valor numérico de 5 dígitos em que
cada dígito é um número de 0 a 9. */

class Agencia
{
private:
    string numero;              ///< Representação numérica de uma Agência.
    const int TAM = 5;          ///< Tamanho válido da representação.
    const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    /// Valida uma representação numérica de uma Agência.
    /** Verifica se a representação contém 5 caracteres e se cada um deles
    está no intervalo 0-9.
        \param Uma string contendo uma representação de uma Agência.
        \return Void.
    */

    void validar( string ) throw ( invalid_argument );

public:

    /// Atribui uma representação numérica ao atributo numero;
    /** Valida o parametro recebido e atribui ao atributo numero;
        \param Uma string contendo uma representação numérica válida.
        \return Void.
    */

    void setAgencia( string numero ) throw ( invalid_argument );

    /// Obtém o atributo número.
    /** Retorna a representação numérica de uma Agência.
        \param Void.
        \return Uma string contendo a representação numérica.
    */

    string getAgencia( ) const
    {
        return numero;
    }

};

/// Representação numérica de um Banco.
/** Representa um banco com um valor numérico de 3 dígitos em que
cada dígito é um número de 0 a 9. */

class Banco
{
private:

    string numero;              ///< Representação numérica de um Banco.
    const int TAM = 3;          ///< Tamanho válido da representação.
    const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    /// Valida uma representação numérica de um Banco.
    /** Verifica se a representação contém 3 caracteres e se cada um deles
    está no intervalo 0-9.
        \param Uma string contendo uma representação de um Banco.
        \return Void.
    */

    void validar( string numero ) throw ( invalid_argument );

public:

    /// Atribui uma representação numérica ao atributo numero;
    /** Valida o parametro recebido e atribui ao atributo numero;
        \param Uma string contendo uma representação numérica válida.
        \return Void.
    */
    void setBanco( string numero) throw ( invalid_argument );

    /// Obtém o atributo número.
    /** Retorna a representação numérica de um Banco.
        \param Void.
        \return Uma string contendo a representação numérica.
    */
    string getBanco( ) const
    {
        return numero;
    }
};

/// Valor numérico de uma capacidade de acomodação.
/** Representa uma capacidade de acomodação com um valor numérico de 0 a 9. */

class CapAcomodacao
{
private:

    int valor;                 ///< Valor da capacidade.
    const int MIN_VALOR = 0;   ///< Valor mínimo de capacidade.
    const int MAX_VALOR = 9;   ///< Valor máximo de capacidade.

    /// Valida um valor de capacidade de acomodação.
    /** Verifica se a representação contém um inteiro no intervalo 0-9.
        \param Um inteiro contendo um valor.
        \return Void.
    */

    void validar( int valor ) throw ( invalid_argument );

public:

    /// Atribui um valor válido ao atributo valor;
    /** Valida o parametro recebido e atribui ao atributo valor;
        \param Um inteiro contendo um valor válido;
        \return Void.
    */

    void setCapAcomodacao( int valor ) throw ( invalid_argument );

    /// Obtém o atributo valor.
    /** Retorna o valor da capacidade de acomodação.
        \param Void.
        \return Um inteiro contendo o valor da capacidade de acomodação.
    */
    int getCapAcomodacao( )
    {
        return valor;
    }
};

#endif // DOMINIOS_HPP_INCLUDED
