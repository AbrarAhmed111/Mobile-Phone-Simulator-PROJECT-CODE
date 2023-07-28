#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;

//CLASSES
class Account {										//INHERITATED CLASS
	protected:
	double balance = 50;
	double price;
	int id;
	string name;
	public:
		void set_balance (double b)
		{
			balance = b;
		}
		void set_name (string n)
		{
			name = n;
		}
		void set_id (int i)
		{
			id = i;
		}
		
		double get_balance ()
		{
			return (balance);
		}
		string get_name ()
		{
			return (name);
		}
		int get_id ()
		{
			return (id);
		}
		
};
class Store : public Account										//DERIVED CLASS
{
		
		
	public:
	void setbook_name(string a)
	{
		name = a;
	}

	void setbook_price(double p)
	{
		price = p;
	}
	
	
	string getbook_name ()
	{
		return (name);
	}
	
	double getbook_price()
	{
		return (price);
	}
};

//CLASSES

//UNIVERSAL VARIABLES
Account guest,user[2];
string name[2];
int ask,ask2;
double subtract;
Store books[10],collection[10];
double a[10];
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
//UNIVERSAL VARIABLES

//FUNCTIONS 
int checkwin();
void board();
void fileinput();
void fileinput(string n); 						//FUNCTION OVERLOADING
void fileread(string n);						//FUNCTION OVERLOADING
void fileread();
void bookstore();
void bookinput();
void bookdisplay();
void checkfile ();
void checkfile (string n);						//FUNCTION OVERLOADING
string implementname (string n);
string implementnamee (string n);
void choice();
void collectiondisplay();
void reading();
void projectBookGeeks ();
void cpatternshow();
void welcomeloop();
void calendar();
void notepad ();
void calculator ();
void givequiz ();
void game1();
void game2();
void game3();
//FUNCTIONS 

