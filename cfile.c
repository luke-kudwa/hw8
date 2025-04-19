#include <stdio.h>
#include <stdlib.h>

struct Matrix{
  int **matrix;
  int row;
  int col;

};

/*
int** addMatracies(int** matrixA, int** matrixB) {
  
}//end addMatricies
*/

void displayMatrix(struct Matrix m){

  for(int i = 0; i < m.row; i++){
    for(int j = 0; j < m.col; j++){
      printf("%d\t", m.matrix[i][j]);
    }//end loop j
    printf("\n");
  }//end loop i

  printf("\n\n");
}//end display



//int scalar(matrix being scaled, value to scale matrix by, resulting matrix);
int scalar(struct Matrix m, int scale, struct Matrix ans){
  if(ans.row != m.row || ans.col != m.col)
    return 0;

  for(int i = 0; i < m.row; i++){
    for(int j = 0; j < m.col; j++){
      ans.matrix[i][j] = m.matrix[i][j]*scale;
    }//end j loop
  }//end i loop
  
  return 1;
}//end scalar



//int addMatrices(matrix being added to, matrix adding onto, resulting matrix);
int addMatrices(struct Matrix m1, struct Matrix m2, struct Matrix ans){
  //storing variables for readability later
  int row = m1.row;
  int col = m1.col;
  //making sure everything has the same dimensions
  if(m2.row != row || ans.row != row || m2.col != col || ans.col != col)
    return 0;
  //add the matrices
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      ans.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
    }//end j loop
  }//end i loop
  //return 1, saying the operation was a success
  return 1;
}//end addMatrices



//int multMatrices(matrix being multiplied, matrix multiplying, resulting matrix)
int multMatrices(struct Matrix m1, struct Matrix m2, struct Matrix ans){

  if(ans.row != m1.row || ans.col != m2.col || m1.col != m2.row)
    return 0;

  for(int i = 0; i < ans.row; i++){
    for(int j = 0; j < ans.col; j++){
      int num = 0;
      for(int k = 0; k < m2.row; k++){
	num += m1.matrix[i][k]*m2.matrix[k][j];
      }//end k loop
      ans.matrix[i][j] = num;
    }//end j loop
  }//end i loop

  return 1;
}//end multMatrices


//int transpose(matrix being transposed, resulting matrix);
int transpose(struct Matrix m1, struct Matrix ans){
  printf("Line: 87\n");
  if(ans.row != m1.col || ans.col != m1.row)
    return 0;

  printf("Line: 91\n");
  for(int i = 0; i < m1.col; i++){
    for(int j = 0; j < m1.row; j++){
      printf("Line: 94\n");
      ans.matrix[i][j] = m1.matrix[j][i];
    }//end j loop
  }//end i loop

  return 1;
}//end transpose


int** createMatrix(int order[], int r, int c){
  //dynamically creating 2d array
  int** arr = (int**)malloc(r * sizeof(int*));
  for (int i = 0; i < r; i++){
    arr[i] = (int*)malloc(c * sizeof(int));
  }//end for loop

  //populating array
  int count = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      arr[i][j] = order[count];
      count++;
    }//end j loop
  }//end i loop

  return arr;
}//end createMatrix




void clearMatrix(int** arr, int r){  
  //deallocates memory for each array inside the 2d array
  for (int i = 0; i < r; i++)
    free(arr[i]);
  //deallocates the 2d array
  free(arr);  
}




int main()
{

  int tempSmall[] = {0,0,0,0};
  int temp[] = {0,0,0,0,0,0};
  int arrA[] = {6,4,8,3};
  int arrB[] = {1,2,3,4,5,6};
  int arrC[] = {2,4,6,1,3,5};
  int** matrixA = createMatrix(arrA, 2, 2);
  int** matrixB = createMatrix(arrB, 2, 3);
  int** matrixC = createMatrix(arrC, 2, 3);
  int** matrixT = createMatrix(temp, 2, 3);
  int** matrixTran = createMatrix(temp, 3,2);
  int** matrixTS = createMatrix(tempSmall, 2, 2);
  
  struct Matrix mA = {matrixA, 2, 2};
  struct Matrix mB = {matrixB, 2, 3};
  struct Matrix mC = {matrixC, 2, 3};

  struct Matrix scaled = {matrixT, 2, 3};
  struct Matrix transposed = {matrixTran, 3, 2};
  struct Matrix multiplied = {matrixTS, 2, 2};
  struct Matrix mD = {matrixTS, 2, 2};
  
  scalar(mB, 3, scaled);
  displayMatrix(mB);
  displayMatrix(scaled);
  printf("Line: 159\n");

  displayMatrix(transposed);
  transpose(mC, transposed);
  displayMatrix(transposed);
  displayMatrix(mC);
  printf("Line: 164\n");
  
  multMatrices(scaled, transposed, multiplied);
  printf("Line: 167\n");
  displayMatrix(multiplied);
  printf("Line: 169\n");
  
  addMatrices(mA, multiplied, mD);
  displayMatrix(mD);

  
  return 0;
}/* main() */
