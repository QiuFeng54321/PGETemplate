//
// Created by mac on 2021/4/28.
//

#include "olcPixelGameEngine.h"
#include <filesystem>
#include <sstream>
#include <string>
//#ifdef _WIN32
//#include <direct.h>
//// MSDN recommends against using getcwd & chdir names
//#define cwd _getcwd
//#define cd _chdir
//#else
//#include "unistd.h"
//#define cwd getcwd
//#define cd chdir
//#endif

int main() {
    std::string key = "";
    olc::ResourcePack* pack = new olc::ResourcePack();
    std::filesystem::current_path("/Users/mac/Documents/VSCProjects/PGETemplate/");
    for(auto itEntry = std::filesystem::recursive_directory_iterator("resources");
        itEntry != std::filesystem::recursive_directory_iterator();
        ++itEntry ) {
        const auto filenameStr = itEntry->path().string();
        std::cout << std::setw(itEntry.depth()*3) << "";
        std::cout << "add:  " << filenameStr << '\n';
        pack->AddFile(filenameStr);
    }
    pack->SavePack("ResourcePack.dat", key);
}
