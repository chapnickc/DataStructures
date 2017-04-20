HEAPPROFILE=/output.prog ./go
CPUPROFILE=./output.prof ./go 
pprof --text  ./go output.prof

