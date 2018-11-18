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
CntrMSAutenticacao cntrMSAutenticacao;

cntrMSAutenticacao.setContainer( &container );
cntrMAAutenticacao.setCntrMSAutenticacao( &cntrMSAutenticacao );

return 0;
}