int main () //                                        INT MAIN START
{
   
	int asking;

	welcomeloop();
	cout<<endl;
	cpatternshow();
	
	cout<<"\t\t\tPress 1 to Log-in as TEACHER\tPress 2 to Log-in as STUDENT\n\n\n\n"<<endl;

	cin>>asking;
	cin.ignore();
	system("cls");
	switch (asking)
	{
		case 1: {
		
			cpatternshow();
			cout<<"                               TEACHER ACCOUNT                              \n\n\n\n"<<endl;
			
			checkfile();
			fileread();
			
			int s;
			do {
			
			cout<<"\n\n1: MESSENGER \n2: TOOLS \n3: APPS\n4: GAMES\n6: CLOSE PHONE "<<endl;
			
			cin>>s;
			switch (s)
			{
				case 1: {
					system("cls");
					cout<<"\n\n\t ______________________>MESSENGER<______________________\n\n\n";
					
					cout<<"\n\n1: SEND MESSAGE \n2: INBOX\n3: BACK "<<endl;
					
					int s1;
					cin>>s1;
					switch (s1)
						{
						case 1: {
							cout<<"\n\n\t------------------SEND MESSAGE------------------\n\n"<<endl;
							ofstream send ("inboxstudent.txt");
							
							cin.ignore();
							string msg;
								cout<<"Write Message to Student: ";
  							  getline(cin, msg);
  							  cout<<"Message sent successfully...\n\n";
								send <<msg;
								send.close();
								
					
						break;
						}
						case 2: {
							cout<<"\n\n\t------------------INBOX------------------\n\n"<<endl;
							ifstream recieve ("inboxteacher.txt");
							cout<<"Message recieved from Student: ''";
							string stdmsg;
							while (getline(recieve, stdmsg))
							{
								cout<<stdmsg;
							}
							cout<<"''";
						break;
						}
					}
					break;
			}
				case 2: {
					system("cls");
					cout<<"\n\n\t ______________________>TOOLS<______________________\n\n\n";
					int s2;
					cout<<"\n\n1: CALENDAR \n2: NOTEPAD \n3: CALCULATOR\n4:Back "<<endl;
					cin>>s2;
					switch (s2)
					{
						case 1 : {
							calendar();
							
							break;
						}
						case 2 : { 
						cout<<"\n\n\t------------------NOTEPAD------------------\n\n"<<endl;
						cout<<"1:WRITE ON PAGE 1\t\t2:WRITE ON PAGE 2\t\t3: READ"<<endl;
						int ask;
						cin>>ask;
						if (ask == 1)
						{
							ofstream writepage1 ("teachernotes1.txt");
							cin.ignore();
							cout<<"WRITE: ";
							string note1;
							getline (cin, note1);
							writepage1 << note1;
							writepage1.close();
						}
						else if (ask == 3)
						{
							ifstream readpage1 ("teachernotes1.txt");
							string note1;
							cout<<"PAGE 1: "<<endl;
							while (getline(readpage1, note1))
							{
								cout<<note1;
							}
							readpage1.close();
							ifstream readpage ("teachernotes.txt");
							string note;
							cout<<"\nPAGE 2: "<<endl;
							while (getline(readpage, note))
							{
								cout<<note;
							}
							readpage.close();
						}
						else if (ask == 2)
						{
							ofstream writepage ("teachernotes.txt");
							cin.ignore();
							cout<<"WRITE: ";
							string note;
							cin.ignore();
							getline (cin, note);
							writepage << note;
							writepage.close();
						}
							break;
						}
						case 3 : {
							calculator();
							break;
						}
					}
					break;
				}
				case 3: {
					system("cls");
					cout<<"\n\n\t ______________________>APPLICATIONS<______________________\n\n\n";
					cout<<"\n\n1: BOOK GEEKS \n2: GIVE QUIZ \n3:Back "<<endl;
					int s4;
					cin>>s4;
					if (s4 == 1)
					{
						system("cls");
						projectBookGeeks();
					}
					else if (s4 == 2)
					{
						system("cls");
						givequiz ();
					}
					
					break;
				}
				case 4: {
					system("cls");
					cout<<"\n\n\t ______________________>GAMES<______________________\n\n\n";
					cout<<"\n\n1: ROCK PAPER SCISSOR \n2: TIC TAC TOE \n3: HANGMAN \n4:Back "<<endl;
					int s5;
					cin>>s5;
					if (s5 == 1)
					{
						system("cls");
						game1();
					}
					else if (s5 == 2)
					{
						
						game2();
					}
					else if (s5 == 3)
					{
						system("cls");
						cout<<"\n\n\t------------------GUESSING GAME------------------\n\n\n\n"<<endl;
						game3();
					}
					break;
				}
				default: {
					
					break;
				}
			
		}
				
		}

	while (s != 6);
	cout<<"Closing Phone...Comeback Anytime!";
		break;
	
		}
		case 2: {
			cpatternshow();
			cout<<"                               STUDENT ACCOUNT                              \n\n\n\n"<<endl;
			checkfile(name[1]);
			fileread(name[1]);
			
			int s;
			do {
			
			cout<<"\n\n1: MESSENGER \n2: TOOLS \n3: APPS\n4: GAMES\n5: GO BACK\n6: CLOSE PHONE "<<endl;
			
			cin>>s;
			switch (s)
			{
				case 1: {
					system("cls");
					cout<<"\n\n\t ______________________>MESSENGER<______________________\n\n\n";
					
					cout<<"\n\n1: SEND MESSAGE \n2: INBOX\n3: BACK "<<endl;
					
					int s1;
					cin>>s1;
					switch (s1)
						{
						case 1: {
							cout<<"\n\n\t------------------SEND MESSAGE------------------\n\n"<<endl;
							ofstream send ("inboxteacher.txt");
							
							cin.ignore();
							string msg;
								cout<<"Write Message to Teacher: ";
  							  getline(cin, msg);
  							  cout<<"Message sent successfully...\n\n";
								send <<msg;
								send.close();
								
					
						break;
						}
						case 2: {
							cout<<"\n\n\t------------------INBOX------------------\n\n"<<endl;
							ifstream recieve ("inboxstudent.txt");
							cout<<"Message recieved from Teacher: ''";
							string stdmsg;
							while (getline(recieve, stdmsg))
							{
								cout<<stdmsg;
							}
							cout<<"''";
						break;
						}
					}
					break;
			}
				case 2: {
					system("cls");
						cout<<"\n\n\t ______________________>TOOLS<______________________\n\n\n";
					int s2;
					cout<<"\n\n1: CALENDAR \n2: NOTEPAD \n3: CALCULATOR\n4:Back "<<endl;
					cin>>s2;
					switch (s2)
					{
						case 1 : {
							system("cls");
							calendar();
							
							break;
						}
						case 2 : { 
						system("cls");
						cout<<"\n\n\t------------------NOTEPAD------------------\n\n"<<endl;
						cout<<"1:WRITE ON PAGE 1\t\t2:WRITE ON PAGE 2\t\t3: READ"<<endl;
						int ask;
						cin>>ask;
						if (ask == 1)
						{
							ofstream writepage1 ("studentnotes1.txt");
							cin.ignore();
							cout<<"WRITE: ";
							string note1;
							getline (cin, note1);
							writepage1 << note1;
							writepage1.close();
						}
						else if (ask == 3)
						{
							ifstream readpage1 ("studentnotes1.txt");
							string note1;
							cout<<"PAGE 1: "<<endl;
							while (getline(readpage1, note1))
							{
								cout<<note1;
							}
							readpage1.close();
							ifstream readpage ("studentnotes.txt");
							string note;
							cout<<"\nPAGE 2: "<<endl;
							while (getline(readpage, note))
							{
								cout<<note;
							}
							readpage.close();
						}
						else if (ask == 2)
						{
							ofstream writepage ("studentnotes.txt");
							cin.ignore();
							cout<<"WRITE: ";
							string note;
							cin.ignore();
							getline (cin, note);
							writepage << note;
							writepage.close();
						}
							break;
						}
						case 3 : {
							system("cls");
							calculator();
							break;
						}
					}
					break;
				}
				case 3: {
					system("cls");
					cout<<"\n\n\t ______________________>APPLICATIONS<______________________\n\n\n";
					cout<<"\n\n1: BOOK GEEKS \n2: GIVE QUIZ \n3:Back "<<endl;
					int s4;
					cin>>s4;
					if (s4 == 1)
					{
						system("cls");
						projectBookGeeks();
					}
					else if (s4 == 2)
					{
						system("cls");
						givequiz ();
					}
					
					break;
				}
				case 4: {
					system("cls");
					cout<<"\n\n\t ______________________>GAMES<______________________\n\n\n";
					cout<<"\n\n1: ROCK PAPER SCISSOR \n2: TIC TAC TOE \n3: GUESSING GAME \n4:Back "<<endl;
					int s5;
					cin>>s5;
					if (s5 == 1)
					{system("cls");
						game1();
					}
					else if (s5 == 2)
					{
						game2();
					}
					else if (s5 == 3)
					{
						system("cls");
						cout<<"\n\n\t------------------GUESSING GAME------------------\n\n\n\n"<<endl;
						game3();
					}
					break;
				}
				default: {
					
					break;
				}
			
		}
		}
	while (s != 6);

	cout<<"Closing Phone...Comeback Anytime!";
		break;
		}
	}

	
	

}

