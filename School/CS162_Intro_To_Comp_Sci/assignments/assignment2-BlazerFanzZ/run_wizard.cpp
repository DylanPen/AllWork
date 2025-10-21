#include "catalog.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

int main()
{
	// TODO Complete the main() function (remember to keep it small for
	// modularity)
	ifstream wizard_file, spellbook_file;
	string sb_file, w_file;
	w_file = FindWizardFile(wizard_file);
	sb_file = FindSpellbookFile(spellbook_file);
	// if(First_Inputs(wizard_file, spellbook_file)){
	// 	return 1;
	// }
	Spellbook* book = Read_Spellbook_File(spellbook_file);
	// for(int i = 0; i < 8; i++){
	// 	cout << book[i].title << endl;
	// }
	Wizard* wizard = Read_Wizard_File(wizard_file);
	// for(int i = 0; i < 20; i++){
	// 	cout << wizard[i].name << endl;
	// }
	Login(wizard_file, wizard, book, spellbook_file, sb_file, w_file);
	return 0;
}
