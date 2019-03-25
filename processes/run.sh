sudo time -v ./processes.exe > log-time
sudo perf stat -d ./processes.exe > log-perf
