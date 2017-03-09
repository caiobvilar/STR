
/////\// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: sleep.c


#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()
#include <time.h>


using std::cout;

//using namespace std;


int main ( )
{

  double x = 1;
  time_t tempo_real1;
  time_t tempo_real2;
  time_t diff;
    
    
    
    //usleep(1000);
    sleep(2);
    cout << "passei. levou 2 segundos" << '\n';
  tempo_real1 = time( (time_t *) 0);  // apontando o ponteiro para null.
  for(int i=0; i<5; i++) {
    sleep(i);
    cout << "teste "  << i <<'\n';
   
  }
  cout << "teste" <<'\n';
  tempo_real2 = time( (time_t *) 0);  // apontando o ponteiro para null.
  diff = tempo_real2 - tempo_real1;
	std::cout << "Demorou: " << diff << " segundos." << std::endl;
  return(0);
}

