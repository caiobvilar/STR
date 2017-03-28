
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>


int main()
{
	std::cout << "Criando os pais." << std::endl;
	int pid;
	pid = fork();
	switch(pid)
	{
		case -1:
			return 0;
			break;//desnecessario, mas so pra manter a estrutura do switch

		case 0:
			
			break;
		deafult: //parte executada pelo pai
			break;
	}
}
