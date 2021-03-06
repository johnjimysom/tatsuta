// csv_read_record_search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//could create a header for read and search


//include these libraries
#include <iostream> //
#include <fstream> //
#include <string>
#include <vector>
#include <cstdlib>
#include <string.h>

using namespace std;


string GetBinaryStringFromHexString(string);
int main(int argc, char *argv[]) 
{
    unsigned int encodeVer, printArea, itemCode, packingDiv, productionYear, quantity, serialNumber, checkSum;
    string inHex, inBinary;

    cout << "Besure you have the most updated version: " << '\n';
    ifstream ip("qr-scan-2.csv");

    if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string barcode;
    string quantities;
    string notes;
    string date;
    // string vendor;
    // string description;

    //gathering the input of the .csv
    while (ip.good()) { //or EOF: end of file

        getline(ip, barcode, ',');
        getline(ip, quantities, ',');
        getline(ip, notes, ',');
        getline(ip, date, '\n');
        // getline(ip, vendor, ',');
        // getline(ip, description, ',');
        // getline(ip, quantities, '\n');

        cout << "string: " << barcode << endl; //debug
        //cout << "hexval: "; //debug to test

        //outputs in the terminal display
        std::cout << "Barcode: " << barcode << '\n';
        std::cout << "Quantities: " << quantities << '\n';
        std::cout << "Notes: " << notes << '\n';
        std::cout << "Date Scanned: " << date << '\n';
        //std::cout << "Vendor: " << vendor << '\n';
        std::cout << "-----------------------------------------------------" << '\n';
    }
    ip.close();
}

/********************************************************************************************************/
/********************************************************************************************************///parseQR
/******************************************************************************************************** 
unsigned int encodeVer, printArea, itemCode, packingDiv, productionYear, quantity, serialNumber, checkSum;
string inHex, inBinary;

for (int i = 1; i < argc; ++i)
{
    inHex = "21109D876080A80020000720000000AB";
    inBinary = GetBinaryStringFromHexString(inHex);
    //cout << inHex << "\n";
    //cout << inBinary << "\n";

    encodeVer = strtoul(inBinary.substr(0, 4).c_str(), nullptr, 2);
    printArea = strtoul(inBinary.substr(4, 4).c_str(), nullptr, 2);
    itemCode = strtoul(inBinary.substr(8, 34).c_str(), nullptr, 2);
    packingDiv = strtoul(inBinary.substr(42, 4).c_str(), nullptr, 2);
    productionYear = strtoul(inBinary.substr(46, 7).c_str(), nullptr, 2);
    quantity = strtoul(inBinary.substr(53, 14).c_str(), nullptr, 2);
    serialNumber = strtoul(inBinary.substr(67, 24).c_str(), nullptr, 2);
    checkSum = strtoul(inBinary.substr(120, 8).c_str(), nullptr, 2);

    std::cout << "Encode Version: " << encodeVer << "\n";
    std::cout << "Print Area: " << printArea << "\n";
    std::cout << "Item Code: " << itemCode << "\n";
    std::cout << "Packing Division: " << packingDiv << "\n";
    std::cout << "Production Year: " << productionYear << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Serial Number: " << serialNumber << "\n";
    std::cout << "Checksum: " << checkSum << "\n";

    return 0;
}
/********************************************************************************************************/ //end parseQR
/********************************************************************************************************/
/********************************************************************************************************/


string GetBinaryStringFromHexString(string barcode)
{
    string sReturn = "";
    for (unsigned int i = 0; i < barcode.length(); ++i)
    {
        switch (toupper(barcode[i]))
        {
        case '0': sReturn.append("0000"); break;
        case '1': sReturn.append("0001"); break;
        case '2': sReturn.append("0010"); break;
        case '3': sReturn.append("0011"); break;
        case '4': sReturn.append("0100"); break;
        case '5': sReturn.append("0101"); break;
        case '6': sReturn.append("0110"); break;
        case '7': sReturn.append("0111"); break;
        case '8': sReturn.append("1000"); break;
        case '9': sReturn.append("1001"); break;
        case 'A': sReturn.append("1010"); break;
        case 'B': sReturn.append("1011"); break;
        case 'C': sReturn.append("1100"); break;
        case 'D': sReturn.append("1101"); break;
        case 'E': sReturn.append("1110"); break;
        case 'F': sReturn.append("1111"); break;
        }
    }
    return sReturn;
}