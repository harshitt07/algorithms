import java.io.*;
class PG211 {
    public static void main(String args[])throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);
        System.out.print("Enter the String in UPPERCASE :  ");
        String str = in.readLine(); // THE CAPITAL OF INDIA IS NEW DELHI.
        int p = str.length();
        String word = "";
        char ch;
        for(int i=0;i<p;i++)
        {   
            ch = str.charAt(i);
            if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
                word = word + ch;
            if(ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U')
            {
                char chr = (char)( (int)ch - 1);
                if(chr=='A' || chr=='E' || chr=='I' || chr=='O' || chr=='U')
                    word = word + (char) ((int)ch + 1);
                else
                    word = word + chr;
            }
        }
        System.out.println(word);
    }
}