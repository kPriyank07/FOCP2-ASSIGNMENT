// ============================================================
// Smart Student Excuse Generator
// A beginner-friendly C++ console project
// ============================================================

#include <iostream>   // For input/output (cin, cout)
#include <string>     // For using the string type
#include <vector>     // For using vectors (like a resizable list)
#include <random>     // For modern random number generation (mt19937, random_device)

using namespace std;

// ------------------------------------------------------------
// FUNCTION: replaceName
// Takes an excuse template and swaps EVERY {name} with the
// real student name — not just the first one.
//
// BUG FIXED: The old code used find() + replace() only once
// (with an if-statement), so only the first {name} was
// replaced. A template like "{name} told {name}'s teacher..."
// would only fix the first {name} and leave the second as-is.
//
// FIX: A while-loop now keeps searching and replacing until
// no more {name} placeholders remain in the text.
// ------------------------------------------------------------
string replaceName(string excuseTemplate, const string& studentName) {
    string placeholder = "{name}";

    // Search for the first {name} occurrence
    size_t position = excuseTemplate.find(placeholder);

    // Keep replacing as long as {name} is still found
    while (position != string::npos) {
        excuseTemplate.replace(position, placeholder.length(), studentName);

        // Search again from just AFTER the replacement ends,
        // so we don't accidentally scan the same spot twice
        position = excuseTemplate.find(placeholder, position + studentName.length());
    }

    return excuseTemplate;
}

// ------------------------------------------------------------
// FUNCTION: isBlankInput
// Returns true if the input is empty or contains only spaces
// ------------------------------------------------------------
bool isBlankInput(const string& input) {
    for (char ch : input) {
        if (ch != ' ') {
            return false; // Found a real character — not blank
        }
    }
    return true; // Nothing but spaces (or completely empty)
}

// ------------------------------------------------------------
// MAIN FUNCTION — where the program begins
// ------------------------------------------------------------
int main() {

    // --------------------------------------------------------
    // MODERN RANDOM SETUP — fixes the "same excuse on quick
    // re-runs" bug.
    //
    // BUG FIXED: The old srand(time(0)) seeded the random
    // generator using the system clock in whole seconds.
    // If you ran the program twice within the same second,
    // both runs produced the EXACT same excuse every time.
    //
    // FIX: random_device asks the operating system for true
    // hardware entropy (keyboard timing, CPU noise, etc.).
    // It is not clock-based, so rapid re-runs still get
    // completely different seeds — and different excuses.
    //
    // mt19937 is a modern, high-quality random engine.
    // uniform_int_distribution gives a fair pick within range.
    // --------------------------------------------------------
    random_device hardwareRandom;           // Hardware-based unpredictable seed
    mt19937 randomEngine(hardwareRandom()); // Seed the Mersenne Twister engine

    // --------------------------------------------------------
    // EXCUSE TEMPLATES — stored in a vector of strings.
    // Each template uses {name} as a placeholder (can appear
    // more than once in a template now that the bug is fixed).
    // --------------------------------------------------------
    vector<string> excuses = {
        "{name} almost finished the assignment, but the laptop restarted during a Windows update.",
        "{name} completed the homework, but the file mysteriously vanished before submission.",
        "{name} tried uploading the project, but the WiFi decided to take a nap at the worst moment.",
        "{name} saved the assignment on a USB drive, but the dog thought it was a chew toy.",
        "{name} was about to submit when the laptop battery hit 0% — and the charger was nowhere to be found.",
        "{name} wrote a brilliant essay, but accidentally sent it to the class group chat instead of the portal.",
        "{name} spent all night on the homework, but Google Docs said 'No internet connection' at 11:59 PM.",
        "{name} printed the assignment, but the printer only printed the blank pages — classic {name}.",
        "{name} had the homework ready, but accidentally clicked 'Discard' instead of 'Submit'.",
        "{name} typed the whole report, but the cat walked on the keyboard and deleted everything.",
        "{name} finished the code, but it only worked on {name}'s home PC — the lab computers disagreed.",
        "{name} submitted the assignment, but to last semester's course by mistake."
    };

    // Store total excuse count for the distribution range
    int totalExcuses = static_cast<int>(excuses.size());

    // Distribution picks a fair random index between 0 and totalExcuses-1
    uniform_int_distribution<int> pickIndex(0, totalExcuses - 1);

    // --------------------------------------------------------
    // PROGRAM HEADER
    // --------------------------------------------------------
    cout << "=========================================" << endl;
    cout << "    Smart Student Excuse Generator       " << endl;
    cout << "=========================================" << endl;
    cout << "Never face a submission deadline unprepared!" << endl;
    cout << "-----------------------------------------" << endl;

    // --------------------------------------------------------
    // INPUT — ask for the student's name
    // --------------------------------------------------------
    string studentName;

    cout << "\nEnter the student's name: ";
    getline(cin, studentName); // getline reads full line including spaces

    // --------------------------------------------------------
    // INPUT VALIDATION — reject blank or space-only names
    // --------------------------------------------------------
    while (isBlankInput(studentName)) {
        cout << "[!] Name cannot be blank. Please enter a valid name: ";
        getline(cin, studentName);
    }

    // --------------------------------------------------------
    // RANDOM EXCUSE SELECTION
    //
    // pickIndex(randomEngine) generates a random integer in
    // the range [0, totalExcuses - 1] using the seeded engine.
    // No clock dependency — safe to run multiple times fast.
    // --------------------------------------------------------
    int randomIndex = pickIndex(randomEngine);

    // Replace every {name} in the chosen template
    string chosenExcuse = replaceName(excuses[randomIndex], studentName);

    // --------------------------------------------------------
    // OUTPUT — display the result
    // --------------------------------------------------------
    cout << "\n=========================================" << endl;
    cout << "          YOUR EXCUSE IS READY!          " << endl;
    cout << "=========================================" << endl;
    cout << "\n>> " << chosenExcuse << "\n" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Use responsibly. (Or don't. We're not professors.)" << endl;
    cout << "=========================================" << endl;

    return 0; // Program ended successfully
}

// ============================================================
// SUMMARY OF BUGS FIXED
// ------------------------------------------------------------
// BUG 1 — Repeating excuses on quick re-runs:
//   Old: srand(time(0)) — clock-based, same seed within 1 sec
//   Fix: random_device + mt19937 — hardware entropy, always
//        different regardless of how fast you re-run
//
// BUG 2 — Only the first {name} was replaced:
//   Old: if (find()) { replace once } — stops after 1 match
//   Fix: while (find()) { replace, then search again } — loops
//        until every single {name} in the template is replaced
// ============================================================

// ============================================================
// SAMPLE OUTPUTS
// ------------------------------------------------------------
// Run 1:
//   Enter the student's name: Arjun
//   >> Arjun printed the assignment, but the printer only
//      printed the blank pages — classic Arjun.
//      [Note: both {name}s replaced correctly]
//
// Run 2 (run immediately after Run 1 — different result!):
//   Enter the student's name: Arjun
//   >> Arjun finished the code, but it only worked on
//      Arjun's home PC — the lab computers disagreed.
//      [Note: both {name}s replaced correctly]
//
// Run 3 (blank input rejected):
//   Enter the student's name:   (spaces only)
//   [!] Name cannot be blank. Please enter a valid name: Priya
//   >> Priya completed the homework, but the file
//      mysteriously vanished before submission.
// ============================================================
