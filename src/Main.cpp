#include "App.h"

int main(int argc, char* argv[]) {
    std::string path, format;
    setConfig(&path, &format);
    App aplicativo(path, format);
    return aplicativo.run(argc, argv);
}