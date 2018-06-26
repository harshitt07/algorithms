import java.util.*;

class PG209 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String st,st1="",st2="";
        int i,p;
        char chr;
        System.out.println("Enter String : ");
        st = sc.nextLine();
        
        st = st + ' '; // for storing of the if it appends at the end of the string
        
        p = st.length(); // length of intial string 
        
        for(i=0;i<p;i++)
        {
            chr = st.charAt(i);  // char at every position of string
            if(chr==' ') 
            {
                st2 = st2+' '+st1;
                st1 = " ";
            }
            else
                st1 = chr + st1; // till the next space occur ; it will store the value of every words ; 
        }
        
        System.out.println(st2);
    }
    
}