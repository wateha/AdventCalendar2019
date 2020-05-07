#ifndef QQDATAFILEREADER
#define QQDATAFILEREADER

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*
Template class to read multi-line input file, line-by-line, then split each line by the given delimiter.
Data gets converted to desired type (int, float and std::string are supported).
Each line is stored inside a vector<T>.
All vectors are stored inside main vector<vector<T>>.
*/

template <class T>
class QQDataFileReader {
public:
    // Master data vector accessor
    std::vector<std::vector<T>>& getData(const std::string& fileName, char delimiter)
    {
        readDataFile(fileName);
        splitData(delimiter);
        return dataVector;
    }

private:
    // Content of data file, each line as a single string element
    std::vector<std::string> inputDataVector{}; 
    // Master data vector, mirroring data file in structure, with data elements converted to desired T type
    std::vector<std::vector<T>> dataVector{};   

    // Read file with the provided name, then store the content of each line as a single vector<string> element
    void readDataFile(const std::string& fileName)
    {
        std::ifstream inputDataFile;

        inputDataFile.open(fileName);
        while (inputDataFile.eof() == 0) {
            std::string data{};
            inputDataFile >> data;
            inputDataVector.push_back(data);
        }
        inputDataFile.close();
    }

    /*
    The entire contents of the file is stored as a single vector<string>.
    The method splits each stored line to vector<T>, using the provided delimiter
    */
    void splitData(char delimiter)
    {
        std::string data{};

        for (size_t dataStringCounter = 0; dataStringCounter < inputDataVector.size(); dataStringCounter++) {
            size_t pos{ 0 };
            std::vector<T> subVector{};

            // Method loops until it reaches the end of the processed line
            do {
                pos = inputDataVector[dataStringCounter].find(delimiter);
                data = inputDataVector[dataStringCounter].substr(0, pos);

                // This is to define specific signature of the overloaded convertToType method
                T tmp{};
                convertToType(data, tmp);

                subVector.push_back(tmp);
                inputDataVector[dataStringCounter].erase(0, pos + 1);
            }
            while (pos != std::string::npos);

            // Store lines split into vectors in the master data vector, mirroring the original data file
            dataVector.push_back(subVector);
        }
    }

    // Overloaded conversion method, to handle conversion to T type via appropriate standard conversion function
    void convertToType(std::string data, int& outConverted)
    {
        outConverted = stoi(data);
    }
    void convertToType(std::string data, float& outConverted)
    {
        outConverted = stof(data);
    }
    void convertToType(std::string data, std::string& outConverted)
    {
        outConverted = data;
    }
};

#endif // !QQDATAFILEREADER