string implementname (string n) //user 1
{
	
	user[0].set_name(n);
	return (user[0].get_name());
}

string implementnamee (string n) //user 2
{
	
	user[1].set_name(n);
	return (user[1].get_name());
}

void bookinput()

{
		
		books[0].setbook_name("The Hitchhiker's Guide to the Galaxy");
		books[0].setbook_price(7.99);
		books[1].setbook_name("To Kill a Mockingbird");
		books[1].setbook_price(9.99);
		books[2].setbook_name("The Lord of the Rings");
		books[2].setbook_price(24.99);
		books[3].setbook_name("The Catcher in the Rye");
		books[3].setbook_price(8.99);
		books[4].setbook_name("1984");
		books[4].setbook_price(10.99);
		books[5].setbook_name("Harry Potter and the Philosopher's Stone");
		books[5].setbook_price(12.99);
		books[6].setbook_name("Pride and Prejudice");
		books[6].setbook_price(7.99);
		books[7].setbook_name("The Great Gatsby");
		books[7].setbook_price(6.99);
		books[8].setbook_name("One Hundred Years of Solitude");
		books[8].setbook_price(11.99);
		books[9].setbook_name("Animal Farm");
		books[9].setbook_price(5.99);
}

void bookdisplay()
{
	bookinput();
	for (int i = 0; i < 10; i++) {
	
    	cout<<"\nBook no"<<i+1<<" : ";
        cout<< books[i].getbook_name()<< ": \t$"<< books[i].getbook_price()<<"\n\n"<<endl;
    }
}

