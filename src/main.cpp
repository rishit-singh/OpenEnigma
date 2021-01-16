#include "openenigma.h"
#include "filemanager.h"
#include "exceptions.h"
#include <iostream>
#include <string.h>

using namespace OpenEnigma; 

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "\n" << "Insufficient Arguements\n";  

		return 0; 
	}

	char XorKey = argv[1][0];

	char* EncryptedString = new char[64];

	strcpy(EncryptedString, "Hello");

	FileOperations::Write(EncryptedString = Cryptography::XORCrypt(EncryptedString, XorKey), "test.txt");

	std::cout << "\nEncryptedBuffer: " << EncryptedString; 

	// FileOperations::Write("Hello World!", "test.txt");
	EncryptedString = Cryptography::XORCrypt(EncryptedString, XorKey);

	std::cout << "\nDecryptedBuffer: " << EncryptedString
		<< '\n'; 

	return 0;
}
