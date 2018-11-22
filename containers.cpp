#include "containers.hpp"

// Métodos da classe Container Acomodacao

//Acomodação

ResultadoAcomodacao ContainerAcomodacao::incluirAcomodacao( Acomodacao acomodacao )
{
    ResultadoAcomodacao resultado;
    string identificador = acomodacao.getIdentificador().getIdentificador();
    list<Acomodacao>::iterator elemento;

    if(!containerAcomodacoes.empty())
    {
        for( elemento = containerAcomodacoes.begin(); elemento != containerAcomodacoes.end(); elemento++ )
        {
            if( elemento->getIdentificador().getIdentificador() == identificador )
            {
                resultado.setValor( Resultado::FALHA );
                return resultado;
            }
        }
    }
    else
    {
        resultado.setValor( Resultado::FALHA );
        return resultado;
    }

    containerAcomodacoes.push_back(acomodacao);
    resultado.setValor( Resultado::SUCESSO );
    return resultado;
}

ResultadoAcomodacao ContainerAcomodacao::removerAcomodacao( Identificador idAcomodacao )
{
    ResultadoAcomodacao resultado;
    string identificador = idAcomodacao.getIdentificador();
    list<Acomodacao>::iterator elemento;

    for( elemento = containerAcomodacoes.begin(); elemento != containerAcomodacoes.end(); elemento++ )
    {
        if( elemento->getIdentificador().getIdentificador() == identificador )
        {
            resultado.setValor( Resultado::SUCESSO );
            containerAcomodacoes.erase( elemento );
            return resultado;
        }
    }
    resultado.setValor( Resultado::FALHA );
    return resultado;
}

ResultadoAcomodacao ContainerAcomodacao::buscarAcomodacao( Identificador idUsuario )
{
    ResultadoAcomodacao resultado;
    string identificador = idUsuario.getIdentificador();
    list<Acomodacao>::iterator elemento;
    list<Acomodacao> acomodacoes;

    for ( elemento = containerAcomodacoes.begin(); elemento != containerAcomodacoes.end(); elemento++ )
    {
        if ( elemento->getIdUsuario().getIdentificador() == identificador )
            {
                acomodacoes.push_back( *elemento );
                resultado.setValor( Resultado::SUCESSO );
            }
    }

    if ( resultado.getValor() == Resultado::SUCESSO )
    {
        resultado.setAcomodacoes( acomodacoes );
    }
    return resultado;
}

//Disponibilidade

ResultadoDisponib ContainerAcomodacao::incluirDisponib( Disponibilidade disponibilidade )
{
    ResultadoDisponib resultado;
    string identificador = disponibilidade.getIdAcomodacao().getIdentificador();
    string dataInicio = disponibilidade.getDataInicio().getData();
    string dataTermino = disponibilidade.getDataTermino().getData();
    list<Disponibilidade>::iterator elemento;

    for ( elemento = containerDisponibilidades.begin(); elemento != containerDisponibilidades.end(); elemento++ )
    {
        if ( ( elemento->getIdAcomodacao().getIdentificador() == identificador ) &&
         ( elemento->getDataInicio().getData() == dataInicio ) &&
         ( elemento->getDataTermino().getData() == dataTermino ) )
        {
            resultado.setValor( Resultado::FALHA );
            return resultado;
        }
    }

    containerDisponibilidades.push_back( disponibilidade );
    resultado.setValor( Resultado::SUCESSO );
    return resultado;
}

ResultadoDisponib ContainerAcomodacao::removerDisponib( Disponibilidade disponibilidade )
{
    ResultadoDisponib resultado;
    string identificador = disponibilidade.getIdAcomodacao().getIdentificador();
    string dataInicio = disponibilidade.getDataInicio().getData();
    string dataTermino = disponibilidade.getDataTermino().getData();
    list<Disponibilidade>::iterator elemento;

    for ( elemento = containerDisponibilidades.begin(); elemento != containerDisponibilidades.end(); elemento++ )
    {
        if ( ( elemento->getIdAcomodacao().getIdentificador() == identificador ) &&
         ( elemento->getDataInicio().getData() == dataInicio ) &&
         ( elemento->getDataTermino().getData() == dataTermino ) )
        {
            resultado.setValor( Resultado::SUCESSO );
            containerDisponibilidades.erase( elemento );
            return resultado;
        }
    }

    resultado.setValor( Resultado::FALHA );
    return resultado;
}

ResultadoDisponib ContainerAcomodacao::removerTodasDisponibAcomod( Identificador idAcomodacao )
{
    ResultadoDisponib resultado;
    string identificador = idAcomodacao.getIdentificador();
    list<Disponibilidade>::iterator elemento;
    resultado.setValor( Resultado::FALHA );

    for ( elemento = containerDisponibilidades.begin(); elemento != containerDisponibilidades.end(); elemento++ )
    {
        if ( elemento->getIdAcomodacao().getIdentificador() == identificador )
        {
            resultado.setValor( Resultado::SUCESSO );
            containerDisponibilidades.erase( elemento );
        }
    }

    return resultado;
}

