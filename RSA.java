import java.math.BigInteger;
import java.util.Scanner;

public class RSA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter p: ");
        BigInteger p = sc.nextBigInteger();

        System.out.print("Enter q: ");
        BigInteger q = sc.nextBigInteger();

        BigInteger n = p.multiply(q);

        BigInteger phi = p.subtract(BigInteger.ONE)
                .multiply(q.subtract(BigInteger.ONE));

        BigInteger e = BigInteger.valueOf(17);
        BigInteger d = e.modInverse(phi);

        System.out.println("Public key: (" + e + ", " + n + ")");
        System.out.println("Private key: (" + d + ", " + n + ")");

        System.out.print("Enter message: ");
        BigInteger m = sc.nextBigInteger();

        BigInteger c = m.modPow(e, n);
        System.out.println("Encrypted message: " + c);

        BigInteger dm = c.modPow(d, n);
        System.out.println("Decrypted message: " + dm);

        sc.close();
    }
}


