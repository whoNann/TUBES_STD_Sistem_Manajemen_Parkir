// Nanta
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
//2. marsell
    void hapusKendaraan(const string& platNomor) {
          for (auto it = kendaraanTerparkir.begin(); it != kendaraanTerparkir.end(); ++it) {
              if (it->platNomor == platNomor) {
                  int harga = (it->jenisKendaraan == "motor") ? 3000 : 5000; // Harga parkir
                  cout << "Kendaraan dihapus." << endl;
                  cout << "Total biaya parkir: " << harga << " IDR" << endl;
                  kendaraanTerparkir.erase(it);
                  tempatParkirTersedia.push(totalTempat - kendaraanTerparkir.size());
                  return;
              }
          }
          cout << "Kendaraan tidak ditemukan." << endl;
    }
    //3. Resi
    void cariKendaraan(const string& platNomor) {
      for (const auto& kendaraan : kendaraanTerparkir) {
          if (kendaraan.platNomor == platNomor) {
              cout << "Kendaraan ditemukan: " << kendaraan.platNomor << ", Pemilik: " << kendaraan.namaPemilik 
                   << ", Jenis: " << kendaraan.jenisKendaraan << endl;
              return;
          }
      }
      cout << "Kendaraan tidak ditemukan." << endl;
    }

    void tampilkanTempatParkirTersedia() {
        cout << "Tempat parkir yang tersedia: " << tempatParkirTersedia.size() << endl;
    }
  
    //4.Ali
    void tampilkanKendaraanTerparkir() {
      if (kendaraanTerparkir.empty()) {
          cout << "Tidak ada kendaraan yang sedang terparkir." << endl;
          return;
      }

      cout << "Kendaraan yang sedang terparkir:" << endl;
      for (const auto& kendaraan : kendaraanTerparkir) {
          cout << "Plat Nomor: " << kendaraan.platNomor << ", Pemilik: " << kendaraan.namaPemilik 
               << ", Jenis: " << kendaraan.jenisKendaraan << endl;
      }
    }

    //5.Ardhian
     void tampilkanMenu() {
      cout << "Menu Sistem Manajemen Parkir:" << endl;
      cout << "1. Tambah Kendaraan" << endl;
      cout << "2. Hapus Kendaraan" << endl;
      cout << "3. Cari Kendaraan" << endl;
      cout << "4. Tampilkan Tempat Parkir Tersedia" << endl;
      cout << "5. Tampilkan Kendaraan Terparkir" << endl;
      cout << "6. Keluar" << endl;
      }
};

int main() {
    int totalTempat;
    cout << "Masukkan total jumlah tempat parkir: ";
    cin >> totalTempat;

    SistemManajemenParkir smp(totalTempat);

    int pilihan;
    string platNomor, namaPemilik, jenisKendaraan;

    do {
        smp.tampilkanMenu();
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan plat nomor: ";
                cin >> platNomor;
                cout << "Masukkan nama pemilik: ";
                cin >> namaPemilik;
                cout << "Masukkan jenis kendaraan (motor/mobil): ";
                cin >> jenisKendaraan;
                smp.tambahKendaraan(platNomor, namaPemilik, jenisKendaraan);
                break;
              case 2:
                cout << "Masukkan plat nomor untuk dihapus: ";
                cin >> platNomor;
                smp.hapusKendaraan(platNomor);
                break;
// Nanta
              case 3:
                cout << "Masukkan plat nomor untuk dicari: ";
                cin >> platNomor;
                smp.cariKendaraan(platNomor);
                break;
              case 4:
                smp.tampilkanTempatParkirTersedia();
                break;
              case 5:
                smp.tampilkanKendaraanTerparkir();
                break;
              case 6:
                cout << " Terimakasih sudah menggunakan sistem kami:) " << endl;
                cout << " Sampai jumpa:D " << endl;
                break;
              default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
          }
      } while (pilihan != 6);

      return 0;
  }
  

