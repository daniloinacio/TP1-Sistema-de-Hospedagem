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
    static const int TAMANHO_AGENCIA = 5;          ///< Tamanho válido da representação.
    static const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    static const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

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
    static const int TAMANHO_BANCO = 3;          ///< Tamanho válido da representação.
    static const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    static const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

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
    static const int MIN_VALOR = 0;   ///< Valor mínimo de capacidade.
    static const int MAX_VALOR = 9;   ///< Valor máximo de capacidade.

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

    static const int ANO_MAX = 2099;
    static const int ANO_MIN = 2000;
    static const int DIA_MIN = 1;
    static const int DIA_MAX1 = 28;
    static const int DIA_MAX2 = 29;
    static const int DIA_MAX3 = 30;
    static const int DIA_MAX4 = 31;
    static const int TAMANHO_DIA = 2;
    static const int TAMANHO_ANO = 4;
    static const int TAMANHO_MES = 3;
    static const int POSICAO_DIA = 0;
    static const int POSICAO_MES = 3;
    static const int POSICAO_ANO = 7;
    static const int TAMANHO_DATA = 11;

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

    static const int ANO_MIN = 00;
    static const int ANO_MAX = 99;
    static const int MES_MIN = 1;
    static const int MES_MAX = 12;
    static const int POSICAO_MES = 0;
    static const int TAMANHO_MES = 2;
    static const int POSICAO_ANO = 3;
    static const int TAMANHO_ANO = 2;
    static const int TAMANHO_DATA_VALIDADE = 5;

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

    static const int TAMANHO_NUMERO = 16;
    static const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    static const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    void validar( string ) throw ( invalid_argument );
public:
    void setNumCartaoCred( string ) throw ( invalid_argument );

    string getNumCartaoCred( ) const
    {
        return numCartaoCred;
    }

};

/// Classe para representar uma senha de usuário
/** A senha é uma sequência de 8 caracteres sendo permitidos letras maiúsculas
    ou minúsculas, números ou alguns símbolos (! # $ % &) */
class Senha
{
private:
    string senha; ///< Representação da senha em formato de string

    static const int TamanhoMaximo = 8; ///< Comprimento fixo da senha

    /// Método que avalia se uma senha é válida ou não
    /**
        \param senha String que será avaliada como válida ou não como senha
        \return void
    */
    void validar( string ) throw ( invalid_argument );

public:
    /// Atribui uma senha para um certo usuário
    /**
        Esta função não trata uma exceção, apemas a lança para que seja tratada
        em uma outra ocasião.
        \param senha Srting a ser atribuída como senha do usuário
        \return void
    */
    void setSenha( string ) throw ( invalid_argument );

    /// Retorna o valor da senha do objeto
    /**
        \param void
        \return senha Senha adiquirida do objeto
    */
    string getSenha() const
    {
        return senha;
    }
};


/// Classe para representar um estado brasileiro
class Estado
{
private:
    string estado; ///< Identificador
    static const int NumEstados = 27; ///< Número de estados brasileiros.
    string LSTEstados[NumEstados] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG",
                                   "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"}; ///< Lista de estados

    /// Função que valida um dado estado
    /**
        \param Estado String que será avaliada como um estado válido ou não
        \return void
    */
    void validar( string ) throw ( invalid_argument );

public:
    /// Função que muda o identificador desta classe para o estado dado como argumento
    /**
        \param Estado String para a qual se quer mudar o identificador
        \return void
    */
    void setEstado( string ) throw ( invalid_argument );

    /// Função que retorna o identificador de um objeto desta classe
    /** O identificador de um objeto desta classe é a sigla do estado
        \param void
        \return void
    */
    string getEstado() const
    {
        return estado;
    }
};

/// Classe que implementa um identificador para o usuário
class Identificador
{
private:
    string identificador; ///< Variável principal

    static const int tamanho = 5; ///< O identificador deve ter 5 caracteres

    /// Função que valida se um certo valor de identificador é válido ou não
    /**
        A função lança a exceção caso o valor seja inválido
       \param Identificador Identificador a ser validado
       \return void
    */
    void validar( string ) throw ( invalid_argument );

public:
    /// Função que seta um certo valor de identificador para a variável principal
    /**
        A função não cria a excecao, apenas a relança
        \param Identificador valor a ser setado
        \return void
    */
    void setIdentificador( string ) throw ( invalid_argument );

    /// Obtém a string do identificador
    /**
        \param void
        \return Identificador Valor de identificação daquele objeto
    */
    string getIdentificador() const
    {
        return identificador;
    }
};

/// Classe para o tipo de acomodação do usuário
class TpAcomodacao
{
private:
    string tpAcomodacao; ///< Identificador da classe
    string LstTipos[3] = {"apartamento", "casa", "flat"}; ///< Lista dos tipos permitidos
    int qtdTipos = 3; ///< Quantidade de tipos permitidos

    /// Valida um determinado tipo fornecido
    /**
        \param Tipo A string que será validada
        \return void
    */
    void validar( string ) throw ( invalid_argument );

public:
    /// Irá setar o valor de TpAcomodacao do objeto para o valor desejado
    /**
        \param Tipo Tipo que se deseja mudar
        \return void
    */
    void setTpAcomodacao( string ) throw ( invalid_argument );

    /// Irá fornecer o tipo de acomodacao
    /**
        \param void
        \return Tipo O tipo de acomodacao
    */
    string getTpAcomodacao() const
    {
        return tpAcomodacao;
    }
};

class Diaria
{
private:
    float diaria;
    float DIARIA_MAX = 10000.0;
    float DIARIA_MIN = 1.0;

    void validar ( float ) throw ( invalid_argument );

public:

    void setDiaria( float ) throw ( invalid_argument );

    float getDiaria( ) const
    {
        return diaria;
    }
};

class NumContaCorr
{
private:
    string numContaCorr;
    static const int LIMITE_SUP = 57;
    static const int LIMITE_INF = 48;
    static const int TAMANHO_NUMERO = 6;

    void validar ( string ) throw ( invalid_argument );
public:
    void setNumContaCorr( string ) throw ( invalid_argument );

    string getNumContaCorr( ) const
    {
        return numContaCorr;
    }
};

class Nome
{
private:
    string nome;
    static const int TAMANHO_NOME_MAX = 15;
    static const int TAMANHO_NOME_MIN = 1;

    void validar ( string ) throw ( invalid_argument );
public:

    void setNome( string ) throw ( invalid_argument );

    string getNome() const
    {
        return nome;
    }

};

#endif // DOMINIOS_HPP_INCLUDED
