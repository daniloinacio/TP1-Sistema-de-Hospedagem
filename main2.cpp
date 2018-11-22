#include <iostream>
#include "containers.hpp"
#include "controladoras.hpp"
#include "interfaces.hpp"
#include "entidades.hpp"
#include "dominios.hpp"

using namespace std;

int main()
{
ContainerUsuario containerUsuario;
ContainerAcomodacao containerAcomodacao;

CntrMAAutenticacao cntrMAAutenticacao;
CntrMAAcomodacao cntrMAAcomodacao;
CntrMAUsuario cntrUsuario;

CntrMSAcomodacao cntrMSAcomodacao;
CntrMSUsuario cntrMSUsuario;

cntrMSAcomodacao.setContainerAcomodacao( &containerAcomodacao );
cntrMSAcomodacao.setContainerUsuario( &containerUsuario );
cntrMSUsuario.setContainer( &containerUsuario );

// Setando valores das controladoras de apresentacao
cntrMAAcomodacao.setCntrMSAcomodacao( &cntrMSAcomodacao );
cntrMAAutenticacao.setCntrMSAutenticacao( &cntrMSUsuario );
cntrUsuario.setCntrMSUsuario( &cntrMSUsuario );

// Criando bool de resultado
bool resultado;

CntrMASistema sistema;
sistema.setCntrMAUsuario( &cntrUsuario );
sistema.setCntrMAAcomodacao( &cntrMAAcomodacao );
sistema.setCntrMAAutenticacao( &cntrMAAutenticacao );

Identificador *idUsuario = new Identificador();
resultado = sistema.menuPrincipal( idUsuario );
cout << resultado << endl;
delete idUsuario;

return 0;
}
