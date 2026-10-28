import java.util.Scanner;
public class CaesarCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter any String: ");
        String str = sc.nextLine();

        System.out.print("Enter the Key: ");
        int key = sc.nextInt();

        String enc = "";
        String dec = "";

        key = key % 26;

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);

            if (c >= 'A' && c <= 'Z')
                c = (char) ('A' + (c - 'A' + key) % 26);
            else if (c >= 'a' && c <= 'z')
                c = (char) ('a' + (c - 'a' + key) % 26);

            enc = enc + c;
        }

        System.out.println("\nEncrypted String: " + enc);

        for (int i = 0; i < enc.length(); i++) {
            char c = enc.charAt(i);

            if (c >= 'A' && c <= 'Z')
                c = (char) ('A' + (c - 'A' - key + 26) % 26);
            else if (c >= 'a' && c <= 'z')
                c = (char) ('a' + (c - 'a' - key + 26) % 26);

            dec = dec + c;
        }

        System.out.println("Decrypted String: " + dec);

        sc.close();
    }
}


