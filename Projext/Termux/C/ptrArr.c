#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr,"[!] Example : ./ptrArr size_of_array\n");	
		exit(EXIT_FAILURE);
	}
	else
	{
		size_t size = atoi(argv[1]);

		/*
			variable  : ptr
			data_type : int*
			size      : size * sizeof(ptr)
			          : 4 * 4
			          : ptr[4]
		*/
		int *ptr = malloc(size * sizeof(ptr));

		if(ptr != NULL)
		{
			size_t i;
			for (i = 0; i < size; i++)			
			{
				// assign value to n elements
				*(ptr + i) = i * 4;
			}
			
			size_t j;
			for (j = 0; j < size; j++)
			{
				fprintf(stdout,"[%d] : %d \n",j,*(ptr + j));
			}
			/*
				variable  : ptr
				data_type : int*
				size      : size / 2
						  : 4 / 2
						  : ptr[2]
			*/
			ptr = realloc(ptr, size / 2);

			*(ptr + 50) = 100; // assign 100 to 50th int

			fprintf(stdout,"\n[%d] : %d\n",50, *(ptr + 50));
		}
		else
		{
			fprintf(stderr,"[!] Failed To Allocate Memory.\n");
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;
}

