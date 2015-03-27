#include <stdio.h>
#include <stdlib.h>
#define NUMBER_SIZE 100

int DisplayNumberArray( int* numberArray, int arraySize, int breakNumber )
{
	int i = 0;
	int lCount = 0;
	for( ; i < arraySize; ++i )
	{
		if( numberArray[i] == breakNumber )
			break;
			
		printf( "%d ", numberArray[i] );

		if( ( ( i % 5 ) == 0 ) && ( i != 0 ) )
			printf( "\n" );
	}
	printf( "\n\n" );

	return 0;
}

// if you wanna returnResult, Set returnArray Parameter over 1
int* ViewMultiplesOfNumber( int multiplesNumber, int *numberArray, int ArraySize, int returnArray )
{
	int i = 0;
	int lCount = 0;
	int *resultArray = 0;

	// If ReturnArray parameter is over 1, Initialize ReturnArray
	if( returnArray >= 1 )
	{
		resultArray = (int*)malloc( sizeof( int ) * ArraySize );
	}


	printf( "Multiples of %d List\n", multiplesNumber );
	for( ; i < ArraySize; ++i  )
	{
		if( ( numberArray[i] % multiplesNumber ) == 0 )
		{
			printf( "%d ", numberArray[i] );

			// Check Array Empty 
			if( resultArray != 0 )
				resultArray[lCount] = numberArray[i];

			lCount++;
			if( ( lCount % 5 ) == 0 )
			{
				printf( "\n" );
			}
		}
	}

	printf( "\n\n" );

	// Write ResultArray's end
	if( resultArray != 0 )
	{
		resultArray[lCount] = -1;
	}

	return resultArray;
}

int main()
{
	int lNumberGroup[NUMBER_SIZE];
	int* resultArray = 0;
	int lCount = 0;
	int i = 0;
	

	// Init
	for( i = 0; i < NUMBER_SIZE; ++i )
	{
		lNumberGroup[i] = i + 1;
	}
	
	// Display Number List
	printf( "Number List\n" );
	DisplayNumberArray( lNumberGroup, NUMBER_SIZE, -1 );
	
	ViewMultiplesOfNumber( 2, lNumberGroup, NUMBER_SIZE, 0 );
	ViewMultiplesOfNumber( 3, lNumberGroup, NUMBER_SIZE, 0 );
	ViewMultiplesOfNumber( 6, lNumberGroup, NUMBER_SIZE, 0 );


	resultArray = ViewMultiplesOfNumber( 6, lNumberGroup, NUMBER_SIZE, 1 );

	if( resultArray != 0 )
		DisplayNumberArray( resultArray, NUMBER_SIZE, -1 );

	if( resultArray != 0 )
		free( resultArray );

	return 0;
}