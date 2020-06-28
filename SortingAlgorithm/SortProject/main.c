#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include<time.h>

int main()
{
	int data[MAX_SIZE] = {0};
	int temp[MAX_SIZE] = {0};
	int n = 0; // 数据量
	int a = 0, b = 0; // 计时
	int choice = 0;
	int exe = 0;
	do
    {
		system("cls");
		printf("                               \n");
		printf("    <Sorting algorithm test>   \n");
		printf("-------------------------------\n");
		printf(">>> 1.Insert                   \n");
		printf(">>> 2.Merge                    \n");
		printf(">>> 3.QuickSort(Recursive)     \n");
		printf(">>> 4.QuickSort(not Recursive) \n");
		printf(">>> 5.Count                    \n");
		printf(">>> 6.RadixCount               \n");
		printf(">>> 7.Color                    \n");
		printf(">>> 8.Find No.k large          \n");
		printf(">>> 9.Exit                     \n");
		printf("-------------------------------\n");
		Print(&data, n);
		if(exe)
        {
            printf("Executed in %dms.\n", b-a);
            printf("-------------------------------\n");
        }
        if(exe)
        {
            do
            {
                int try_again;
                printf("Try another algorithm? <0> No <1> Yes\nInput your choice[0/1]:");
                try_again = InputNumber();
                if(try_again == 1)
                {
                    goto label;
                }
                else if(try_again == 0)
                {
                    system("cls");
                    printf("                               \n");
                    printf("    <Sorting algorithm test>   \n");
                    printf("-------------------------------\n");
                    printf(">>> 1.Insert                   \n");
                    printf(">>> 2.Merge                    \n");
                    printf(">>> 3.QuickSort(Recursive)     \n");
                    printf(">>> 4.QuickSort(not Recursive) \n");
                    printf(">>> 5.Count                    \n");
                    printf(">>> 6.RadixCount               \n");
                    printf(">>> 7.Color                    \n");
                    printf(">>> 8.Find No.k large          \n");
                    printf(">>> 9.Exit                     \n");
                    printf("-------------------------------\n");
                    break;
                }
            } while(1);
        }
		printf(">>> 0.Input data by yourself\n>>> 1.Randomly generate data\n>>> 2.Exit\n");
		printf("-------------------------------\n");
		printf("Input your choice[0/1/2]:");
		do
        {
			choice = InputNumber();
			if(choice == 0)
            {
                n = InputData(&data);
                system("cls");
                printf("                               \n");
                printf("    <Sorting algorithm test>   \n");
                printf("-------------------------------\n");
                printf(">>> 1.Insert                   \n");
                printf(">>> 2.Merge                    \n");
                printf(">>> 3.QuickSort(Recursive)     \n");
                printf(">>> 4.QuickSort(not Recursive) \n");
                printf(">>> 5.Count                    \n");
                printf(">>> 6.RadixCount               \n");
                printf(">>> 7.Color                    \n");
                printf(">>> 8.Find No.k large          \n");
                printf(">>> 9.Exit                     \n");
                printf("-------------------------------\n");
				break;
			}
			else if(choice == 1)
			{
                test(&data, &n);
                break;
			}
			else if(choice == 2)
            {
                printf("\nByeBye~\n");
                exit(0);
            }
			printf("No such choice, try agian:");
		} while(1);

        Print(&data, n);
		label:printf("Choose an algorithm:");
		switch(InputNumber())
		{
		case 1:
		    a = clock();
			insertSort(&data, n);
			b = clock();
			exe = 1;
			break;
		case 2:
		    a = clock();
			MergeSort(&data, 0, n - 1, temp);
			b = clock();
			exe = 1;
			break;
		case 3:
		    a = clock();
			QuickSort_Recursion(&data, 0, n - 1);
			b = clock();
			exe = 1;
			break;
		case 4:
		    a = clock();
			QuickSort(&data, n);
			b = clock();
			exe = 1;
			break;
		case 5:
		    a = clock();
			CountSort(&data, n, MAX_SIZE);
			b = clock();
			exe = 1;
			break;
		case 6:
		    a = clock();
			RadixCountSort(&data, n);
			b = clock();
			exe = 1;
			break;
		case 7:
			if(ChecColorData(&data, n) == 0)
            {
                a = clock();
				ColorSort(&data, n);
                b = clock();
                exe = 1;
			}
			else
			{
				printf("Your data must be in [0,1,2].\n");
				system("pause");
			}
			break;
		case 8:
			printf("No.k large? ");
			int k = InputNumber();
			if (k > 0 && k < n)
            {
				printf("No.%d large number is %d.\n", k, No_K(&data, n, k));
			}
			else
			{
				printf("Out of range!\n");
			}
			system("pause");
			break;
		case 9:
			printf("\nByeBye~\n");
			exit(0);
			break;
		default:
			printf("No such choice.\n");
			system("pause");
		}
	} while(1);
	return 0;
}
