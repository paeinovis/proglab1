#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void print(vector<string> stringArray, vector<int> intArray, string dataTitle, string column1, string column2) {
    int titleJust = 33;          // Integers for format (Justification) of tables
    int col1Just = 20;
    int col2Just = 23;
    int histoJust = 20;

    cout << right << setw(titleJust) << dataTitle << endl;          // Prints title of graph as well as column names and divider
    cout << left << setw(col1Just) << column1;
    cout << "|";
    cout << right << setw(col2Just) << column2;
    cout << endl << "--------------------------------------------" << endl;

    for (int i = 0; i < stringArray.size(); i++) {        // Prints data under columns
        cout << left << setw(col1Just) << stringArray[i];
        cout << "|";
        cout << right << setw(col2Just) << intArray[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < stringArray.size(); i++) {        // Prints histogram
        cout << right << setw(histoJust) << stringArray[i] << " ";
        for (int j = 0; j < intArray[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}


int main()
{
    string dataTitle;                                       // Variable declaration of table labels
    string column1;
    string column2;

    string userInput = "null";                              // Variable declaration for evaluation of data
    string userString = "null";
    string userIntString = "null";
    string commaToFind = ",";
    int userInt = 0;
    int numCommas = 0;

    vector<string> stringArray;                             // Declaration of arrays to use to store values
    vector<int> intArray;

    cout << "Enter a title for the data:" << endl;           // Input/output for data title
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl;

    cout << "Enter the column 1 header:" << endl;            // Input/output for column 1
    getline(cin, column1);
    cout << "You entered: " << column1 << endl;

    cout << "Enter the column 2 header:" << endl;            // Input/output for column 2
    getline(cin, column2);
    cout << "You entered: " << column2 << endl;


    while (userInput != "-1"){                             // Beginning of while loop for input
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, userInput);
        numCommas = count(userInput.begin(), userInput.end(), ',');            // Determines how many commas are in the userInput

        if (userInput == "-1") {
            break;
        }
        else if (numCommas == 1) {                                                       // Will execute if a comma was detected
            size_t found = userInput.find(commaToFind);
            userString = userInput.substr(0, found);                    // Grabs string part of input
            userIntString = userInput.substr(found + 1, userInput.length());   // Grabs integer part of input as a string

            try {
                userInt = stoi(userIntString);                                     // Attempts to convert second part of input to integer
            }
            catch(invalid_argument) {                                              // Thrown if no integer detected
                cout << "Error: Comma not followed by an integer." << endl;
                continue;
            }

            cout << "Data string: " << userString << endl;
            cout << "Data integer: " << userInt << endl;

            stringArray.push_back(userString);         // Updates values of string vector array
            intArray.push_back(userInt);               // Updates values of int vector array
        }
        else if (numCommas > 1) {                          // Executes if too many commas (more than 1) given
            cout << "Error: Too many commas in input." << endl;
        }
        else {                                             // Executes if no commas given
            cout << "Error: No comma in string." << endl;
            continue;
        }
    }
    cout << endl;
    print(stringArray, intArray, dataTitle, column1, column2);


    /* Type code here. */
    /* Overall flow of the program:
    Get some input for the title
    Get some input for column header #1
    Get some input for column header #2

    Until the user types "-1":
    Get input for a string
    Validate input
    If valid...
       Split
       Validate second half of input
       If also valid...
          Store separate pieces

    Print out data in table format

    Print out data in chart format
    */

    return 0;
}