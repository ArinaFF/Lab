//вариант 2
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

static void enableAnsiColors() {
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(h, &mode))
        SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}
static bool fileExists(const string& name) {
    ifstream f(name);
    return f.good();
}
static void ensureFile(const string& name, const string& defaultContent) {
    if (!fileExists(name)) {
        ofstream f(name);
        f << defaultContent;
        cout << "[создан файл] " << name << endl;
    }
    else {
        cout << "[найден файл] " << name << endl;
    }
}
class JaggedArray {
private:
    vector<vector<string>> data;
public:
    JaggedArray() {}
    JaggedArray(const vector<vector<string>>& d) : data(d) {}

    vector<string>& operator[](int i) { return data[i]; }
    const vector<string>& operator[](int i) const { return data[i]; }
    int rows() const { return (int)data.size(); }
    int cols(int i) const { return (int)data[i].size(); }
    void add_endline(int k, const string& item) {
        if (k < 0 || k >= (int)data.size()) return;
        data[k].push_back(item);
    }
    void deleteAt(int i, int j) {
        if (i < 0 || i >= (int)data.size())    return;
        if (j < 0 || j >= (int)data[i].size()) return;
        data[i].erase(data[i].begin() + j);
    }
    void deleteItem(const string& item) {
        for (auto& row : data)
            row.erase(remove(row.begin(), row.end(), item), row.end());
    }
    void sortRows() {
        for (auto& row : data)
            sort(row.begin(), row.end());
    }
    JaggedArray operator+(const JaggedArray& other) const {
        JaggedArray res;
        int maxRows = max((int)data.size(), (int)other.data.size());
        for (int i = 0; i < maxRows; ++i) {
            vector<string> merged;

            auto addUnique = [&](const string& s) {
                if (find(merged.begin(), merged.end(), s) == merged.end())
                    merged.push_back(s);
                };

            if (i < (int)data.size())
                for (const auto& s : data[i]) addUnique(s);
            if (i < (int)other.data.size())
                for (const auto& s : other.data[i]) addUnique(s);
            res.data.push_back(merged);
        }
        return res;
    }
    JaggedArray& operator++() {
        for (auto& row : data)
            for (auto& s : row)
                s += "+1A";
        return *this;
    }
    JaggedArray operator++(int) {
        JaggedArray copy = *this;
        ++(*this);
        return copy;
    }
    void print() const {
#ifdef _WIN32
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        const WORD colors[] = {
            12, 10, 14, 9, 13, 11, 15,
            4,  2,  6, 1,  5,  3,  7
        };
        const int N = 14;
        for (int i = 0; i < (int)data.size(); ++i) {
            SetConsoleTextAttribute(h, colors[i % N]);
            cout << "Row " << i << ": ";
            for (const auto& s : data[i]) cout << s << "  ";
            cout << endl;
        }
        SetConsoleTextAttribute(h, 7);
#else
        const string colors[] = {
            "\033[91m", "\033[92m", "\033[93m", "\033[94m",
            "\033[95m", "\033[96m", "\033[97m",
            "\033[31m", "\033[32m", "\033[33m",
            "\033[34m", "\033[35m", "\033[36m", "\033[37m"
        };
        const int N = 14;
        for (int i = 0; i < (int)data.size(); ++i) {
            cout << colors[i % N] << "Row " << i << ": ";
            for (const auto& s : data[i]) cout << s << "  ";
            cout << "\033[0m" << endl;
        }
#endif
    }
    void loadFromFile(const string& filename) {
        data.clear();
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл: " << filename << endl;
            return;
        }
        string ext;
        size_t dot = filename.find_last_of('.');
        if (dot != string::npos) ext = filename.substr(dot + 1);

