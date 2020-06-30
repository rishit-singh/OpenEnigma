#pragma once

#define FILEMANAGER_H
#define FILEMANAGER_H

#include <stdio.h>
#include <iostream>
#include <stack>
#include <ofstream> 

namespace DirectoryManager
{
    class Directory
    {
    public:
        stack<Directory*>* NestedDirectories;

        char* Name, *Root;

        bool Add(Directory* directory) // Adds a directory.
        {
            this->NestedDirectories->Push(directory);
        }

        static bool IsValid(Directory* dir)
        {
            
        }

        Directory(char* name, Directory* root)
        {
            this->Name = name;
            this->Root = root;
        }
    };
}
