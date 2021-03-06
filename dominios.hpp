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

    /// Método que verifica se a representação contém 5 caracteres e se cada um deles está no intervalo 0-9.
    /**
        \param Uma representação numérica de uma Agência.
        \return Void.
    */

    void validar( string ) throw ( invalid_argument );

public:

    /// Método que atribui um numero válido à Agência.
    /**
        \param Uma representação numérica válida.
        \return Void.
    */

    void setAgencia( string agencia ) throw ( invalid_argument );

    /// Método que obtém o número da Agência.
    /**
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

    /// Método que verifica se a representação contém 3 caracteres e se cada um deles está no intervalo 0-9.
    /**
        \param Uma representação numérica de um Banco.
        \return Void.
    */

    void validar( string ) throw ( invalid_argument );

public:

    /// Método que atribui um número válido ao Banco;
    /** 
        \param Uma representação numérica válida.
        \return Void.
    */
    void setBanco( string ) throw ( invalid_argument );

    /// Método que obtém o número do Banco;
    /** 
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

    /// Método que verifica se o valor de capacidade é um inteiro no intervalo 0-9.
    /**
        \param Um valor inteiro.
        \return Void.
    */

    void validar( int ) throw ( invalid_argument );

public:

    /// Método que atribui um valor válido à capacidade de acomodação;
    /**
        \param Um valor inteiro válido;
        \return Void.
    */

    void setCapAcomodacao( int ) throw ( invalid_argument );

    /// Método que btém o valor da capacidade de acomodação.
    /**
        \param Void.
        \return O valor da capacidade de acomodação.
    */
    int getCapAcomodacao( ) const
    {
        return capAcomodacao;
    }
};

///Classe que representa uma Data.
/**Representa uma data com seus componentes dia, mes e ano separados por /, com os meses representados pelas
3 primeiras letras do seu nome e considerando anos bissextos  */

class Data
{
private:

    string data; ///< Representação da data.
    int dia; ///< Valor do dia contido na data.
    string mes; ///< Nome do mês contido na data.
    int ano; ///< Valor do ano contido na data.
    bool bissexto = false; ///< Indicador de ano bissexto.

    static const int ANO_MAX = 2099; ///< Valor máximo que o ano pode assumir.
    static const int ANO_MIN = 2000; ///< Valor mínimo que o ano pode assumir.
    static const int DIA_MIN = 1; ///< Valor mínimo que o dia pode assumir.
    static const int DIA_MAX1 = 28; ///< Valor máximo que o dia pode assumir.
    static const int DIA_MAX2 = 29; ///< Valor máximo que o dia pode assumir.
    static const int DIA_MAX3 = 30; ///< Valor máximo que o dia pode assumir.
    static const int DIA_MAX4 = 31; ///< Valor máximo que o dia pode assumir.
    static const int TAMANHO_DIA = 2; ///< Espaço ocupado pelo dia na data
    static const int TAMANHO_ANO = 4; ///< Espaço ocupado pelo ano na data.
    static const int TAMANHO_MES = 3; ///< Espaço ocupado pelo mês na data.
    static const int POSICAO_DIA = 0; ///< Posição do dia na data
    static const int POSICAO_MES = 3; ///< Posição do mes na data
    static const int POSICAO_ANO = 7; ///< Posição do ano na data
    static const int TAMANHO_DATA = 11; ///< Tamanho da representação da data

    /// Método que verifica a validade dos valores assumidos pelo dia, mes e ano e a coerencia entre eles.
    /** 
        \param Uma data.
        \return Void.
    */
    void validar( string ) throw ( invalid_argument );

public:

    /// Método que atribui valores válidos para à data.
    /** 
        \param Uma representação válida de uma data.
        \return Void.
    */
    void setData( string ) throw ( invalid_argument );

    /// Método que obtém a representação da data.
    /** 
        \param Void.
        \return A representação da data.
    */
    string getData( ) const
    {
        return data;
    }


};

///Classe que representa uma data de validade.
/** Representa uma data de validade com os valores de mes e ano separados por /. */
class DataValidade
{

private:
    string dataValidade; ///< Representação da data de validade.
    int mes; ///< Valor do mês.
    int ano; ///< Valor do ano.

    static const int ANO_MIN = 00; ///< Valor mínimo que o ano pode assumir.
    static const int ANO_MAX = 99; ///< Valor máximo que o ano pode assumir.
    static const int MES_MIN = 1; ///< Valor mínimo que o mês pode assumir.
    static const int MES_MAX = 12; ///< Valor máximo que o mês pode assumir.
    static const int POSICAO_MES = 0; ///< Posição do mês na data de validade.
    static const int TAMANHO_MES = 2; ///< Espaço ocupado pelo mês na data de validade.
    static const int POSICAO_ANO = 3; ///< Posição do ano na data de validade.
    static const int TAMANHO_ANO = 2; ///< Espaço ocupado pelo ano na data de validade.
    static const int TAMANHO_DATA_VALIDADE = 5; ///< Tamanho da representação da data de validade

