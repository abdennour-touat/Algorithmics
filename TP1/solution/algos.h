#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

bool A1 (long long n){
	//boolean
	bool premier = true;
	long long i = 2;
	while(i <= n -1 && premier){
		if(n % i == 0){
			premier = false;
		}else{
			i++;
		}
	}
	return premier;
}

bool A2 ( long long n){
	//boolean
	bool premier = true;
	long long i = 2;
	while(i <= n/2  && premier){
		if(n % i == 0){
			premier = false;
		}else{
			i++;
		}
	}
	return premier;
}
bool A5 (long long n){
	//boolean
	bool premier = true;	
	long long i = 2;
	while(i <= sqrt((double)n)  && premier){
		if(n % i == 0){
			premier = false;
		}else{
			i++;
		}
	}
	return premier;
}
bool A4 (long long  n){
	//boolean
	bool premier = true;	
	if(n != 2 && n % 2 ==0){
		premier = false;
	}else{
		if(n !=2){

		long long i= 3;
		while(i <= n/2 && premier){
			if(n % i == 0){
				premier = false;
			}else{
				i = i+2;
			}
		}
		}
	}
	return premier;
}
bool A3 (long long n){
	//boolean
	bool premier = true;	
	if(n != 2 && n % 2 == 0){
		premier = false;
	}else{
		if(n !=2){
			long long i = 3;
			while (i <= n-2 && premier){
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
bool A6 (long long n){
	//boolean
	bool premier = true;	
	if(n !=2 && n%2 == 0){
		premier = false;	
	}else{
		if(n !=2){
			long long i =3;
			while (i <= sqrt((double)n)&& premier){
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
