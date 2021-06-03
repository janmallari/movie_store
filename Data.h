#pragma once
using namespace std;
namespace ns
{
	class MovieList
	{
	   private:
		   struct Movie
		   {
			   string code;
         string title;
         string genre;
         int year;
			   struct Movie *next;
		   };
		   Movie *head;
	   public:
		   MovieList();
		   ~MovieList();
		   void appendMovie(string code, string title, string genre, int year);
		   void insertMovie(string code, string title, string genre, int year);
		   void deleteMovie(string code);
		   void showDetails(string code);
		   void displayList();
    };
}