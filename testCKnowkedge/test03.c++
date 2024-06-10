#include <cstdlib>
// #include <functional>
#include <iostream>
#include <stdexcept>
// #include <system_error>
#include <vector>
#include <set>

using namespace std;

class Hasing {
private:
    struct Nums {
        int alocat;
        vector<int> arr;
        vector<int> hashTable;
        Nums(int A) : alocat(A), arr(A), hashTable(A, 0) {}
    };
    Nums* N;

    void hasingNums() {
        set<int> s;
        for (int i = 0; i < N->alocat; i++) {
            if (s.find(N->arr[i]) == s.end()) {
                s.insert(N->arr[i]);
                N->hashTable[N->arr[i]] = 1;
            } else {
                N->hashTable[N->arr[i]]++;
            }
        }
    }

    int binarySearch(vector<int> &arr, int L, int R, int key) {
        while (L <= R) {
            int mid = L + (R + L) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[mid] < key) {
                return binarySearch(arr, L, mid-1, key);
            } else {
                return binarySearch(arr, mid+1, R, key);
            }
        }
        return -1;
    }

    void bubbleSort(vector<int> &arr) {
        int lenarr = arr.size();
        bool track;
        for (int i=0; i<lenarr-1; i++) {
            track = false;
            for (int j=0; j<lenarr-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    // swap(arr[j], arr[j-1]);
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    track = true;
                }
            }
            if (!track) {
                cout << "Error! Exit sort" << endl;
                break;
            }
        }
    }

public:
    Hasing() : N(NULL) {}
    ~Hasing() {delete N;}

    void insertNums() {
        int alocat;
        cout << "Enter alocat : ";
        cin >> alocat;

        N = new Nums(alocat);

        for (int i = 0; i < alocat; i++) {
            cout << "Enter ur nums : ";
            cin >> N->arr[i];
        }
        cout << endl;
        hasingNums();
    }

    void Search() {
        int key;
        cout << "Enter ur key : ";
        cin >> key;

        int left = 0;
        int right = N->arr.size() - 1;
        int result = binarySearch(N->arr, left, right, key);
        if (result == -1) {
            throw runtime_error("Error not found key");
        } else {
            cout << "Binary found -> ( " << N->arr[result] << " ) in Key's " << endl;
        }
    }

    void printHasing() {
        if (N != NULL) {
            set<int> printUn;
            cout << "Ur Hasing : \n";
            for (int i = 0; i < N->alocat; i++) {
                // sort(N->arr.begin(), N->arr.end(), greater<int>());
                bubbleSort(N->arr);
                if (printUn.find(N->arr[i]) == printUn.end()) {
                    cout << "Value: " << N->arr[i] << ", Frequency: " << N->hashTable[N->arr[i]] << endl;
                    printUn.insert(N->arr[i]);
                }
            }
        }
    }

};

int main() {
    Hasing N;
    N.insertNums();
    N.printHasing();
    N.Search();

    return 0;
}
