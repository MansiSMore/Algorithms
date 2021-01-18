#include <stdio.h>


void TowerOfHanoi(int num, char A, char B, char C)
{
	//If only one disk then, move directly from source to destination.
	if(num == 1)
	{
		printf("Disk 1 moved from tower %c to tower %c\n", A, C);
		return;
	}
	
	//Move n-1 disk from A to B using C as auxiliary.
	//Here, source is A, auxiliary is C, destination is B.
	TowerOfHanoi(num - 1, A, C, B);
	
	//Move remaining disks from A to C.
	printf("Disk %d moved from tower %c to tower %c\n", num, A, C);
	
	//Move n-1 disk from B to C using A as auxiliary.
	//Here, source is B, auxiliary is A, destination is C.
	TowerOfHanoi(num - 1, B, A, C);
}

int main()
{
	int num = 0;
	printf("Enter the number of disks : ");
	scanf("%d", &num);
	
	//A = Source, B = Auxiliary, C = Destination. 
	TowerOfHanoi(num, 'A', 'B', 'C');
	return 0;
}
