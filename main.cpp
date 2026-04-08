#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

const int SIZE = 300;
const int NUM_MATRICES = 30;

vector<vector<int>> A(SIZE, vector<int>(SIZE));
vector<vector<int>> B(SIZE, vector<int>(SIZE));
vector<vector<int>> C(SIZE, vector<int>(SIZE));

void fillRandom(vector<vector<int>> &M) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            M[i][j] = dis(gen);
}

void multiply(int startRow, int endRow) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {

    fillRandom(B);

    for (int t = 1; t <= 12; t++) {

        auto start = chrono::high_resolution_clock::now();

        for (int iter = 0; iter < NUM_MATRICES; iter++) {

            fillRandom(A);

            vector<thread> threads;
            int chunk = SIZE / t;

            for (int i = 0; i < t; i++) {
                int startRow = i * chunk;
                int endRow = (i == t - 1) ? SIZE : startRow + chunk;

                threads.push_back(thread(multiply, startRow, endRow));
            }

            for (int i = 0; i < threads.size(); i++) {
                threads[i].join();
            }
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;

        cout << "Threads: " << t
             << " | Time Taken: " << duration.count()
             << " seconds" << endl;
    }

    return 0;
}