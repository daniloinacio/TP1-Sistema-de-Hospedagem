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
    const int TAMANHO_AGENCIA = 5;          ///< Tamanho válido da representação.
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
    const int TAMANHO_BANCO = 3;          ///< Tamanho válido da representação.
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
    int getCapAcomodacao( ) const
    {
        return capAcomodacao;
    }
};

class Data
{
private:

    string data;
    int dia;
    string mes;
    int ano;
    bool bissexto = false;

    const int ANO_MAX = 2099;
    const int ANO_MIN = 2000;
    const int DIA_MIN = 1;
    const int DIA_MAX1 = 28;
    const int DIA_MAX2 = 29;
    const int DIA_MAX3 = 30;
    const int DIA_MAX4 = 31;
    const int TAMANHO_DIA = 2;
    const int TAMANHO_ANO = 4;
    const int TAMANHO_MES = 3;
    const int POSICAO_DIA = 0;
    const int POSICAO_MES = 3;
    const int POSICAO_ANO = 7;
    const int TAMANHO_DATA = 11;

    void validar( string ) throw ( invalid_argument );

public:

    void setData( string ) throw ( invalid_argument );

    string getData( ) const
    {
        return data;
    }


};

class DataValidade
{

private:
    string dataValidade;
    int mes;
    int ano;

    const int ANO_MIN = 00;
    const int ANO_MAX = 99;
    const int MES_MIN = 1;
    const int MES_MAX = 12;
    const int POSICAO_MES = 0;
    const int TAMANHO_MES = 2;
    const int POSICAO_ANO = 3;
    const int TAMANHO_ANO = 2;
    const int TAMANHO_DATA_VALIDADE = 5;

    void validar( string ) throw ( invalid_argument );

public:

    void setDataValidade( string ) throw ( invalid_argument );

    string getDataValidade( ) const
    {
        return dataValidade;
    }

};

class NumCartaoCred
{
private:
    string numCartaoCred;

    const int TAMANHO_NUMERO = 16;
    const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    void validar( string ) throw ( invalid_argument );
public:
    void setNumCartaoCred( string ) throw ( invalid_argument );

    string getNumCartaoCred( ) const
    {
        return numCartaoCred;
    }

};

class Senha
{
private:
    string senha;

    static const int TamanhoMaximo = 8;

    void validar( string ) throw ( invalid_argument );

public:
    void setSenha( string ) throw ( invalid_argument );

    string getSenha() const
    {
        return senha;
    }
};

#endif // DOMINIOS_HPP_INCLUDED
