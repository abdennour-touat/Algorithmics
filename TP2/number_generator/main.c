#include<stdio.h>
#include<stdlib.h>

//create two files with an ascending and descending order
void print_asc_desc(char *nomasc,char *nomdesc,long num){
	
	FILE *fasc, *fdesc;
	fasc = fopen(nomasc, "w");
	fdesc = fopen(nomdesc, "w");

	 long i = 0;
	while(i < num){
		//printf("%ld\n", i);
		//ascending order
		fprintf(fasc, "%ld\n", i);
		//descending order
		fprintf(fdesc, "%ld\n", num - i -1);
		i++;
	}
	//close the files..
	fclose(fasc);
	fclose(fdesc);
}
void fill_array( long num){
	//declare an array and fill it with numbers
	 long arr[num];
	for ( long x = 0; x<num;x++){
		arr[x] = x;
	}
//	return arr;
}
//print a file with random numbers in a range
void print_random ( char *nom, long num){
	FILE *frand;
	frand = fopen(nom, "w");

	//declare an array and fill it with numbers
//	 long arr[num];
	long *arr;
	arr = (long*)malloc(num* sizeof(long));
	for ( long x = 0; x<num;x++){
		arr[x] = x;
	}
	// long arr[num] = fill_array(num);
	 long i = 0;
	while (i< num){
		//find a random position and shuffle the current position with the random position..
        	size_t j = i + rand() / (RAND_MAX / (num - i) + 1);
		int t = arr[j];
          	arr[j] = arr[i];
          	arr[i] = t;
		i++;
	}
	//printing the shuffled array to the file
	for (long y = 0; y<num; y++){
		//printf("%ld\n", arr[y]);
		fprintf(frand, "%ld\n", arr[y]);
	}
	free(arr);
	fclose(frand);
}

int main(){

	print_asc_desc("10^4asc.txt", "10^4desc.txt", 10000);
	print_asc_desc("5x10^4asc.txt", "5x10^4desc.txt", 50000);
	print_asc_desc("5x10^5asc.txt", "5x10^5desc.txt", 500000);
	print_asc_desc("10^5asc.txt", "10^5desc.txt", 100000);

	print_asc_desc("5x10^6asc.txt", "5x10^6desc.txt", 5000000);
	print_asc_desc("10^7asc.txt", "10^7desc.txt", 10000000);
	print_asc_desc("5x10^7asc.txt", "5x10^7desc.txt", 50000000);
	print_asc_desc("10^8asc.txt", "10^8desc.txt", 100000000);


	print_random("5x10^4rand.txt", 50000);
	print_random("10^4rand.txt", 10000);
	print_random("5x10^5rand.txt", 500000);
	print_random("10^5rand.txt", 100000);
	
	print_random("5x10^6rand.txt", 5000000);
	print_random("10^7rand.txt", 10000000);
	print_random("5x10^7rand.txt", 50000000);
	print_random("10^8rand.txt", 100000000);

	return 0;
}
