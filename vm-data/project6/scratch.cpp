
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct test {
  int ** pointer;
  int rows;
  int cols;
};




void doot (test grid){
  cout << "POINTER: " << grid.pointer << endl;
  cout << "ROW: " << grid.rows << endl;
  cout << "COL: " << grid.cols << endl;
}






int main(){

  test grid;

  int rows = 4;
  int cols = 5;

  grid.cols = cols;
  grid.rows = rows;


  int ** p2d;
  p2d = new int* [rows];
  for(int i=0; i<rows; i++) {
    p2d[i] = new int[cols];
  }

  cout << "P2D:" << p2d << endl;

    //'blank' out scoresheet to 0's
  for (int row=0; row < rows; ++row){
    for (int col=0; col<cols; ++col){
      p2d[row][col] = 0;
    }
  }

  grid.pointer = p2d;

  //for (int i=0; i<99; i++){
  //  cout << i << endl;

  cout << "POINTER: " << grid.pointer << endl;
  cout << "ROW: " << grid.rows << endl;
  cout << "COL: " << grid.cols << endl;

  cout << "DOOT" << endl;

  doot(grid);
}
