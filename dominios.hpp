#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <stdexcept>

using namespace std;

/// Representação numérica de uma Agência.
/** Detailed description. */

class Agencia
{
private:
    string numero;              ///< Representação numérica da Agência.
    const int TAM = 5;          ///< Tamanho válido da representação.
    const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    /// Valida uma representação numérica de da Agência.
    /** Verifica se a representação contém 5 caracteres e se cada um deles
    está no intervalo 0-9.
        \param Uma string contendo uma representação da Agência.
        \return Void.
    */

    void validar( string ) throw ( invalid_argument );

public:

    /// Atribui uma representação numérica ao atributo numero da Agencia;
    /** Valida o parametro recebido e atribui ao atributo numero;
        \param Uma string contendo uma representação numérica válida.
        \return Void.
    */

    void setAgencia( string numero ) throw ( invalid_argument )
    {
        validar( numero );
        this->numero = numero;
    }

    /// Obtém o atributo número.
    /** Retorna a representação numérica da Agência.
        \param Void.
        \return Uma string contendo a representação numérica.
    */

    string getAgencia( ) const
    {
        return numero;
    }

};

/// Brief description.
/** Detailed description. */

class Banco
{
private:

    string numero;              ///<
    const int TAM = 3;          ///<
    const int LIMITE_INF = 48;  ///<
    const int LIMITE_SUP = 57;  ///<

    /// Brief description.
    /** Detailed description.
        \param
        \return
    */

    void validar( string numero ) throw ( invalid_argument );

public:

    /// Brief description.
    /** Detailed description.
        \param
        \return
    */

    void setBanco( string numero) throw ( invalid_argument )
    {
        validar( numero );
        this->numero = numero;
    }
    /// Brief description.
    /** Detailed description.
        \param
        \return
     */
    string getBanco( ) const
    {
        return numero;
    }
}

/// Brief description.
/** Detailed description. */

class CapAcomodacao
{
private:

    int quantidade;         ///<
    const LIMITE_INF = 0;   ///<
    const LIMITE_SUP = 9;   ///<

    /// Brief description.
    /** Detailed description.
        \param
        \return
    */

    void validar( int quantidade ) throw ( invalid_argument );

public:

    /// Brief description.
    /** Detailed description.
        \param
        \return
    */

    void setCapAcomodacao( int quantidade ) throw ( invalid_argument ){
        validar( quantidade );
        this->quantidade = quantidade;
    }

    /// Brief description.
    /** Detailed description.
        \param
        \return
    */

    int getCapAcomodacao( )
    {
        return quantidade;
    }
}

#endif // DOMINIOS_HPP_INCLUDED
