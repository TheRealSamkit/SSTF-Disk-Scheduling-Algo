# SSTF Disk Scheduling Algorithm

## Overview
This program implements the **Shortest Seek Time First (SSTF) Disk Scheduling Algorithm** in C. The SSTF algorithm selects the disk request that is closest to the current head position, minimizing seek time and improving efficiency.

## Features
- Accepts user input for disk request sequence and initial head position.
- Computes the optimal scheduling order based on the SSTF algorithm.
- Calculates and displays the total seek time.

## How It Works
1. The user inputs the number of disk requests.
2. The user enters the disk request sequence.
3. The user provides the initial position of the disk head.
4. The program selects the request with the shortest seek time (closest to the current head position) and processes it.
5. The process continues until all requests are served.
6. The total seek time is calculated and displayed.

## Compilation and Execution
### Compile the program:
```bash
gcc sstf.c -o sstf
```

### Run the program:
```bash
./sstf
```

## Sample Input/Output
### Input:
```
Enter number of disk requests: 5
Enter Requests for scheduling: 98 183 37 122 14
Enter the initial head position: 53
```

### Output:
```
Disk Scheduling Sequence (SSTF):
37 14 98 122 183 
Total Seek Time: 236
```

## Memory Management
- The program dynamically allocates memory for the request array using `malloc`.
- Memory is freed at the end to prevent memory leaks.

## Limitations
- The program does not handle duplicate requests efficiently.
- It assumes all requests are valid disk positions.

## License
This project is open-source and can be modified or distributed freely.

## Author
Samkit Jain
