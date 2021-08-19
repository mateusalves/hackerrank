#include <stdio.h>

void countSwaps( int a_count, int* a)
{
  int numSwaps = 0;
  for(int i = 0; i < a_count-1; i++)
  {
    for(int j = 0; j < a_count-i-1; j++)
    {
      if(*(a + j) > *(a+j+1))
      {
        int tmp = *(a + j);
        *(a + j) = *(a + j + 1);
        *(a + j + 1) = tmp;
        numSwaps++;
      }
    }
    if(a_count - i - 1 == 1)
      break;
  }

  printf("Array is sorted in %d swaps.\n", numSwaps);
  printf("First Element: %d\n", *(a));
  printf("Last Element: %d\n", *(a+a_count-1));
}

int main(int argc, char **argv){
  int n = 7;
  int arr[] = {1, 12, 5, 111, 200, 1000, 10};

  countSwaps(n, arr);

  printf("Array sorted:\n");
  for(int k = 0; k < n; k++)
    printf("%d ", *(arr + k));
  printf("\n");

}
