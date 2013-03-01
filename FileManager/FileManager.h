/*===============================================================
FILENAME:
DESC: Header file for the File management routines
AUTHOR: Girish D

UPDATED:01-01-2013
NOTES:
====================================================================*/
#pragma once

#include "targetver.h"
#include<iostream>
#include<stdio.h>
#include<tchar.h>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class FileManager
{

	//methods
public:
    int fileCopy(const string&, string newFile);
    int fileErase(const string&);
	int fileParse(const string&);
	int fileRemoveWhiteSpaceFromEachLine(const string&);
	int FileManager::fileVectorize(const string& fname, vector<float>& fileDataVectorNum);
	int FileManager::fileVectorize(const string& fname, vector<string>& fileDataVecorStr);

};
