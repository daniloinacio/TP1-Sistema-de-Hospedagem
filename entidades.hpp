#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

using namespace std;

/// Classe da entidade de cartão de crédito
class CartaoCredito
{
private:
    NumCartaoCred numero; ///< Número do cartão
    DataValidade validade; ///< Data de validade do mesmo
    Identificador idUsuario;

public:
    /// Seta o número do cartão de crédito
    /**
        \param numero Objeto com o número de cartão de crédito que se quer associar
        \return void
    */
    void setNumero ( NumCartaoCred numero )
    {
        this->numero = numero;
    }

    /// Seta a data de validade do cartão
    /**
        \param validade Objeto com a data de validade que se quer associar
        \return void
    */
    void setValidade ( DataValidade validade)
    {
        this->validade = validade;
    }

    void setIdUsuario ( Identificador idUsuario)
    {
        this->idUsuario = idUsuario;
    }

    /// Retorna um objeto com o número do cartão
    NumCartaoCred getNumero()
    {
        return numero;
    }

    /// Retorna um objetivo de validade com a validade com cartão
    DataValidade getValidade()
    {
        return validade;
    }

    Identificador getIdUsuario()
    {
        return idUsuario;
    }
};

///Classe que representa a entidade conta corrente e seu atributos.
class ContaCorrente
{
private:
	NumContaCorr numero; ///< número associado a conta.
	Agencia agencia; ///< número da agência da qual a conta pertence.
	Banco banco; ///< número do banco do qual a agência pertence.
	Identificador idUsuario;

public:

	/// Método que atribui um numero a conta corrente.
	/**
		\param Um número de conta corrente.
		\return Void.
	*/
	void setNumero( NumContaCorr numero )
	{
		this->numero = numero;
	}
	/// Método que atribui uma agência a conta corrente.
	/**
		\param Um número de agência.
		\return Void.
	*/
	void setAgencia( Agencia agencia )
	{
		this->agencia = agencia;
	}

	/// Método que atribui um banco a conta corrente.
	/**
		\param Um número de banco.
		\return Void.
	*/
	void setBanco( Banco banco)
	{
		this->banco = banco;
	}

	void setIdUsuario ( Identificador idUsuario )
	{
	    this->idUsuario = idUsuario;
	}

	/// Método que obtém o numero da conta corrente.
	/**
		\param Void.
		\return O número da conta corrente.
	*/
	NumContaCorr getNumero()
	{
		return numero;
	}
	/// Método que obtém a agência da conta corrente.
	/**
		\param Void.
		\return O número da agência.
	*/
	Agencia getAgencia()
	{
		return agencia;
	}
	/// Método que obtém o banco da conta corrente.
	/**
		\param Void.
		\return O número do banco.
	*/
	Banco getBanco()
	{
		return banco;
	}

	Identificador getIdUsuario()
	{
	    return idUsuario;
	}
};

/// Classe para que identifica um usuário do sistema
class Usuario
{
private:
    Nome nome; ///< String de até 15 caracteres
    Identificador identificador; ///< Srting 5 caracteres somente de letras
    Senha senha; ///< String de até 8 caracteres

public:
    /// Associa um nome ao usuário
    /**
        \param nome Objeto com o nome a ser estabelecido
    */
    void setNome ( Nome nome )
    {
        this->nome = nome;
    }

    /// Associa um identificador a um certo usuário
    /**
        \param identificador Objeto com o identificador que se quer associar
    */
    void setIdentificador ( Identificador identificador )
    {
        this->identificador = identificador;
    }

    /// Associa uma senha a um certo usuário
    /**
        \param Senha Objeto com a senha que se quer atribuir
    */
    void setSenha ( Senha senha )
    {
        this->senha = senha;
    }

    /// Retorna o nome do usuário
    /**
        \return Nome Objeto com o nome do usuário
    */
    Nome getNome()
    {
        return nome;
    }

    /// Retorna o identificador do usuário
    /**
        \return Identificador objeto que identifica o usuário
    */
    Identificador getIdentificador()
    {
        return identificador;
    }

    /// Retorna a senha do usuário
    /**
        \return Senha Objeto com a senha do usuário
    */
    Senha getSenha()
    {
        return senha;
    }
};

class Resultado {

protected:
    int valor;

public:

    const static int SUCESSO = 0;
    const static int FALHA   = 1;

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};

class ResultadoUsuario:public Resultado {

private:
    Usuario usuario;

public:
    void setUsuario(const Usuario &usuario){
        this->usuario = usuario;
    }

    Usuario getUsuario() const {
        return usuario;
    }
};

