#include <iostream>
#include "containers.hpp"
#include "controladoras.hpp"
#include "interfaces.hpp"
#include "entidades.hpp"
#include "dominios.hpp"

using namespace std;

int main()
{

ContainerUsuario container;
CntrMAAutenticacao cntrMAAutenticacao;
CntrMSUsuario cntrMSUsuario;

cntrMSUsuario.setContainer( &container );
cntrMAAutenticacao.setCntrMSAutenticacao( &cntrMSUsuario );

return 0;
}
