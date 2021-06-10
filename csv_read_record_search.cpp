// csv_read_record_search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//could create a header for read and search


//include these libraries
#include <iostream> //
#include <fstream> //
#include <string>
#include <vector>


using namespace std;

int main() {

    ifstream ip("qr-scan-2.csv");

    if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string barcode;
    string quantities;
    string notes;
    string date;
   // string vendor;
   // string description;
    
    while (ip.good()) { //or EOF: end of file

        getline(ip, barcode, ',');
        getline(ip, quantities, ',');
        getline(ip, notes, ',');
        getline(ip, date, '\n');
       //getline(ip, vendor, ',');
       // getline(ip, description, ',');
       // getline(ip, quantities, '\n');

        std::cout << "Barcode: " << barcode << '\n';
        std::cout << "Quantities: " << quantities << '\n';
        std::cout << "Notes: " << barcode << '\n';
        std::cout << "Date Scanned: " << date << '\n';
        //std::cout << "Vendor: " << vendor << '\n';
        std::cout << "-----------------------------------------------" << '\n';
    }

    ip.close();
}