    /// Método que verifica se os valores de mes e ano estão dentro do intervalo válido e se a data de validade está no formato correto.
    /** 
        \param Uma data de validade contendo os valores de mês e ano.
        \return Void.
    */
    void validar( string ) throw ( invalid_argument );

public:
    /// Método que atribui uma valores válidos para data de validade.
    /** 
        \param Uma data de validade válida.
        \return Void.
    */
    void setDataValidade( string ) throw ( invalid_argument );

    /// Método que obtém a representação da data de validade.
    /**
        \param Void.
        \return A representação da data de validade.
    */
    string getDataValidade( ) const
    {
        return dataValidade;
    }

};

/// Classe que representa um número de cartão de crédito.
/** Representa um número de cartão de crédito com um total de 16 digitos em que cada dígito
está no intervalo de 0 a 9.*/
class NumCartaoCred
{
private:
    string numCartaoCred; ///< Representação do número de cartão de crédito.

    static const int TAMANHO_NUMERO = 16; ///< Tamanho da representação do número de cartão de crédito.
    static const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    static const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.

    /// Método que verifica se o número está no formato adequado e se é válido.
    /** 
        \param Um número de cartão de crédito.
        \return Void.
    */
    void validar( string ) throw ( invalid_argument );
public:

    /// Método que atribui um número válido ao número de cartão de crédito.
    /**
        \param Um número de cartão de crédito válido.
        \return Void.
    */
    void setNumCartaoCred( string ) throw ( invalid_argument );

    /// Método que obtém o número do cartão de crédito.
    /**
        \param Void.
        \return O número do cartão de crédito.
    */
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

/// Classe que representa o valor de uma diária.
class Diaria
{
private:
    float diaria; ///< Valor da diária.
    float DIARIA_MAX = 10000.0; ///< Valor máximo que a diária pode assumir.
    float DIARIA_MIN = 1.0; ///< Valor mínimo que a diária pode assumir.

    /// Método se a diaria está no intervalo válido de valores.
    /** 
        \param Um valor de diária.
        \return Void.
    */
    void validar ( float ) throw ( invalid_argument );

public:

    /// Método que atribui um valor válido a diária.
    /**
        \param Um valor de diária válido.
        \return void.
    */
    void setDiaria( float ) throw ( invalid_argument );

    /// Método que obtém o valor da diária.
    /**
        \param Void.
        \return O valor da diária.
    */
    float getDiaria( ) const
    {
        return diaria;
    }
};

/// Classe que representa um número de conta corrente.
/** Representa um número de conta corrente com um total de 6 digitos em que cada dígito
está no intervalo de 0 a 9.*/

class NumContaCorr
{
private:
    string numContaCorr; ///< Representação do número de conta corrente
    static const int LIMITE_INF = 48;  ///< Valor mínimo que um caracter pode assumir, número 0 em ASCII.
    static const int LIMITE_SUP = 57;  ///< Valor máximo que um caracter pode assumir, número 9 em ASCII.
    static const int TAMANHO_NUMERO = 6; ///< Tamanho da representação do número de conta corrente

    /// Método que verifica se o número está no formato adequado.
    /**
        \param Um número de conta corrente.
        \return Void.
    */
    void validar ( string ) throw ( invalid_argument );
public:

    /// Método que atribui um número válido ao número de conta corrente.
    /**
        \param Uḿ número de conta corrente válido.
        \return Void.
    */
    void setNumContaCorr( string ) throw ( invalid_argument );

    /// Método que obtém o número da conta corrente.
    /**
        \param Void.
        \return O número da conta corrente.
    */
    string getNumContaCorr( ) const
    {
        return numContaCorr;
    }
};

/// Classe que representa um nome.
/** Representa um nome com no máximo 15 caracters em que cada um pode ser letra, ponto ou espaço. Pelo menos um caracter é
letra, não há espaços seguidos e ponto é precedido por letra.*/
class Nome
{
private:
    string nome; ///< Representação do nome.
    static const int TAMANHO_NOME_MAX = 15; ///< Tamanho máximo do nome.
    static const int TAMANHO_NOME_MIN = 1; ///< Tamanho mínimo do nome.
    static const int PONTO = 46; ///< Valor caracter ponto, ASCII.
    static const int ESPACO = 32; ///< Valor caracter espaço, ASCII.
    static const int MIN_LETRA_MINUSCULA = 97; ///< Valor mínimo que um caracter pode assumir, número a em ASCII.
    static const int MAX_LETRA_MINUSCULA = 122; ///< Valor máximo que um caracter pode assumir, número z em ASCII.
    static const int MIN_LETRA_MAIUSCULA = 65; ///< Valor mínimo que um caracter pode assumir, número A em ASCII.
    static const int MAX_LETRA_MAIUSCULA = 90; ///< Valor máxomo que um caracter pode assumir, número Z em ASCII.
    bool letra; ///< Indicador da existencia de letra no nome.
    /// Método que verifica se o nome está no formato correto.
    /** 
        \param Um nome.
        \return Void.
    */
    void validar ( string ) throw ( invalid_argument );
public:

    /// Método que atribui uma representação válida ao nome.
    /**
        \param Um nome válido.
        \return Void.
    */
    void setNome( string ) throw ( invalid_argument );

    /// Método que obtém o nome.
    /**
        \param Void.
        \return O nome.
    */
    string getNome() const
    {
        return nome;
    }

};

#endif // DOMINIOS_HPP_INCLUDED
