import java.util.Scanner;
import java.util.Base64;
import javax.crypto.*;
import javax.crypto.spec.DESedeKeySpec;

public class DES {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String msg = sc.nextLine();

        String k = "ThisIsSecretEncryptionKey";
        DESedeKeySpec ks = new DESedeKeySpec(k.getBytes("UTF8"));
        SecretKey key = SecretKeyFactory.getInstance("DESede")
                .generateSecret(ks);

        Cipher c = Cipher.getInstance("DESede");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(msg.getBytes("UTF8"));
        String encrypted = Base64.getEncoder().encodeToString(enc);

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(Base64.getDecoder().decode(encrypted));

        System.out.println("\nString To Encrypt : " + msg);
        System.out.println("Encrypted Value   : " + encrypted);
        System.out.println("Decrypted Value   : " + new String(dec, "UTF8"));

        sc.close();
    }
}

