
import java.util.Scanner;

public class SubstitutionCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String b = "zyxwvutsrqponmlkjihgfedcba";

        System.out.print("Enter any string: ");
        String str = sc.nextLine().toLowerCase();

        String encrypt = "";

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);

            if (c >= 'a' && c <= 'z')
                encrypt += b.charAt(c - 'a');
            else
                encrypt += c;
        }

        System.out.println("The encrypted data is: " + encrypt);

        sc.close();
    }
}

