import java.util.Scanner;
import java.util.Base64;
import javax.crypto.*;

public class BlowFish {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter message: ");
        String msg = sc.nextLine();

        KeyGenerator kg = KeyGenerator.getInstance("Blowfish");
        kg.init(128);
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("Blowfish");
        c.init(Cipher.ENCRYPT_MODE, key);

        byte[] enc = c.doFinal(msg.getBytes("UTF-8"));

        System.out.println("Encrypted message: " +
                Base64.getEncoder().encodeToString(enc));

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        System.out.println("Decrypted message: " +
                new String(dec, "UTF-8"));

        sc.close();
    }
}