void choice() 
{
	if (ask == 1)
    {
    	subtract = subtract-books[0].getbook_price();
    	collection[0].setbook_name(books[0].getbook_name()) ;
    	a[0] = {7.99};
    	
	}
	else if (ask == 2)
	{
		subtract =subtract-books[1].getbook_price();
		collection[1].setbook_name(books[1].getbook_name()) ;
		collection[1].setbook_price(books[1].getbook_price());
		a[1] = {9.99};
		
	}
	else if (ask == 3)
	{
		subtract =subtract-books[2].getbook_price();
		collection[2].setbook_name(books[2].getbook_name()) ;
		collection[2].setbook_price(books[2].getbook_price());
		a[2] = {24.99};
	}
	else if (ask == 4)
	{
		subtract =subtract-books[3].getbook_price();
		collection[3].setbook_name(books[3].getbook_name()) ;
		collection[3].setbook_price(books[3].getbook_price());
		a[3] = {8.99};
	}
	else if (ask == 5)
	{
		subtract =subtract-books[4].getbook_price();
		collection[4].setbook_name(books[4].getbook_name()) ;
		collection[4].setbook_price(books[4].getbook_price());
		a[4] = {10.99};
	}
	else if (ask == 6)
	{
		subtract =subtract-books[5].getbook_price();
		collection[5].setbook_name(books[5].getbook_name()) ;
		collection[5].setbook_price(books[5].getbook_price());
		a[5] = {12.99};
		
	}
	else if (ask == 7)
	{
		subtract =subtract-books[6].getbook_price();
		collection[6].setbook_name(books[6].getbook_name()) ;
		collection[6].setbook_price(books[6].getbook_price());
		a[6] = {7.99};
	}
	else if (ask == 8)
	{
		subtract =subtract-books[7].getbook_price();
		collection[7].setbook_name(books[7].getbook_name()) ;
		collection[7].setbook_price(books[7].getbook_price());
		a[7] = {6.99};
	}
    else if (ask == 9)
	{
		subtract =subtract-books[8].getbook_price();
		collection[8].setbook_name(books[8].getbook_name()) ;
		collection[8].setbook_price(books[8].getbook_price());
		a[8] = {11.99};
	}
	else if (ask == 10)
	{
		subtract =subtract-books[9].getbook_price();
		collection[9].setbook_name(books[9].getbook_name()) ;
		collection[9].setbook_price(books[9].getbook_price());
		a[9] = {5.99};
		
		
	}
}

void collectiondisplay()
{

	for (int i = 0; i < 10; i++) {
	if (a[i] > 0) {

    	cout<<"\nBook no"<<i+1<<" : ";
        cout<< collection[i].getbook_name()<<"\n\n"<<endl;
	}
	}
}
void reading()
{
	if (ask2 == 1)
    {
    	cout<<"The Hitchhiker's Guide to the Galaxy\n\n"<<endl;
    	cout<<"The story follows the adventures of an unwitting human named Arthur Dent and his friend Ford Prefect, an alien researcher for the eponymous Hitchhiker's Guide to the Galaxy. The book begins with Earth being destroyed to make way for a hyperspace bypass, but Arthur and Ford escape just in time by hitching a ride on a spaceship. From there, they embark on a series of absurd and often dangerous adventures throughout the galaxy, encountering a host of strange characters, including a depressed robot, a two-headed alien president, and a planet that's home to the most intelligent creatures in the universe. Along the way, they search for the answer to the ultimate question of life, the universe, and everything, which is famously revealed to be 42. They also discover that the entire universe is in fact a giant computer designed to find the question to the answer of 42. The Hitchhiker's Guide to the Galaxy is known for its irreverent humor, zany characters, and satirical take on science fiction tropes. It has since become a cultural phenomenon, spawning a radio series, a TV series, a movie, and numerous sequels and adaptations.\n\n";
    	
	}
	else if (ask2 == 2)
	{
		cout<<"To Kill a Mockingbird\n\n"<<endl;
		
	}
	else if (ask2 == 3)
	{
		cout<<"The Lord of the Rings\n\n"<<endl;
	}
	else if (ask2 == 4)
	{
		cout<<"The Catcher in the Rye\n\n"<<endl;
	}
	else if (ask2 == 5)
	{
		cout<<"1984\n\n"<<endl;
	}
	else if (ask2 == 6)
	{
		cout<<"Harry Potter and the Philosopher's Stone\n\n"<<endl;
		
	}
	else if (ask2 == 7)
	{
		cout<<"Pride and Prejudice\n\n"<<endl;
	}
	else if (ask2 == 8)
	{
		cout<<"The Great Gatsby\n\n"<<endl;
	}
    else if (ask2 == 9)
	{
		cout<<"One Hundred Years of Solitude\n\n"<<endl;
	}
	else if (ask2 == 10)
	{
		cout<<"Animal Farm\n\n"<<endl;
		
	}
	
}
void fileinput(string n)
{
	ofstream fileinput ("account1data.txt");
	cout<<"Your Name: ";
	cin>>n;
	fileinput << implementnamee(n)<<endl;	
	fileinput.close();
}
void fileread(string n)

{
	ifstream fileread ("account1data.txt");
	string ns = implementnamee(n);
	while (fileread >> ns )
	{
	cout<<"Welcome "<<ns;
	}
	fileread.close();

}

void fileinput()
{
	ofstream fileinput ("accountdata.txt");
	cout<<"Your Name: ";
	cin>>name[0];
	fileinput << implementname(name[0])<<endl;	
	fileinput.close();
}

