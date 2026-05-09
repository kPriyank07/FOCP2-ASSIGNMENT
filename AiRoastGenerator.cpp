// =====================================================
//  AI Roast Generator
//  Generates a random (but friendly!) roast by name
// =====================================================

#include <iostream>   // For input/output (cin, cout)
#include <vector>     // For using std::vector
#include <string>     // For std::string
#include <random>     // For mt19937 and uniform_int_distribution (modern randomness)
#include <algorithm>  // For std::all_of (blank input check)

// -------------------------------------------------
// Function: replaceName
// Purpose : Replaces every "{name}" placeholder
//           inside a roast string with the actual
//           user's name before we print it.
// -------------------------------------------------
std::string replaceName(std::string roast, const std::string& name) {
    std::string placeholder = "{name}";
    size_t pos = 0;

    // Keep searching for "{name}" and swapping it out
    while ((pos = roast.find(placeholder, pos)) != std::string::npos) {
        roast.replace(pos, placeholder.length(), name);
        pos += name.length(); // Move past the newly inserted name
    }

    return roast;
}

int main() {

    // ---- Set up a modern random number generator ----
    // std::random_device asks the operating system for a
    // truly unpredictable seed (hardware entropy), so two
    // runs that start in the same second still differ.
    std::random_device rd;

    // mt19937 is a high-quality random engine seeded by rd.
    // Think of it as a much better version of the old rand().
    std::mt19937 rng(rd());

    // ---- Store all roast templates ----
    // Each roast contains "{name}" as a placeholder.
    std::vector<std::string> roasts = {
        "{name} types so slowly that autocorrect gives up halfway.",
        "Even Google needs extra loading time to understand {name}'s search history.",
        "{name} studies so hard that even the calculator asks for a break.",
        "{name}'s Wi-Fi password is so long it took three semesters to memorise.",
        "Scientists discovered a new unit of slowness — they named it after {name}.",
        "{name} once submitted an assignment early. The professor fainted from shock.",
        "{name}'s laptop battery lasts longer than {name}'s attention span. Barely.",
        "Alexa started charging extra just for answering {name}'s questions.",
        "{name} put 'breathing' on their resume under Special Skills.",
        "The spell-checker installed a coffee machine specifically to deal with {name}.",
        "{name} asked the library for a book on common sense. They're still on the waiting list.",
        "NASA's latest discovery: a black hole that consumes snacks at the same rate as {name}."
    };

    // ---- Get the user's name ----
    std::string userName;
    std::cout << "========================================\n";
    std::cout << "       Welcome to AI Roast Generator    \n";
    std::cout << "========================================\n\n";
    std::cout << "Enter your name to receive your roast: ";
    std::getline(std::cin, userName);

    // ---- Validate input ----
    // Reject blank input or input that is only spaces
    bool isBlank = userName.empty() ||
                   std::all_of(userName.begin(), userName.end(), ::isspace);

    if (isBlank) {
        std::cout << "\n[Error] No name entered. ";
        std::cout << "Even the roast generator needs something to work with!\n";
        return 1; // Exit with error code
    }

    // ---- Pick a random roast ----
    // uniform_int_distribution guarantees every roast has
    // exactly the same chance of being picked — no bias.
    // We give it the valid index range: 0 to size-1.
    std::uniform_int_distribution<int> dist(0, static_cast<int>(roasts.size()) - 1);
    int randomIndex = dist(rng); // Ask the distribution for one random index

    // ---- Replace placeholder and display result ----
    std::string finalRoast = replaceName(roasts[randomIndex], userName);

    std::cout << "\n----------------------------------------\n";
    std::cout << "  Your Roast:\n\n";
    std::cout << "  " << finalRoast << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << "\n(All in good fun, " << userName << "! Keep smiling.)\n\n";

    return 0; // Program finished successfully
}
