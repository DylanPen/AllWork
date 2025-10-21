#ifndef CATALOG_HPP
#define CATALOG_HPP

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

struct Spell {
	string name;
	float success_rate;
	string effect;
};

struct Spellbook {
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct Spell *spells;
};

//a struct to hold info of a Playlist
struct Wizard {
	string name;
	int id; // Used for logging in
	string password; // Used for logging in
	string position_title; // Used to restrict poison and death spells
	float beard_length;
};

/*
 * Function: create_spells
 * Description: Allocates a dynamic array of spells of the requested size and
 * 		returns a pointer that points to it
 * Parameters:
 * 		size (int): Size of dynamic array of spells to create
 * Returns: Pointer that points to dynamically allocated array of spells
 */
Spell* create_spells(int size);

/*
 * Function: read_spell_data
 * Description: Reads all of the information associated with a single spell
 * 		structure from the given spellbooks text file and returns a created
 * 		spell structure containing that information.
 * Parameters:
 * 		file (ifstream&): A reference to an std::ifstream that is open on
 * 		the input spellbooks text file and prepared to read information about
 * 		the next spell in a spellbook.
 * Returns: The created spell structure containing the information of the
 * 		next spell in the input file
 *
 * Hint: “ifstream& file” is a reference to a filestream object. You will
 * need to create one, open it up to read from the spellbooks text file, read
 * the information up to (but not including) the first spell, and then pass it
 * into this function to start reading spell data. Remember that information in
 * an input file must generally be read by your program in the order that it’s
 * presented in the file.
 */
Spell read_spell_data(ifstream& file);

/*
 * Function: create_spellbooks
 * Description: Allocates a dynamic array of spellbooks of the requested size
 * 		and returns a pointer that points to it.
 * Parameters:
 * 		size (int): Size of dynamic array of spellbooks to create
 * Returns: Pointer that points to dynamically allocated array of spellbooks
 */
Spellbook* create_spellbooks(int size);

/*
 * Function: read_spellbook_data
 * Description: Reads all of the information associated with a single spellbook
 * 		structure from the given spellbooks text file and returns a created
 * 		spellbook structure containing that information. Note that the
 * 		avg_success_rate member variable of the returned spellbook structure is
 * 		not contained in the text file, but rather will need to be computed as
 * 		the average (mean) success rate of all spells in the spellbook (i.e.,
 * 		add up the success rates of all spells in the spellbook, then divide by
 * 		the number of spells in the spellbook).
 * Parameters:
 * 		file (ifstream&): A reference to an std::ifstream that is open on
 * 		the input spellbooks text file and prepared to read information about
 * 		the next spellbook.
 * Returns: The created spellbook structure containing the information of the
 * 		next spellbook in the file
 *
 * Hint: This function will need to call the read_spell_data() function several
 * times in order to read all of the data associated with all of the spells in
 * the given spellbook.
 */
Spellbook read_spellbook_data(ifstream& file);

/*
 * Function: delete_spells
 * Description: Deletes a given dynamic array of spells and updates its pointer
 * 		to be nullptr.
 * Parameters:
 * 		spells (Spell*&): A reference to the pointer that points to the dynamic
 * 			array of spells to be deleted.
 * Post-conditions: 1. Dynamic array of spells should be deleted. 2. spells
 * 		pointer parameter should be set to nullptr. Since this parameter is
 * 		passed by reference, the corresponding argument will be set to nullptr
 * 		as well.
 *
 * Hint: A dynamic array of spells is normally represented with a pointer of
 * type spell* pointing to the array’s base address, but here it’s spell*&.
 * That is, it’s a reference to a spell pointer. This is because the function
 * needs to be able to delete the array that the pointer points to AND modify
 * the pointer itself to be nullptr. In order to be able to modify the pointer
 * itself (which is an argument), the pointer needs to be passed by reference
 * (or passed by pointer---here we use a reference for simplicity).
 */
void delete_spells(Spell*& spells);