void fileread()
{
	ifstream fileread ("accountdata.txt");
	string ns = implementname(name[0]);
	while (fileread >> ns )
	{
	cout<<"Welcome "<<ns;
	}
	fileread.close();

}

void projectBookGeeks ()
{
		
	
		cout<<">>>                               BOOK GEEKS                               <<<\n\n\n\n\n\n"<<endl;
	int s;
		cout<<"Loging as Guest"<<endl;
			{	cout<<"\n\n\t ______________________>GUEST ACCOUNT<______________________\n\n\n"<<endl;
				
    			cout<<"\n!_____________>>>WELCOME "<<" TO THE BOOK GEEKS<<<_____________!\n"<<endl;
				int s3;
				subtract = guest.get_balance();
				do {
					
				
				cout<<"Press 1 to Enter Book Store\tPress 2 to Check Account Library\tPress 4 to Exit"<<endl;
				cin>>s3;
				switch (s3)
				{
					case 1: {
						cout<<"\n\n\t------------------BOOK STORE------------------\n\n"<<endl;
						
						cout<<"Account Balance Status: "<<subtract<<"$"<<endl;
						cout<<"ATTENTION!!! (your are using Guest Account therefore Books to buy will be limited for you!)\n\n\n\n\n\n";
						bookdisplay();
						if (subtract > 3 && subtract != 0)
						{
						cout<<"Select Book to buy: ";
						cin>>ask;
						choice();
						cout<<"Purchased Completed!"<<endl;
						cout<<"Your Current Balance: "<<subtract<<"$"<<endl;
						break;
						}
						else 
						{
							cout<<"Account Balance limit Reached... Register Your Account to buy more books"<<endl;
						}
						
						
						break;
					}
			
					case 2: {
						cout<<"\n\n\t------------------Account Library------------------\n\n"<<endl;
						cout<<"These Books you can read for now: "<<endl;
						cout<<"ATTENTION!!! (your are using Guest Account therefore Books to read will be limited for you!)\n\n\n";
						choice();
						collectiondisplay();
						int s4;
						cout<<"Press 1 to Enter READING SECTION Press 2 to Go Back Press 5 to EXIT"<<endl;
						cin>>s4;
						switch (s4)
						{
							case 1 : {
								cout<<"\n\n\t ______________________>READING BOOKS<______________________\n\n\n"<<endl;
								cout<<"ATTENTION!!! (your are using Guest Account therefore Books to read will be as summary for you!)\n\n\n";
								collectiondisplay();
								cout<<"Select Which Book to read: ";
								cin>>ask2;
								reading();
								break;
							}
							
							default :
							break;
								
								
								
						}
						break;
					}
				
					default :
					break;
				}
			
			}
			while (s3 !=4);
			}
		

cout<<"Ending Program...Comeback Anytime!";
}
void checkfile (string n)
{
	ifstream fileread ("account1data.txt");
	
	if (fileread.peek() == ifstream::traits_type::eof())
	{
		fileinput(n);
	}
}
void checkfile ()
{
	ifstream fileread ("accountdata.txt");
	
	if (fileread.peek() == std :: ifstream::traits_type::eof())
	{
		fileinput();
	}
}

