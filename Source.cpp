#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

// Global Variables
string PlayerN;
string RTitle;
string RDescription;
string RID;
string MName;
string MIntro;
int PHealth = 100;
int Weapon;
int Dmg;
int MDmg;
int MHealth;
int Gold;
int Occ;
int Exit;
int TEntered;
int MEntered;
int CEntered;
int DEntered;
int VEntered;
char Direction;
char Return;

// Function Prototypes
void Greeting();
void PName();
void Intro();
void Occupied();
void Art();
void Look();
void Trap();
void Treasure();
void Merchant();
void Combat();
void Purchase();

// Rooms Class
class Rooms {
public:
	void Hideout() {
		RTitle = "\nHIDEOUT\n";
		RDescription = "A safe haven, boarded up windows and reinforced doors.\n";
		cout << RTitle << RDescription;
		Sleep(2000);
	}
	void Town() {
		RTitle = "DECREPIT TOWN\n";
		RDescription = "Littered in filth and decay. But currently inhabited\nby a travelling merchant.\n\n";
		cout << RTitle;
		if (TEntered == 0) {
			cout << RDescription;
			TEntered = 1;
		}
		do {
			cout << "Where would you like to go?\nM) Merchant\nN) North: Dustlands - Return after clearing to exit\nE) East: Catacombs\nS) South: Vale\nW)West: Marshes\n";
				// Specification C3 - Input Validation
				cin >> Direction;
			Direction = tolower(Direction);
			if (Direction == 'm') {
				Merchant();
			}
			else if (Direction == 'n') {
				Dustlands();
			}
			else if (Direction == 'e') {
				Catacombs();
			}
			else if (Direction == 'w') {
				Marsh();
			}
			else if (Direction == 's') {
				Vale();
			}
		} while (Direction != 'm' && Direction != 'n' && Direction != 'e' &&
			Direction != 'w' && Direction != 's');
	}
	void Marsh() {
		RTitle = "\nMARSH\n";
		RDescription = "Muck and mire, you don't want to stay here long.\n\n";
		cout << RTitle;
		if (MEntered == 0) {
			cout << RDescription;
			Trap();
			Occupied();
			Combat();
			Treasure();
			MEntered = 1;
			cout << "Marsh cleared. Returning to town\n\n";
			Sleep(2000);
		}
		else if (MEntered == 1) {
			cout << "You have traveled here already. Return to town\nor enter 'L' to see where you are.\n";
				cin >> Return;
			Return = tolower(Return);
			if (Return == 'l') {
				Look();
				cout << "Returning to town.\n";
				Sleep(2000);
				Town();
			}
			Town();
		}
	}
	void Catacombs() {
		RTitle = "\nCATACOMBS\n";
		RDescription = "Dim and dreary, some of the tombs have been broken into... or worse.\n\n";
			cout << RTitle;
		// Specification C4 - Abbreviated Room Description
		if (CEntered == 0) {
			cout << RDescription;
			Trap();
			Occupied();
			Combat();
			Treasure();
			CEntered = 1;
			cout << "Catacombs cleared. Returning to town\n\n";
			Sleep(2000);
		}
		else if (CEntered == 1) {
			cout << "You have traveled here already. Return to town\nor enter 'L' to see where you are.\n";
				cin >> Return;
			Return = tolower(Return);
			if (Return == 'l') {
				Look();
				cout << "Returning to town.\n";
				Sleep(2000);
				Town();
			}
			Town();
		}
	}
	// Specification C1 - Five Rooms
	void Vale() {
		RTitle = "\nVALE\n";
		RDescription = "The hidden gem in a world of waste.\n\n";
		cout << RTitle;
		if (VEntered == 0) {
			cout << RDescription;
			Trap();
			Occupied();
			Combat();
			Treasure();
			VEntered = 1;
			cout << "Vale cleared. Returning to town\n\n";
			Sleep(2000);
		}
		else if (VEntered == 1) {
			cout << "You have traveled here already. Return to town\nor enter 'L' to see where you are.\n";
				cin >> Return;
			Return = tolower(Return);
			if (Return == 'l') {
				Look();
				cout << "Returning to town.\n";
				Sleep(2000);
				Town();
			}
			Town();
		}
	}
	// Specification A3 - Extra Room
	void Dustlands() {
		RTitle = "\nDUSTLANDS\n";
		RDescription = "Barren plains, void of life, nothing here except strife.\n\n";
			cout << RTitle;
		if (DEntered == 0) {
			cout << RDescription;
			Trap();
			Occupied();
			Combat();
			Treasure();
			DEntered = 1;
			cout << "Dustlands cleared. Returning to town\n\n";
			Sleep(2000);
		}
		else if (DEntered == 1) {
			cout << "\nLeaving so soon? Return to town or escape this nightmare? (t / e)\n";
				Return = 'x';
			while (Return != 't' && Return != 'e') {
				cin >> Return;
				Return = tolower(Return);
				if (Return == 't') {
					Town();
				}
				else if (Return == 'e') {
					cout << "You wake up in a dark room, foreign... yet familiar...\n";
					exit(0);
				}
			}
		}
	}
};
// Specification B1 - Monster Class
class Monsters {
public:
	void Rat() {
		MHealth = 1;
		MDmg = 3;
		MName = "Rat";
		MIntro = "Out of the corner of your eye, you notice a large rat\ncreeping"
				 "towards you.\nPrepare for battle!\n\n";
			Sleep(3000);
	}
	void Goblin() {
		MHealth = 5;
		MDmg = 5;
		MName = "Goblin";
		MIntro = "There appears to be a child crouched by some debris.\nBeing the"
				 "upstanding citizen you are, you approach.\nUnfortunately for you, it turns"
				 "out to be a small goblin brandishing a blade.\nPrepare for battle!\n\n";
			Sleep(3000);
	}
	void Zombie() {
		MHealth = 10;
		MDmg = 7;
		MName = "Zombie";
		MIntro = "A jawless, flesh rotted zombie notices you trying to sneak past.\nPrepare for battle!\n\n";
			Sleep(3000);
	}
	void Ogre() {
		MHealth = 15;
		MDmg = 9;
		MName = "Ogre";
		MIntro = "As tall as a tree, a fully grown ogre rushes you.\nPrepare for battle!\n\n";
			Sleep(3000);
	}
	// Specification A4 - Extra Monster
	void Necromancer() {
		MHealth = 20;
		MDmg = 12;
		MName = "Necromancer";
		MIntro = "Amidst a crowd of shambling horrors, a necromancer focuses its gaze upon you.\nPrepare for battle!\n\n";
			Sleep(3000);
	}
};
// Specification A1 - Weapons Class
class Weapons {
public:
	void WChoice() {
		cin >> Weapon;
		string W;
		if (Weapon == 1 || Weapon == 2 || Weapon == 3 || Weapon == 4) {
			if (Weapon == 1) {
				Dmg = 1;
				W = "stick";
			}
			else if (Weapon == 2) {
				Dmg = 4;
				W = "knife";
			}
			else if (Weapon == 3) {
				Dmg = 5;
				W = "spear";
			}
			else if (Weapon == 4) {
				Dmg = 7;
				W = "crossbow";
			}
		}
		else {
			cin.clear();
			cin.ignore();
			WChoice();
		}
		cout << "\nWeary and slightly frightened you take your " << W << " and head towards\nthe town Grainchapel.\n\n";
			Sleep(3000);
	}
};
int main() {
	srand(time(0));
	Art();
	Greeting();
	PName();
	Rooms RoomsObject;
	Weapons WeaponsObject;
	RoomsObject.Hideout();
	Intro();
	WeaponsObject.WChoice();
	do {
		RoomsObject.Town();
	} while (Exit == 0);
}
// Program Greeting
void Greeting() {
	cout << "\n\nVerzweiflung is a text-based adventure game. Discover your fate.\n\n\n\n";
}
// Specification C2 - Player Name
void PName() {
	cout << "What is your name adventurer?\n";
	cin >> PlayerN;
}
// Intro
void Intro() {
	cout << "\n\nYou arise in a battered stupor, unsure of how or when you "
			"arrived, but at least\nyou are still breathing.Just as you feel you are "
			"coming to your senses\nthe front door crashes openand a tall shrouded "
			"figure enters. \n'Unbelievable. Welcome back " << PlayerN << "' he says. "
			"You surmise he learned your name\nfrom your journal, you hope.Appearing "
			"to be short on timeand providing little\ninsight onto why he presumably "
			"saved you, he suggests that you grab a weapon\nand be on your way.\n";
		Sleep(15000);
	cout << "\n\nPick a weapon:\n1) Stick\n2) Knife\n3) Spear\n4) Crossbow\n";
}
// Specification C5 - Detailed Look
void Look() {
	cout << RTitle << RDescription;
}

	
	// Specification B2 - Occupied By A Random Monster
	void Occupied() {
		int ROc;
		Monsters MonstersObject;
		ROc = (rand() % 5) + 1;
		if (ROc == 1)
		{
			MonstersObject.Rat();
		}
		if (ROc == 2)
		{
			MonstersObject.Goblin();
		}
		if (ROc == 3)
		{
			MonstersObject.Zombie();
		}
		if (ROc == 4)
		{
			MonstersObject.Ogre();
		}
		if (ROc == 5)
		{
			MonstersObject.Necromancer();
		}
	}
	// Specification B3 - Trap Encounters
	void Trap() {
		int Trap;
		Trap = (rand() % 5) + 1;
		if (Trap == 3) {
			cout << "OH NO! You have wandered into an ambush. You hear something " 
					"rushing\nup behind you, but you are too slow to react...\n";
				PHealth = PHealth - 10;
			cout << "\nYou wake up damaged with " << PHealth << " HP\n\n";
			Sleep(3000);
		}
	}
	// Specification A2 - Treasure
	void Treasure() {
		int Treasure;
		Treasure = (rand() % 3) + 1;
		if (Treasure == 1) {
			cout << "*TREASURE* You found a small coin pouch containing 3 gold!\n\n";
			Gold = Gold + 3;
		}
		if (Treasure == 2) {
			cout << "**TREASURE** You found a lockbox containing 7 gold!\n\n";
			Gold = Gold + 12;
		}
		if (Treasure == 3) {
			cout << "***TREASURE*** You found a gold bar worth 20 gold!\n\n";
			Gold = Gold + 20;
		}
	}
	// Specification A5 - Merchant
	void Merchant() {
		char Offer;
		cout << "Greetings, my name is Lucius, conjurer of tinctures,\nprocurer of desirables.Would you like to see what I have to offer ? (y / n)\n";
			cin >> Offer;
		Offer = tolower(Offer);
		while (Offer != 'y' && Offer != 'n') {
			cin.clear();
			cin.ignore();
			cout << "(y/n)";
			cin >> Offer;
			Offer = tolower(Offer);
		}
		if (Offer == 'y') {
			Purchase();
		}
	}
	void Purchase() {
		int Buy;
		cout << "You currently have " << Gold << " gold\n";
		cout << "1) Healing Potion(+5hp) - 5g\n2) Large Healing Potion(+10hp) - 10g\n3) Greatsword - 50g\n4) Leave\n";
			cin >> Buy;
		if (Buy == 1 && Gold > 4) {
			Gold = Gold - 5;
			cout << "\nPurchased healing potion.\nYou currently have " << Gold << " gold\n";
				PHealth = PHealth + 5;
			cout << "HP: " << PHealth << "\n\n";
		}
		else if (Buy == 1 && Gold < 3) {
			cout << "Not enough gold\n";
			Purchase();
		}
		if (Buy == 2 && Gold > 11) {
			Gold = Gold - 10;
			cout << "\nPurchased large healing potion.\nYou currently have " << Gold
				<< " gold\n";
			PHealth = PHealth + 10;
			cout << "HP: " << PHealth << "\n\n";
		}
		else if (Buy == 1 && Gold < 12) {
			cout << "Not enough gold\n";
			Purchase();
		}
		if (Buy == 3 && Gold > 49) {
			Gold = Gold - 50;
			cout << "\nPurchased greatsword.\nYou currently have " << Gold << " gold\n\n";
				Dmg = 100;
		}
		else if (Buy == 3 && Gold < 50) {
			cout << "Not enough gold\n";
			Purchase();
		}
		if (Buy == 4) {
			return;
		}
	}
	// Specification A6 - Combat
	void Combat() {
		cout << MIntro;
		do {
			cout << MName << " attacks!\n";
			PHealth = PHealth - MDmg;
			cout << PlayerN << " HP: " << PHealth << endl;
			Sleep(1000);
			cout << PlayerN << " attacks!\n";
			Sleep(1000);
			MHealth = MHealth - Dmg;
			cout << MName << " HP: " << MHealth << endl;
			Sleep(1000);
		} while (PHealth >= 1 && MHealth >= 1);
		if (PHealth <= 0) {
			cout << "Death. This is end of your adventure. GAME OVER.\n";
			exit(0);
		}
		if (MHealth <= 0) {
			cout << "\nVICTORY! You loot two gold.\n\n";
			Gold = Gold + 2;
			Sleep(2000);
		}
	}
	// Intro Art
	void Art() {
		cout << R"(
_   _                             _______ _
| | | |                           (_)  ___| |
| | | | ___ _ __ ______      _____ _| |_  | |_   _ _ __   __ _
| | | |/ _ \ '__|_  /\ \ /\ / / _ \ |  _| | | | | | '_ \ / _` |
\ \_/ /  __/ |   / /  \ V  V /  __/ | |   | | |_| | | | | (_| |
\___/ \___|_|  /___|  \_/\_/ \___|_\_|   |_|\__,_|_| |_|\__, |
                                                         __/ |
                                                         |___/
)";
	}
