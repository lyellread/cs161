#include <iostream>

using namespace std;

void initialize(int towers[][3], int n){
   
   for(int i = 0; i < n; i++){
      for(int j = 0; j < 3; j++){
	 towers[i][j] = 0; 
      }
   }

   for(int i = 0; i < n; i++){
      towers[i][0] = i + 1;
   }

}

void print_array(int towers[][3], int n){
   for(int i = 0; i < n; i++){
      for(int j = 0; j < 3; j++){
	 cout << towers[i][j] << " ";
      }
      cout<< endl;
   }
   cout << endl;
}

void move_disk(int towers[][3], int n, int from_col, int to_col){

   //tow(n, towers, 0, 2, 1);

   int temp = 0;
   for(int i = 0; i < n; i++){
      if(towers[i][from_col] != 0){
	 temp = towers[i][from_col];
	 towers[i][from_col] = 0;
	 //cout << "temp: " << temp << endl;
	 for(int j = 0; j < n; j++){
            if(towers[j][to_col] != 0){
	       towers[j-1][to_col] = temp;
	       print_array(towers, n);
	       return;
            }
         }
	 towers[n-1][to_col] = temp;
	 print_array(towers, n);
	 return;
      }
   }

}

void tow(int disks, int towers[][3], int from_col, int to_col, int spare){
   if(disks >= 1){
      tow(disks-1, towers, from_col, spare, to_col);
      move_disk(towers, disks, from_col, to_col);
      //print_array(towers, disks);
      tow(disks-1, towers, spare, to_col, from_col);
   }
}

int main(int argc, char* argv[]){

   int n;
   //cout << "Number of disks:" << endl;
   //cin >> n;

   n = int(argv[1][0])-48;

   cout << "N is: " << n << endl;
   
   int towers [n][3];

   initialize(towers, n);

   print_array(towers, n);

   tow(n, towers, 0, 2, 1);

   print_array(towers, n);

}
