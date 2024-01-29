#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main (){
    FILE* ptr;
    char ch[3];
    char c;
	int *list;
    // Opening file in reading mode
    ptr = fopen("1000asc.txt", "r");
    fseek(ptr, 0L, SEEK_END);
    int sz = ftell(ptr);
    rewind(ptr);
    printf("size of the file is : %d\n", sz);

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

//    printf("content of this file are \n");

    // Printing what is written in file
    // character by character using loop.
    int i = 1;
     while (c != EOF){
	 fscanf(ptr, "%[^\n]", ch);
	 printf("the line value is %s\n", ch); 
	 list[i] = atoi(ch);
	 c = fgetc(ptr);

	 i++;
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } ;
     for (int k = 1; k< i; k++){
	     printf("%d",list[i]);
     }

    printf("the i value is : %d",i);
    // Closing the file
    fclose(ptr);
	return 0;
}
