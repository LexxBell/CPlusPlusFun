
/// @author Alexis Beliveau


#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

// bubble sort function
template <class T>
void bubbleSort(std::vector<T>& vec);
// insertion sort function
template <class T>
void insertionSort(std::vector<T>& vec);
//selection sort function
template <class T>
void selectionSort(std::vector<T>& vec);


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// By Kevin

struct Integer {
    int value;  ///< Stored value.
    Integer(int n = 0) : value(n) {}
    bool operator<(const Integer& other) const  {
        return value <  other.value;
    }
    bool operator==(const Integer& other) const {
        return value == other.value;
    }
    friend std::ostream& operator<<(std::ostream& output, const Integer& object)
    {
        return output << object.value;
    }
    friend std::istream& operator>>(std::istream& input, Integer& object) {
        return input >> object.value;
    }
};


template <class T>
void fill_rand(std::vector<T>& vec) {
    for (auto& item : vec) {
        item = rand() % std::numeric_limits<int>::max();
    }
}

template <>
void fill_rand(std::vector<char>& vec) {
    for (auto& item : vec) {
        item = static_cast<char>(rand() % ('z' - 'a' + 1) + 'a');
    }
}

template <>
void fill_rand(std::vector<double>& vec) {
    for (auto& item : vec) {
        item = static_cast<double>(rand()) / RAND_MAX;
    }
}

