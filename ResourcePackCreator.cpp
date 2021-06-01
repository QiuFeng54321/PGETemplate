//     <one line to give the program's name and a brief idea of what it does.>
//     Copyright (C) 2021  Qiufeng54321
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
    olc::ResourcePack *pack = new olc::ResourcePack();
    std::filesystem::current_path("/Users/mac/Documents/VSCProjects/PGETemplate/resources");
    for (auto itEntry = std::filesystem::recursive_directory_iterator(".");
         itEntry != std::filesystem::recursive_directory_iterator();
         ++itEntry) {
        if (itEntry->is_directory()) continue;
        const auto filenameStr = relative(itEntry->path(), std::filesystem::current_path()).string();
        std::cout << std::setw(itEntry.depth() * 3) << "";
        std::cout << "add:  " << filenameStr << '\n';
        pack->AddFile(filenameStr);
    }
    pack->SavePack("../ResourcePack.dat", key);
}
