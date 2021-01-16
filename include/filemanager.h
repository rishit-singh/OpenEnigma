#ifndef FILEMANAGER_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Debug.h"

namespace OpenEnigma
{
	class Directory
	{
	public:
		std::vector<Directory*>* NestedDirectories;
		Directory* Root;

		char* Name; 

		bool Add(Directory* directory) // Adds a directory.
		{
			this->NestedDirectories->push_back(directory);
		}

		static bool IsValid(Directory* dir)
		{
			
		}

		Directory(char* name, Directory* root) : Name(name), Root(root)
		{
		}
	};

	class FileOperations
	{
	public:
		template<typename T>
		static bool Write(T data, char* path)
		{
			FILE* FilePointer = fopen(path, "w");
			
			try 
			{
				fprintf(FilePointer, "%s", data); 
			}
			catch (std::exception& e)
			{
				Debug->Log(e.what()); 

				return false;
			};

			return true;
		}

		template<typename T>
		static bool Write(T* data, int size, char* path)  //  Writes the provided array of data to the provided file path
		{
			FILE* FilePointer = fopen(path, "w");
			
			try 
			{
				fprintf(FilePointer, "%s", data); 
			}
			catch (std::exception& e)
			{
				Debug->Log(e.what()); 

				return false;
			};

			return true;
		}
		
		static bool Write(char* buffer, char* path)  //  Writes the provided string to the provided file path
		{
			FILE* FilePointer = fopen(path, "w");
			
			try 
			{
				fputs(buffer, FilePointer);
			}
			catch (std::exception& e)
			{
				Debug->Log(e.what()); 

				return false;
			};

			return true;	
		}

		static char* Read(char*);   //  Reads the data from the provided file path
	};    
}

#endif
