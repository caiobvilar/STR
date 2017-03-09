#include <iostream> // para: cout
#include <time.h>   // para: time()
#include <unistd.h>
#include <stdlib.h>



using std::cout;
using std::cin;


int main ( )
{

  time_t tempo_real1;
  time_t tempo_real2;
  time_t diff;
  
  int numero;

  tempo_real1 = time( (time_t *) 0);  // apontando o ponteiro para null.
  cout << "Já se passaram  " << tempo_real1 << " segundos desde 0:00:00 de 01/01/1970 " << '\n';
	for(int i=0;i<1000000;i++)
		for(int k=0;k< 10000;k++);
  tempo_real2 = time( (time_t *) 0);  // apontando o ponteiro para null.
	diff = tempo_real2-tempo_real1;
  cout << "Já se passaram  " << tempo_real2 << " segundos desde 0:00:00 de 01/01/1970 " << '\n';
  cout << "Já se passaram  " << diff << " segundos entre os tempos." << std::endl;

  exit(0);
}

