#include "catalog.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

// TODO Function definitions go here

string FindWizardFile(ifstream &w_file){
    string wizard_file;
    cout << "What wizard file would you like to choose? ";
    cin >> wizard_file;
    w_file.open(wizard_file);
    if(!w_file){
        cout << "File does not exist." << endl;
        return 0;
    }
    return wizard_file;
}

string FindSpellbookFile(ifstream &sb_file){
    string spellbook_file;
    cout << "What spellbook file would you like to choose? ";
    cin >> spellbook_file;
    sb_file.open(spellbook_file);
    if(!sb_file){
        cout << "File does not exist." << endl;
        return 0;
    }
    return spellbook_file;
}

Wizard* Read_Wizard_File(ifstream &file){
    int size;
    file >> size;
    Wizard* wizards = Create_Wizards(size);
    for(int i = 0; i < size; i++){
        wizards[i] = Read_Wizard_Data(file);
    }
    file.close();
    return wizards;
}

Wizard Read_Wizard_Data(ifstream &file){
    Wizard wizard;
    file >> wizard.name >> wizard.id >> wizard.password >> wizard.position_title >> wizard.beard_length;

    return wizard;
}

Wizard* Create_Wizards(int size){
    Wizard* wizards = new Wizard[size];
    return wizards;
}

Spellbook* create_spellbooks(int size){
    Spellbook* spellbooks = new Spellbook[size];
    return spellbooks;
}

Spellbook* Read_Spellbook_File(ifstream &file){
    int size;
    file >> size;
    Spellbook* books = create_spellbooks(size);
    for(int i = 0; i < size; i++){
        books[i] = read_spellbook_data(file);
    }
    file.close();
    return books;
}

Spellbook read_spellbook_data(ifstream& file){
    Spellbook spellbook;
    file >> spellbook.title >> spellbook.author >> spellbook.num_pages >> spellbook.edition >> spellbook.num_spells;
    spellbook.spells = create_spells(spellbook.num_spells);
    for(int i = 0; i < spellbook.num_spells; i++){
        spellbook.spells[i] = read_spell_data(file);
    }

    return spellbook;
} 

Spell* create_spells(int size){
    Spell* spell = new Spell[size];
    return spell;
}

Spell read_spell_data(ifstream& file){
    Spell spell;
    file >> spell.name >> spell.success_rate >> spell.effect;
    return spell;
}

bool Login(ifstream &file, Wizard* wizard, Spellbook* spellbook, ifstream& sb_file, string spellb_file, string wiz_file){
    int ID, flag = 0, size = 0, end_check, sb_size;
    string password;
    file.open(wiz_file);
    sb_file.open(spellb_file);
    file >> size;
    sb_file >> sb_size;
    do{
        cout << "Please enter your ID: ";
        cin >> ID;
        cout << "Please enter your password: ";
        cin >> password;
        for(int i = 0; i < size; i++){
            if(wizard[i].id == ID && wizard[i].password == password){
                cout << "Welcome " << wizard[i].name << endl;
                cout << "ID: " << wizard[i].id << endl;
                cout << "Status: " << wizard[i].position_title << endl;
                string wizard_position = wizard[i].position_title;
                cout << "Beard Length: " << wizard[i].beard_length << endl;
                do{
                    end_check = Options(wizard, spellbook, sb_file, wizard_position, sb_size, size);
                }
                while(end_check != 4);
                delete_spellbooks(spellbook, sb_size);
                delete_wizards(wizard, size);
                return 0;
            }
        }
        flag++;
        cout << "Incorrect login, " << 3 - flag << " tries remaining" << endl; 
    }
    while(flag < 3);
    delete_spellbooks(spellbook, sb_size);
    delete_wizards(wizard, size);
    return 1;

}

int Options(Wizard* wizard, Spellbook* spellbook, ifstream& file, string wizard_position, int sb_size, int w_size){
    int choice;
    cout << "Which option would you like to choose?" << endl;
    cout << "1. Display all" << endl;
    cout << "2. Search spellbook by its name" << endl;
    cout << "3. Search spells by their effect" << endl;
    cout << "4. Quit" << endl;
    cout << "Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            Display_All(spellbook, file, wizard, wizard_position, sb_size);
            break;
        case 2:
            Search_By_Name(spellbook, sb_size);
            break;
        case 3:
            Search_By_Effect(spellbook, wizard_position, sb_size);
            break;
        case 4:
            return 4;
            break;
    }
    return 0;
}

