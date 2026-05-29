//Pythagorean Theorem
#include <stdio.h>
#include <math.h>

int main ( ) {
	
	int part;
	int valueA, valueB, valueC;
	double resultA, resultB, resultC;
	
	printf("Pythagorean Theorem\n");
	printf(" a² + b² = c² \n\n");
	
	printf("Press for the following:\n");
	printf("[ 1 ] for A\n");
	printf("[ 2 ] for B\n");
	printf("[ 3 ] for C\n\n");
	
	printf("Missing Part: ");
	scanf("%d", &part);
	
	printf("\n\n");
	
	if (part == 1) {
	    
	    printf("Enter the value of ( b ): ");
	    scanf("%d", &valueB);
	    printf("Enter the value of ( c ): ");
	    scanf("%d", &valueC);
	    
	    printf("\n\n");
	    
	    printf("Equation");
	    printf(" a² + %d² = %d²", valueB, valueC);
	    
	    printf("\n\n");
	    
	    printf("Solving......\n\n");
	    
	    printf(" a² + %d² = %d²", valueB, valueC);
	    
	    printf("\n");
	    
	    resultB = valueB * valueB;
	    resultC = valueC * valueC;
	    
	    printf(" a² + %.0lf = %.0lf", resultB, resultC);
	   
	     printf("\n");
	     
	    printf(" a² = %.0lf - %.0lf", resultC, resultB);
	    
	    resultC -= resultB;
	    
	    printf("\n");
	    
	    printf(" a² = %.0lf", resultC);
	    
	    printf("\n");
	    
	    printf(" √a² = √%.0lf", resultC);
	    
	    printf("\n");
	    
	    double sqrt_resultC  = sqrt(resultC);
	    
	    printf(" a = %.2lf", sqrt_resultC);
	    
	    printf("\n\n");
	    
	    printf("Answer: a = %.2lf", sqrt_resultC);
	    
	}
	    
	    else if (part == 2) {
	    
	    printf("Enter the value of ( a ): ");
	    scanf("%d", &valueA);
	    printf("Enter the value of ( c ): ");
	    scanf("%d", &valueC);
	    
	    printf("\n\n");
	    
	    printf("Equation");
	    printf(" %d² + b² = %d²", valueA, valueC);
	    
	    printf("\n\n");
	    
	    printf("Solving......\n\n");
	    
	    printf(" %d² + b² = %d²", valueA, valueC);
	    
	    printf("\n");
	    
	    resultA = valueA * valueA;
	    resultC = valueC * valueC;
	    
	    printf(" %.0lf + b² = %.0lf", resultA, resultC);
	   
	     printf("\n");
	     
	    printf(" b² = %.0lf - %.0lf", resultC, resultA);
	    
	    resultC -= resultA;
	    
	    printf("\n");
	    
	    printf(" b² = %.0lf", resultC);
	    
	    printf("\n");
	    
	    printf(" √b² = √%.0lf", resultC);
	    
	    printf("\n");
	    
	    double sqrt_resultC  = sqrt(resultC);
	    
	    printf(" b = %.2lf", sqrt_resultC);
	    
	    printf("\n\n");
	    
	    printf("Answer: b = %.2lf", sqrt_resultC);
	    
	    }
	    
	    else if (part == 3) {
	    
	    printf("Enter the value of ( a ): ");
	    scanf("%d", &valueA);
	    printf("Enter the value of ( b ): ");
	    scanf("%d", &valueB);
	    
	    printf("\n\n");
	    
	    printf("Equation");
	    printf(" %d² + %d² = c²", valueA, valueB);
	    
	    printf("\n\n");
	    
	    printf("Solving......\n\n");
	    
	    printf(" %d² + %d² = c²", valueA, valueB);
	    
	    printf("\n");
	    
	    resultA = valueA * valueA;
	    resultC = valueC * valueC;
	    
	    printf(" a² + %.0lf = %.0lf", resultB, resultC);
	   
	     printf("\n");
	     
	    printf(" a² = %.0lf - %.0lf", resultC, resultB);
	    
	    resultC -= resultB;
	    
	    printf("\n");
	    
	    printf(" a² = %.0lf", resultC);
	    
	    printf("\n");
	    
	    printf(" √a² = √%.0lf", resultC);
	    
	    printf("\n");
	    
	    double sqrt_resultC  = sqrt(resultC);
	    
	    printf(" a = %.2lf", sqrt_resultC);
	    
	    printf("\n\n");
	    
	    printf("Answer: a = %.2lf", sqrt_resultC);
	    
	    
	    }
	    
	    else {
	    printf("ERROR OCCURED");
	    
	}
	
	return 0;
	    	
}