void cpatternshow ()
{
	for (int i = 0; i <6; i++)
{
	if (i > 0)
	{
	cout<<"*";
	}
	else
	cout<<" ";	
}
cout<<"\t\t\t\t\t\t  MY PHONE";
cout<<endl;

for (int i = 0; i <2; i++)
{
	for (int j = 0; j <4; j++)
	{

	if ( (i != 2 && j != 1) || (i == 0 && j == 1))
	{
		cout<<"*";
		for(int i =1; i <6; i++)
		{
			cout<<" ";
		}
	}
	else
	{		   
		for(int i =1; i <7; i++)  
		{
		cout<<" ";
		}
	}
	}
	cout<<endl;
}

for(int i=1; i < 9; i++)
{
	if(i == 1)
	{
		cout<<"*";
	}
	cout<<" ";
}
for(int i=1; i < 7; i++)
		{
			
			cout<<"*";
			if (i == 6)
			
			for(int j=1; j < 7; j++)
			{
				if (j == 1)
				{
					cout<<" ";
				}
				cout<<"*";
			}
			
		}
		
cout<<endl;

		

for (int i = 0; i <2; i++)
{
	for (int j = 0; j <4; j++)
	{

	if ( (i != 2 && j != 1) || (i == 1 && j == 1))
	{
		cout<<"*";
			for(int i =1; i <6; i++)
		{
			cout<<" ";
		}
	}
	else
		for(int i =1; i <7; i++)  
		{
		cout<<" ";
		}
	}
	
	cout<<endl;
	
}
for (int i = 0; i <6; i++)
{
	if (i > 0)
	{
	cout<<"*";
	}
	else
	cout<<" ";	
}	
}
void welcomeloop()
{
	
char h = 'a';
char e = 'a',l='a',l2 = 'a',o = 'a';
char d ='a', u = 'a', n = 'a', k = 'a',y = 'a', a = 'a', a2 = 'a';
char id[10];
id [0] = 'T', id [1] = 'E', id[2] = 'A', id[3] = 'C', id[4] = 'H', id[5] = 'E', id[6] = 'R';
//cout<<"Write Your First Name: ";
//cin>>id;
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING.\t\t\t\t"<<h;
	h++;
	cout<<endl;
	if (h == 'H')
	{
		cout<<"LOADING..\t\t\t\t"<<h<<endl;
		break;
	}
	}
	while (h!='H');
	}
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING...\t\t\t\t"<<h<<e;
	e++;
	cout<<endl;
	if (e == 'E')
	{
		cout<<"LOADING.\t\t\t\t"<<h<<e<<endl;
		break;
	}
	}
	while (e!='E');
	}
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING..\t\t\t\t"<<h<<e<<l;
	l++;
	cout<<endl;
	if (l == 'L')
	{
		cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<endl;
		break;
	}
	}
	while (l !='L');
	}
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2;
	l2++;
	cout<<endl;
	if (l2 == 'L')
	{
		cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<endl;
		break;
	}
	}
	while (l2!='L');
	}
	for (int i =0; i< 1; i++)
	{
	do {
	cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o;
	o++;
	cout<<endl;
	if (o == 'O')
	{
		cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<endl;
		break;
	}
	}
	while (o!='O');
	}
	for(int i = 0; i<7; i++)
	{
		cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<o<<endl;
	}
	for(int i = 0; i<7; i++)
	{
		cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o<<endl;
	}
	for(int i = 0; i<7; i++)
	{
		cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<endl;
	}
	
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d;
	d++;
	cout<<endl;
	if (d == id[0])
	{
		cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<endl;
		break;
	}
	}
	while (d != id[0]);
	}
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u;
	u++;
	cout<<endl;
	if (u == id[1])
	{
		cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<endl;
		break;
	}
	}
	while (u !=id[1]);
	}
	
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n;
	n++;
	cout<<endl;
	if (n == id[2])
	{
		cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<endl;
		break;
	}
	}
	while (n !=id[2]);
	}
	
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k;
	k++;
	cout<<endl;
	if (k == id[3])
	{
		cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<endl;
		break;
	}
	}
	while (k !=id[3]);
	}
	
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y;
	y++;
	cout<<endl;
	if (y == id[4])
	{
		cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<endl;
		break;
	}
	}
	
	while (y !=id[4]);
	}
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a;
	a++;
	cout<<endl;
	if (a == id[5])
	{
		cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a<<endl;
		break;
	}
	}
	while (a !=id[5]);
	}
	for (int i =0; i< 2; i++)
	{
	do {
	cout<<"LOADING...\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a<<a2;
	a2++;
	cout<<endl;
	if (a2 == id[6])
	{
		cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a<<a2<<endl;
		break;
	}
	}
	while (a2 !=id[6]);
	}
	
	
	for(int i = 0; i<200; i++)
	{
	cout<<"LOADING.\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a<<a2<<endl;
	}
	for(int i = 0; i<200; i++)
	{
	cout<<"LOADING..\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a<<a2<<endl;
	}
	for(int i = 0; i<200; i++)
	{
	cout<<"\t\t\t\t\t"<<h<<e<<l<<l2<<o<<" "<<d<<u<<n<<k<<y<<a<<a2<<endl;
	}
	system("cls");
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLOADING COMPLETED.";
	}
void calendar()
{
							int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
						    string monthNames[] = {"January", "February", "March", "April", "May", "June",
						                           "July", "August", "September", "October", "November", "December"};
						
						    cout << "----------------- Calendar 2023 -----------------" << endl;
						
						    int monthChoice;
						
						    do {
						        cout << "Enter the month number (1-12): ";
						        cin >> monthChoice;
						    } while (monthChoice < 1 || monthChoice > 12);
						
						    int startingDayOfWeek = 1; 
						
						    int month = monthChoice - 1;
						
						    cout << endl;
						    cout << "********** " << monthNames[month] << " **********" << endl;
						    cout << "-------------------------------------------" << endl;
						    cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;
						
						    for (int i = 0; i < startingDayOfWeek; i++) {
						        cout << "     ";
						    }
						
						    int dayOfWeek = startingDayOfWeek;
						
						    for (int day = 1; day <= daysInMonth[month]; day++) {
						        if (day < 10) {
						            cout << " ";
						        }
						        cout << day << "   ";
						
						        if (dayOfWeek == 0) {
						            cout << endl;
						        }
						
						        dayOfWeek = (dayOfWeek + 1) % 7;
						    }
						
						    cout << endl;
						    cout << "-------------------------------------------" << endl;

}

