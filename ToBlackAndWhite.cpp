
/// @author <Alexis Beliveau>
/// @brief Converts a PPM to black and white

#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

// program constants
const int MAX_W   = 1024;    // max size of image width
const int MAX_L   = 768;     // max size of image length
const int MAX_COL = 255;     // max color value

// program structs
struct pixel_t {
    short red     = 0;       // pixel color
    short green   = 0;       // pixel color
    short blue    = 0;       // pixel color
};

struct fileInfo {

    string inName;                  // input file name from user
    string outName;                 // output file name from user
    string id;                      // file type id
    int width;                      // width of image
    int length;                     // length of image
    int colorVal;                   // color value
    pixel_t pixels[MAX_L][MAX_W];   // array of pixel structs
};

// function prototypes
void getfileInfo(ifstream& input, struct fileInfo& info);
void checkID(struct fileInfo& info);
void checkSize(struct fileInfo& info);
void checkColor(struct fileInfo& info);
bool isPPM(string fileType);
void make2D(ifstream& inFile, struct fileInfo& info);
void toGrayScale(short r, short g, short b, int i, int j,
                 struct fileInfo& info);
void writeFile(ofstream& outFile, struct fileInfo& info);



int main(int argc, char *argv[]) {

    fileInfo ppm;       // info for ppm file type
    ifstream inFile;    // input file to open
    ofstream outFile;   // file to write to

    // check for missing inputs
    if (argc == 1) {
        cout << "Error: missing input file name " << endl;
    }

    if (argc == 2) {
        cout << "Error: missing output filename " << endl;

    } else {
        ppm.inName = argv[1];
        ppm.outName = argv[2];

        // check for differing file names
        if (ppm.inName == ppm.outName) {
            cout << "Error: input and output file names must differ " << endl;

            // check file extension and open
        } else {
            if (isPPM(ppm.inName) && isPPM(ppm.outName)) {
                inFile.open(ppm.inName);

                if (inFile.good()) {
                    // check/convert/write file ~ see funct def ~
                    getfileInfo(inFile, ppm);
                    make2D(inFile, ppm);
                    checkID(ppm);
                    checkSize(ppm);
                    checkColor(ppm);
                    writeFile(outFile, ppm);
                }

                inFile.close();
            } else {
                cout << "Error: Files must be PPM format" << endl;
            }
        }
    }

    return 0;
}

// @brief reads in color values to convert to a 2D array of
// gray scale averages
// @param input file stream
// @param structure for ppm
void make2D(ifstream& inFile, struct fileInfo& info) {
    for (int i = 0; i < info.length; ++i) {
        for (int j = 0; j < info.width; ++j) {
            short red;   // red from file
            short green; // green from file
            short blue;  // blue from file
            inFile   >> red;
            inFile   >> green;
            inFile   >> blue;
            toGrayScale(red, green, blue, i, j, info);
        }
    }
}

// @brief writes all struct info to output file
// @param output file stream
// @param structure for ppm
void writeFile(ofstream& outFile, struct fileInfo& info) {
    outFile.open(info.outName);

    if (outFile.good()) {
        outFile << info.id << endl;
        outFile << info.width << ' ' << info.length << endl;
        outFile << info.colorVal << endl;

        for (int i = 0; i < info.length; ++i) {
            for (int j = 0; j < info.width; ++j) {
                outFile << info.pixels[i][j].red   << ' '
                        << info.pixels[i][j].green << ' '
                        << info.pixels[i][j].blue  << ' ';
            }

            outFile << endl;
        }
    }

    outFile.close();
}

// @brief converts RGB values to grayscale
// @param file stream
// @param short red, green, and blue values
// @param counter i and j values
// @param structure for ppm file
void toGrayScale(short r, short g, short b, int i, int j, struct fileInfo
                 &info) {
    short avg;   // holds average of colors
    avg = (r + b + g) / 3;
    info.pixels[i][j].red   = avg;
    info.pixels[i][j].green = avg;
    info.pixels[i][j].blue  = avg;
}

// @brief collects all header info from file
// @param input file stream
// @param structure for ppm
void getfileInfo(ifstream& inFile, struct fileInfo& info) {
    string check;
    getline(inFile, info.id);
    getline(inFile, check);

    if (check.at(0) != '#') {
        unsigned long pos;     // pos of space char
        pos = check.find(' ');
        info.width = stoi(check.substr(0, pos));
        info.length = stoi(check.substr(pos + 1, '\n'));
        inFile >> info.colorVal;
    } else {
        inFile >> info.width >> info.length >> info.colorVal;
    }
}

// @brief checks for incorrect color values
// @param structure for ppm
void checkColor(struct fileInfo& info) {
    if (info.colorVal > MAX_COL) {
        cout << "Error: max color value exceeded" << endl;
    }
}

// @brief checks for incorrect width and length values
// @param structure for ppm
void checkSize(struct fileInfo& info) {
    if (info.width > MAX_W || info.length > MAX_L) {
        cout << "Error: image file too large"     << endl;
    }
}

// @brief checks for incorrect ID type
// @param structure for ppm
void checkID(struct fileInfo& info) {
    if ((info.id.length() < 2) || (info.id != "P3")) {
        cout << "Error: wrong input file type"    << endl;
    }
}

// @brief checks string for ppm extension
// @param name of file in string format
// @returns true if file is a PPM
bool isPPM(string filetype) {
    char delim = '.';  // first char before extention type
    bool isPPM;        // returns true if file is a PPM

    if (filetype.substr(filetype.find_first_of(delim) + 1) == "ppm") {
        isPPM = true;
    } else {
        isPPM = false;
    }
    return isPPM;
}


