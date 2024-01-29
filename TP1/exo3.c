#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

//fonction recursive
int pgcd_rec (int a, int b){
	int permute ;
	if(b > a){
		permute = b;
		b = a;
		a =permute;
	}
	if( b == 1){
		return 1;	
	}else{
		if(a%b == 0){
			return b;
		}else{
			return pgcd_rec(b, a %b);
		}
	}
}
//fonction iterative
int pgcd_iter (int a, int b){
	int permute ;
	if(b > a){
		permute = b;
		b = a;
		a =permute;
	}
	if(b == 1)return 1;
	while(a%b !=0){
		b = a%b;	
	}
	return b;
}




int main(){
	int result = pgcd_rec(81,63);
	int result2 = pgcd_iter(81, 63);
	int result3 = pgcd_rec(100, 10);
	int result4 = pgcd_iter(100, 10);
	int result5 = pgcd_rec(877, 63);
	int result6 = pgcd_iter(877, 63);

	printf("%d\n", result);
	printf("%d\n", result2);
	printf("%d\n", result3);
	printf("%d\n", result4);
	printf("%d\n", result5);
	printf("%d\n", result6);

	return 0;
}
