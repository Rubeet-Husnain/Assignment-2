#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int f1[2];
	int f2[2];
	int f3[2];
	int f4[2];
	int f5[2];
	int f6[2];
	int f7[2];
	int f8[2];
	int f9[2];
	int f10[2];

	pipe(f1);
	pipe(f2);
	pipe(f3);
	pipe(f4);
	pipe(f5);
	pipe(f6);
	pipe(f6);
	pipe(f7);
	pipe(f8);
	pipe(f9);
	pipe(f10);

	int ArrSize = 1000;
	int arr[ArrSize];
	for (int index = 0; index<ArrSize; index++)
	arr[index] = index + 1;
	int childProcessId = fork();
	int sum = 0;
	if (childProcessId == 0)
	{
		int start = 0;
		int end = 100;
		for (; start<end; start++)
		sum = sum + arr[start];
		write(f1[1], &sum, sizeof(sum));
   //     close(f1);
		printf("sum from 1st pipe is=%d\n", sum);
	}
	else
	{
		int childProcessId1 = fork();
		if (childProcessId1 == 0)
		{
			int start = 100;
			int end = 200;
			for (; start<end; start++)
			sum = sum + arr[start];
			write(f2[1], &sum, sizeof(sum));
        //    close(f2);
			printf("sum from 2nd pipe is=%d\n", sum);
		}
		else
		{
			int childProcessId2 = fork();
			if (childProcessId2 == 0)
			{
				int start = 200;
				int end = 300;
				for (; start<end; start++)
				sum = sum + arr[start];
				write(f3[1], &sum, sizeof(sum));
             //   close(f3);
				printf("sum from 3rd pipe is=%d\n", sum);
			}
			else
			{
				int childProcessId3 = fork();
				if (childProcessId3 == 0)
				{
					int start = 300;
					int end = 400;
					for (; start<end; start++)
					sum = sum + arr[start];
					write(f4[1], &sum, sizeof(sum));
               //     close(f4);
					printf("sum from 4th pipe is=%d\n", sum);
				}
				else
				{
					int childProcessId4 = fork();
					if (childProcessId4 == 0)
					{
						int start = 400;
						int end = 500;
						for (; start<end; start++)
						sum = sum + arr[start];
						write(f5[1], &sum, sizeof(sum));
                     //   close(f5);
						printf("sum from 5th pipe is=%d\n", sum);
					}
					else
					{
						int childProcessId5 = fork();
						if (childProcessId5 == 0)
						{
							int start = 500;
							int end = 600;
							for (; start<end; start++)
							sum = sum + arr[start];
							write(f6[1], &sum, sizeof(sum));
                          //  close(f6);
							printf("sum from 6th pipe is=%d\n", sum);
						}
						else
						{
							int childProcessId6 = fork();
							if (childProcessId6 == 0)
							{
								int start = 600;
								int end = 700;
								for (; start<end; start++)
								sum = sum + arr[start];
								write(f7[1], &sum, sizeof(sum));
                              //  close(f7);
								printf("sum from 7th pipe is=%d\n", sum);
							}
							else
							{
								int childProcessId7 = fork();
								if (childProcessId7 == 0)
								{
									int start = 700;
									int end = 800;
									for (; start<end; start++)
									sum = sum + arr[start];
									write(f8[1], &sum, sizeof(sum));
                                //    close(f8);
									printf("sum from 8th pipe is=%d\n", sum);
								}
								else
								{
									int childProcessId8 = fork();
									if (childProcessId8 == 0)
									{
										int start = 800;
										int end = 900;
										for (; start<end; start++)
										sum = sum + arr[start];
										write(f9[1], &sum, sizeof(sum));
                                     //   close(f9);
										printf("sum from 9th pipe is=%d\n", sum);
									}
									else
									{
										int childProcessId9 = fork();
										if (childProcessId9 == 0)
										{
											int start = 900;
											int end = 1000;
											for (; start<end; start++)
											sum = sum + arr[start];
											write(f10[1], &sum, sizeof(sum));
                                           // close(f10);
											printf("sum from 10th pipe is=%d\n", sum);
										}
										else
										{
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);

											int sum, sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9;
											read(f1[0], &sum, sizeof(sum));
											read(f2[0], &sum1, sizeof(sum1));
											read(f3[0], &sum2, sizeof(sum2));
											read(f4[0], &sum3, sizeof(sum3));
											read(f5[0], &sum4, sizeof(sum4));
											read(f6[0], &sum5, sizeof(sum5));
											read(f7[0], &sum6, sizeof(sum6));
											read(f8[0], &sum7, sizeof(sum7));
											read(f9[0], &sum8, sizeof(sum8));
											read(f10[0], &sum9, sizeof(sum9));
											int totalSum = 0;
											totalSum = sum + sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8 + sum9;
											printf("Sum is=%d\n", totalSum);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
