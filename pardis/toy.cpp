#include <mpi.h>
#include <omp.h>

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

const int N=10000000;
int sqrtN;


int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);

  double st=omp_get_wtime();

  // Get the number of processes
  int num_procs;
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  // Get the rank of the process
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	sqrtN = (int)sqrt(N);
	//vector<int> marks = sieve(N);

	int split, remainder, low, high;

	// numbers > sqrtN that each processor gets
	split = (N - sqrtN+1) / num_procs;
	// possible remainder
	remainder = (N - sqrtN+1) % num_procs;

	low = sqrtN + rank*split + 1;
	high = low + split-1;

	// If last processor, increase split-size by remainder
	if(rank == num_procs-1) {
		high += remainder;
	}
	
	// all processors need to find primes up to sqrtN
	int * marks_common = new int[sqrtN+1];
	// numbers marked specifically by proc[rank]
	int * marks_proc = new int[high-low+1];


	#pragma omp parallel for
	for(int i=0; i < sqrtN+1; ++i) {
		marks_common[i] = 0;
	}
	marks_common[0] = 1;
	marks_common[1] = 1;

	#pragma omp parallel for 
	for(int i = low; i < high+1; ++i) {
		marks_proc[i-low] = 0;
	}

	// sieving process
	for(int i=2; i < sqrtN+1; ++i) {
		if(marks_common[i] == 0) {
			for(int j=i+1; j < sqrtN+1; ++j) {
				if(j%i == 0) {
					marks_common[j] = 1;
				}
			}
			for(int k=low; k < high+1; ++k) {
				if(k%i == 0) {
					marks_proc[k-low] = 1;
				}
			}
		}
	}




	// printing / messaging
	if(rank == 0){
		// print common
		for(int i=2; i < sqrtN+1; ++i) {
			if(marks_common[i] == 0) {
				cout << i << " ";
			}
		}
		// print own specifics
		for(int i=low; i < high+1; ++i) {
			if(marks_proc[i-low] == 0) {
				cout << i << " ";
			}
		}

		// receive other specifics in order
		for(rank = 1; rank < num_procs; ++rank){
			low = sqrtN + rank*split + 1;
			high = low + split-1;
			if(rank == num_procs-1) {
				delete[](marks_proc);
				high += remainder;
				marks_proc = new int[high-low+1];
			}

			MPI_Recv(marks_proc, high-low+1, MPI_INT, rank, 
								0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			// print received specifics
			for(int i=low; i < high+1; ++i) {
				if(marks_proc[i-low] == 0){
					cout << i << " ";
				}
			}
		}
	}else{
		MPI_Send(marks_proc, high-low+1, MPI_INT, 
							0, 0, MPI_COMM_WORLD);
	}


	delete[](marks_proc);
	delete[](marks_common);
	MPI_Finalize();

  double en=omp_get_wtime();
	if(rank == num_procs) {
		printf("\n\nTime taken using openmp %lf\n",en-st);
	}
	return 0;
}