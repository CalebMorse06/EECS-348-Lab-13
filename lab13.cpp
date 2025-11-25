/*
EECS 348 — Lab 13: Debugging & Testing
Student: Caleb Morse
Edited and verified by: ChatGPT 
Date: Fall 2025

This program includes:
- The ORIGINAL buggy function (provided in the lab assignment)
- The corrected function (required by TA clarification)
- Test cases showing:
    Actual Output   = result of buggy function
    Expected Output = result of corrected function

Written answers to Questions 1–5 are in answers.txt.
*/

#include <iostream>
#include <vector>
using namespace std;

// ---------------------------------------------------
// ORIGINAL BUGGY FUNCTION (starts loop at index 1)
// ---------------------------------------------------
bool faillecture_buggy(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

// ---------------------------------------------------
// CORRECTED FUNCTION (starts loop at index 0)
// ---------------------------------------------------
bool faillecture_correct(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 0; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

// ---------------------------------------------------
// PRINT TEST RESULTS (Actual = buggy, Expected = correct)
// ---------------------------------------------------
void run_test(const vector<int>& rec, const string& label) {
    cout << label << "\nInput: [ ";
    for (int x : rec) cout << x << " ";
    cout << "]\n";

    bool actual = faillecture_buggy(rec);
    bool expected = faillecture_correct(rec);

    cout << "Actual (buggy):     " << actual << "\n";
    cout << "Expected (correct): " << expected << "\n";
    cout << "--------------------------------------------------\n";
}

int main() {
    cout << "Running Lab 13 Test Cases\n";
    cout << "--------------------------------------------------\n";

    // Q2 — Fault always executes; sample case only
    run_test({1,1,1,1,1,1,1,1,1,1}, "Q2 Sample (fault always executes):");

    // Q3 — executes fault but NO error state
    run_test({1,1,1,1,1,1,1,1,1,1}, "Q3:");

    // Q4 — error state but NO failure
    run_test({0,1,1,1,1,1,1,1,1,1}, "Q4:");

    // Q5 — failure occurs
    run_test({0,0,0,1,1,1,1,1,1,1}, "Q5:");

    return 0;
}
