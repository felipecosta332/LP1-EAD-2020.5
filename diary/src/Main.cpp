#include "../inc/App.hpp"

int main(int argc, char* argv[])
{
    App aplicativo("diary.md");
    return aplicativo.run(argc, argv);
}
