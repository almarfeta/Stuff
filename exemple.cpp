#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <string>
#include <iostream>
#include <vector>
#include <experimental/filesystem>

using namespace std;
using namespace experimental::filesystem;

int main()
{
    string cale = "C:\\Users\\Almar\\Desktop\\Dummy";
    path p{ cale };
    vector <string> files;
    if (exists(p) && is_directory(p)) {
        for (auto& e : recursive_directory_iterator(p)) {
            files.push_back(e.path().stem().string());
        }
    }
    else {
        cout << "Path doesnt exist or it is not a directory\n";
    }

    for (string s : files) {
        cout << s << "\n";
    }
    return 0;
}
