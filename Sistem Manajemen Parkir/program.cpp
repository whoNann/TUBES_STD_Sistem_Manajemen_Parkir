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

    void tambahKendaraan(const string& platNomor, const string& namaPemilik, const string& jenisKendaraan) {
        if (tempatParkirTersedia.empty()) {
            cout << "Tidak ada tempat parkir yang tersedia." << endl;
            return;
        }

        int spot = tempatParkirTersedia.top();
        tempatParkirTersedia.pop();

        Kendaraan kendaraan = {platNomor, namaPemilik, jenisKendaraan};
        kendaraanTerparkir.push_back(kendaraan);

        cout << "Kendaraan ditambahkan. Parkir di tempat: " << spot << endl;
    }
