#include <iostream>
#include "Data.h"
#include <string>
using namespace std;
using namespace ns;

int menu();

int main()
{
  MovieList list;
  string code;
  string title;
  string genre;
  int year;
  int ch;

  do
  {
    ch = menu();
    //system("clear");
    if (ch == 1)
    {
      cout << " << Inserting a Movie >> " << endl
           << endl;
      cout << "Enter a movie code: ";
      cin >> code;
      cout << "Enter movie title: ";
      cin >> title;
      cout << "Enter movie genre: ";
      cin >> genre;
      cout << "Enter year released: ";
      cin >> year;
      list.insertMovie(code, title, genre, year);
    }
    else if (ch == 2)
    {
      cout << " << Deleting a Movie >> " << endl
           << endl;
      cout << "Enter movie code to rent: ";
      cin >> code;
      list.deleteMovie(code);
    }
    else if (ch == 3)
    {
      cout << " << Return Movie >> " << endl
           << endl;
      cout << "Enter a movie code: ";
      cin >> code;
      cout << "Enter movie title: ";
      cin >> title;
      cout << "Enter movie genre: ";
      cin >> genre;
      cout << "Enter year released: ";
      cin >> year;
      list.appendMovie(code, title, genre, year);
    }
    else if (ch == 4)
    {
      cout << " << Show Movie Details >> " << endl
           << endl;

      cout << "Enter movie code: ";
      cin >> code;
      list.showDetails(code);
      system("sleep 3s");
    }
    else if (ch == 5)
    {
      cout << " << Print Movie List >> " << endl
           << endl;
      list.displayList();
      system("sleep 3s");
    }
    else if (ch == 6)
    {
      cout << "Thank you for using the program!" << endl;
      list.~MovieList();
      exit(0);
    }
    else
    {
      cout << "Invalid Input!" << endl
           << endl;
      break;
    }
    cout << endl;
  } while (ch >= 1 && ch <= 5);
}

int menu()
{
  int ch;
  system("clear");
  cout << " << Movie Store >> " << endl
       << endl;
  cout << "[1] Insert a new Movie" << endl;
  cout << "[2] Rent a Movie" << endl;
  cout << "[3] Return a Movie" << endl;
  cout << "[4] Show Movie Details" << endl;
  cout << "[5] Print Movie List" << endl;
  cout << "[6] Quit the Program" << endl
       << endl;
  cout << "Enter Choice: ";
  cin >> ch;
  return (ch);
}