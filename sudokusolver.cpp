#include<bits/stdc++.h>
using namespace std;

bool is_occupied(int x, int y, int s, int *grid, int n)
{   int i, j;
    for(i = 0; i < n ; ++i)
    {
        if( *(grid + x*n + i) == s)
            {
                return true;
            }
    }
        for(i = 0; i < n ; ++i)
    {
        if( *(grid+ i*n + y) == s)
            return true;
    }
    int x1 = x/sqrt(n) , y1 = y/sqrt(n);
    for ( i = sqrt(n)*x1 ; i < sqrt(n)*(x1+1) ; ++i )
    {
        for ( j = sqrt(n)*y1 ; j < sqrt(n)*(y1+1) ; ++j )
         {
                 if ( *(grid+ i*n + j) == s )
                     return true;
         }
    }
  return false;
}
bool is_vacant(int *grid, int n, int &x, int &y )
{
    for (x = 0 ; x < n ; ++x )
    {       for (y = 0 ; y < n ; ++y )
              {
                  if( *(grid+ x*n + y) == 0 )
                      return true;
              }
    }
    return false;
}
bool sudoku(int *grid, int n)
{  int x, y, k;
    if(!is_vacant(grid, n, x, y) )
         return true;
    for ( k = 1; k <= n ; ++k )
    {
    if (is_occupied( x, y, k, grid, n) == false)
       { *(grid + x * n + y) = k;
        if( sudoku(grid, n) == true)
                return true;
        *(grid + x * n + y) = 0;    }

    }
    return false;

}

int main()
{  int n, i, j;
   cout<<"Enter the length of the grid (for ex:9 if 9x9):\n";
   cin>>n;
   int grid[n][n];
   cout<<"Enter the values of the grid starting from left top (enter 0 if the cell is empty):\n";
   for (i = 0 ; i < n ; ++i )
           for (j = 0 ; j < n ; ++j )
                cin >> grid[i][j];

   if (sudoku(&grid[0][0], n) == true )
   {
    for (i = 0 ; i < n ; ++i )
          { for (j = 0 ; j < n ; ++j )
            {    cout<< grid[i][j]<<" ";}
            cout<<"\n";
          }
   }
   else
      cout<<"NO SOLUTION EXISTS"<<endl;
}
