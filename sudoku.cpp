#include<iostream>
using namespace std;
#define N 9

void print(int g[N][N]){
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << g[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}




bool valid(int puzzle[N][N], int row, int col, int num){
    for(int i=0; i<=8; i++){
        if(puzzle[row][i]==num)
            return false;
        }
    
    for(int i=0; i<=8; i++){
        if(puzzle[i][col]==num){
            return false;
        }
    }
    	int sRow = row - row % 3,
			sCol = col - col % 3;
	     for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (puzzle[i + sRow][j +sCol] == num)
                return false;
 
    return true;
}

bool solve(int puzzle[N][N], int row, int col){
    if(row==N-1 && col==N){
        return true;
    }
    if(col==N){
        row++;
        col=0;
    }
    if (puzzle[row][col] > 0)
		return solve(puzzle, row, col + 1);
	for (int number = 1; number <= N; number++)
	{
		
		if (valid(puzzle, row, col, number))
		{	
		
			puzzle[row][col] = number;
			
			if (solve(puzzle, row, col + 1))
				return true;
		}
	
		puzzle[row][col] = 0;
	}
	return false;
}


int main(){
    int g[N][N];
    cout<<"Enter grid"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0;j<N;j++){
            cin>>g[i][j];
        }
    }
    if(solve(g,0,0)){
        cout<<endl;
        print(g);
    }
    else{
        cout<<"No solution";
    }
    return 0;
}