int Search_By_Effect(Spellbook* spellbook, string wizard_position, int sb_size){
    string spell_effect, filename;
    int display_type;
    bool flag = true;
    ofstream f;
    do{
        cout << "Enter a valid spell effect: ";
        cin >> spell_effect;
    }
    while(spell_effect != "fire" && spell_effect != "bubble" && spell_effect != "memory_loss" && spell_effect != "death" && spell_effect != "poison");
    cout << "How would you like the information displayed?" << endl;
    cout << "1. Pring to screen (press 1)" << endl;
    cout << "2. Pring to file (press 2)" << endl;
    cout << "Your Choice: ";
    cin >> display_type;
    switch(display_type){
        case 1:
            for(int i = 0; i < sb_size; i++){
                cout << spellbook[i].title << " " << spellbook[i].author << " " << spellbook[i].num_pages << " " << spellbook[i].edition << " " << spellbook[i].num_spells << endl;
                for(int j = 0; j < spellbook[i].num_spells; j++){
                    if(wizard_position != "Student" && spellbook[i].spells[j].effect == spell_effect){
                        cout << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
                    }
                    else if(wizard_position == "Student" && spellbook[i].spells[j].effect != "death" && spellbook[i].spells[j].effect != "poison"){
                        cout << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
                    }
                    else{
                        cout << "\t" << endl;
                    } 
                }
            }
            break;
        case 2:
            cout << "Please provide desired filename: ";
            cin >> filename;
            f.open(filename);
            for(int i = 0; i < sb_size; i++){
                f << spellbook[i].title << " " << spellbook[i].author << " " << spellbook[i].num_pages << " " << spellbook[i].edition << " " << spellbook[i].num_spells << endl;
                for(int j = 0; j < spellbook[i].num_spells; j++){
                    if(wizard_position != "Student" && spellbook[i].spells[j].effect == spell_effect){
                        f << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
                    }
                    else if(wizard_position == "Student" && spellbook[i].spells[j].effect != "death" && spellbook[i].spells[j].effect != "poison"){
                        f << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
                    }
                }
            }
            f.close();
            break;
    }
    return 0;
}

int Search_By_Name(Spellbook* spellbook, int sb_size){
    string spellbook_name, filename;
    int input;
    bool flag = true;
    ofstream f;
    do{
        cout << "Spellbook name: ";
        cin >> spellbook_name;
        for(int k = 0; k < sb_size; k++){
            if(spellbook_name == spellbook[k].title){
                flag = false;
            }
        }
        if(flag == true){
            cout << "File does not exist, please try again" << endl;
        }
    }
    while(flag == true);
    for(int i = 0; i < sb_size; i++){
        if(spellbook_name == spellbook[i].title){
            do{
                cout << "How would you like the information displayed?" << endl;
                cout << "1. Print to screen (Press 1)" << endl;
                cout << "2. Print to file (Press 2)" << endl;
                cin >> input;
                switch(input){
                    case 1:
                        cout << spellbook[i].title << " " << spellbook[i].author << " " << spellbook[i].num_pages << " " << spellbook[i].edition << " " << spellbook[i].num_spells << endl;
                        for(int j = 0; j < spellbook[i].num_spells; j++){
                            cout << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
                        }
                        break;
                    case 2:
                        cout << "Please provide desired filename: ";
                        cin >> filename;
                        f.open(filename);
                        f << spellbook[i].title << " " << spellbook[i].author << " " << spellbook[i].num_pages << " " << spellbook[i].edition << " " << spellbook[i].num_spells << endl;
                        for(int j = 0; j < spellbook[i].num_spells; j++){
                            f << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
                        }
                        f.close();
                        break;
                }
            }
            while(input != 1 && input != 2);
        }
    }
    return 0;
}

void Display_All(Spellbook* spellbook, ifstream& file, Wizard* wizard, string wizard_position, int sb_size){
    int size = 0;
    file >> size;
    for(int i = 0; i < 8; i++){
        cout << spellbook[i].title << " " << spellbook[i].author << " " << spellbook[i].num_pages << " " << spellbook[i].edition << " " << spellbook[i].num_spells << endl;
        for(int j = 0; j < spellbook[i].num_spells; j++){
            if(wizard_position != "Student"){
                cout << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
            }
            else if(wizard_position == "Student" && spellbook[i].spells[j].effect != "death" && spellbook[i].spells[j].effect != "poison"){
                cout << "\t" << spellbook[i].spells[j].name << " " << spellbook[i].spells[j].success_rate << " " << spellbook[i].spells[j].effect << endl;
            }
            else{
                cout << "\t" << "Forbidden Spell" << endl;
            }
        }
    }
}

void delete_spells(Spell*& spells){
    if (spells){
        delete [] spells;
        spells = nullptr;
    }
}

void delete_spellbooks(Spellbook*& spellbooks, int size){
    for(int i = 0; i < size; i++){
        delete_spells(spellbooks[i].spells);
    }
    delete [] spellbooks;
    spellbooks = nullptr;
}

void delete_wizards(Wizard*& wiz, int size){
    delete [] wiz;
    wiz = nullptr;
}