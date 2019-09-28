#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int main()
{
   int useSomeHow = 0;
   int foundNumTimes = 1;
   ifstream inputFile;
   FILE * ptrInFile;
   string userFileName;
   char findWord[30];
   string word = "hi";

   do
   {
      cout << "Please enter the file you wish to open: " << endl;
      cin >>  userFileName;

      inputFile.open(userFileName);
      if (!inputFile)
      {
         cout << "Error, cannot open " << userFileName << endl;
      }
   } while (!inputFile);

   ptrInFile = fopen("DeclOfIndep.txt", "r");

   cout << "Your file has been open. Please type the word you are looking for: " << endl;
   cin >> word;



   while (fgets(findWord, 100, ptrInFile))
   {
      char * strPtr = findWord;
      while ((strPtr = strchr(strPtr, '\n')) != '\0')
         *strPtr++ = '\0';

      cout << findWord << endl;
   }


   system("pause");
   
   return 0;
}