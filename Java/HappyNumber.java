/*
 * A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
eg  n = 5
 5*5 = 25
 2*2 + 5*5 = 29
 2*2 + 9*9 = 85 
 8*8 + 5*5 = 89 
 8*8 + 9*9 = 145
 1*1 + 4*4 + 5*5 = 42
 4*4 + 2*2 = 20 
 2*2 + 0*0 = 4
 Similarly every number either ends with 4 or 1.
 */
public class HappyNumber {
    public boolean isHappy(int n) {
        while( n!= 4 && n!=1){    // after doing the required process every number ends on either 4 or 1 . 
            int sum = 0;
            while(n>0){
                int rem = n%10;
                 sum =sum + rem * rem;
                n=n/10;
            }
            n = sum;
        }
       return n==1;
    }
}