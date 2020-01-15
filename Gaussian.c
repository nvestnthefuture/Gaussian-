#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*************************************************
 *************************************************
**Program Name: Gaussian Elimination 
**Purpose: To perform Gaussian Elimination
**         Put the system in row echelon form
**         Use back substitution to compute values
**         for x1, x2, & x3
**         Use Gaussian Elimination with partial 
**         pivot to recompute the values for x1, 
**         x2, & x3.
**Author:  Jessica Byrd
**Date:    11/17/2019
**Version: 1.0
*************************************************
*************************************************/

/*************************************************
**************************************************
**	Program Structure:
**
**			GaussianElimination
**			   getCoefficients 
**			   displayCoefficients	
**			RowEchelonForm
**		           displayREF
**			BackSubstitution
**			   displayBS
**			PartialPivot
**			   displayPP			
***************************************************
***************************************************/
//Global Var
	float array[3][4];

//Partial Pivot
int partialPivotZ(int column)
{
	//Declaration & Initialization
        float x;
	int y = column;
	x = array[column][column];

	   //Compare R1 & C1
           //Compare R2 & C1
           //Compare R3 & C1
	   for(int i = column; i <= 2; i++)
	    {
              if(fabs(x) < fabs(array[i][column]))
               {
		  x = array[i][column];
                  y = i;
	       }
             }

             float pivotArray[4];
	     for(int i = column; i < 4; i++)
             {
		 pivotArray[i] = array[column][i];
                 array[column][i] = array[y][i];
	         array[y][i] = pivotArray[i];
      	     }

	return 0;
}

int backSubstitution()
{
	//Perform Back Substitution
	//Make a 1D array to hold the solutions
	float arrayBackSubstitution[3];

	arrayBackSubstitution[2] = array[2][3] / array[2][2];
	arrayBackSubstitution[1] = (array[1][3] - (arrayBackSubstitution[2] * array[1][2] / array[1][1]));
	arrayBackSubstitution[0] = (array[0][3] - (arrayBackSubstitution[2] * array[0][2] + arrayBackSubstitution[1] * array[0][1])) / array[0][0];

	//Print the results
	printf("The Back Substitution Values are: %fx1 + %fx2 + %fx3\n", arrayBackSubstitution[0], arrayBackSubstitution[1], 
		arrayBackSubstitution[2]);

}

float main()
{
   
	//Declaration & Initialization
    	int row;
	int column;
	int preferredMethod;
	float x1;
	float x2;
	float x3;
        float polynomialResults;

	//Ask the user to select their preferred Numerical Method
	printf(">Choose 1 for Gaussian Elimination\n");
        printf("             OR\n");
        printf(">Choose 2 for Partial Pivot with Gaussian Elimination\n");

	//get User Input
	scanf("%d", &preferredMethod);
	getchar();

	//Get the Polynomial from the user and store in an array
   	//Ask user to input a coefficient  
   	//Loop three times and store the results
   	for(row = 0; row <= 2; row++)
    	{
        	printf("Enter your coefficients for x1: ");
   		scanf("%f", &x1);
        	array[row][0] = x1;
   		printf("Enter your coefficients for x2: ");
  		scanf("%f", &x2);
		array[row][1] = x2;

   		printf("Enter your coefficients for x3: ");
   		scanf("%f", &x3);
		array[row][2] = x3;
 
		//Ask user to enter the results of the polynomial
   		printf("Enter the results of your polynomial: ");
   		scanf("%f", &polynomialResults);
		array[row][3] = polynomialResults;

		//Print the array out for the user
		printf("The polynomial you have entered is: %fx1 + %fx2 + %fx3 = %f\n", x1, x2, x3, polynomialResults);
   	         
   	 }

	//Gaussian Elimination Choice for user choice 1
	if(preferredMethod == 1)
	{
		//Declaration & Initialization
   		int rowUpdated;
		int columnUpdated;
		float newX;

		//Matrix into row echelon form
		//Cancel out column 1 for everything greater than row 1
		//For loop to cancel out column 0 & column 1
		for(columnUpdated = 0; columnUpdated <= 1; columnUpdated++)
		{

			//For loop to traverse the next row
			for(rowUpdated = columnUpdated + 1; rowUpdated <= 2; rowUpdated++)
		  	{
			
				newX = array[rowUpdated][columnUpdated] / array[columnUpdated][columnUpdated];
				
				for(int i = columnUpdated; i < 4; i++)
			 	{
					array[rowUpdated][i] = array[rowUpdated][i] - newX * array[columnUpdated][i];
					
				}
			}
		}

		//Temp loop
		int i; 
	
		for(i = 0; i < 3; i++)
		{
			//Print the new updated array out for the user
			//printf("The new matrix in row echelon form is: %fx1 + %fx2 + %fx3 = %f\n", x1, x2, x3, polynomialResults);
			printf("The updated matrix in row echelon form is: %fx1 + %fx2 + %fx3 + %fx4\n", array[i][0], array[i][1], array[i][2], array[i][3]);

		}

		backSubstitution();
	}		


	//User choice 2, Thus, perform Parital Pivot and recompute the values for x1, x2, & x3
	else
	{
		int i;
		float newX;

		for (int columnUpdated = 0; columnUpdated <= 1; columnUpdated++)
		{
			partialPivotZ(columnUpdated);

			//For loop to traverse the next row
			for(int rowUpdated = columnUpdated + 1; rowUpdated <= 2; rowUpdated++)
	  		{
		
				newX = array[rowUpdated][columnUpdated] / array[columnUpdated][columnUpdated];
				
				for(int i = columnUpdated; i < 4; i++)
		 		{
					array[rowUpdated][i] = array[rowUpdated][i] - newX * array[columnUpdated][i];
					
				}
			}
			
		}
		
		//Temp loop
		for(int j = 0; j < 3; j++)
		{
			//Print the new updated array out for the user
			//printf("The new matrix in row echelon form is: %fx1 + %fx2 + %fx3 = %f\n", x1, x2, x3, polynomialResults);
			printf("The updated matrix in row echelon form is: %fx1 + %fx2 + %fx3 + %fx4\n", array[j][0], array[j][1], array[j][2], array[j][3]);

		}
		
		//Back Substitution
		backSubstitution();
	}       

}	

//End of Program
   


	



































