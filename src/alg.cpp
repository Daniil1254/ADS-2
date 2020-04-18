#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

void sortAscending(int *arr, int len)
{
	int min;
	int address;
	int c;
	for (int i = 0; i < len - 1; i++)
	{
		min = arr[i];
		address = i;
		for (int j = i + 1; j < len; j++)
		if (arr[j] < min)
		{
			min = arr[j];
			address = j;
		}
		c = arr[i];
		arr[i] = min;
		arr[address] = c;
	}
}

int countPairs1(int *arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len; i++)
		for (int j = i + 1; j <= len; j++)
			if (arr[i] + arr[j] == value)
				k++;
	return k;
}

int countPairs2(int *arr, int len, int value)
{
	int k = 0;
	int rightBorder = len;
	sortAscending(arr, len);

	for (int leftBorder = 0; leftBorder < rightBorder; leftBorder++)
	for (int i = leftBorder + 1; i < rightBorder; i++)
	{	
		if (arr[i] + arr[leftBorder] > value)
		{
			rightBorder = i;
			break;
		}
		else if(arr[i] + arr[leftBorder] == value)
			 k++;
	}
	return k;
}



int countPairs3(int *arr, int len, int value)
{
	int k = 0;
	int center;
	int rightBorder = len;
	int leftBorder = 0;
	sortAscending(arr, len);

	for (int i = 0; ((i < len) && (leftBorder < rightBorder)); i++)
	{
		leftBorder = i;
		while (leftBorder + 1 < rightBorder)
		{
			center = (rightBorder + leftBorder) / 2;
			if (arr[i] + arr[center] > value) rightBorder = center;
			else if (arr[i] + arr[center] < value) leftBorder = center;
			else
			{
				while (arr[i] + arr[center] == value)
					center--;
				break;
			}
		}
		while ((arr[i] + arr[center + 1] == value) && (center + 1 < len))
		{
			center++;
			k++;
		} 
	}
	return k;
}
