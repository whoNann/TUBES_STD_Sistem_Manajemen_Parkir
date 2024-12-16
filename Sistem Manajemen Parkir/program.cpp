#include <iostream>
#include <stack>
#include <list>
#include <string>

using namespace std;

struct Kendaraan {
    string platNomor;
    string namaPemilik;
    string jenisKendaraan;
};

class SistemManajemenParkir {
private:
    stack<int> tempatParkirTersedia;
    list<Kendaraan> kendaraanTerparkir;
    int totalTempat;

public:
    SistemManajemenParkir(int totalTempat) : totalTempat(totalTempat) {
        for (int i = totalTempat; i > 0; --i) {
            tempatParkirTersedia.push(i);
        }
    }
