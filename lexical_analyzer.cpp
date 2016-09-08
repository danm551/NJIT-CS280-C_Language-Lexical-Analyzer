/*
o CS 280-102, SPRING 2015
o Ernesto Martinez
o Program #1
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <iosfwd>
#include <sstream>
using namespace std;

int CheckArguments(int&, char *argv[]);
void AddAdjective1(string&, string&, int&, bool&);
void AddAdjective1b(string&, string&, int&, bool&);
void AddAdjective1c(string&, string&, int&, bool&);
void AddAdjective2(string&, string&, int&, bool&);
void AddAdjective2b(string&, string&, int&, bool&);
void AddAdjective2c(string&, string&, int&, bool&);
void AddAdjective3(string&, string&, int&, bool&);
void AddAdjective3b(string&, string&, int&, bool&);
void AddAdjective3c(string&, string&, int&, bool&);
int CheckCase(string&, int&);
bool CheckVowel(char);
void CheckForArticle(string&, string&, int&, bool&);

/*
	                           Articles/search cases
*/
string a = " a ";
string a2 = "a ";
string alb = " a\n";
string A = " A ";
string A2 = "A ";
string Alb = " A\n";
string an = " an ";
string an2 = "an ";
string anlb = " an\n";
string An = " An ";
string An2 = "An ";
string Anlb = " An\n";
string aN = " aN ";
string aN2 = "aN ";
string aNlb = " aN\n";
string AN = " AN ";
string AN2 = "AN ";
string ANlb = " AN\n";
string the = " the ";
string the2 = "the ";
string thelb = " the\n";
string The = " The ";
string The2 = "The ";
string Thelb = " The\n";
string tHe = " tHe ";
string tHe2= "tHe";
string tHelb = " tHe\n";
string thE = " thE ";
string thE2 = "thE ";
string thElb = " thE\n";
string THE = " THE ";
string THE2 = "THE ";
string THElb = " THE\n";
string THe = " THe ";
string THe2 = "THe ";
string THelb = " THe\n";
string tHE = " tHE ";
string tHE2 = "tHE ";
string tHElb = " tHE\n";
string ThE = " ThE ";
string ThE2 = "ThE ";
string ThElb = " ThE\n";
int currentLoc = 0;

int main(int argc, char*argv[]) {

	int gateKeeper = CheckArguments(argc, argv);

	if(gateKeeper == 1)
		return 0;

	//Checks to make sure file exists
	ifstream testStream(argv[2]);
	if(testStream.is_open())
		testStream.close();
	else
	{
		cout << "File Not Found." << endl;
		return 0;
	}

	string adjective = argv[1];
	string fileName = argv[2];
	ifstream myStream(fileName.c_str());
	string mystring((istreambuf_iterator<char>(myStream)),istreambuf_iterator<char>()); //copies file into mystring
	int adjSize = adjective.length();
	char firstLetter = adjective[0];
	bool vowel = false;

	vowel = CheckVowel(firstLetter);
	CheckForArticle(mystring, adjective, adjSize, vowel);

	cout << mystring << endl; // Prints final result

	return 0;
}

/*
 * Name: CheckArguments
 *
 * Args: argc, argv
 *
 * Description: Makes sure command line arguments are valid in quantity and format.
 *
 * Returns: 0 to exit program, 1 to continue.
 */
int CheckArguments(int &argc, char *argv[])
{
	int counter = 0;
	string adj = argv[1];
	string file = argv[2];

	if(argc != 3)
	{
		cout << "two command line arguments are required to run" << endl;
		return 1;
	}

	for(int i = 0; i < adj.length()+1; i++)
	{
		if(isalpha(adj[i]) > 0)
			counter++;
	}

	if(counter == adj.length())
	{
		return 0;
	}
	else
		cout << "Adjective must consist of letters. No numbers or characters allowed." << endl;
		return 1;
}
/*
 * Name: CheckForArticle
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Searches for the articles in string mystring.
 *
 * Returns: void
 */
