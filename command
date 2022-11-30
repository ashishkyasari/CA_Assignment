gcc -Wall -pg profile.c -o profile

gprof profile gmon.out > output


mpicc mpi.c -o mpi
mpirun -np 4 ./mpi

awk -f grading.awk grade.txt > res.txt
