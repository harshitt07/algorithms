import java.util.*;

class PG210 {
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String st,st1,st2="";
        int i,p,f=0;
        char chr;
        System.out.println("Enter String : ");
        st = sc.nextLine();
        System.out.println("Enter Word to be searched : ");
        st1 = sc.nextLine();
        
        st = st + ' '; // for storing of the if it appends at the end of the string
        
        p = st.length(); // length of intial string 
        
        for(i=0;i<p;i++)
        {
            chr = st.charAt(i);  // char at every position of string
            if(chr==' ') //
            {
                if(st2.compareTo(st1)==0) // it will compare the every word store in st2 to st1(the word entered by input)
                    f=f+1;
                st2 = ""; // to flush out previous word 
            }
            else
                st2 = st2 + chr; // till the next space occur ; it will store the value of every words ; 
        }
        
        System.out.println(f);
    }
    
}