/*
 * Function: delete_spellbooks
 * Description: Deletes all of the dynamic memory associated with the given
 * 		array of spellbooks, including the arrays of spells inside each
 * 		spellbook. The size parameter indicates the size of the array of
 * 		spellbooks.
 * Parameters:
 * 		spellbooks (Spellbook*&): A reference to the pointer that points to the
 * 			dynamic array of spellbooks to be deleted
 * Post-conditions: 1. Dynamic arrays of spells within each spellbook should
 * 		be deleted (see hint). 2. Dynamic array of spellbooks should be deleted.
 * 		3. spellbooks pointer parameter should be set to nullptr. Since this
 * 		parameter is passed by reference, the corresponding argument will be set
 * 		to nullptr as well.
 *
 * Hint: This function should call the delete_spells() function several
 * times---once for each spellbook’s array of spells---and then proceed to
 * delete the array of spellbooks itself. spellbooks is passed by reference for
 * the same reason as in the delete_spells() function.
 */
void delete_spellbooks(Spellbook*& spellbooks, int size);

// TODO Prototype more functions here

/*********************************************************************
** Program Filename: FindWizardFile
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: opens the file where the wizard data is stored
** Input: ifstream &w_file
** Output: a string of the wizard file name
*********************************************************************/

string FindWizardFile(ifstream &w_file);

/*********************************************************************
** Program Filename: FindSpellbookFile
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: ** Description: opens the file where the spellbook data is stored
** Input: ifstream &file
** Output: a string of the spellbook file name
*********************************************************************/

string FindSpellbookFile(ifstream &sb_file);

/*********************************************************************
** Program Filename: Read_Spellbook_File
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: calls functions to create the spellbook array
** Input: ifstream &file
** Output: returns spellbook array
*********************************************************************/

Spellbook* Read_Spellbook_File(ifstream &file);

/*********************************************************************
** Program Filename: Read_Wizard_File
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: calls functions to create the wizard array
** Input: ifstream &file
** Output: returns wizard array
*********************************************************************/

Wizard* Read_Wizard_File(ifstream &file);

/*********************************************************************
** Program Filename: Read_Wizard_Data
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: reads a line of wizard data and returns it
** Input: ifstream &file
** Output: returns the wizard object
*********************************************************************/

Wizard Read_Wizard_Data(ifstream &file);

/*********************************************************************
** Program Filename: Create_Wizards
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: creates the wizard array
** Input: int size
** Output: returns wizard object
*********************************************************************/

Wizard* Create_Wizards(int size);

/*********************************************************************
** Program Filename: Login
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: checks the input of ID and password to see if the user is a valid, then print the welcome statement and runs the options function
** Input: ifstream &file, Wizard* wizard, Spellbook* spellbook, ifstream& sb_file, string spellb_file, string wiz_file
** Output: returns 1 or 0
*********************************************************************/

bool Login(ifstream &file, Wizard* wizard, Spellbook* spellbook, ifstream& sb_file, string spellb_file, string wiz_file);

/*********************************************************************
** Program Filename: Options
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: holds a switch statement which runs functions depending on the user input
** Input: Wizard* wizard, Spellbook* spellbook, ifstream& file, string wizard_position, int sb_size, int w_size
** Output: a return value of 0 or 4
*********************************************************************/

int Options(Wizard* wizard, Spellbook* spellbook, ifstream& file, string wizard_position, int sb_size, int w_size);

/*********************************************************************
** Program Filename: Display_All
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: Displays all spellbooks and spells
** Input: Spellbook* spellbook, ifstream& file, Wizard* wizard, string wizard_position, int sb_size
** Output: all spellbooks and spells
*********************************************************************/

void Display_All(Spellbook* spellbook, ifstream& file, Wizard* wizard, string wizard_position, int sb_size);

/*********************************************************************
** Program Filename: Search_By_Name
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: allows the user to search for a spellbook and its spells based off the name of a spellbook
** Input: Spellbook* spellbook, int sb_size
** Output: the spellbook and spells in that spellbook
*********************************************************************/

int Search_By_Name(Spellbook* spellbook, int sb_size);

/*********************************************************************
** Program Filename: Search_By_Effect
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: allows the user to search for a spell based off of its type
** Input: Spellbook* spellbook, string wizard_position, int sb_size
** Output: all spellbooks and the type of spell in each spellbook the user wanted to see
*********************************************************************/

int Search_By_Effect(Spellbook* spellbook, string wizard_position, int sb_size);

/*********************************************************************
** Program Filename: delete_wizards
** Author: Dylan Peniuk
** Date: 10/27/24
** Description: deletes the array of wizards
** Input: Wizard*& wiz, int size
** Output: nothing
*********************************************************************/

void delete_wizards(Wizard*& wiz, int size);

#endif
