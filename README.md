# hw8

Author: Luke Kudwa, a student at UMBC, enrolled in CMSC 313 section 5 with Kid Kidd. Assignment is due 4/19/2025 at 11:59pm.
Purpose: The purpose of the code is to allow users to do matrix functions: Matrix addition, Matrix Multiplication, Transpose, and scalar of a matrix.

Important Functions: addMatrix() - adds 2 matrices together, scalar() - applys a scale to a matrix, transpose() - creates the transpose of a matrix(), multMatrices() - multiplies 2 matrices together.

Files:
        - cfile.c is a c program that has a structure called matrix that stores the variables of a matrix. The file also has the 4 listed functions in "purpose" up above. The 4 listed matrix functions all return an
        int. Either 1 or 0, 1 is returned when the operation was successful. But 0 is returned when it didn't do the operation.
        - cplus.cpp is a c++ program that has a class called matrix that stores variables but also functions of a matrix. The 4 important functions are the ones listed above. The 4 listed matrix functions all return an
        int. Either 1 or 0, 1 is returned when the operation was successful. But 0 is returned when it didn't do the operation.

Build Instructions:

      cfile.c   - In order to create a matrix: you must first create a 1d int array with the values put in. To enter the values into the aray you go left to right, top down if you were reading a 2d array. For example
      if I were to create the matrix C as listed in the homework description, it would be {2, 4, 6, 1, 3, 5}... and matrix A would be {6, 4, 8, 3}. Once you have the 1d version of the matrix, you create a int** that
      is equal to the return of createMatrix(1d array, # of rows, # of columns);    Then you can create a struct with "struct Matrix (insert Name) = {int**, rows, columns};"

      cplus.cpp - In order to create a matrix object:  you must first create a 1d int array with the values put in. To enter the values into the aray you go left to right, top down if you were reading a 2d array.
      For example if I were to create the matrix C as listed in the homework description, it would be {2, 4, 6, 1, 3, 5}... and matrix A would be {6, 4, 8, 3}. Once you have the 1d version of the matrix, create a
      matrix object with the specified rows and columns, ex/ Matrix matrixA(2,2); creates a matrix with 2 rows and 2 columns but an empty matrix with 0 as place holder values. Then call that objects function
      fillMatrix(int*) with the parameter being that 1d int array with all the matrix values passed in.

Testing methodology:
        - Create the matrix objects, and to test a matrix function (the four listed above) you must first create a matrix with the expected resulting dimensions (can be a blank 2d array of like striaght 0's). The
        parameters you send in to each function, make sure the follow the comment above each of those 4 functions where the code is written in each file. It tells what each parameter means.

        In other words, each time you do one of the 4 listed functions, you must create a new matrix where the resulting matrix will be stored.


Additional information:
           - I will leave example code in my main functions to provide examples of me solving the function D = A + (3*B) X C^T
