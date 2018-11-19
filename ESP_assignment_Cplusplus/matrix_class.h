/*
 * matrix_class.h
 *
 *  Created on: 15 Nov 2018
 *      Author: rhydian
 */

#ifndef MATRIX_CLASS_H_
#define MATRIX_CLASS_H_
#include <vector>

using namespace std;

class Matrix{
public:
	Matrix();
	Matrix(int rows, int cols);
	double index(int i, int j);
	void print(void);
	void set_to_zeros(void);
	void randomise_matrix(void);
	vector<double> *get_row(int i);
	void swap_rows(int i1, int i2);
	Matrix get_row_echelon_form(void);
	int get_number_of_rows(void);
	int get_number_of_columns(void);
private:
	vector<vector <double> > data;
	int num_rows;
	int num_columns;
};


vector<double> operator-(vector<double> v1,vector<double> v2);
vector<double> operator*(int k,vector<double> v1);
void printv(vector<double> v);
#endif /* MATRIX_CLASS_H_ */
