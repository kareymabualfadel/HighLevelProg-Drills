#include "std_lib_facilities.h"

// Chapter 10 Drill


struct Point { //struct is defining the POINT type
    int x;
    int y;
};

// 2. Make Point input-able
istream& operator>>(istream& is, Point& p) //istream is the general purpose input stream to allow the user to input values , is will be the input variable
{
    char ch1;
    if (is >> ch1 && ch1 != '(') { //inputting the first character of ( brackets, if we didnt start with a bracket, we receive an error that we got an error point
        is.unget(); //unget the character and used to decrease the location by one character and makes the extracted character available for used once again
        is.clear(ios_base::failbit); // here it is used to remove all the elements from the vector container, making it's size = 0
        return is;
    }
    // ch1,ch2,ch3 is basically constructing the points into this layout (x,y)
    char ch2; // the next character which will be the comma
    char ch3; // the last character which will be the )
    int xx;
    int yy;
    is >> xx >> ch2 >> yy >> ch3; //after inputting ch1 which is (, we can enter x element, then ch2 which is a comma or a dot
    if (!is || ch3 != ')') { // the 3rd character was not entered or it is not a bracket, then an error message will also be displayed
        if (is.eof()) return is; //its a method of io class which checks if the stream has raised any end of file error, which means after the first input we forgot the last bracket and then we go the next point and input it all, the compiler checks for any error and then prints the error
        error("bad point");
    }
    p.x = xx; // we assign x in the point to the inputted x
    p.y = yy; // we assign y in the point to the inputted y
    return is;
}

// Make points printable
ostream& operator<<(ostream& os, Point& p) //ostream is the general purpose output which is displayed in the end and is assigned as os
{
    return os << '(' << p.x << ',' << p.y << ')'; // this is the final layout (x,y)
}

// 5. Read points back in from file
void fill_from_file(vector<Point>& points, string& name) //the vector which stores values together
{
    ifstream ist {name}; //ifstream is the open function which can be used to open a file, that means Once input is done, you can read from the ifstream object in exactly the same way you would read from cin
    ist.exceptions(ist.exceptions()|ios_base::badbit); //if there is any error, an exception would be made and output a message of badbit

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p); //inserts a new element at the end of the vector and increase the size of it by 1
}

int main()
try {
    // 2. prompt user for points and store them in vector
    cout << "Please enter seven sets of x, y points:\n";
    vector<Point> original_points; // declaring the vector

    while (original_points.size() < 7) { //the limit is 7 points
        Point p;
        cin >> p;
        original_points.push_back(p); // after every element inserted, it will be pushed at the end of the vector and the size is increased by 1 until we reach 7
    }

    // 3. Print out the original_points
    for (Point p : original_points)
        cout << p; // we print the points inserted (the original ones)
    cout << '\n';

    // 4. Output the points to file
    string fname = "mydata.txt";
    ofstream ost { fname };// the output file stream is used to create a new file and write the information in this file, we are just outputting the date to a file and we are naming it mydata.txt
    if (!ost) error("could not open file ", fname); //if an error occurs, it reads this message

    for (Point p : original_points)
        ost << p; //a loop is done to add all points into the output file stream created
    ost.close(); //the file will close once the loop is finished

    // 5. Read the file back into a vector
    vector<Point> processed_points;
    fill_from_file(processed_points, fname); //we are going to re-add the elements in this file back to another vector to this name

    for (Point p : processed_points)
        cout << p; // a loop is created to output each point in order
    cout << '\n';

    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n"; //if the original points are the not the same as the processed points created after adding them from the ofstream file, an error occurs. they should also be in order
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n'; //for any error, a message is shown as an exception and the code still runs
    return 1;
}
catch (...) {
    cerr << "Something terrible has happened!\n";
    return 2;
}