void CheckForArticle(string &mystring, string &adjective, int &adjSize, bool &vowel)
{
	while(currentLoc < mystring.length()+1)
	{
		if(mystring.find(a, currentLoc) == currentLoc)
		{
			AddAdjective1(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(a2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective1b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(alb, currentLoc) == currentLoc)
		{
			AddAdjective1c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(A, currentLoc) == currentLoc)
		{
			AddAdjective1(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(A2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective1b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(Alb, currentLoc) == currentLoc)
		{
			AddAdjective1c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(an, currentLoc) == currentLoc)
		{
			AddAdjective2(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(an2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective2b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(anlb, currentLoc) == currentLoc)
		{
			AddAdjective2c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(An, currentLoc) == currentLoc)
		{
			AddAdjective2(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(An2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective2b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(Anlb, currentLoc) == currentLoc)
		{
			AddAdjective2c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(aN, currentLoc) == currentLoc)
		{
			AddAdjective2(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(aN2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective2b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(aNlb, currentLoc) == currentLoc)
		{
			AddAdjective2c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(AN, currentLoc) == currentLoc)
		{
			AddAdjective2(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(AN2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective2b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(ANlb, currentLoc) == currentLoc)
		{
			AddAdjective2c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(the, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(the2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(thelb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(The, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(The2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(Thelb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(tHe, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(tHe2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(tHelb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(thE, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(thE2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(thElb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(THE, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(THE2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(THElb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(THe, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(THe2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(THelb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(tHE, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(tHE2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(tHElb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(ThE, currentLoc) == currentLoc)
		{
			AddAdjective3(mystring, adjective, adjSize, vowel);
		}
		else if(mystring.find(ThE2, currentLoc) == currentLoc)
		{
			if(currentLoc == 0)
				AddAdjective3b(mystring, adjective, adjSize, vowel);
			else
			{
				currentLoc++;
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(mystring.find(ThElb, currentLoc) == currentLoc)
		{
			AddAdjective3c(mystring, adjective, adjSize, vowel);
		}
		else
		{
			currentLoc++;
		}
	}
}
/*
 * Name: AddAdjective1
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article " a " and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective1(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles a, A
{
	int caseValue = 0;
	int key = 3;
	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+3, 1, " ") != 0 && mystring.compare(currentLoc+3, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0)
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			if(vowel == true)
			{
				mystring.replace(currentLoc+2, 0, "n"); //adds n to a on positive vowel check
				mystring.replace(currentLoc+3, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
			else
			{
				mystring.replace(currentLoc+2, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
				currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(caseValue == 3) //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+2, 0, "n"); //adds n to a on positive vowel check
					mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
		else if(caseValue == 2) //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

				if(vowel == true)
				{
					mystring.replace(currentLoc+2, 0, "n"); //adds n to a on positive vowel check
					mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
				}
				else
				{
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
				}
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective1b
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article "a " and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective1b(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles "a "
{
	int caseValue = 0;
	int key = 2;

	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+2, 1, " ") != 0 && mystring.compare(currentLoc+2, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0)
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			if(vowel == true)
			{
				mystring.replace(currentLoc+1, 0, "n"); //adds n to a on positive vowel check
				mystring.replace(currentLoc+2, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
				currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
			else
			{
				mystring.replace(currentLoc+1, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+1, 0, " "); //adds space between article and adjective
				currentLoc += (3+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(caseValue == 3)                  //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+1, 0, "n"); //adds n to a on positive vowel check
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.replace(currentLoc+1, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+1, 0, " "); //adds space between article and adjective
					currentLoc += (3+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
		else if(caseValue == 2) //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

				if(vowel == true)
				{
					mystring.replace(currentLoc+1, 0, "n"); //adds n to a on positive vowel check
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
				}
				else
				{
					mystring.replace(currentLoc+1, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+1, 0, " "); //adds space between article and adjective
					currentLoc += (3+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
				}
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective1c
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article " a\n" and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective1c(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles alb
{
	int caseValue = 0;
	int key = 3;

	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+3, 1, "\0") == 0) //moves article to next line if null found
		{

			mystring.replace(currentLoc+1, 0, "\n");
			mystring.replace(currentLoc+3, 0, " ");
		}

	if(mystring.compare(currentLoc+3, 1, " ") != 0 && mystring.compare(currentLoc+3, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0)
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			if(vowel == true)
			{
				mystring.replace(currentLoc+2, 0, "n"); //adds n to a on positive vowel check
				mystring.replace(currentLoc+1, 0, "\n");//add \n before article
				mystring.replace(currentLoc+4, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
				mystring.erase(currentLoc+5+adjective.length(), 1); //erases the former \n
				mystring.replace(currentLoc+5+adjective.length(), 0, " "); //replaces former \n with space
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
			else
			{
				mystring.replace(currentLoc+1, 0, "\n");//add \n before article
				mystring.replace(currentLoc+3, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
				mystring.erase(currentLoc+4+adjective.length(), 1); //erases the former \n
				mystring.replace(currentLoc+4+adjective.length(), 0, " "); //replaces former \n with space
				currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(caseValue == 3)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+2, 0, "n"); //adds n to a on positive vowel check
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
					mystring.replace(currentLoc+4, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+5+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+5+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
		    		mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+4+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+4+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
		else if(caseValue == 2)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+2, 0, "n"); //adds n to a on positive vowel check
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
					mystring.replace(currentLoc+4, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+5+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+5+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
		    		mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+4+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+4+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective2
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article " an " and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective2(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles an, An
{
	int caseValue = 0;
	int key = 4;
	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+4, 1, " ") != 0 && mystring.compare(currentLoc+4, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0) //adjusted
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			if(vowel == true)
			{
				mystring.replace(currentLoc+3, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
			else
			{
				mystring.erase(currentLoc+2, 1); //adds n to a on positive vowel check
				mystring.replace(currentLoc+2, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(caseValue == 3)                  //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.erase(currentLoc+2, 1); //adds n to a on positive vowel check
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
		else if(caseValue == 2)                  //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.erase(currentLoc+2, 1); //adds n to a on positive vowel check
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective2b
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article "an " and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective2b(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles an, An
{
	int caseValue = 0;
	int key = 3;

	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+3, 1, " ") != 0 && mystring.compare(currentLoc+3, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0) //adjusted
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			if(vowel == true)
			{
				mystring.replace(currentLoc+2, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
				currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
			else
			{
				mystring.erase(currentLoc+1, 1); //adds n to a on positive vowel check
				mystring.replace(currentLoc+1, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+1, 0, " "); //adds space between article and adjective
				currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(caseValue == 3)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.erase(currentLoc+1, 1); //adds n to a on positive vowel check
					mystring.replace(currentLoc+1, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+1, 0, " "); //adds space between article and adjective
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
		else if(caseValue == 2)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+2, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+2, 0, " "); //adds space between article and adjective
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.erase(currentLoc+1, 1); //adds n to a on positive vowel check
					mystring.replace(currentLoc+1, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+1, 0, " "); //adds space between article and adjective
					currentLoc += (4+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective2c
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article " an\n" and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective2c(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles anlb
{
	int caseValue = 0;
	int key = 4;

	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+4, 1, "\0") == 0) //moves article to next line if null found
		{
			mystring.replace(currentLoc+1, 0, "\n");
			mystring.replace(currentLoc+4, 0, " ");
		}
	if(mystring.compare(currentLoc+4, 1, " ") != 0 && mystring.compare(currentLoc+4, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0) //adjusted
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			if(vowel == true)
			{
				mystring.replace(currentLoc+1, 0, "\n");//add \n before article
				mystring.replace(currentLoc+4, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
				mystring.erase(currentLoc+5+adjective.length(), 1); //erases the former \n
				mystring.replace(currentLoc+5+adjective.length(), 0, " "); //replaces former \n with space
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
			else
			{
				mystring.erase(currentLoc+2, 1); //deletes n to a on negative vowel check
				mystring.replace(currentLoc+1, 0, "\n");//add \n before article
				mystring.replace(currentLoc+3, 0, adjective); //adds adjective after article
				mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
				mystring.erase(currentLoc+4+adjective.length(), 1); //erases the former \n
				mystring.replace(currentLoc+4+adjective.length(), 0, " "); //replaces former \n with space
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
			}
		}
		else if(caseValue == 3)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
		    		mystring.replace(currentLoc+4, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+5+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+5+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.erase(currentLoc+2, 1); //adds n to a on positive vowel check
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
					mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+4+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+4+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
		else if(caseValue == 2)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

		    	if(vowel == true)
		    	{
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
		    		mystring.replace(currentLoc+4, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+5+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+5+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		    	}
		    	else
		    	{
					mystring.erase(currentLoc+2, 1); //adds n to a on positive vowel check
					mystring.replace(currentLoc+1, 0, "\n");//add \n before article
					mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
					mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
					mystring.erase(currentLoc+4+adjective.length(), 1); //erases the former \n
					mystring.replace(currentLoc+4+adjective.length(), 0, " "); //replaces former \n with space
					currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
					CheckForArticle(mystring, adjective, adjSize, vowel);
		        }
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective3
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article " the " and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective3(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles the, The
{
	int caseValue = 0;
	int key = 5;
	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+5, 1, " ") != 0 && mystring.compare(currentLoc+5, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0) //adjusted
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			mystring.replace(currentLoc+4, 0, adjective); //adds adjective after article
			mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
			currentLoc += (6+adjSize); //increment currentLoc by size of article, adjective
			CheckForArticle(mystring, adjective, adjSize, vowel);
		}
		else if(caseValue == 3)                  //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
				mystring.replace(currentLoc+4, 0, upperCase); //adds adjective after article
				mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
				currentLoc += (6+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
		}
		else if(caseValue == 2)                  //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

			mystring.replace(currentLoc+4, 0, upperCase); //adds adjective after article
			mystring.replace(currentLoc+4, 0, " "); //adds space between article and adjective
			currentLoc += (6+adjSize); //increment currentLoc by size of article, adjective
			CheckForArticle(mystring, adjective, adjSize, vowel);
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective3b
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article "the " and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective3b(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles the, The
{
	int caseValue = 0;
	int key = 4;

	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+4, 1, " ") != 0 && mystring.compare(currentLoc+4, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0) //adjusted
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			mystring.replace(currentLoc+3, 0, adjective); //adds adjective after article
			mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
			currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
			CheckForArticle(mystring, adjective, adjSize, vowel);
		}
		else if(caseValue == 3)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
				mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
				mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
				currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
		}
		else if(caseValue == 2)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

			mystring.replace(currentLoc+3, 0, upperCase); //adds adjective after article
			mystring.replace(currentLoc+3, 0, " "); //adds space between article and adjective
			currentLoc += (5+adjSize); //increment currentLoc by size of article, adjective
			CheckForArticle(mystring, adjective, adjSize, vowel);
		}
	}
	else
		currentLoc++;
}
/*
 * Name: AddAdjective3c
 *
 * Args: string mystring, string adjective, int adjSize, bool vowel
 *
 * Description: Handles adjective insertion for article " the\n" and all it's derivatives
 *
 * Returns: void
 */
void AddAdjective3c(string &mystring, string &adjective, int &adjSize, bool &vowel) //handles articles the, The
{
	int caseValue = 0;
	int key = 5;

	caseValue = CheckCase(mystring, key);

	if(mystring.compare(currentLoc+5, 1, "\0") == 0) //moves article to next line if null found
		{
			mystring.replace(currentLoc+1, 0, "\n");
			mystring.replace(currentLoc+5, 0, " ");
		}

	if(mystring.compare(currentLoc+5, 1, " ") != 0 && mystring.compare(currentLoc+5, 1, ".") != 0 && mystring.compare(currentLoc+3, 1, "\0") != 0) //adjusted
	{
		if(caseValue == 1) //lower case condition: if first letter of noun is lower case -- insert adjective unchanged
		{
			mystring.replace(currentLoc+1, 0, "\n"); //moves the \n character behind the article
			mystring.replace(currentLoc+5, 0, adjective); //adds adjective after article
			mystring.replace(currentLoc+5, 0, " "); //adds space between article and adjective
			mystring.erase(currentLoc+6+adjective.length(), 1); //erases the former \n
			mystring.replace(currentLoc+6+adjective.length(), 0, " "); //replaces former \n with space
			currentLoc += (6+adjSize); //increment currentLoc by size of article, adjective
			CheckForArticle(mystring, adjective, adjSize, vowel);
		}
		else if(caseValue == 3)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;

		    for(int i = 0; i < adjSize+1; i++)
		    {
		    	upperCase[i] = toupper(adjective[i]);
		    }
		    	mystring.replace(currentLoc+1, 0, "\n"); //moves the \n character behind the article
		    	mystring.replace(currentLoc+5, 0, upperCase); //adds adjective after article
				mystring.replace(currentLoc+5, 0, " "); //adds space between article and adjective
				mystring.erase(currentLoc+6+adjective.length(), 1); //erases the former \n
				mystring.replace(currentLoc+6+adjective.length(), 0, " "); //replaces former \n with space
				currentLoc += (6+adjSize); //increment currentLoc by size of article, adjective
				CheckForArticle(mystring, adjective, adjSize, vowel);
		}
		else if(caseValue == 2)                 //upper case condition: if first letter in noun is upper case -- change adjective to upper case and insert
		{
			string upperCase = adjective;
			upperCase[0] = toupper(adjective[0]);

		    mystring.replace(currentLoc+1, 0, "\n"); //moves the \n character behind the article
		    mystring.replace(currentLoc+5, 0, upperCase); //adds adjective after article
			mystring.replace(currentLoc+5, 0, " "); //adds space between article and adjective
			mystring.erase(currentLoc+6+adjective.length(), 1); //erases the former \n
			mystring.replace(currentLoc+6+adjective.length(), 0, " "); //replaces former \n with space
			currentLoc += (6+adjSize); //increment currentLoc by size of article, adjective
			CheckForArticle(mystring, adjective, adjSize, vowel);
		}
	}
	else
		currentLoc++;
}
/*
 * Name: CheckCase
 *
 * Args: string mystring, int key
 *
 * Description: Determines the upper/lower case condition of the noun
 *
 * Returns: 1 if first letter is lower case, 2 if all letters are upper case, 3 if first letter is upper case and there's one or more lower case letters
 */
int CheckCase(string &mystring, int &key) // Checks case of noun: 1 if all lower case; 2 if only first letter is upper; 3 if all letters are upper
{
	int tempLoc = currentLoc;
	int tempLoc2 = currentLoc;

	switch(key)
	{
	case 2:
			tempLoc+=2;
			tempLoc2+=2;
		break;
	case 3:
			tempLoc+=3;
			tempLoc2+=3;
		break;
	case 4:
			tempLoc+=4;
			tempLoc2+=4;
		break;
	case 5:
			tempLoc+=5;
			tempLoc2+=5;
		break;
	}

	int firstLetterCase = 0;
	int upper = 0;
	int lower = 0;

	if(isupper(mystring[tempLoc]))
			firstLetterCase = 1;

	while(isalpha(mystring[tempLoc]) > 0)
	{
		tempLoc++;
	}

	int difference = tempLoc - tempLoc2;

	for(int i = tempLoc2; i < tempLoc; i++)
	{
		if(isupper(mystring[i]))
			upper++;
		else
			lower++;
	}

	if(firstLetterCase == 0)
		return 1;
	if(firstLetterCase == 1 && lower > 0)
		return 2;
	if(upper == difference)
		return 3;
}
/*
 * Name: CheckVowel
 *
 * Args: char firstLetter
 *
 * Description: Examines first letter of adjective argument and determines if vowel or consonant
 *
 * Returns: true if vowel, false if not
 */
bool CheckVowel(char firstLetter)
{
	switch(firstLetter)
	{
		case 'a':
			return true;
		case 'e':
			return true;
		case 'i':
			return true;
		case 'o':
			return true;
		case 'u':
			return true;
		case 'A':
			return true;
		case 'E':
			return true;
		case 'I':
			return true;
		case 'O':
			return true;
		case 'U':
			return true;
		default:
			return false;
	}
}
