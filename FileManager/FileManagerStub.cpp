/*==========================
Filename:
Author:
Desc:

/=========================*/

#include "stdafx.h"
#include "FileManager.h"



int main()
{
	vector<float> v1;
	FileManager fm1,fm2;
	//fm1.fileCopy("testfile1.txt","copyfile.txt");
	// fm1.fileParse("testfile1.txt");
	// fm1.fileRemoveWhiteSpace("testfile1.txt");
	fm1.fileVectorize("testfile1.txt", v1 );
	fm2.fileVectorize("testfile1.txt", v1 );



}
