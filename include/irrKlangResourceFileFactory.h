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
// Created by mac on 2021/5/20.
//

#ifndef PGETEMPLATE_IRRKLANGRESOURCEFILEFACTORY_H
#define PGETEMPLATE_IRRKLANGRESOURCEFILEFACTORY_H

#include "irrKlang.h"
#include "olcPixelGameEngine.h"
#include "Resources.h"

using namespace irrklang;


// a class implementing the IFileFactory
// interface to override irrklang file access
class irrKlangResourceFileFactory : public irrklang::IFileFactory {
public:

    //! Opens a file for read access. Simply return 0 if file not found.
    virtual irrklang::IFileReader *createFileReader(const irrklang::ik_c8 *filename) {
        printf("irrKlangResourceFileFactory: open file %s\n", filename);
        std::vector<char> buf = williamcraft::ResourcePack->GetFileBuffer(filename).vMemory;
        auto file = fmemopen(buf.data(), buf.size(), "rb");
        return new ResourceReadFile(file, filename);
    }

    // an own implementation if IReadFile to overwrite read access to files
    class ResourceReadFile : public irrklang::IFileReader {
    public:

        // constructor, store size of file and filename
        ResourceReadFile(FILE *file, const ik_c8 *filename) {
            File = file;
            strcpy(Filename, filename);

            // get file size
            fseek(File, 0, SEEK_END);
            FileSize = ftell(File);
            fseek(File, 0, SEEK_SET);
        }

        ~ResourceReadFile() {
            fclose(File);
        }

        //! reads data, returns how much was read
        ik_s32 read(void *buffer, ik_u32 sizeToRead) {
//            printf("ResourceReadFile: read %d bytes\n", sizeToRead);
            return (ik_s32) fread(buffer, 1, sizeToRead, File);
        }

        //! changes position in file, returns true if successful
        bool seek(ik_s32 finalPos, bool relativeMovement) {
//            printf("ResourceReadFile: seek to position %d\n", finalPos);
            return fseek(File, finalPos, relativeMovement ? SEEK_CUR : SEEK_SET) == 0;
        }

        //! returns size of file
        ik_s32 getSize() {
            return FileSize;
        }

        //! returns where in the file we are.
        ik_s32 getPos() {
            return ftell(File);
        }

        //! returns name of file
        const ik_c8 *getFileName() {
            return Filename;
        }

        FILE* File;
        char Filename[1024];
        ik_s32 FileSize;

    }; // end class ResourceReadFile
};

#endif //PGETEMPLATE_IRRKLANGRESOURCEFILEFACTORY_H
