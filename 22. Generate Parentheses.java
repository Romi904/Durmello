class Solution {
    public List<String> generateParenthesis(int n) {
        
            List<String> result=new ArrayList();
            find("(",1,0,result,n);
            return result;
    }
        
        void find(String cur,int open,int close,List<String> result,int n){
                
                if(cur.length()==2*n){
                        result.add(cur);
                        return;
                }
                if(open<n){
                        find(cur+"(",open+1,close,result,n);
                }
                if(close<open){
                       find(cur+")",open,close+1,result,n);
        }
}
  
  public static void main(String [] args){
    int n=3
   System.out.Println(generateParenthesis(n));
  }
}
