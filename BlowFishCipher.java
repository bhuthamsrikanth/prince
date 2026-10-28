import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.util.Scanner;

public class BlowFishCipher {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        SecretKey key = KeyGenerator.getInstance("Blowfish").generateKey();

        System.out.print("Enter message: ");
        String msg = sc.nextLine();

        if (msg.isEmpty())
            msg = "Hello world";

        Cipher c = Cipher.getInstance("Blowfish");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(msg.getBytes("UTF-8"));

        String encrypted = Base64.getEncoder().encodeToString(enc);

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        String decrypted = new String(dec, "UTF-8");

        System.out.println("Encrypted (Base64): " + encrypted);
        System.out.println("Decrypted: " + decrypted);

        sc.close();
    }
}
