#include <stdio.h>

int main() {
	int height = 5;

    	for (int row = 1; row <= height; row++) {
        	for (int space = 1; space <= height - row; space++) {
            		printf(" ");
        }
        
        	for (int star = 1; star <= 2 * row - 1; star++) {
            		printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}

	
	
