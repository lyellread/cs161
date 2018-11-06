
#include <iostream>
#include <string>

using namespace std;


void get_string(string *str_ptr){

   cout << "Enter the string: " << endl;
   getline(cin, *str_ptr);

}

void set_replace_string(string original, string *str_ptr){

   for(int i = 0; i < original.length(); i++){
	if(original[i] >= 97 && original[i] <= 122){
	    (*str_ptr).append("-");
	} else {
	    (*str_ptr).append(" ");
	}
   }

}

int get_search_replace(char ch, string original, string &str_ref){

   int counter = 0;
   for(int i = 0; i < original.length(); i++){
	if(original[i] == ch){
	    str_ref[i] = ch;
	    counter++;
	}
   }
   return counter;

}

int main(){
   
   string working_str;
   string str_ptr;

   //cout << "*str_ptr: " << str_ptr << endl;
   //cout << "working_str: " << working_str << endl;
   get_string(&str_ptr);

   set_replace_string(str_ptr, &working_str);

   cout << "working_str: " << working_str << endl;

   char ch;
   cout << "Enter the letter: ";
   cin >> ch;

   int count = get_search_replace(ch, str_ptr, working_str);

   cout << "Count: " << count << endl;
   cout << "working_str: " << working_str << endl;
}