ResultadoDisponib ContainerAcomodacao::buscarDisponib( Data dataInicio, Data dataTermino )
{
    ResultadoDisponib resultado;
    string dataInic = dataInicio.getData();
    string dataTer = dataTermino.getData();
    list<Disponibilidade> disponibilidades;
    list<Disponibilidade>::iterator elemento;

    resultado.setValor( Resultado::FALHA );
    for ( elemento = containerDisponibilidades.begin(); elemento != containerDisponibilidades.end(); elemento++ )
    {
        if( ( elemento->getDataInicio().getData() == dataInic ) && ( elemento->getDataTermino().getData() == dataTer ) )
        {
            resultado.setValor( Resultado::SUCESSO );
            disponibilidades.push_back( *elemento );
        }
    }

    if ( resultado.getValor() == Resultado::SUCESSO )
    {
        resultado.setDisponibilidades( disponibilidades );
    }
    return resultado;
}

//Reserva

ResultadoReserva ContainerAcomodacao::incluirReserva( Reserva reserva )
{
    ResultadoReserva resultado;
    string idUsuario = reserva.getIdUsuario().getIdentificador();
    string idAcomodacao = reserva.getIdAcomodacao().getIdentificador();
    string dataInicio = reserva.getDataInicio().getData();
    string dataTermino = reserva.getDataTermino().getData();
    list<Reserva>::iterator elemento;

    for ( elemento = containerReservas.begin(); elemento != containerReservas.end(); elemento++ )
    {
        if ( ( elemento->getIdAcomodacao().getIdentificador() == idAcomodacao ) &&
         ( elemento->getIdUsuario().getIdentificador() == idUsuario ) &&
         ( elemento->getDataInicio().getData() == dataInicio ) &&
         ( elemento->getDataTermino().getData() == dataTermino ) )
        {

            resultado.setValor( Resultado::FALHA );
            return resultado;
        }
    }

    containerReservas.push_back( reserva );
    resultado.setValor( Resultado::SUCESSO );
    return resultado;
}

