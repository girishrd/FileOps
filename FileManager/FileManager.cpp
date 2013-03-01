/*===============================================================
FILENAME:
DESC: A set of simple file management routines
AUTHOR: Girish D

UPDATED:01-01-2013
NOTES:
====================================================================*/
#include "stdafx.h"
#include "FileManager.h"
#define SUCCESS 0
#define FAILURE -1;

using namespace std;


int FileManager::fileParse(const string& fname)
{
	double NO_OF_SENTENCES=0;
	double NO_OF_WORDS=0;
	double NO_OF_LINES=0;
	double NO_OF_CHARS_WWS=0; //excluding whitespaces
	double NO_OF_CHARS_WS=0; //including whitespaces
	
	ifstream IFSTRM;
	string FILEDATA;
	
	IFSTRM.open(fname);
	if(!IFSTRM.is_open()){
		cout<<"ERROR: File ["<<fname.c_str()<<"] not found!"<<endl;
		return FAILURE;
	}
	
	while(IFSTRM.good()){
		
		getline(IFSTRM,FILEDATA);
		if(!FILEDATA.empty()) 
			NO_OF_LINES++;
	}
	IFSTRM.clear(); //note to self: clear the streambuf for EOF before seek
	IFSTRM.seekg(0, ios::beg);
	while(IFSTRM.good()){
		char ch;
		ch=IFSTRM.get();
		if(ch=='.')
		{
			NO_OF_SENTENCES++;
		}
	}
	IFSTRM.clear(); //note to self: clear the streambuf for EOF before seek
	IFSTRM.seekg(0, ios::beg);
	unsigned found=0;
	while(IFSTRM.good()){
			FILEDATA.clear();
		
			getline(IFSTRM,FILEDATA);
			if(FILEDATA.length() > 0)
			{
				NO_OF_CHARS_WS+=FILEDATA.length();
				for (unsigned int i(0); i< FILEDATA.length(); i++ ){
					{
						if ( FILEDATA.at(i)==' ') 
							NO_OF_WORDS++;
						else
							NO_OF_CHARS_WWS++;
					}

				}
			}
			 
	}
	cout<<"Filename: ["<<fname<<"]"<<endl;
	cout<<"======================="<<endl;
	cout<<"statistics:"<<endl;
	cout<<"----------------"<<endl;
	cout<<"NO.OF.LINES="<<NO_OF_LINES<<endl;
	cout<<"NO OF SENTENCES="<<NO_OF_SENTENCES<<endl;
	cout<<"NO.OF WORDS="<<(NO_OF_WORDS-1)<<endl;
	cout<<"NO.OF CHARACTERS(excluding spaces)="<<NO_OF_CHARS_WWS<<endl;
	cout<<"NO.OF CHARACTERS(including spaces)="<<NO_OF_CHARS_WS<<endl;

	return SUCCESS;
}

//--------------------------------------------------------------------

int FileManager::fileCopy(const string& fname,string newFile){
ifstream IFSTRM;
ofstream OFSTRM;
string  FILEDATA;

	IFSTRM.open(fname);
	if(!IFSTRM.is_open()){
		cout<<"ERROR: File ["<<fname.c_str()<<"] not found!"<<endl;
		return FAILURE;
	}
	OFSTRM.open(newFile);
	if(!OFSTRM.is_open()){
		cout<<"ERROR creating file"<<endl;
		return FAILURE;
	}
	
	while(IFSTRM.good()){
		 getline(IFSTRM,FILEDATA);
		 if(OFSTRM.good()){
			OFSTRM<<FILEDATA<<"\n";
		 }
		 else{
			 cout<<"ERROR: Couldn't write to file..."<<endl;
			 return FAILURE;
		 }

	}
	IFSTRM.close();
	OFSTRM.close();
	
return SUCCESS;
}

//-----------------------------------------------------------
int FileManager::fileRemoveWhiteSpaceFromEachLine(const string& fname)
{
ifstream IFSTRM;
ofstream OFSTRM;
string  FILEDATA;
FileManager fm;

	
	IFSTRM.open(fname);
	if(!IFSTRM.is_open()){
		cout<<"ERROR: File ["<<fname.c_str()<<"] not found!"<<endl;
		return FAILURE;
	}
	OFSTRM.open("tempfile");
	if(!OFSTRM.is_open()){
		cout<<"ERROR creating file"<<endl;
		return FAILURE;
	}
	while(IFSTRM.good()){
		getline(IFSTRM,FILEDATA);
		std::string::iterator EOS= std::remove_if( FILEDATA.begin(), FILEDATA.end(), isspace );
		string TEMP(FILEDATA.begin(),EOS);
		if(OFSTRM.good()){
			OFSTRM<<TEMP<<"\n";
		}
		else{
			cout<<"ERROR: Couldn't write to file..."<<endl;
			return FAILURE;
		}

	}
	IFSTRM.close();
	OFSTRM.close();
	fm.fileCopy("tempfile",fname);
	if( remove( "tempfile" ) != 0 ){
		cout<<"ERROR: Couldn't delete file..."<<endl;
		return FAILURE;
	}
	else{   
		return SUCCESS;
	}

}
//-----------------------------------------------

//globals -- move elsewhere later?
vector<float> fileDataVectorNum;
vector<string> fileDataVectorStr;
//Converts to double
int FileManager::fileVectorize(const string& fname, vector<float>& fileDataVectorNum)
{
ifstream IFSTRM;
ofstream OFSTRM;
string  FILEDATA;

long double value;

IFSTRM.open(fname);
	if(!IFSTRM.is_open()){
		cout<<"ERROR: File ["<<fname.c_str()<<"] not found!"<<endl;
		return FAILURE;
	}
	while(IFSTRM.good()){
		getline(IFSTRM,FILEDATA);
		
			value= atof(FILEDATA.c_str());//WARNING:might result in loss of precision based on compiler-TBV:girish.rd
			fileDataVectorNum.push_back(value);
	}
	for (std::vector<float>::iterator it = fileDataVectorNum.begin() ; it != fileDataVectorNum.end(); ++it)
    std::cout <<*it<<endl;
}
//stores parsed values as strings

int FileManager::fileVectorize(const string& fname, vector<string>& fileDataVectorStr)
{
ifstream IFSTRM;
ofstream OFSTRM;
string  FILEDATA;

long double value;

IFSTRM.open(fname);
	if(!IFSTRM.is_open()){
		cout<<"ERROR: File ["<<fname.c_str()<<"] not found!"<<endl;
		return FAILURE;
	}
	while(IFSTRM.good()){
		getline(IFSTRM,FILEDATA);
		fileDataVectorStr.push_back(FILEDATA.c_str());
	}
	for (std::vector<string>::iterator it = fileDataVectorStr.begin() ; it != fileDataVectorStr.end(); ++it)
    std::cout <<*it<<endl;
}