void notepad ()
{
	
	
}

void calculator ()
{
	 double num1, num2;
    char op;

    cout << "Simple Calculator" << endl;
    cout << "-----------------" << endl;

    // Input first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Input operator
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    // Input second number
    cout << "Enter the second number: ";
    cin >> num2;

    double result;

    // Perform calculation based on the operator
    switch (op) {
        case '+':
            cout<< num1 + num2;
            break;
        case '-':
            cout<< num1 - num2;
            break;
        case '*':
            cout<< num1 * num2;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                cout<< num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return ;
            }
            break;
        default:
            cout << "Error: Invalid operator." << endl;
            return ;
    }
}

void givequiz ()
{
	int subjects,x,y,z;
	cout<<"\n                                                GIVE QUIZ                                                \n"<<endl;
				cout<<"\n\nEnter 1 for ENGLISH\nEnter 2 for MATH\nEnter 3 for Science\nEnter 4 for Computer\nEnter 5 To go back"<<endl;
	cin>>subjects;
	switch (subjects)
	{
		case 1:	
				cout<<"!____________________________________>>>ENGLISH<<<____________________________________!\n";
				cout<<"\n\nTEST STARTED!\n\n"<<endl;
				cout<<"Qno1: Which one is vowel?\n1: K\n2: L\n3: M\n4: O"<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno2: Identify noun in the following sentence: I live in germany. \n1: I\n2: live\n3: in\n4: germany."<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno3: Identify pronoun in the following sentence: They were having dinner.\n1. They\n2. were \n3. having \n4. dinner"<<endl;
				cin>>x;
				if(x == 1)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 2)&&(x <= 5) && (x != 1))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno4: Identify verb in the following sentence: The monkey sat by the door..\n 1. The \n 2. Monkey \n 3. sat \n 4. by \n 5. door"<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno5: Identify adverb in the following sentence: Marcus always arrives early. \n1. arrives \n2. always \n3. early \n4. Marcus"<<endl;
				cin>>x;
				if(x == 2)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 2))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Your MCQs Score: "<<z<<endl;
				
		break;
		
		case 2:
				cout<<"!____________________________________>>>MATH<<<____________________________________!\n";
				cout<<"\n\nTEST STARTED!\n\n"<<endl;
				cout<<"Qno1: What number follows 5? \n1. 3 \n2. 7 \n3. 5 \n4. 6"<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno2: The answer of 2+2 = ? \n1. 3 \n2. 4 \n3. 7 \n4. 9"<<endl;
				cin>>x;
				if(x == 2)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 2))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno3: The answer of 2x5 = ? \n1. 5 \n2. 4 \n3. 11 \n4. 10"<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno4: The answer of 34-2= ? \n1. 30 \n2. 40 \n3. 32 \n4. 19"<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno5: Which number is greater 12,34,56 \n1. 12 \n2. 34 \n3. 56 "<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Your MCQs Score: "<<z<<endl;
				
		break;
		
		case 3:
				cout<<"!____________________________________>>>SCIENCE<<<____________________________________!\n";
				cout<<"\n\nTEST STARTED!\n\n"<<endl;
				cout<<"Qno1: Which animal never drinks water? \n1. Kangaroo \n2. Hippopotamus \n3. Rat \n 4. Kangaroo Rat"<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno2: The SI Unit of Speed is:? \n1. M/S \n2. Cm/kg \n3. Km/H \n4. none"<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno3: The Largest Cell is? \n1. Nerve Cell \n2. Ovum \n3. The egg of an Ostrich \n4. none"<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno4: How many planets are there in our solar system? \n1. 4 \n2. 9 \n3. 8 \n4. 10 "<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno5: The Center of Atom is called? \n1. nucleus \n2. proton \n3. electron \n4. none"<<endl;
				cin>>x;
				if(x == 1)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x > 1)&&(x <= 5) && (x != 1))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Your MCQs Score: "<<z<<endl;
				
		break;
		
		case 4:
				cout<<"!____________________________________>>>COMPUTER<<<____________________________________!\n";
				cout<<"\n\nTEST STARTED!\n\n"<<endl;
				cout<<"Qno1: What is the brain of a computer system called? \n1. RAM \n2. CPU \n3. ROM \n4. GPU"<<endl;
				cin>>x;
				if(x == 2)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 2))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno2: What does ALU stand for in the context of computer? \n1. Array logic unit \n2. Application logic unit \n3. Arithematic logic unit \n4. Automatic logic unit"<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno3: What is the role of computer port? \n1. Downloading file \n2. communicating with computer peripherals \n3. Linking to computer cpu \n4. none"<<endl;
				cin>>x;
				if(x == 2)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 2))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno4: What is known as temporary memory or volatile memory ? \n1. SSD \n2. HDD \n3. ROM \n4. RAM"<<endl;
				cin>>x;
				if(x == 4)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 4))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Qno5: Who is known as father of computer? \n1. Bill Gates \n2. James Gostling \n3. Charles Babbage \n4. Dennis Ritchie"<<endl;
				cin>>x;
				if(x == 3)
				{
					cout<<"Correct Answer!\n"<<endl;
					z++;
				}
				else if ((x >= 1)&&(x <= 5) && (x != 3))
				{
					cout<<"Incorrect Answer!\n"<<endl;
				}
				else
				{
					cout<<"INVALID INPUT!\n"<<endl;
				}
				cout<<"Your MCQs Score: "<<z<<endl;
		break;
		
		default :
		break;	
	}
}

