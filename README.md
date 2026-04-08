# multiThreadingAssignment

## Overview
102303877
<br>
This project demonstrates the use of multithreading in C++ to optimize matrix multiplication. It analyzes how execution time changes with different numbers of threads and how this relates to CPU cores.

## Objective
- Implement matrix multiplication using multithreading
- Compare execution time for different thread counts
- Identify optimal thread usage

## Methodology
- A constant matrix B is generated once
- Multiple random matrices A are generated
- Each A is multiplied with B
- Work is divided among threads (row-wise)
- Execution time is recorded for threads from 1 to 12

## Multithreading Approach
- Each thread processes a subset of rows
- Threads run in parallel
- Synchronization using `join()`
- Repeated computation simulates real workload

## Results

| Threads | Time (seconds) |
|---------|----------------|
| 1       | 16.0855        |
| 2       | 9.0761         |
| 3       | 6.4517         |
| 4       | 5.4506         |
| 5       | 4.9288         |
| 6       | 5.5618         |
| 7       | 6.3655         |
| 8       | 4.6082         |
| 9       | 4.2839         |
| 10      | 3.74098        |
| 11      | 3.8142         |
| 12      | 3.89822        |

## Performance Graph

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/1ff83b39-8f86-4760-958e-b2a26e7d206d" />


## CPU Utilization

<img width="980" height="305" alt="image" src="https://github.com/user-attachments/assets/e5b654d6-9378-4311-8bf0-0f13c54172ee" />


## Key Observations
- Execution time decreases as threads increase
- Performance improves beyond 6 cores due to workload distribution
- Best performance observed around 10 threads
- After that, overhead causes stabilization

**Note:** Matrix size and iterations were reduced due to hardware constraints.

## Technologies Used
- C++
- Multithreading (`std::thread`)
- MinGW-w64 (GCC 15)
- Excel / Google Sheets

## Conclusion
Multithreading significantly improves performance, but optimal results depend on balancing threads with system capabilities.

## Author
Dhruv Gupta
