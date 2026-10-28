import javax.crypto.*;
import java.util.Scanner;

public class AES {
    public static String hex(byte[] data) {
        String s = "";
        for (byte b : data)
            s += String.format("%02x", b & 255);
        return s;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter message: ");
        String msg = sc.nextLine();

        KeyGenerator kg = KeyGenerator.getInstance("AES");
        kg.init(128);
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("AES");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(msg.getBytes("UTF-8"));

        System.out.println("Encrypted string: " + hex(enc));

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        System.out.println("Original string: " +
                new String(dec, "UTF-8") + " " + hex(dec));

        sc.close();
    }
}

