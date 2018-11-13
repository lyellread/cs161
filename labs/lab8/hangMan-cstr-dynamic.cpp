
#include <iostream>
#include <string.h>

using namespace std;


void get_string(char * message){

   cout << "Enter the string: " << endl;
   cin.ignore();
   cin.getline(message, 255, '\n');

}

void set_replace_string(char * original, char * blanks){

   for(int i = 0; i < strlen(original); i++){
	if(original[i] >= 97 && original[i] <= 122){
	    blanks[i] = ('-');
	} else {
	    blanks[i] = (' ');
	}
   }

}

int get_search_replace(char ch, char * original, char * blanks){

   int counter = 0;
   for(int i = 0; i < strlen(original); i++){
	if(original[i] == ch){
	    blanks[i] = ch;
	    counter++;
	}
   }
   return counter;

}

int main(){
   
   //string working_str;
   //string str_ptr;

   char ch;
   int len;

   cin >> len;   
   
   cout << len << endl;
   //char message[256];
   //char rep[256];

   char * message = new char[len+1];
   char * rep = new char[len+1];

   //cout << "*str_ptr: " << str_ptr << endl;
   //cout << "working_str: " << working_str << endl;
   get_string(message);

   cout << message << endl;


   set_replace_string(message, rep);

   cout << rep << endl;

   
   cout << "Char from usr:";
   cin >> ch;

   get_search_replace(ch, message, rep);
   
   cout << rep << endl;
   delete[] message;
   delete[] rep; 
   /*

   set_replace_string(str_ptr, &working_str);

   cout << "working_str: " << working_str << endl;

   char ch;
   cout << "Enter the letter: ";
   cin >> ch;

   int count = get_search_replace(ch, str_ptr, working_str);

   cout << "Count: " << count << endl;
   cout << "working_str: " << working_str << endl;
   */
}
