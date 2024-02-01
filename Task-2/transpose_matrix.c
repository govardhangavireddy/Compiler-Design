// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>
void readmatrix(int arr[100][100], int r, int c) {
  printf("Enter the matrix elements : ");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

void transpose(int arr[100][100], int r, int c) {
  int temp;
  for (int i = 0; i < r; i++) {
    for (int j = i; j < c; j++) {
      if (i == j) {
        continue;
      }
      temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }
}

void printmatrix(int arr[100][100], int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d\t", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int arr[100][100];
  int r, c;
  printf("Enter dimensions of matrix : ");
  scanf("%d %d", &r, &c);
  if (r == c) {
    readmatrix(arr, r, c);
    printf("Original matrix : \n");
    printmatrix(arr, r, c);
    transpose(arr, r, c);
    printf("Transpose matrix : \n");
    printmatrix(arr, r, c);
  } else {
    printf("Matrix is not square ");
  }
  return 0;
}