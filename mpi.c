#include<stdio.h>
#include<mpi.h>
int main(int argc, char** argv)
{
	int rank;
	int a[10] = {1,2,3,4};
	int r[4] = {4,3,2,1};
	MPI_Status st;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank==0){
		MPI_Recv( &a, 4, MPI_INT, 1, 10, MPI_COMM_WORLD, &st);
		printf("The data is received at headoffice from department 1 is\n");
		for(int i = 0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
		a[0] = a[0]*r[0];
         	a[1] = a[1]*r[1];
         	a[2] = a[2]*r[2];
         	a[3] = a[3]*r[3];
         	MPI_Send( &a, 4, MPI_INT, 1, 10, MPI_COMM_WORLD);
		MPI_Recv( &a, 4, MPI_INT, 2, 20, MPI_COMM_WORLD, &st);
		printf("The data is received at headoffice from department 2 is\n");
		for(int i = 0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
		a[0] = a[0]*r[0];
         	a[1] = a[1]*r[1];
         	a[2] = a[2]*r[2];
         	a[3] = a[3]*r[3];
         	MPI_Send( &a, 4, MPI_INT, 2, 20, MPI_COMM_WORLD);
		MPI_Recv( &a, 4, MPI_INT, 3, 30, MPI_COMM_WORLD, &st);
		printf("The data is received at headoffice from department 3 is\n");
		for(int i = 0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
		a[0] = a[0]*r[0];
         	a[1] = a[1]*r[1];
         	a[2] = a[2]*r[2];
         	a[3] = a[3]*r[3];
         	MPI_Send( &a, 4, MPI_INT, 3, 30, MPI_COMM_WORLD);
		
	}
	else if(rank == 1)
	{
		if (!a) // error checking
         	{
          		MPI_Abort (MPI_COMM_WORLD,1);
         	}
         	a[0] = 10;
         	a[1] = 20;
         	a[2] = 30;
         	a[3] = 40;
         	printf("The item cost of department 1\n");
         	for(int i = 0;i<4;i++)
			printf("%d ",a[i]);	
		printf("\n");
		MPI_Send( &a, 4, MPI_INT, 0, 10, MPI_COMM_WORLD);
		printf("The data is sent to the head office from the server number %d\n",rank);
		MPI_Recv( &a, 4, MPI_INT, 0, 10, MPI_COMM_WORLD, &st);
		printf("Successfully Received the data at department number 1 after processing\n");
		for(int i = 0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
		
	}
	else if(rank == 2)
	{
		if (!a) // error checking
         	{
          		MPI_Abort (MPI_COMM_WORLD,1);
         	}
         	a[0] = 5;
         	a[1] = 15;
         	a[2] = 20;
         	a[3] = 25;
         	printf("The item cost of department 2\n");
         	for(int i = 0;i<4;i++)
			printf("%d ",a[i]);	
		printf("\n");
		MPI_Send( &a, 4, MPI_INT, 0, 20, MPI_COMM_WORLD);
		printf("The data is sent to the head office from the server number %d\n",rank);
		MPI_Recv( &a, 4, MPI_INT, 0, 20, MPI_COMM_WORLD, &st);
		printf("Successfully Received the data at department number 2 after processing\n");
		for(int i = 0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else if(rank == 3)
	{
		if (!a) // error checking
         	{
          		MPI_Abort (MPI_COMM_WORLD,1);
         	}
         	a[0] = 2;
         	a[1] = 4;
         	a[2] = 6;
         	a[3] = 8;
         	printf("The item cost of department 3\n");
         	for(int i = 0;i<4;i++)
			printf("%d ",a[i]);	
		printf("\n");
		MPI_Send( &a, 4, MPI_INT, 0, 30, MPI_COMM_WORLD);
		printf("The data is sent to the head office from the server number %d\n",rank);
		MPI_Recv( &a, 4, MPI_INT, 0, 30, MPI_COMM_WORLD, &st);
		printf("Successfully Received the data at department number 3 after processing\n");
		for(int i = 0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	MPI_Finalize();
	return 0;
}
