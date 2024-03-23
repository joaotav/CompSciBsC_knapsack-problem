#include <iostream>
#include <fstream>
#include <cstdlib>

/* Implemented by João Chervinski (2018) */

using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return EXIT_FAILURE;
    }

    int n, M, i, x, a, b, *v, *p, *V;

    ifstream arq(argv[1]);

    // Checks if the input file could be successfully opened
    if (!arq.is_open()) {
        cout << "Error reading the input file" << endl;
        exit(EXIT_FAILURE);
    }
    arq >> M; // Reads the capacity of the knapsack from the file
    arq >> n; // Reads the number of items from the file

    v = new int[n]; // Allocates an array for the values
    p = new int[n]; // Allocates an array for the weights

    V = new int[(n+1) * (M+1)]; // Allocate the matrix as an array, initialized to 0

    for (i = 0; i <= M; i++) {
        V[i] = 0;
    }

    for(i = 0; i < n; i++){
        arq >> v[i];
        arq >> p[i];
    }

    for(i = 1; i <= n; i++){
        for(x = 0; x <= M; x++){
            if (p[i-1] <= x) { // Check if the current item's weight is less than or equal to the knapsack's capacity
                // Take the max between taking the item or not taking it
                V[i * (M+1) + x] = max(V[(i-1) * (M+1) + x], v[i-1] + V[(i-1) * (M+1) + x - p[i-1]]);
            } else {
                // If the item cannot be taken, get the value from the previous item
                V[i * (M+1) + x] = V[(i-1) * (M+1) + x];
            }
        }
    }

    cout << "Result: " << V[n * (M+1) + M] << endl;

    delete[] v;
    delete[] p;
    delete[] V;

    return 0;
}
