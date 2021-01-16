#include <string.h> 
#include "openenigma.h"

char* OpenEnigma::Cryptography::XORCrypt(char* buffer, char key)
{
	int BufferSize; 
	
	char* BufferTemp = new char[(BufferSize = strlen(buffer))]; 

	for (int x = 0; x < BufferSize; x++)
		BufferTemp[x] = buffer[x] ^ key;

	return BufferTemp; 
}