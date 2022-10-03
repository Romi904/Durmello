import java.util.Scanner;
import java.io.*;
class inputwritefileread{
    public static void main(String args[]){
        try{
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a String!");
        String s = sc.nextLine();
        
       FileWriter fw = new FileWriter("abc.txt");
       fw.write(s);
       fw.flush();
       fw.close();

       // All at once
       FileReader fr =new FileReader("abc.txt");
       int a = fr.read();
       while(a != -1){
        sout((char)a)
        a = fr.read();
       }
       fr.close();
    } catch(Exception e){
        e.printStackTrace();
    }
}
}
