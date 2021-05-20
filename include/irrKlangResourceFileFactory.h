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
    class ResourceReadFile : public irrklang::IFileReader
    {
    public:

        // constructor, store size of file and filename
        ResourceReadFile(FILE* file, const ik_c8* filename)
        {
            File = file;
            strcpy(Filename, filename);

            // get file size
            fseek(File, 0, SEEK_END);
            FileSize = ftell(File);
            fseek(File, 0, SEEK_SET);
        }

        ~ResourceReadFile()
        {
            fclose(File);
        }

        //! reads data, returns how much was read
        ik_s32 read(void* buffer, ik_u32 sizeToRead)
        {
//            printf("ResourceReadFile: read %d bytes\n", sizeToRead);
            return (ik_s32)fread(buffer, 1, sizeToRead, File);
        }

        //! changes position in file, returns true if successful
        bool seek(ik_s32 finalPos, bool relativeMovement)
        {
//            printf("ResourceReadFile: seek to position %d\n", finalPos);
            return fseek(File, finalPos, relativeMovement ? SEEK_CUR : SEEK_SET) == 0;
        }

        //! returns size of file
        ik_s32 getSize()
        {
            return FileSize;
        }

        //! returns where in the file we are.
        ik_s32 getPos()
        {
            return ftell(File);
        }

        //! returns name of file
        const ik_c8* getFileName()
        {
            return Filename;
        }

        FILE* File;
        char Filename[1024];
        ik_s32 FileSize;

    }; // end class ResourceReadFile
};

#endif //PGETEMPLATE_IRRKLANGRESOURCEFILEFACTORY_H
