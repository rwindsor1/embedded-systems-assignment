/*
 * main.cpp
 *
 *  Created on: 15 Nov 2018
 *      Author: rhydian
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include "matrix_class.h"
#include "linear_equation_solver.h"
#include <time.h>
using namespace std;



int main()
{
    cout << "Hello, World! \n";

    Matrix my_matrix(100,101);
    printf("Randomise Matrix: \n ");
    my_matrix.randomise_matrix();
    //my_matrix.print();
    clock_t start, end;
    double cpu_time_used;
    //Matrix my_matrix2;
    //printf("Row Echelon Form: \n");
    //my_matrix2 = my_matrix.get_row_echelon_form();
    vector<double> clock_times;
    for(int i = 1;i<=500;i++){
    	Matrix my_matrix(i,i+1);
    	my_matrix.randomise_matrix();
		start = clock();
		//printf("Solve Matrix Equation: \n");
		vector<double> x = solve_linear_equation(my_matrix);
		end= clock();
		//printv(x);
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		clock_times.push_back(cpu_time_used);
		printf("No. of Dimensions: %i, Time taken: %f seconds \n",i,cpu_time_used);
    }
    ofstream output_file("./clock_times.csv");
    ostream_iterator<double> output_iterator(output_file, ",");
    copy(clock_times.begin(), clock_times.end(), output_iterator);
    return 0;
}

