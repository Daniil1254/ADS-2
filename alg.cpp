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

	for (int leftBorder = 0; leftBorder < rightBorder; leftBorder++)
	for (int i = leftBorder + 1; i < rightBorder; i++)
	{
		if (arr[i] + arr[leftBorder] == value)
			k++;
		else if (arr[i] + arr[leftBorder] > value)
			rightBorder = i;
	}
	return k;
}



int countPairs3(int *arr, int len, int value)
{
	int k = 0;
	int center;
	int rightBorder = len;
	int leftBorder = 0;

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