        if (ext == "csv") {
            string line;
            while (getline(file, line)) {
                if (line.empty()) continue;
                vector<string> row;
                stringstream ss(line);
                string token;
                while (getline(ss, token, ',')) {
                    size_t a = token.find_first_not_of(" \t\r\n");
                    size_t b = token.find_last_not_of(" \t\r\n");
                    if (a != string::npos)
                        row.push_back(token.substr(a, b - a + 1));
                }
                data.push_back(row);
            }
        }
        else if (ext == "json") {
            string content((istreambuf_iterator<char>(file)),
                istreambuf_iterator<char>());
            size_t pos = 0;
            while (pos < content.size() && content[pos] != '[') ++pos;
            ++pos;
            while (pos < content.size()) {
                while (pos < content.size() &&
                    (content[pos] == ' ' || content[pos] == '\n' ||
                        content[pos] == '\r' || content[pos] == '\t' ||
                        content[pos] == ','))
                    ++pos;

                if (pos >= content.size() || content[pos] == ']') break;
                if (content[pos] == '[') {
                    ++pos;
                    vector<string> row;
                    while (pos < content.size() && content[pos] != ']') {
                        while (pos < content.size() &&
                            (content[pos] == ' ' || content[pos] == '\n' ||
                                content[pos] == '\r' || content[pos] == '\t' ||
                                content[pos] == ','))
                            ++pos;
                        if (pos < content.size() && content[pos] == '"') {
                            ++pos;
                            string val;
                            while (pos < content.size() && content[pos] != '"')
                                val += content[pos++];
                            ++pos;
                            row.push_back(val);
                        }
                        else if (pos < content.size() && content[pos] != ']') {
                            string val;
                            while (pos < content.size() &&
                                content[pos] != ',' && content[pos] != ']' &&
                                content[pos] != ' ' && content[pos] != '\n')
                                val += content[pos++];
                            if (!val.empty()) row.push_back(val);
                        }
                    }
                    ++pos;
                    data.push_back(row);
                }
                else ++pos;
            }
        }
        else {
            string line;
            while (getline(file, line)) {
                if (line.empty()) continue;
                vector<string> row;
                stringstream ss(line);
                string token;
                while (ss >> token) row.push_back(token);
                data.push_back(row);
            }
        }
    }
};
int main() {
    setlocale(LC_ALL, "Russian");
    enableAnsiColors();

    ensureFile("data.txt",
        "b a c\n"
        "d x\n"
        "z n e n\n");

    ensureFile("data.csv",
        "b,a,c\n"
        "d,x\n"
        "z,n,e,n\n");

    ensureFile("data.json",
        "[ [\"b\",\"a\",\"c\"],"
        "[\"d\",\"x\"],"
        "[\"z\",\"n\",\"e\",\"n\"] ]\n");

    JaggedArray A;
    cout << "\n-------- Чтение из TXT ---------" << endl;
    A.loadFromFile("data.txt");
    A.print();

    cout << "\n-------- Чтение из CSV --------" << endl;
    A.loadFromFile("data.csv");
    A.print();

    cout << "\n------- Чтение из JSON ---------" << endl;
    A.loadFromFile("data.json");
    A.print();

    cout << "\n------ После сортировки внутри строк ------" << endl;
    A.sortRows();
    A.print();

    cout << "\n------ add_endline(0, \"y\") -------" << endl;
    A.add_endline(0, "y");
    A.print();
    cout << "\n------ deleteAt(0, 0) ---------" << endl;

    A.deleteAt(0, 0);
    A.print();
    cout << "\n---------- deleteItem(\"n\") ---------" << endl;

    A.deleteItem("n");
    A.print();
    cout << "\n---------- A[1][0] --- w ----------" << endl;

    A[1][0] = "w";
    A.print();
    JaggedArray B;
    B.loadFromFile("data.csv");
    B.add_endline(1, "w");
    B.add_endline(2, "q");
    JaggedArray C = A + B;
    cout << "\n--------- A + B -----------" << endl;
    C.print();

    ++A;
    cout << "\n---------После ++A -----------" << endl;
    A.print();
    return 0;
}