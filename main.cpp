#include <iostream>
using namespace std;

// Corrected function
void print (char q[][3]) { // Assume q is a 2D array with 3 columns
    cout<<"        |       |      "<<endl;
  cout << "\t"<<q[0][0] << "\t" << "|\t" << q[0][1] << "\t" << "|\t" << q[0][2] << "\t"<<endl;
  
   cout << "_ _ _ _ | _ _ _ | _ _ _ _" << endl;
   cout<<"        |       |      "<<endl;
  cout << "\t"<<q[1][0] << "\t" << "|\t" << q[1][1] << "\t" << "|\t" << q[1][2] << "\t"<<endl;
  cout << "_ _ _ _ | _ _ _ | _ _ _ _" << endl;
  cout<<"        |       |      "<<endl;
  cout << "\t"<<q[2][0] << "\t" << "|\t" << q[2][1] << "\t" << "|\t" << q[2][2] << "\t"<<endl;
  cout<<"        |       |      "<<endl;
}

bool full(char q[][3]){
 for (int i=0; i<3; i++){
for (int j=0; j<3; j++){
  if (q[i][j]=='.'){
    return false;
  }
}
 }
  return true;
}

bool win(char q[][3], int r, int c){
  
    for (int i = 0; i < 3; i++) {
    for (int j=0; j<3; j++){
    if (q[i][j]==q[(i+1)%3][j] && q[i][j]==q[(i+2)%3][j] && q[i][j]!='.'){
      return true;
    }
    else if (q[i][j]==q[i][(j+1)%3] && q[i][j]==q[i][(j+2)%3] && q[i][j]!='.'){
      return false;
    }
    }
    }
    if ((q[0][0]==q[1][1] && q[0][0]== q[2][2] && q[0][0]!='.') || (q[0][2]==q[1][1] && q[0][2] == q[2][0] && q[0][2]!='.')){
      return true;
    }
  return false;
}
   
  


int main() {
char q[3][3]={};
for (int i=0; i<3; i++){
for (int j=0; j<3; j++){
  q[i][j]= '.';
}
}
int move=1;
int row1, col1, row2, col2;
print(q);

while (!full(q)){
 move++;
  if (move % 2==0){
    cout<<"player 1, place the row and column for your next move"<<endl;
    cout<<"row:";
    cin>>row1;
    cout<<"column";
    cin>>col1;
    while (q[row1][col1] !='.'){
      cout<<"sorry, invalid position, try again:";
      cin>>row1;
      cout<<"column";
      cin>>col1;
    }
    q[row1][col1]='X';
    print(q);
    if (win (q, row1, col1)){
      cout<<"PLAYER 1 WINS!!";
      return 0;
    }
  }
  if (move % 2!=0){
    cout<<"player 2, place the row and column for your next move"<<endl;
    cout<<"row:";
    cin>>row2;
    cout<<"column";
    cin>>col2;
    while (q[row2][col2] !='.'){
      cout<<"sorry, position already taken, try again:";
      cin>>row2;
      cout<<"column";
      cin>>col2;
    }
    q[row2][col2]='O';
    print(q);
    if (win (q, row2, col2)){
      cout<<"PLAYER 2 WINS!!";
      return 0;
    }
  }
}
  cout<<"Its a tie"<<endl;
  return 0;
}
