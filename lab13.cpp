/*
EECS 348 — Lab 13: Debugging & Testing
This file contains:
- The original faulty function (required by assignment)
- Test cases for all 5 questions
- Author: Caleb Morse, verified with assistance from ChatGPT*/

#include <iostream>
#include <vector>
using namespace std;

// Faulty function provided in the lab
bool faillecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

// Helper to print a test
void run_test(const vector<int>& rec, string label) {
    cout << label << "  Input: [ ";
    for (int x : rec) cout << x << " ";
    cout << "]  Output: " << faillecture(rec) << endl;
}

int main() {
    cout << "Running Lab 13 Test Cases\n--------------------------\n";

    // Q2 — impossible to create a test that does NOT execute the fault
    // Still running a sample input to show the loop always executes
    run_test({1,1,1,1,1,1,1,1,1,1}, "Q2 Sample (fault always executes):");

    // Q3 — executes the fault, but no error state
    run_test({1,1,1,1,1,1,1,1,1,1}, "Q3:");

    // Q4 — error state but no failure
    run_test({0,1,1,1,1,1,1,1,1,1}, "Q4:");

    // Q5 — failure (incorrect output)
    run_test({0,0,0,1,1,1,1,1,1,1}, "Q5:");

    return 0;
}
