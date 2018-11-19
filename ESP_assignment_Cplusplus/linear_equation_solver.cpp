/*
 * linear_equation_solver.cpp
 *
 *  Created on: 16 Nov 2018
 *      Author: rhydian
 */

#include <vector>
#include "matrix_class.h"
#include <stdlib.h>

vector<double> solve_linear_equation(Matrix A){
	vector<double> x(A.get_number_of_rows(), 0);
	if(A.get_number_of_columns()-A.get_number_of_rows() != 1){
		printf("Error: Should have augmented matrix with one more column than row");
		return x;
	}
	Matrix A_ech = A.get_row_echelon_form();
	double rh_val;
	for(int i = A_ech.get_number_of_rows()-1; i>=0; i--){

		rh_val = A_ech.index(i,A_ech.get_number_of_columns()-1);
		for(int j = i+1; j<=A_ech.get_number_of_rows(); j++){
			rh_val = rh_val - A_ech.index(i,j)*x[j];
		}
		x[i] = rh_val / A_ech.index(i,i);
	}
	return x;
}

vector<double> generate_random_vector(int size){
	vector<double> return_vec;
	for(int i=0; i < size; i++){
		return_vec.push_back((double)(rand()%100));
	}
	return return_vec;
}


