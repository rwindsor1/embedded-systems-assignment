import random
import time
from matrix_class import Matrix, solve_linear_equation
import matplotlib.pyplot as plt
import numpy as np

times = []
for n in range(1, 500):
    a = Matrix(n, n+1)
    a.randomise()
    start = time.time()
    x = solve_linear_equation(a)
    stop = time.time()
    time_taken = stop-start
    times.append(time_taken)
    print(n)

with open("../clock_times/python_clock_times.csv", "w") as outfile:
    for time_point in times:
        outfile.write(str(time_point))
        outfile.write(",")

print("Some stuff")

