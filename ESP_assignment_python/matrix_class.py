import numpy as np


class Matrix:
    def __init__(self, num_rows, num_cols):
        row = [0]*num_cols
        self.data = [row]*num_rows
        self.num_rows = num_rows
        self.num_columns = num_cols

    def randomise(self):
        random_numbers = np.random.rand(self.num_rows, self.num_columns)*100
        self.data = list(random_numbers)

    def print(self):
        for i in range(self.num_rows):
            for j in range(self.num_columns):
                print(str(self.data[i][j]) + " ,", end="")
            print("\n")

    def get_row_echelon_form(self):
        newmat = Matrix(self.num_rows, self.num_columns)
        newmat.data = self.data
        for i in range(self.num_columns-1):
            # find first non zero element
            for j in range(i, self.num_rows):
                if newmat.data[j][i] != 0:
                    newmat.swap_rows(i, j)
                    break
            # now set elements of all rows below to zero
            for j in range(i+1, self.num_rows):
                multiplicative_constant = newmat.data[j][i]/newmat.data[i][i]
                for el_it in range(i, self.num_columns):
                    newmat.data[j][el_it] -= newmat.data[i][el_it]*multiplicative_constant
        return newmat

    def swap_rows(self, i, j):
        current_row = self.data[i]
        self.data[i] = self.data[j]
        self.data[j] = current_row


def solve_linear_equation(aug_matrix):
    if aug_matrix.num_columns - aug_matrix.num_rows != 1:
        raise Exception("There should be 1 more column than row for an augmented matrix")
    row_ech = aug_matrix.get_row_echelon_form()
    x = [None]*row_ech.num_rows
    for row_it in range(row_ech.num_rows-1, -1, -1):
        rhs_val = row_ech.data[row_it][-1]
        for col_it in range(row_it+1, row_ech.num_rows):
            rhs_val -= row_ech.data[row_it][col_it]*x[col_it]
        x[row_it] = rhs_val / row_ech.data[row_it][row_it]
    return x
