#include <string>
#include <bitset>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Decryptor {

private:
        vector<bitset <5> > bitsetData;
        string outputFile;

public:
        Decryptor(string data, string outputFile);
        void convertDataToBits(string data);
        void convertBitToHex();
        string convertToAscii(int num []);
        void writeToOutputFile(string data);
};

Decryptor::Decryptor(string data, string outputFile) {
        this->outputFile = outputFile;
        convertDataToBits(data);
}

void Decryptor::convertDataToBits(string data) { //data should be in binary
        for (int count = 0; count < data.length(); count++) {
                bitsetData.push_back(data[count]);
        }

        convertBitToHex();
}

void Decryptor::convertBitToHex(){
        stringstream stream;
        int num [bitsetData.size()];
        for (int count = 0; count < bitsetData.size(); count++) {
                stream << hex << bitsetData[count].to_ulong() << endl;
                stream >> num [count];
        }
        writeToOutputFile(convertToAscii(num)) ;
}

string Decryptor::convertToAscii(int num []) {
        string data;
        stringstream stream;
        for (int count = 0; count < bitsetData.size(); count++) {
                stream << dec << num [count] << endl;
                int number;
                stream >> number;
                int prevNum;
                if (count != 0) {
                        stream << dec << num[count - 1] << endl;
                        stream >> prevNum;
                }
                char data2;
                if (number == 0)
                        data2 = ' ';
                else if (number < 27 && prevNum != 31)
                        data2 = static_cast<char>(number + 96);
                else if (number < 27)
                        data2 = static_cast<char>(number + 34);
                else if (number == 27)
                        data2 = '.';
                else if (number == 28)
                        data2 = ',';
                data += data2;
        }

        return data;
}

void Decryptor::writeToOutputFile(string data) {
        ofstream out(outputFile.c_str());
        out << data;
}

int main () {
        char * memblock;
        streampos size;

        ifstream file;
        file.open("File.bin", ios::binary | ios::in);
        if(file.is_open()) {
            size = file.tellg();
            memblock = new char [size];
            file.seekg(0, ios::beg);
            file.read(memblock, size);
            file.close();

            string str(memblock);
            Decryptor* decryptor = new Decryptor(str, "Output.txt");
        }
        return 0;
}
