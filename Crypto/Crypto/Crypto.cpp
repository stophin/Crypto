// Crypto.cpp : 定义控制台应用程序的入口点。
//
#include "Crypto.h"

#include "AES.h"

void testAES() {
	string str1 = "4F1Z9jQZohmNcCOU+xVGwmP6qTMK/NndtV35M691aBi1u+qHwIBJUDN3AhJij7x5b+y3+NnmWY4Z5kfMcJIiAAdnSyr5A30mf0HWJe0R500dpEHYi+pLVnYHDxgHXMcqMBgRIOOP5r7CrWHXS08e3JhUnjRWvId8xeFO4Wcz2ZA=";

	string str2 = AES::DecryptionAES(str1);

	printf("%s\n", str2.c_str());
}


int main(int argc, char * argv[])
{
	testAES();

	getch();
	return 0;
}

