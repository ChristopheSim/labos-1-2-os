sudo time -v ./app.exe > log-time
sudo perf stat -d ./app.exe > log-perf