/// Classe que representa a entidade Acomodação e seus atributos.
class Acomodacao
{
private:
	Identificador identificador; ///< Identificação da acomodação.
	Identificador idUsuario;
	TpAcomodacao tipo; ///< O tipo ao qual a acomodação pertence.
	CapAcomodacao capacidade; ///< Valor da capacidade da acomodação.
	Data dataInicio; ///< Data de inicio do período de disponibilidade da acomodação.
	Data dataTermino; ///< Data de termino do período de disponibilidade da acomodação.
	Nome cidade; ///< Nome da cidade em que a acomodação está localizada.
	Estado estado; ///< Sigla do estado em que a acomodação está localizada.
	Diaria diaria; ///< Valor da diária da acomodação.

public:

	/// Método que atribui um identificador a acomodação
	/**
		\param Um identificador.
		\return Void.
	*/
	void setIdentificador( const Identificador &identificador )
	{
		this->identificador = identificador;
	}

	void setIdUsuario( Identificador idUsuario )
	{
	    this->idUsuario = idUsuario;
	}

	/// Método que atribui um tipo a acomodação
	/**
		\param Um tipo de acomodação.
		\return Void.
	*/
	void setTipo( TpAcomodacao tipo )
	{
		this->tipo = tipo;
	}

	/// Método que atribui uma capacidade a acomodação
	/**
		\param Um valor de capacidade.
		\return Void.
	*/
	void setCapacidade( CapAcomodacao capacidade )
	{
		this->capacidade = capacidade;
	}

	/// Método que atribui uma data de inicio a acomodação
	/**
		\param Uma data.
		\return Void.
	*/
	void setDataInicio( Data dataInicio )
	{
		this->dataInicio = dataInicio;
	}

	/// Método que atribui uma data de termino a acomodação
	/**
		\param Uma data.
		\return Void.
	*/
	void setDataTermino( Data dataTermino )
	{
		this->dataTermino = dataTermino;
	}

	/// Método que atribui uma cidade a acomodação
	/**
		\param O nome de uma cidade.
		\return Void.
	*/
	void setCidade( Nome cidade )
	{
		this->cidade = cidade;
	}

	/// Método que atribui um Estado a acomodação
	/**
		\param A sigla de um estado brasileiro.
		\return Void.
	*/
	void setEstado( Estado estado )
	{
		this->estado = estado;
	}

	/// Método que atribui um valor de diária a acomodação
	/**
		\param Um valor de diária.
		\return Void.
	*/
	void setDiaria( Diaria diaria )
	{
		this->diaria = diaria;
	}

	/// Método que obtém o identificador da acomodação
	/**
		\param Void.
		\return O identificador da acomodação.
	*/
	Identificador getIdentificador()
	{
		return identificador;
	}

	/// Método que obtém o tipo da acomodação
	/**
		\param Void.
		\return O tipo da acomodação.
	*/
	TpAcomodacao getTipo()
	{
		return tipo;
	}

	/// Método que obtém a capacidade da acomodação
	/**
		\param Void.
		\return A capacidade da acomodação.
	*/
	CapAcomodacao getCapacidade()
	{
		return capacidade;
	}

	/// Método que obtém a data de inicio da disponibilidade da acomodação
	/**
		\param Void.
		\return A data de inicio da disponibilidade da acomodação.
	*/
	Data getDataInicio()
	{
		return dataInicio;
	}

	/// Método que obtém a data de termino da disponibilidade da acomodação
	/**
		\param Void.
		\return A data de termino da disponibilidade da acomodação.
	*/
	Data getDataTermino()
	{
		return dataTermino;
	}

	/// Método que obtém a cidade da acomodação
	/**
		\param Void.
		\return A cidade da acomodação.
	*/
	Nome getCidade()
	{
		return cidade;
	}

	/// Método que obtém o estado da acomodação
	/**
		\param Void.
		\return O estado da acomodação.
	*/
	Estado getEstado()
	{
		return estado;
	}

	/// Método que obtém a diária da acomodação.
	/**
		\param Void.
		\return A diária da acomodação.
	*/
	Diaria getDiaria()
	{
		return diaria;
	}

	Identificador getIdUsuario()
	{
	    return idUsuario;
	}
};

class ResultadoAcomodacao:public Resultado {

private:
    Acomodacao acomodacao;

public:
    void setAcomodacao(const Acomodacao &acomodacao){
        this->acomodacao = acomodacao;
    }

    Acomodacao getAcomodacao() const {
        return acomodacao;
    }
};
#endif // ENTIDADES_HPP
