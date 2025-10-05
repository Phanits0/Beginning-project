#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Birthday {
public:
    string name;
    int day, month, year;
};

vector<Birthday> vectorBirthdaylist;

bool checkInputNumber() {
    if (cin.fail()) {
        cout << "Please input number only." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void Displaybirthdaylist() {
    if (vectorBirthdaylist.empty()) {
        cout << "\nNo birthday data to display!" << endl;
        return;
    }
    cout << "\n===== Birthday List =====" << endl;
    for (unsigned int i = 0; i < vectorBirthdaylist.size(); ++i) {
        cout << i + 1 << ": "
             << "Name: " << vectorBirthdaylist[i].name
             << ", Day: " << vectorBirthdaylist[i].day
             << ", Month: " << vectorBirthdaylist[i].month
             << ", Year: " << vectorBirthdaylist[i].year << endl;
    }
}

void ReadDataFileTovector() {
    ifstream infile("birthdays3.txt");
    if (!infile.is_open()) {
        cout << "birthdays3.txt not found. A new file will be created upon saving." << endl;
        return;
    }
    string name;
    int day, month, year;
    vectorBirthdaylist.clear(); // Clear vector before loading new data
    while (infile >> name >> day >> month >> year) {
        Birthday tmpBirthday;
        tmpBirthday.name = name;
        tmpBirthday.day = day;
        tmpBirthday.month = month;
        tmpBirthday.year = year;
        vectorBirthdaylist.push_back(tmpBirthday);
    }
    infile.close();
    cout << "Loaded " << vectorBirthdaylist.size() << " birthdays from file." << endl;
    Displaybirthdaylist();
}

void saveDatafromvectortofile() {
    ofstream outfile("birthdays3.txt");
    if (!outfile.is_open()) {
        cout << "Error: Cannot open birthdays3.txt for writing!" << endl;
        return;
    }
    cout << "Saving " << vectorBirthdaylist.size() << " birthdays to file..." << endl;
    for (unsigned int i = 0; i < vectorBirthdaylist.size(); ++i) {
        outfile << vectorBirthdaylist[i].name << " "
                << vectorBirthdaylist[i].day << " "
                << vectorBirthdaylist[i].month << " "
                << vectorBirthdaylist[i].year << "\n";
    }
    outfile.close();
    cout << "File completed save." << endl;
}

void addBirthday() {
    int count;
    cout << "How many birthdays do you want to add? ";
    cin >> count;if (!checkInputNumber()) return;
    cin.get(); // Clear newline from input buffer

    for (int i = 0; i < count; i++) {
        Birthday newBirthday;
        cout << "\n--- Adding Birthday " << i + 1 << " of " << count << " ---" << endl;
        cout << "Enter name: ";
        cin >> newBirthday.name;
        cout << "Enter day: ";
        cin >> newBirthday.day; if (!checkInputNumber()) return;
        cout << "Enter month: ";
        cin >> newBirthday.month;if (!checkInputNumber()) return;
        cout << "Enter year: ";
        cin >> newBirthday.year;if (!checkInputNumber()) return;
        cin.get(); // Clear newline from input buffer
        vectorBirthdaylist.push_back(newBirthday);
        Displaybirthdaylist();
    }

    if (count > 0) {
        saveDatafromvectortofile();
    }
}
string ConverStringToUper(string OriginalString){
    string UpperString = OriginalString;
    for ( int i = 0; i < UpperString.length(); ++i )
        UpperString[i] = (char) toupper(UpperString[i]);
        return UpperString;
}
void search_name() {
    string person_name;
    cout << "Please enter name you want to search for: ";
    cin >> person_name;
    string ConverInputToUpper = ConverStringToUper(person_name);
    string NameInFile;

    bool flagfound = false; // Renamed for clarity
    for (unsigned int i = 0; i < vectorBirthdaylist.size(); ++i) {
        NameInFile = ConverStringToUper( vectorBirthdaylist[i].name );
        if (NameInFile == ConverInputToUpper) {
            cout << i + 1 << ": Name: " << vectorBirthdaylist[i].name
                 << ", Day: " << vectorBirthdaylist[i].day
                 << ", Month: " << vectorBirthdaylist[i].month
                 << ", Year: " << vectorBirthdaylist[i].year << endl;
            flagfound = true; // Assignment, not comparison
        }
    }
    if (!flagfound) {
        cout << "There is no person with that name in the list!" << endl;
    }
}

void search_day() {
    int person_day;
    cout << "Please enter day you want to search for: ";if (!checkInputNumber()) return;
    cin >> person_day; if (!checkInputNumber()) return;// Correct variable
    if ( cin.fail()){
        cout << "______________________________" << endl;
        cout << "|  Please input only Number!  |" << endl;
        cout << "|_____________________________|" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    bool flagfound = false;
    for (unsigned int i = 0; i < vectorBirthdaylist.size(); ++i) {
        if (vectorBirthdaylist[i].day == person_day) {
            cout << i + 1 << ": Name: " << vectorBirthdaylist[i].name
                 << ", Day: " << vectorBirthdaylist[i].day
                 << ", Month: " << vectorBirthdaylist[i].month
                 << ", Year: " << vectorBirthdaylist[i].year << endl;
            flagfound = true;
        }
    }
    if (!flagfound) {
        cout << "There is no person with that day in the list!" << endl;
    }
}

void search_month() {
    int person_month;
    cout << "Please enter month you want to search for: ";
    cin >> person_month;if (!checkInputNumber()) return; // Correct variable
     if ( cin.fail()){
        cout << "______________________________" << endl;
        cout << "|  Please input only Number!  |" << endl;
        cout << "|_____________________________|" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    bool flagfound = false;
    for (unsigned int i = 0; i < vectorBirthdaylist.size(); ++i) {
        if (vectorBirthdaylist[i].month == person_month) {
            cout << i + 1 << ": Name: " << vectorBirthdaylist[i].name
                 << ", Day: " << vectorBirthdaylist[i].day
                 << ", Month: " << vectorBirthdaylist[i].month
                 << ", Year: " << vectorBirthdaylist[i].year << endl;
            flagfound = true;
        }
    }
    if (!flagfound) {
        cout << "There is no person with that month in the list!" << endl;
    }
}

void search_year() {
    int person_year;
    cout << "Please enter year you want to search for:"<<endl;
    cin >> person_year;if (!checkInputNumber()) return; // Correct variable
     if ( cin.fail()){
        cout << "______________________________" << endl;
        cout << "|  Please input only Number!  |" << endl;
        cout << "|_____________________________|" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    bool flagfound = false;
    for (unsigned int i = 0; i < vectorBirthdaylist.size(); ++i) {
        if (vectorBirthdaylist[i].year == person_year) {
            cout << i + 1 << ": Name: " << vectorBirthdaylist[i].name
                 << ", Day: " << vectorBirthdaylist[i].day
                 << ", Month: " << vectorBirthdaylist[i].month
                 << ", Year: " << vectorBirthdaylist[i].year << endl;
            flagfound = true;
        }
    }
    if (!flagfound) {
        cout << "There is no person with that year in the list!" << endl;
    }
}

void search_birthdaylist() {
    int option;
    cout << "______________________________" << endl;
    cout << "| Welcome to Search Function! |" << endl;
    cout << "|_____________________________|" << endl;
    cout << "What do you want to search by?" << endl;
    cout << "__________  _________  __________   __________" << endl;
    cout << "|1. Name |  |2. Day |  |3. Month |  |4. Year |" << endl;
    cout << "|________|  |_______|  |_________|  |________|" << endl;
    cin >> option;if (!checkInputNumber()) return;
    switch (option) {
        case 1:
            search_name();
            break;
        case 2:
            search_day();
            break;
        case 3:
            search_month();
            break;
        case 4:
            search_year();
            break;
        default:
            cout << "Invalid option! Please select 1, 2, 3, or 4." << endl;
            break;
    }
}
void EditDataofbirthday() {
    Displaybirthdaylist();
    if (vectorBirthdaylist.empty()) {
        cout << "\nNo birthdays to edit!" << endl;
        return;
    }

    unsigned int birthdayID;
    cout << "\nWhich birthday do you want to edit? Please input number from 1 to " << vectorBirthdaylist.size() << ": ";
    cin >> birthdayID;if (!checkInputNumber()) return;
    cin.get(); // Clear newline from input buffer

    if (birthdayID < 1 || birthdayID > vectorBirthdaylist.size()) {
        cout << "Invalid birthday ID!" << endl;
        return;
    }
    cout << "What do you want to correct for " << vectorBirthdaylist[birthdayID - 1].name << "?" << endl;
    cout << " 1. Name \n 2. Day \n 3. Month \n 4. Year \nSelect an option: ";
    int choice;
    cin >> choice;if (!checkInputNumber()) return;
    cin.get(); // Clear newline from input buffer

    switch (choice) {
        case 1:
            cout << "Please input new Name: ";
            cin >> vectorBirthdaylist[birthdayID - 1].name;
            break;
        case 2:
            cout << "Please input new Day: ";
            cin >> vectorBirthdaylist[birthdayID - 1].day;
            break;
        case 3:
            cout << "Please input new Month: ";
            cin >> vectorBirthdaylist[birthdayID - 1].month;
            break;
        case 4:
            cout << "Please input new Year: ";
            cin >> vectorBirthdaylist[birthdayID - 1].year;
            break;
        default:
            cout << "Invalid option!" << endl;
            return;
    }

    saveDatafromvectortofile();
    cout << "Birthday edited successfully!" << endl;
    Displaybirthdaylist();
}

void deleteBirthday() {
    Displaybirthdaylist();
    if (vectorBirthdaylist.empty()) {
        cout << "\nNo birthdays to delete!" << endl;
        return;
    }

    unsigned int birthdayID;
    cout << "\nWhich birthday do you want to delete? Please input number from 1 to " << vectorBirthdaylist.size() << ": ";
    cin >> birthdayID;
    cin.get(); // Clear newline from input buffer

    if (birthdayID < 1 || birthdayID > vectorBirthdaylist.size()) {
        cout << "Invalid birthday ID!" << endl;
        return;
    }

    cout << "Deleting birthday for " << vectorBirthdaylist[birthdayID - 1].name << endl;
    vectorBirthdaylist.erase(vectorBirthdaylist.begin() + (birthdayID - 1));
    saveDatafromvectortofile();
    cout << "Birthday deleted successfully!" << endl;
    Displaybirthdaylist();
}

void addNewBirthdayWithPosition() {
    Displaybirthdaylist();
    unsigned int position;
    cout << "\nEnter the position to insert the new birthday (1 to " << vectorBirthdaylist.size() + 1 << "): ";
    cin >> position;
    cin.get(); // Clear newline from input buffer

    if (position < 1 || position > vectorBirthdaylist.size() + 1) {
        cout << "Invalid position! Must be between 1 and " << vectorBirthdaylist.size() + 1 << "." << endl;
        return;
    }

    Birthday newBirthday;
    cout << "\n--- Adding Birthday at Position " << position << " ---" << endl;
    cout << "Enter name: ";
    cin >> newBirthday.name;
    cout << "Enter day: ";
    cin >> newBirthday.day;
    cout << "Enter month: ";
    cin >> newBirthday.month;
    cout << "Enter year: ";
    cin >> newBirthday.year;
    cin.get(); // Clear newline from input buffer

    vectorBirthdaylist.insert(vectorBirthdaylist.begin() + (position - 1), newBirthday);
    saveDatafromvectortofile();
    cout << "Birthday added successfully at position " << position << "!" << endl;
    Displaybirthdaylist();
}

// ====================== Main ======================
int main() {
    ReadDataFileTovector();
    int option;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << " 1. Add a birthday \n";
        cout << " 2. Add a birthday to specified position \n";
        cout << " 3. Show All Birthdays\n";
        cout << " 4. Edit birthday information\n";
        cout << " 5. Delete a birthday\n";
        cout << " 6. Search birthday (menu)\n";
        cout << "-1. Exit and save data\n";
        cout << "Please Select Option: ";
        cin >> option; if (!checkInputNumber()) continue;
    cout << "Initializing program, loading data..." << endl;
        if ( cin.fail()){
            cout << "______________________________" << endl;
            cout << "|  Please input only Number!  |" << endl;
            cout << "|_____________________________|" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
        if (option == -1) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        switch (option) {
            case 1:
                addBirthday();
                break;
            case 2:
                addNewBirthdayWithPosition();
                break;
            case 3:
                Displaybirthdaylist();
                break;
            case 4:
                EditDataofbirthday();
                break;
            case 5:
                deleteBirthday();
                break;
            case 6:
                search_birthdaylist();
                break;
            default:
                cout << "Invalid option. Please try again!" << endl;
        }
    }

    return 0;
}