void game1()
{
	
cout<<"                                                   ROCK, PAPER, SCISSORS                                                   \n\n";
		
    		int player,player2;
    		string name2,name;
    		cout << "Hello Players, and welcome to Rock, Paper, Scissors!\nRules of the game are: \n\n1) Rock beats scissors\n2) Scissors beats paper\n3) Paper beats rock.\n";
    		cout<<"\nPlayer 1 Please Enter your name: "; cin>> name2;
    		cout<<"\nPlayer 2 Please Enter your name: "; cin>> name;
    		if (name2 >= "a" && name2 <= "z" || name2 >= "A" && name2 <= "Z" || name >= "z" || name >= "Z" )
    		{cout <<"\n"<<name<<" Please make your choice: \n\nPick 0 for rock, 1 for paper and 2 for scissors." << endl;
    		cin >> player;
    		system("cls");
			cout <<name2<<" Please make your choice: \n\nPick 0 for rock, 1 for paper and 2 for scissors." << endl;
    		cin >> player2;
    		system("cls");
			switch(player2)
			{
        case 0:
            if (player == 0)
            {
                cout << "\n"<<name<<" picked rock, and the "<<name2<<" picked rock. The game is tied!\n";
            }
            else if (player == 1)
            {
                cout << "\n"<<name<<" picked paper, and the "<<name2<<" picked rock. "<<name<<" wins!\n";
            }
            else if (player == 2)
            {
                cout << "\n"<<name<<" picked scissors, and the "<<name2<<" picked rock. "<<name2<<" wins!\n";
            }
            break;
        case 1:
            if (player == 0)
            {
                cout << "\n"<<name<<" picked rock, and the "<<name2<<" picked paper. "<<name2<<" wins!\n";
            }
            else if (player == 1)
            {
                cout << "\n"<<name<<" picked paper, and the "<<name2<<" picked paper. The game is tied!\n";
            }
            else if (player == 2)
            {
                cout << "\n"<<name<<" picked scissors, and the "<<name2<<" picked paper. "<<name<<" wins!\n";
            }
            break;
        case 2:
            if (player == 0)
            {
                cout << "\n"<<name<<" picked rock, and the "<<name2<<" picked scissors. "<<name<<" wins!\n";
            }
            else if (player == 1)
            {
                cout << "\n"<<name<<" picked paper, and the "<<name2<<" picked scissors. "<<name2<<" wins!\n";
            }
            else if (player == 2)
            {
                cout << "\n"<<name<<" picked scissors, and the "<<name2<<" picked scissors. The game is tied!\n";
            }
            break;
        default:
            cout << "Invalid number, try again" << endl;
            break;
}
}
}
void game2()
{
		int player = 1,i,choice;

    char mark;
    do
    {
        board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();

        player++;
    }while(i==-1);
    board();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
}
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}
void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

void game3()
{
	unsigned maxguess(0);
    string hidden("concealed");
    string answer("*********");
    char guess;
    do
    {
        cout << "Uncovered: >>" << answer << "<< Your guess pls: "; 
        cin >> guess;
        for(int i = 0; i < hidden.length(); i++)
        {
            if (guess == hidden[i])
                answer[i] = guess;
        }
    } while (++maxguess < 7);
    cout << "Game over: >>" << answer << "<<";
}
