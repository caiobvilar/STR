/*
 *  sortcompare.cpp
 *  
 *
 *  Created by Caio José Borba Vilar Guimarães.
 *
 *	Codigo baseado no ordenacao.cpp do Prof. Luiz Affonso - DCA UFRN.
 */



#include <cstdlib>   	//
#include <ctime>    	// clock(),time()
#include <iostream> 	//std::cout
#include <string>			//std::string
#include <map>				//map
#include <vector>


//Vetores usados pelos métodos de ordenação
int *vetorQuickSort;
int *vetorBubbleSort;
int tamanho;

//Função usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b )
{
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 < *arg2 )
	{
		return -1;
	}
	else if( *arg1 == *arg2 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Algoritmos de ordenação bubble sort
void bubbleSort(int *vetor, int tamanho)
{
	int aux;
	for (int i = 0; i < tamanho-1; i++)
	{
		for (int j = 0; j < tamanho-1; j++)
		{
			if (vetor[j] > vetor[j+1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}


//Observe que os números são gerados aleatoriamente baseados
//em uma semente. Se for passado a mesma semente, os 
//números aleatórios serão os mesmos
void criarVetor(int tamanhoVetor, int semente)
{
	srand (semente);
	vetorQuickSort = new int[tamanhoVetor];
	vetorBubbleSort = new int[tamanhoVetor];
	for (int i=0;i<tamanhoVetor;i++)
	{
		vetorQuickSort[i] =  rand()%100000;
    vetorBubbleSort[i] = vetorQuickSort[i]; // utilizar os mesmos valores
		//vetorBubbleSort[i] = rand()%100000;
	}
}

void geratesteBubble(int` numvetor,int seed)
{
	clock_t clock_1, clock_2;
	std::map<std::string,double> resultMap;
	//Criar vetor com elementos aleatorios[0,100000] 
	criarVetor(numvetor,23);
	clock_1 = clock();
	bubbleSort(vetorBubbleSort,numvetor);
	clock_2 = clock();
	//1000 10.000 100.000
	std::cout << "Tempo de utilização de CPU em segundos: " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("BubbleSort - 1000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	delete vetorQuickSort;
	delete vetorBubbleSort;
}


int main ()
{
	//Tamanho do vetor
	clock_t clock_1, clock_2;
	int n=1000;
	std::map<std::string,double> resultMap;
	//Criar vetor com elementos aleatorios[0,100000] 
	criarVetor(n,23);
	//Ordenar utilizando quickSort
	clock_1 = clock();
	qsort (vetorQuickSort, n, sizeof(int), compare_ints);
	clock_2 = clock();
	std::cout << "Tempo de utilização de CPU em segundos : " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("QuickSort - 1000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	//Ordenar utilizando bubleSort
	clock_1 = clock();
	bubbleSort(vetorBubbleSort,n);
	clock_2 = clock();
	//1000 10.000 100.000
	std::cout << "Tempo de utilização de CPU em segundos: " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("BubbleSort - 1000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	delete vetorQuickSort;
	delete vetorBubbleSort;
	//Criar vetor com elementos aleatorios[0,100000] 
	n = 10000; //10.000 elementos no vetor de sorting
	criarVetor(n,23);
	//Ordenar utilizando quickSort
	clock_1 = clock();
	qsort (vetorQuickSort, n, sizeof(int), compare_ints);
	clock_2 = clock();
	std::cout << "Tempo de utilização de CPU em segundos : " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("QuickSort - 10000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	//Ordenar utilizando bubleSort
	clock_1 = clock();
	bubbleSort(vetorBubbleSort,n);
	clock_2 = clock();
	//1000 10.000 100.000
	std::cout << "Tempo de utilização de CPU em segundos: " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("BubbleSort - 10000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	delete vetorQuickSort;
	delete vetorBubbleSort;
	//Criar vetor com elementos aleatorios[0,100000] 
	n = 100000; //10.000 elementos no vetor de sorting
	criarVetor(n,23);
	//Ordenar utilizando quickSort
	clock_1 = clock();
	qsort (vetorQuickSort, n, sizeof(int), compare_ints);
	clock_2 = clock();
	std::cout << "Tempo de utilização de CPU em segundos : " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("QuickSort - 100000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	//Ordenar utilizando bubleSort
	clock_1 = clock();
	bubbleSort(vetorBubbleSort,n);
	clock_2 = clock();
	//1000 10.000 100.000
	std::cout << "Tempo de utilização de CPU em segundos: " << ((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) << std::endl;
	resultMap.insert(std::pair<std::string,double>("BubbleSort - 100000",((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC)));
	delete vetorQuickSort;
	delete vetorBubbleSort;
	std::map<std::string,double>::iterator itr;
	for(itr = resultMap.begin();itr != resultMap.end();itr++)
	{
		std::cout << (*itr).first << ": " << (*itr).second << std::endl;
	}
	return 0;
}
