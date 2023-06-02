#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool gameEnd(bool &tie, char table[][3]) 	//table, tie 
{
    for (int i = 0; i < 3; i++)
    {
        if (table[i][0] == table[i][1] && table[i][0] == table[i][2] || table[0][i] == table[1][i] &&table[0][i] == table[2][i])
        return false;
    }
    if (table[0][0] == table[1][1] && table[0][0] == table[2][2] || table[0][2] == table[1][1] && table[0][2] ==table[2][0])
	{
        
		return false;
    }

    for (int i = 0; i < 3; i++)
    {
    	for (int j = 0; j < 3; j++)
    	{
    	    if (table[i][j] != 'X' && table[i][j] != 'Y')
		    {
                return true;
            }  	
		}
	}
	
    tie = true;
    return false;
}

void display(char table[][3], string name1, string name2)
{
	
	system("cls");
	cout << "-------------------------T I C   T A C   T O E ---------------" << endl<<endl;
	cout<<" \t\t"<<name1<<" [X]  vs "<<name2<<" [Y] \n\n";
	cout<<"\t" <<table[0][0] <<"	 	|     " <<table[0][1]<<	  "		|	" <<table[0][2]  <<"         \n";	
	cout<<"\t------------------------------------------------------\n";
	cout<<"\t" <<table[1][0] <<"	 	|     " <<table[1][1]<<	  "		|	" <<table[1][2]  <<"         \n";
	cout<<"\t------------------------------------------------------  \n";
	cout<<"\t" <<table[2][0] <<"	 	|     " <<table[2][1]<<	  "		|	" <<table[2][2]  <<"         \n";	
	cout<<endl<<endl;
}

void spin(char &turn, char table[][3], string name1,string name2) 
{
	int choice,row,col;
    if (turn == 'X' ) 
	{
        cout << "\t "<<name1<<" [X] your turn : ";
        cin >> choice;
        while ( choice < 1 || choice > 9)
		{
		
    	cout << "ERROR!! INVALID INPUT! TRY AGAIN ";
        cin >> choice;
    	}
}

    if (turn == 'Y') 
	{
        cout << "\t "<<name2<<" [Y] Now its your turn : ";
        cin >> choice;
        while ( choice < 1 || choice > 9){
		
        cout<<"ERROR!! INVALID INPUT! TRY AGAIN ";
        cin>>choice;
    }
}

    switch (choice)
    {
    case 1: 
		row = 0; col = 0; 
		break;
    case 2: 
		row = 0; col = 1; 
		break;
    case 3: 
		row = 0; col = 2; 
		break;
    case 4: 
		row = 1; col = 0;
		break;
    case 5: 
		row = 1; col = 1; 
		break;
    case 6: 
		row = 1; col = 2; 
		break;
    case 7: 
		row = 2; col = 0; 
		break;
    case 8: 
		row = 2; col = 1; 
		break;
    case 9: 
		row = 2; col = 2; 
		break;
    default:
        cout << "\t " << " INVALID Selection !!! "<< endl;
       break;
        
    }
    if (turn == 'Y' && table[row][col] != 'X' &&table[row][col] != 'Y')
	{
        table[row][col] = 'Y';
        turn = 'X';
    }
    else if (turn == 'X' && table[row][col] != 'X' && table[row][col] != 'Y') 
	{
       table[row][col] = 'X';
       turn = 'Y';
    }
    else 
	{
        cout << "\t "<< "hahaha!!! Table Filled Try Again!"<< endl;
        spin(turn,table,name1,name2);
    }
    display(table,name1,name2);
    
}
int main()
 {
	
	char turn = 'X';
	string name1;
	string name2;
	char choice;
	char select ;
	int count1=0,count2=0,again=0,draw=0;
	ofstream outputFile;
	outputFile.open("game.txt");
	if(outputFile.fail())
	{
		cout<<" Error !!! try again ";
	}
	else
	{
		cout<<" Enter the name of player 1 [X] ";
		cin>>name1;
		cout<<" Enter the name of player 2 [Y] ";
		cin>>name2;
		outputFile<<"\t\t\t"<<name1 <<" vs "<<name2<<endl<<endl;
	do
    {		
	char table[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	bool tie = false;
    while (gameEnd(tie, table)) 
	{
        display(table,name1,name2);
        spin(turn,table,name1,name2);      
    }
    
    if (turn == 'Y' && tie == false) 
	{
        cout << "\t\t "<< " Congarts!!! "<<name1<<" [X]  WINS! " << endl;
        outputFile<< "\t\t "<< " Congarts!!! "<<name1<<" [X]  WINS! " << endl;
        count1++;
    }
    else if (turn == 'X'  && tie == false)
    {
        cout << "\t\t "<< " Congrts!!! "<<name2<<" [Y]  WINS! " << endl;
        outputFile<< "\t\t "<< " Congarts!!! "<<name2<<" [X]  WINS! " << endl;
        count2++;
    }
    else
    {
        cout << "\t\t "<< "HAHHAHH!!  GAME TIE !! " << endl;
        outputFile << "\t\t "<< "HAHHAHH!!  GAME TIE !! " << endl;
        draw++;
    }
    cout << " Do you want to play again  Y/N " ;
    cin >> select ;
    again++;
    }while ( select == 'y' ||select == 'Y' ) ;
    if(select=='N'||select=='n')
    {
    	outputFile<<"\t\t"<<"Total playing games are "<<again<<endl;
    	outputFile<<"\t\t"<<name1<<"\t"<<"wons"<<"\t"<<count1<<" games"<<endl;
    	outputFile<<"\t\t"<<name2<<"\t"<<"wons"<<"\t"<<count2<<" games"<<endl;
    	outputFile<<"\t\t"<<"Draw games are "<<draw;
	}
    outputFile.close();
	}

   return 0 ;
}
