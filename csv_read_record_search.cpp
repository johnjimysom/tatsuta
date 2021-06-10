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

    ifstream ip("qr-scan-sample-3c.csv");

    if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string barcode;
    string vendor;
   // string description;
    string quantities;

    while (ip.good()) {

        getline(ip, barcode, ',');
        getline(ip, vendor, ',');
       // getline(ip, description, ',');
        getline(ip, quantities, '\n');

        std::cout << "Barcode: " << barcode << '\n';
        std::cout << "Vendor: " << vendor << '\n';
        std::cout << "Quantities: " << quantities << '\n';
        std::cout << "-----------------------------------------------" << '\n';
    }

    ip.close();
}