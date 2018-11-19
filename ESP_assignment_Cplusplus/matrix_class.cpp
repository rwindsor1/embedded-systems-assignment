/*
 * matrix_class.cpp
 *
 *  Created on: 15 Nov 2018
 *      Author: rhydian
 */


#include <iostream>
#include <vector>
#include <stdlib.h>
#include<time.h>
#include "matrix_class.h"

vector<double> operator-(vector<double> v1,vector<double> v2){
	vector<double> return_vec = v1;
	if(v1.size() != v2.size()){
		printf("ERROR : tried to subtract two vectors of different sizes");
		return return_vec;
	}
	for(int i = 0; i <v1.size(); i++){
		return_vec[i] = v1[i] - v2[i];
	}
	return return_vec;
}

vector<double> operator*(double k, vector<double> v1){
	vector<double> return_vec = v1;
	for(int i = 0; i <v1.size(); i++){
			return_vec[i] = k*v1[i];
		}
	return return_vec;
}

void printv(vector<double> v){
	int size = (int) v.size();
	for(int i = 0; i< size;i++){
		printf("%f ,", v[i]);
	}
}

// MATRIX CLASS FUNCTIONS
Matrix::Matrix(){
	num_rows = 0;
	num_columns = 0;
}

Matrix::Matrix(int rows, int cols){

	num_rows = rows;
	num_columns = cols;
	data.assign(num_rows,vector<double>(num_columns,0));
}

double Matrix::index(int i, int j){
	//check in bounds
	if(i >= num_rows || j >= num_columns ){
		printf("ERROR, tried to access something out of bounds \n");
		return (double) NULL;
	}


	return data[i][j];
};

void Matrix::print(void){
	for(int i = 0; i < num_rows; i++){
		for(int j = 0; j <num_columns; j++){
			printf("%.2f ,", data[i][j]);
		}
		printf("\n");
	};
	return;
};

void Matrix::randomise_matrix(){
	srand(time(0)); //randomised seed
	for(int i = 0; i < num_rows; i++){
			for(int j = 0; j <num_columns; j++){
				data[i][j] = (double) (rand() % 100 + 1);
			}
		};
	return;
}

int Matrix::get_number_of_rows(){
	return num_rows;
}

int Matrix::get_number_of_columns(){
	return num_columns;
}

vector<double>* Matrix::get_row(int i){
	return &data[i];
}

void Matrix::swap_rows(int i1,int i2){
	vector<double> switch_row = data[i1];
	data[i1] = data[i2];
	data[i2] = switch_row;
	return;
}

Matrix Matrix::get_row_echelon_form(){
	// loop across columns
	Matrix new_matrix = *this;
	for(int col_it = 0; col_it < num_columns-1; col_it++){
		// find first non-zero entry in columns
		for(int elem_it=col_it; elem_it < num_rows; elem_it++){
			if(new_matrix.index(elem_it,col_it) != 0){
				new_matrix.swap_rows(elem_it, col_it);
				break;
			}
		}
		// set alias for row with non-zero entry
		vector<double> pivot_row = *new_matrix.get_row(col_it);
		for(int row_it = col_it+1 ; row_it < num_rows; row_it++){
			double multiplic_const = (double) (new_matrix.index(row_it,col_it)/pivot_row[col_it]);
			*new_matrix.get_row(row_it) = *new_matrix.get_row(row_it)- (multiplic_const*pivot_row);
		}
	}

	return new_matrix;
}


