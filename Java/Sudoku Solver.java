class Solution
{
    //Function to find a solved Sudoku. 
    static boolean SolveSudoku(int grid[][])
   {
       // add your code here
       return Sudoku(grid);
   }
   
   static boolean Sudoku(int grid[][]){
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               if(grid[i][j]==0){
                   for(int v = 1;v<=9;v++){
                       if(isSafe(grid,i,j,v)){
                           grid[i][j]=v;
                           if(Sudoku(grid)){
                               return true;
                           }
                           else{
                               grid[i][j]=0;
                           }
                       }
                   }
                   return false;
               }
           }
       }
       return true;
   }
   
   static boolean isSafe(int[][] grid,int row,int col,int v){
       for(int i=0;i<9;i++){
           if(grid[i][col]==v)return false;
           if(grid[row][i]==v)return false;
           if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==v)return false;
       }
       return true;
   }
   
   //Function to print grids of the Sudoku.
   static void printGrid (int grid[][])
   {
       // add your code here
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               System.out.print(grid[i][j]+" ");
           }
       }
   }
}