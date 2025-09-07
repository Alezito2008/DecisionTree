//
// Created by alezito on 9/5/25.
//

#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

void CSVReader::LoadCSV() {

    std::ifstream file(m_path);

    if (!file.is_open()) {
        std::cout << "Error al abrir CSV" << std::endl;
    }

    bool isFirstLine = true;
    std::string line;

    unsigned int lineNumber = 0;

    while (std::getline(file, line)) {
        std::stringstream row(line);
        std::string cell;

        unsigned int cellNumber = 0;

        // Por cada celda
        while (std::getline(row, cell, ',')) {
            if (lineNumber == 0) {
                m_columnIndexes[cell] = cellNumber;
                m_table.push_back(Serial());
                cellNumber++;
                continue;
            }
            m_table[cellNumber].push_back(stof(cell));
            cellNumber++;
        }
        lineNumber++;
    }

    file.close();
    m_loaded = true;
}

int CSVReader::GetLocationByName(const std::string &columnName) const {
    if (!m_loaded) {
        std::cout << "Call LoadCSV() first" << std::endl;
        return -1;
    }

    auto it = m_columnIndexes.find(columnName);
    if (it != m_columnIndexes.end()) {
        return it -> second;
    } else {
        std::cout << "Not found" << std::endl;
        return -1;
    }
}

CSVReader::CSVReader(const std::string &path): m_path(path) {
    LoadCSV();
}

Serial CSVReader::GetColumn(const std::string& columnName) const {
    const unsigned int columnLoc = GetLocationByName(columnName);
    if (const Table table= GetTable(); columnLoc < table.size()) {
        return table[columnLoc];
    }
    return Serial();
}

const Table & CSVReader::GetTable() const {
    return m_table;
}
