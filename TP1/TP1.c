#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

bool A1 (int n){
	//boolean
	bool premier = true;
	int i = 2;
	while(i <= n -1 && premier){
		if(n % i == 0){
			premier = false;
		}else{
			i++;
		}
	}
	return premier;
}

bool A2 (int n){
	//boolean
	bool premier = true;
	int i = 2;
	while(i <= n/2  && premier){
		if(n % i == 0){
			premier = false;
		}else{
			i++;
		}
	}
	return premier;
}
bool A3 (int n){
	//boolean
	bool premier = true;	
	int i = 2;
	while(i <= sqrt((double)n)  && premier){
		if(n % i == 0){
			premier = false;
		}else{
			i++;
		}
	}
	return premier;
}
bool A4 (int n){
	//boolean
	bool premier = true;	
	if(n != 2){
		premier = false;
	}else{
		int i= 3;
		while(i <= n-2 && premier){
			if(n % i == 0){
				premier = false;
			}else{
				i = i+2;
			}
		}
	}
	return premier;
}
bool A5 (int n){
	//boolean
	bool premier = true;	
	if(n != 2 && n % 2 == 0){
		premier = false;
	}else{
		if(n !=2){
			int i = 3;
			while (i <= n/2 && premier){
				if(n % i == 0) {
					premier = false;
				}else{
					i = i+2;
				}
			}
		}
	}
	return premier;
}
int A6 (int n){
	//boolean
	bool premier = true;	
	if(n !=2 && n%2 == 0){
		premier = false;	
	}else{
		if(n !=2){
			int i =3;
			while (i <= sqrt(n)&& premier){
				if (n %i ==0){
					premier = false;
				}else{
					i = i+2;	
				}
			}
		}
	}
	return premier;
}

int main (){
//	printf("%s\n", A1(5972) ? "true": "false");
//	printf("%s\n", A2(3) ? "true": "false");
//	printf("%s\n", A3(3) ? "true": "false");
//	printf("%s\n", A4(3) ? "true": "false");
//	printf("%s\n", A5(3) ? "true": "false");
//	printf("%s\n", A6(3) ? "true": "false");
	clock_t t1, t2;
	double delta;
	int num;	
	
	//1: Mesure les temps d'execution..
	// 15489079
	num  = 15489079;
	printf("temps d'execution pour le numero 15489079\n");
	printf("Algorithme 1\n");
	t1 =clock();
	A1(num);
	t2 = clock();
	 delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	
	
	printf("Algorithme 2\n");
	t1 =clock();
	A2(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 3\n");
	t1 =clock();
	A3(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	


	printf("Algorithme 4\n");
	t1 =clock();
	A4(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 5\n");
	t1 =clock();
	A5(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 6\n");
	t1 =clock();
	A6(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	




	//1831463033 
	num  = 1831463033;
	printf("temps d'execution pour le numero 1831463033\n");
	printf("Algorithme 1\n");
	t1 =clock();
	A1(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	
	
	printf("Algorithme 2\n");
	t1 =clock();
	A2(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 3\n");
	t1 =clock();
	A3(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	


	printf("Algorithme 4\n");
	t1 =clock();
	A4(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 5\n");
	t1 =clock();
	A5(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 6\n");
	t1 =clock();
	A6(num);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	





	
	return 0;
}
