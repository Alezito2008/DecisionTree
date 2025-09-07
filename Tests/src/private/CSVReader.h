//
// Created by alezito on 9/5/25.
//

#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Types.h"

class CSVReader {
public:
    CSVReader(const std::string& path);

    Serial GetColumn(const std::string& columnName) const;

private:
    bool m_loaded = false;
    std::string m_path;
    Table m_table;
    std::unordered_map<std::string, int> m_columnIndexes;

    void LoadCSV();
    const Table& GetTable() const;
    int GetLocationByName(const std::string& columnName) const;
};