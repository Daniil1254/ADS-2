int countPairs1(int *arr,int len,int value)
{
  int k = 0;
  for(int i = 0; i < len; i++)
    for(int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value)
         k++;
  return k;
}

int countPairs2(int *arr,int len,int value)
{
  int k = 0;
  int leftBorder = 0;
  int rightBorder = len;
  for(int i = 0; i < len; i++)
    if rightBorder > value
      rightBorder--;
    else break;
  
  for(int j = 0; j < rightBorder; j++)
    for(int i = j + 1; i < rightBorder; i++)
    {
      if (arr[i] + arr[j] == value)
        k++;
        else if (arr[i] + arr[j] > value) 
        for(int g = len - rightBorder; g < len; g++)
          if (rightBorder > value)
          rightBorder--;
        else break;
    }
  return k;
  
}

int countPairs3(int *arr,int len,int value)
{

}
