#include <stdio.h>
 
 int main() 
 {
 	unsigned long int i, j;

 	long int num;
 	printf("Enter the number: ");
 	scanf("%ld", &num);

 	long primes[num+1];

 	for(i = 2; i <= num; i++){
 		primes[i] = i;
 	}

 	for(i = 2; (i*i) <= num; i++){
 		if(primes[i] != 0){
 			for(j = (i*i); j <= num; j = j + i){
 				primes[j] = 0;
 			}
 		}
 	}

 	long int count = 0;
 	for(i = 2; i <= num; i++){
 		if(primes[i] != 0){
 			count++;
 		}
 	}
 	printf("The number of primes is: %ld \n", count);

 	return 0;
 }