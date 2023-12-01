/********************************************************************************************************
* Course: CS33211 Operating Systems
* Assignment: Banker's Algorithm for deadlock avoidance
* Name: Carlton Canaday
* Version: 1.1
* Description: Make sure there is enough resourcse so that all 5 clients needs can be met.
* Refrence URL: https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/
*/
#include <stdio.h>
int main()
{
									 // P0, P1, P2, P3, P4 are the Process names here
									 // A, B, C are the resources names here

	int n, m, i, j, k;					// Setup standard variables
	n = 5; 								// Number of processes
	m = 3; 								// Number of resources
	// Allocation Matrix
	int alloc[5][3] = { { 0, 1, 0 },	// P0, A = 0, B = 1, C = 0
						{ 2, 0, 0 },	// P1, A = 2, B = 0, C = 0
						{ 3, 0, 2 },	// P2, A = 3, B = 0, C = 2
						{ 2, 1, 1 }, 	// P3, A = 2, B = 1, C = 1
						{ 0, 0, 2 } };	// P4, A = 0, B = 0, C = 2
	// MAX Matrix
	int max[5][3] = { { 7, 5, 3 },		// P0, A = 7, B = 5, C = 3
					{ 3, 2, 2 },		// P1, A = 3, B = 2, C = 2
					{ 9, 0, 2 },		// P2, A = 9, B = 0, C = 2
					{ 2, 2, 2 },		// P3, A = 2, B = 2, C = 2
					{ 4, 3, 3 } };		// P4, A = 4, B = 3, C = 3
	// Available Resources
	int avail[3] = { 3, 3, 2 }; 			// This is the starting values of resources A = 3, B = 3, C = 2

	int f[n], ans[n], ind = 0;			/* f is an array of the processes to show if they are in a safe state or not
										 * ans holds the order of the proccesses that were used
										 * ind holds the current location of the array for ans
										*/
	for (k = 0; k < n; k++) {
		f[k] = 0;						// Places 0 in f array
	}
	int need[n][m];						// Setting up the need matrix
	for (i = 0; i < n; i++) {			// i = which process it is currently on
		for (j = 0; j < m; j++)	{		// j = to which resource it is currently on
			need[i][j] = max[i][j] - alloc[i][j]; //Take the current location of max and subtract it from the current location of allocate to produce the need location of the matrix
		}
	}
	int y = 0;

	for (k = 0; k < n; k++) {			// Go though all the processess
		for (i = 0; i < n; i++) {		// Go though all the processess again
			if (f[i] == 0) {

				int flag = 0;			// seting the flag as NOT in a safe state as defualt
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){ // check if the need is greater than the available resources
						flag = 1;				// if true set the flag as one and break out of the loop
						break;			// Break from the loop
					}
				}

				if (flag == 0) {
					ans[ind++] = i;				// Which process was used and setup for the next process number that will be used
					for (y = 0; y < m; y++)		// Where it is on the availability array
						avail[y] += alloc[i][y]; // Releaseing resorces back to Available for A, B, C 
					f[i] = 1;					// Will skip the the rest of the processes and go to the next 
				}
			}
		}
	}

	int flag = 1;	// Setting the flag to 1 as defult it IS in a safe state
	
	for(int i = 0; i < n; i++){
		if(f[i] != 1) // States if the system is NOT in a safe state
		{
			flag = 0; // Set the flag to 0 because the system is not in a safe state
			printf("The following system is NOT safe\n");
			break;	// break out of the loop
		}
	}
	
	if(flag == 1){ 		// Stating that the system is in a safe state if true
		printf("Following is the SAFE Sequence\n");
		for (i = 0; i < n - 1; i++){ 	
			printf(" P%d ->", ans[i]); // Printing off the order the processes that were completed
		}
	printf(" P%d\n", ans[n - 1]);		// Print off the final process
	printf(" A = %d, B = %d, C = %d\n", avail[0], avail[1], avail[2]); // Print off the available resources of A B and C
	}
	

	return (0); // Close the program

	// This code is contributed by Deep Baldha (CandyZack). I slighly modified the code to make it eaiser for myself to read.
}