ResultadoReserva ContainerAcomodacao::removerReserva( Reserva reserva )
{
    ResultadoReserva resultado;
    string idUsuario = reserva.getIdUsuario().getIdentificador();
    string idAcomodacao = reserva.getIdAcomodacao().getIdentificador();
    string dataInicio = reserva.getDataInicio().getData();
    string dataTermino = reserva.getDataTermino().getData();
    list<Reserva>::iterator elemento;

    for ( elemento = containerReservas.begin(); elemento != containerReservas.end(); elemento++ )
    {
        if ( ( elemento->getIdAcomodacao().getIdentificador() == idAcomodacao ) &&
         ( elemento->getIdUsuario().getIdentificador() == idUsuario ) &&
         ( elemento->getDataInicio().getData() == dataInicio ) &&
         ( elemento->getDataTermino().getData() == dataTermino ) )
        {
            containerReservas.erase(elemento);
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }

    resultado.setValor( Resultado::FALHA );
    return resultado;
}

ResultadoReserva ContainerAcomodacao::buscarReservaAcomodacao( Identificador idAcomodacao )
{
    ResultadoReserva resultado;
    string identificador = idAcomodacao.getIdentificador();
    list<Reserva>::iterator elemento;
    list<Reserva> reservas;

    resultado.setValor( Resultado::FALHA );
    for ( elemento = containerReservas.begin(); elemento != containerReservas.end(); elemento++ )
    {
        if ( ( elemento->getIdAcomodacao().getIdentificador() == identificador ) )
        {
            reservas.push_back( *elemento );
            resultado.setValor( Resultado::SUCESSO );
        }
    }

    if ( resultado.getValor() == Resultado::SUCESSO )
    {
        resultado.setReservas( reservas );
    }
    return resultado;
}

ResultadoReserva ContainerAcomodacao::buscarReservaUsuario( Identificador idUsuario )
{
    ResultadoReserva resultado;
    string identificador = idUsuario.getIdentificador();
    list<Reserva>::iterator elemento;
    list<Reserva> reservas;

    resultado.setValor( Resultado::FALHA );
    for ( elemento = containerReservas.begin(); elemento != containerReservas.end(); elemento++ )
    {
        if ( ( elemento->getIdUsuario().getIdentificador() == identificador ) )
        {
            reservas.push_back( *elemento );
            resultado.setValor( Resultado::SUCESSO );
        }
    }

    if ( resultado.getValor() == Resultado::SUCESSO )
    {
        resultado.setReservas( reservas );
    }
    return resultado;
}

//Métodos da classe ContainerUsuario

//Usuario

ResultadoUsuario ContainerUsuario::incluirUsuario( Usuario usuario )
{
    ResultadoUsuario resultado;
    string identificador = usuario.getIdentificador().getIdentificador();
    list<Usuario>::iterator elemento;

    for ( elemento = containerUsuarios.begin(); elemento != containerUsuarios.end(); elemento++ )
    {
        if ( elemento->getIdentificador().getIdentificador() == identificador )
        {
            resultado.setValor( Resultado::FALHA );
            return resultado;
        }
    }

    containerUsuarios.push_back( usuario );
    resultado.setValor( Resultado::SUCESSO );
    return resultado;
}

ResultadoUsuario ContainerUsuario::removerUsuario( Identificador idUsuario )
{
    ResultadoUsuario resultado;
    string identificador = idUsuario.getIdentificador();

    for ( list<Usuario>::iterator elemento = containerUsuarios.begin(); elemento != containerUsuarios.end(); elemento++ )
    {

        if ( elemento->getIdentificador().getIdentificador() == identificador ){

            containerUsuarios.erase( elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }
    resultado.setValor( Resultado::FALHA );
    return resultado;
}

ResultadoUsuario ContainerUsuario::buscarUsuario( Identificador idUsuario )
{
    ResultadoUsuario resultado;
    string identificador = idUsuario.getIdentificador();
    list<Usuario>::iterator elemento;

    for ( elemento = containerUsuarios.begin(); elemento != containerUsuarios.end(); elemento++ )
    {
        if ( elemento->getIdentificador().getIdentificador() == identificador )
        {
            resultado.setUsuario( *elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }

    resultado.setValor( Resultado::FALHA );
    return resultado;
}

//Conta Corrente

ResultadoConta ContainerUsuario::incluirConta( ContaCorrente conta )
{
    ResultadoConta resultado;
    string numero = conta.getNumero().getNumContaCorr();
    list<ContaCorrente>::iterator elemento;

    for ( elemento = containerContas.begin(); elemento != containerContas.end(); elemento++ )
    {
        if ( elemento->getNumero().getNumContaCorr() == numero )
        {
            resultado.setValor( Resultado::FALHA );
            return resultado;
        }
    }

    containerContas.push_back( conta );
    resultado.setValor( Resultado::SUCESSO );
    return resultado;
}

ResultadoConta ContainerUsuario::removerConta( Identificador idUsuario )
{
    ResultadoConta resultado;
    string identificador = idUsuario.getIdentificador();

    for ( list<ContaCorrente>::iterator elemento = containerContas.begin(); elemento != containerContas.end(); elemento++ )
    {

        if ( elemento->getIdUsuario().getIdentificador() == identificador ){

            containerContas.erase( elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }
    resultado.setValor( Resultado::FALHA );
    return resultado;
}

ResultadoConta ContainerUsuario::buscarConta( Identificador idUsuario )
{
    ResultadoConta resultado;
    string identificador = idUsuario.getIdentificador();
    list<ContaCorrente>::iterator elemento;

    for ( elemento = containerContas.begin(); elemento != containerContas.end(); elemento++ )
    {
        if ( elemento->getIdUsuario().getIdentificador() == identificador )
        {
            resultado.setConta( *elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }

    resultado.setValor( Resultado::FALHA );
    return resultado;
}

//Cartão de Crédito

ResultadoCartao ContainerUsuario::incluirCartao( CartaoCredito cartao )
{
    ResultadoCartao resultado;
    string numero = cartao.getNumero().getNumCartaoCred();
    list<CartaoCredito>::iterator elemento;

    for ( elemento = containerCartoes.begin(); elemento != containerCartoes.end(); elemento++ )
    {
        if ( elemento->getNumero().getNumCartaoCred() == numero )
        {
            resultado.setValor( Resultado::FALHA );
            return resultado;
        }
    }

    containerCartoes.push_back( cartao );
    resultado.setValor( Resultado::SUCESSO );
    return resultado;
}

ResultadoCartao ContainerUsuario::removerCartao( Identificador idUsuario )
{
    ResultadoCartao resultado;
    string identificador = idUsuario.getIdentificador();
    list<CartaoCredito>::iterator elemento;

    for ( elemento = containerCartoes.begin(); elemento != containerCartoes.end(); elemento++ )
    {

        if ( elemento->getIdUsuario().getIdentificador() == identificador ){

            containerCartoes.erase( elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }
}

ResultadoCartao ContainerUsuario::buscarCartao( Identificador idUsuario )
{
    ResultadoCartao resultado;
    string identificador = idUsuario.getIdentificador();
    list<CartaoCredito>::iterator elemento;

    for ( elemento = containerCartoes.begin(); elemento != containerCartoes.end(); elemento++ )
    {
        if ( elemento->getIdUsuario().getIdentificador() == identificador )
        {
            resultado.setCartao( *elemento );
            resultado.setValor( Resultado::SUCESSO );
            return resultado;
        }
    }

    resultado.setValor( Resultado::FALHA );
    return resultado;
}