template <>
void fill_rand(std::vector<std::string>& vec) {
    for (auto& item : vec) {
        // simplistic approach
        item = std::to_string(rand());
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



int main() {
    using namespace std::chrono;
    using std::string;
    using std::cout;
    using std::endl;
    using std::vector;
    using std::ostream;
    using std::istream;


    // output titles
    cout << endl;
    cout << "|" << std::setw(8)   << "Size "   << '|'
         << std::setw(14)         << "Bubble "        << '|'
         << std::setw(14)         << "Insertion "     << '|'
         << std::setw(14)         << "Selection "     << '|'
         << std::setw(14)         << "std:sort "      << '|' << endl;
    cout << "+--------+"
         << "--------------+"
         << "--------------+"
         << "--------------+"
         << "--------------+" << endl;

    // declare vectors
    std::vector<Integer> nums;    // 1000 space vector
    std::vector<Integer> nums2;   // 2000 space vector
    std::vector<Integer> nums3;   // 4000 space vector
    std::vector<Integer> nums4;   // 8000 space vector
    std::vector<Integer> nums5;   // 16000 space vector
    std::vector<Integer> nums6;   // 32000 space vector
    nums.assign(1000, 0);
    nums2.assign(2000, 0);
    nums3.assign(4000, 0);
    nums4.assign(8000, 0);
    nums5.assign(16000, 0);
    nums6.assign(32000, 0);

    // test all sorts
    fill_rand(nums);
    auto start = high_resolution_clock::now();
    bubbleSort(nums);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    std::random_shuffle(nums.begin(), nums.end());
    auto start0 = high_resolution_clock::now();
    insertionSort(nums);
    auto stop0 = high_resolution_clock::now();
    auto duration0 = duration_cast<seconds>(stop0 - start0);

    std::random_shuffle(nums.begin(), nums.end());
    auto start1 = high_resolution_clock::now();
    selectionSort(nums);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<seconds>(stop1 - start1);

    std::random_shuffle(nums.begin(), nums.end());
    auto start2 = high_resolution_clock::now();
    std::sort(nums.begin(), nums.end());
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<seconds>(stop2 - start2);

    ///////////////////////////////////////////////////////////////////////////

    fill_rand(nums2);
    auto start3 = high_resolution_clock::now();
    bubbleSort(nums2);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<seconds>(stop3 - start3);

    std::random_shuffle(nums2.begin(), nums2.end());
    auto start4 = high_resolution_clock::now();
    insertionSort(nums2);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<seconds>(stop4 - start4);

    std::random_shuffle(nums2.begin(), nums2.end());
    auto start5 = high_resolution_clock::now();
    selectionSort(nums2);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<seconds>(stop5 - start5);

    std::random_shuffle(nums2.begin(), nums2.end());
    auto start6 = high_resolution_clock::now();
    std::sort(nums2.begin(), nums2.end());
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<seconds>(stop6 - start6);

    ////////////////////////////////////////////////////////////////////////////

    fill_rand(nums3);
    auto start7 = high_resolution_clock::now();
    bubbleSort(nums3);
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<seconds>(stop7 - start7);

    std::random_shuffle(nums3.begin(), nums3.end());
    auto start8 = high_resolution_clock::now();
    insertionSort(nums2);
    auto stop8 = high_resolution_clock::now();
    auto duration8 = duration_cast<seconds>(stop8 - start8);

    std::random_shuffle(nums3.begin(), nums3.end());
    auto start9 = high_resolution_clock::now();
    selectionSort(nums3);
    auto stop9 = high_resolution_clock::now();
    auto duration9 = duration_cast<seconds>(stop9 - start9);

    std::random_shuffle(nums3.begin(), nums3.end());
    auto start10 = high_resolution_clock::now();
    std::sort(nums3.begin(), nums3.end());
    auto stop10 = high_resolution_clock::now();
    auto duration10 = duration_cast<seconds>(stop10 - start10);

    ////////////////////////////////////////////////////////////////////////////

    fill_rand(nums4);
    auto start11 = high_resolution_clock::now();
    bubbleSort(nums4);
    auto stop11 = high_resolution_clock::now();
    auto duration11 = duration_cast<seconds>(stop11 - start11);

    std::random_shuffle(nums4.begin(), nums4.end());
    auto start12 = high_resolution_clock::now();
    insertionSort(nums4);
    auto stop12 = high_resolution_clock::now();
    auto duration12 = duration_cast<seconds>(stop12 - start12);

    std::random_shuffle(nums4.begin(), nums4.end());
    auto start13 = high_resolution_clock::now();
    selectionSort(nums4);
    auto stop13 = high_resolution_clock::now();
    auto duration13 = duration_cast<seconds>(stop13 - start13);

    std::random_shuffle(nums4.begin(), nums4.end());
    auto start14 = high_resolution_clock::now();
    std::sort(nums4.begin(), nums4.end());
    auto stop14 = high_resolution_clock::now();
    auto duration14 = duration_cast<seconds>(stop14 - start14);

    ////////////////////////////////////////////////////////////////////////////

    fill_rand(nums5);
    auto start15 = high_resolution_clock::now();
    bubbleSort(nums5);
    auto stop15 = high_resolution_clock::now();
    auto duration15 = duration_cast<seconds>(stop15 - start15);

    std::random_shuffle(nums5.begin(), nums5.end());
    auto start16 = high_resolution_clock::now();
    insertionSort(nums5);
    auto stop16 = high_resolution_clock::now();
    auto duration16 = duration_cast<seconds>(stop16 - start16);

    std::random_shuffle(nums5.begin(), nums5.end());
    auto start17 = high_resolution_clock::now();
    selectionSort(nums5);
    auto stop17 = high_resolution_clock::now();
    auto duration17 = duration_cast<seconds>(stop17 - start17);

    std::random_shuffle(nums5.begin(), nums5.end());
    auto start18 = high_resolution_clock::now();
    std::sort(nums5.begin(), nums5.end());
    auto stop18 = high_resolution_clock::now();
    auto duration18 = duration_cast<seconds>(stop18 - start18);

    ////////////////////////////////////////////////////////////////////////////

    fill_rand(nums6);
    auto start19 = high_resolution_clock::now();
    bubbleSort(nums6);
    auto stop19 = high_resolution_clock::now();
    auto duration19 = duration_cast<seconds>(stop19 - start19);

    std::random_shuffle(nums6.begin(), nums6.end());
    auto start20 = high_resolution_clock::now();
    insertionSort(nums6);
    auto stop20 = high_resolution_clock::now();
    auto duration20 = duration_cast<seconds>(stop20 - start20);

    std::random_shuffle(nums6.begin(), nums6.end());
    auto start21 = high_resolution_clock::now();
    selectionSort(nums6);
    auto stop21 = high_resolution_clock::now();
    auto duration21 = duration_cast<seconds>(stop21 - start21);

    std::random_shuffle(nums6.begin(), nums6.end());
    auto start22 = high_resolution_clock::now();
    std::sort(nums6.begin(), nums6.end());
    auto stop22 = high_resolution_clock::now();
    auto duration22 = duration_cast<seconds>(stop22 - start22);
    cout << endl;


    // print grid of all sorts
    cout << '|' << std::setw(7) << nums.size()       << " |"
         << std::setw(13)            << duration.count()  << " |"
         << std::setw(13)            << duration0.count() << " |"
         << std::setw(13)            << duration1.count() << " |"
         << std::setw(13)            << duration2.count() << " |";
    cout << endl;

    cout << '|' << std::setw(7) << nums2.size()         << " |"
         << std::setw(13)            << duration3.count()    << " |"
         << std::setw(13)            << duration4.count()    << " |"
         << std::setw(13)            << duration5.count()    << " |"
         << std::setw(13)            << duration6.count()    << " |";
    cout << endl;

    cout << '|' << std::setw(7) << nums3.size()         << " |"
         << std::setw(13)            << duration7.count()    << " |"
         << std::setw(13)            << duration8.count()    << " |"
         << std::setw(13)            << duration9.count()    << " |"
         << std::setw(13)            << duration10.count()   << " |";
    cout << endl;

    cout << '|' << std::setw(7) << nums4.size()          << " |"
         << std::setw(13)            << duration11.count()    << " |"
         << std::setw(13)            << duration12.count()    << " |"
         << std::setw(13)            << duration13.count()    << " |"
         << std::setw(13)            << duration14.count()    << " |";
    cout << endl;

    cout << '|' << std::setw(7) << nums5.size()          << " |"
         << std::setw(13)            << std::setprecision(5) << std::fixed <<
         duration15.count() << " |"
         << std::setw(13)            << duration16.count()    << " |"
         << std::setw(13)            << duration17.count()    << " |"
         << std::setw(13)            << duration18.count()    << " |";
    cout << endl;

    cout << '|' << std::setw(7) << nums6.size()          << " |"
         << std::setw(13)            << duration19.count()    << " |"
         << std::setw(13)            << duration20.count()    << " |"
         << std::setw(13)            << duration21.count()    << " |"
         << std::setw(13)            << duration22.count()    << " |";
    cout << endl;

}

template <class T>
void bubbleSort(std::vector<T>& vec) {
    Integer temp;  // Temporary - holds int to be copied

    for (int iteration = 1; iteration < vec.size(); iteration++) {
        for (int index = 0; index < vec.size() - iteration; index ++) {
            if (vec[index + 1] < vec[index]) {
                temp = vec[index];
                vec[index] = vec[index + 1];
                vec[index + 1] = temp;
            }
        }
    }
}

template <class T>
void insertionSort(std::vector<T>& vec) {
    int firstOut; // First out of order variable
    int location; // location of OoO var
    Integer temp;     // Temporary - holds int to be copied

    for (firstOut = 1; firstOut < vec.size(); firstOut++) {
        if (vec[firstOut] < vec[firstOut - 1]) {
            temp = vec[firstOut];
            location = firstOut;

            do {
                vec[location] = vec[location - 1];
                location--;
            } while (0 < location && temp < vec[location - 1]);

            vec[location] = temp;

        }
    }
}

template <class T>
void selectionSort(std::vector<T>& vec) {
    int index;  // holds iterator
    int smallest; // current smallest var
    int location; // location of the smallest current var
    Integer temp;     // holds smallest var data temporarily

    for (index = 0; index < vec.size() - 1; index++) {
        smallest = index;

        for (location = index + 1; location < vec.size(); location++) {
            if (vec[location] < vec[smallest]) {
                smallest = location;
            }
        }

        temp = vec[smallest];
        vec[smallest] = vec[index];
        vec[index] = temp;
    }
}










