// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  int sisi;
  int x1, y1;
  int xmin, ymin;
  int xmax, ymax;
  string nomap = to_string(1);

  // --- Read map.txt ---
    ifstream fileInput;
    fileInput.open("map.txt");
    int x0, y0;
    string line;

    if (fileInput.is_open())
    {
        while ( getline (fileInput,line) )
        {
            fileInput >> x0 >> y0;
            //scout << x0;
            if ((x0 == 9999) && (y0 == 9999)){
                cout << "read file\n";
            }else{
                cout << x0 << "," << y0 << endl;    
            }
            //cout << line << '\n';
        }
        fileInput.close();
    } else {
        cout << "Unable to open file";
    }

  return 0;
}