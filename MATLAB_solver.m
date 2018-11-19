times = zeros(1000,1);

for i= 1:1:1000
    A = round(rand(i)*100);
    b = round(rand(i,1)*100);
    start = clock;
    linsolve(A,b);
    stop = clock;
    delta_t = stop-start
    times(i) = delta_t(6);
    i
end

csvwrite("./matlab_times.csv",times)