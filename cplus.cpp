#include <iostream>


using namespace std;

class Matrix {
public:

  //CONSTRUCTORS AND DESTRUCTORS
  Matrix(int rows, int columns){

    row = rows;
    column = columns;

    matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
      matrix[i] = new int[columns];
    }

    //filling the matrix with temp variables
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < columns; j++){
	matrix[i][j] = 0;
      }
    }

  }//end constructor

  //destructor
  ~Matrix(){
    clearData();
  }

  //dynamically deletes data
  void clearData(){
    for(int i = 0; i < row; i++){
      delete[] matrix[i];
    }//end for loop
    delete[] matrix;
    matrix = nullptr;

    row = 0;
    column = 0;
  }

  void fillMatrix(int arr[]){
    //double for loop to fill in matrix
    //int counter to keep track within passed in array
    int counter  = 0;
    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
	matrix[i][j] = arr[counter];
	counter++;
      }//end insider for loop
    }//end outside for loop

  }//end fill matrix

  //this function will display the matrix, for testing purposes
  void displayMatrix(){
    //cycle throguh matrix and print it
    for(int i = 0; i < row; i++){
      cout << endl;
      for(int j = 0; j < column; j++){
	//creating new line when we go to new row
	cout << matrix[i][j] << " ";
      }//end inside for loop
    }//end outside for loop
    cout << endl;
  }//end displayMatrix


  //int transpose(2d matrix int array, rows of the matrix, columns of the matrix)
  int transpose(int  **answer, int r, int c){
    //if the dimensions of the matrix we are storing the answer in aren't correct
    if(r != column || c != row)
      return 0;

    //int order[row*column];
    //int count = 0;

    for(int i = 0; i < column; i++){
      for(int j = 0; j < row; j++){
	answer[i][j] = matrix[j][i];	
      }//end inside for loop
    }//end outside for loop
    //answer.fillMatrix(order);
    
    return 1;
  }//end transpose

  //addMatrix(matrix having multiplication done to it, resulting matrix, result matrix rows, resulting matrix columns)

  
  //if returns 0, means operation didn't happen. If return 1, means it did happen
  int addMatrix(const Matrix& obj, int **answer, int r, int c){
    //making sure dimension of obj and answer match current matrix
    if(obj.row != row || obj.column != column || r != row || c != column)
      return 0;
    
    //int order[row*column];
    //int count = 0;

    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
	answer[i][j] = matrix[i][j] + obj.matrix[i][j];
	//order[count] = matrix[i][j] + obj.matrix[i][j];
	//count++;
      }//end inside for loop
    }//end outside for loop

    //answer.fillMatrix(order);
    return 1;
  }//end addMAtrix


  //multiplyMatrices(matrix passed int, resulting 2d array matrix, answer matrix rows, answer matrix columns);
  int multiplyMatrices(const Matrix& obj, int **answer, int r, int c){
    //making sure answer has valid dimensions
    if(r != row || c != obj.column || column != obj.row)
      return 0;

    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
	int num = 0;
	for(int k = 0; k < obj.row; k++){
	  num += matrix[i][k]*obj.matrix[k][j];
	}//end k loop

	answer[i][j] = num;
      }//end j loop
    }//end i loop

    return 1;
  }//end multiply matrices

  //int scalar(scalar value, resulting matrix, rows of answer, columns of answer);
  //int r and c, are the dimensions of answer... for rows and columns
  int scalar(int scale, int **answer, int r, int c){
    //making sure answer has correct dimensions
    if(r != row || c != column)
      return 0;

    //int order[row*column];
    //int counter = 0;
    
    //for loops to scalar matrix
    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
	//order[counter] = matrix[i][j]*scale;
	//counter++;
	answer[i][j] = matrix[i][j]*scale;
      }//end j loop
    }//end i loop

    //answer.fillMatrix(order);
    
    return 1;
  }//end scalar


  int** getMatrix(){
    return matrix;
  }

  void setMatrix(int **newMatrix){
    matrix = newMatrix;
  }

  int getRow(){
    return row;
  }

  int getColumn(){
    return column;
  }

private:
  //private variables
  int row;
  int column;
  int **matrix;
};// class MatrixFunctions

int main()
{

  //these are the values to be passed into the matrix reading left to right, top down
  int matrixA[] = {6,4,8,3};
  int matrixB[] = {1,2,3,4,5,6};
  int matrixC[] = {2,4,6,1,3,5};

  Matrix a(2,2);
  a.fillMatrix(matrixA);
  cout << "Displaying matrix A: " << endl;
  a.displayMatrix();
  Matrix b(2,3);

  b.fillMatrix(matrixB);
  Matrix c(2,3);
  c.fillMatrix(matrixC);

  Matrix insideParenthesis(2,3);
  insideParenthesis.displayMatrix();
  b.scalar(3, insideParenthesis.getMatrix(), 2, 3);
  insideParenthesis.displayMatrix();
  
  
  Matrix transposed(3,2);
  c.transpose(transposed.getMatrix(), transposed.getRow(), transposed.getColumn());
  transposed.displayMatrix();

  Matrix multMatrices(2,2);
  insideParenthesis.multiplyMatrices(transposed, multMatrices.getMatrix(), 2, 2);
  multMatrices.displayMatrix();

  Matrix d(2,2);
  a.addMatrix(multMatrices, d.getMatrix(), 2, 2);
  d.displayMatrix();
  
  return 0;
}/* main() */
