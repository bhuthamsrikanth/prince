import java.util.Scanner;
import java.security.MessageDigest;

public class SHA1 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String str = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("SHA-1");
        byte[] hash = md.digest(str.getBytes());

        String hex = "";

        for (byte b : hash)
            hex += String.format("%02X", b & 0xFF);

        System.out.println("SHA-1 Message Digest: " + hex);

        sc.close();
    }
}




