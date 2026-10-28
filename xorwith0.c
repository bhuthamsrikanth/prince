//              1) XOR each character with 0

#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Hello World";
    char str1[12];
    int i, len;

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        str1[i] = str[i] ^ 0;
        printf("%c", str1[i]);
    }

    str1[len] = '\0';

    printf("\n");

    return 0;
}

//              2)XOR each character with 127

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello World";
    char str1[12];
    char str2[12];
    int i, len;

    len = strlen(str);

    printf("%s\n", str);

    for(i = 0; i < len; i++)
    {
        str1[i] = str[i] ^ 127;
    }
    str1[len] = '\0';

    for(i = 0; i < len; i++)
    {
        str2[i] = str1[i] ^ 127;
    }
    str2[len] = '\0';

    printf("%s\n", str2);

    printf("%s\n", str);

    return 0;
}

//              3)Caesar Cipher

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




//              b) Substitution Cipher




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


//              C) Hill Cipher

import java.util.Scanner;
public class HillCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] key = new int[3][3];
        int[] msg = new int[3];
        int[] enc = new int[3];

        System.out.println("Enter 3x3 Key Matrix:");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                key[i][j] = sc.nextInt();

        System.out.print("Enter a 3-letter message: ");
        String str = sc.next().toLowerCase();

        if (str.length() != 3) {
            System.out.println("Message should contain exactly 3 letters.");
            sc.close();
            return;
        }

        for (int i = 0; i < 3; i++)
            msg[i] = str.charAt(i) - 'a';

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                enc[i] += key[i][j] * msg[j];

            enc[i] %= 26;
        }

        System.out.print("Encrypted Message: ");
        for (int i = 0; i < 3; i++)
            System.out.print((char) (enc[i] + 'a'));

        System.out.println();
        sc.close();
    }
}




//              7)  “Hello world” using Blowfish


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


//              8)RSA Algorithm


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




//              9)Diffie-Hellman Key Exchange


<!DOCTYPE html>
<html>
<head>
    <title>Diffie-Hellman</title>
</head>
<body>

<h2>Diffie-Hellman Key Exchange</h2>

Prime p: <input id="p" type="number" value="23"><br><br>
Base g: <input id="g" type="number" value="5"><br><br>
Alice key: <input id="a" type="number" value="4"><br><br>
Bob key: <input id="b" type="number" value="3"><br><br>

<button onclick="run()">Generate Secret</button>

<p>Alice's Public Key: <span id="A"></span></p>
<p>Bob's Public Key: <span id="B"></span></p>
<p>Alice's Shared Secret: <span id="S1"></span></p>
<p>Bob's Shared Secret: <span id="S2"></span></p>

<script>
function pow(g, a, p) {
    let r = 1n;
    g = BigInt(g); a = BigInt(a); p = BigInt(p);

    while (a > 0n) {
        if (a % 2n) r = r * g % p;
        g = g * g % p;
        a /= 2n;
    }
    return r;
}

function run() {
    let p = document.getElementById("p").value;
    let g = document.getElementById("g").value;
    let a = document.getElementById("a").value;
    let b = document.getElementById("b").value;

    if (!p || !g || !a || !b || +p < 2 || +g < 1 || +g >= +p || +a < 1 || +b < 1) {
        alert("Enter valid values");
        return;
    }

    let A = pow(g, a, p), B = pow(g, b, p);
    let S1 = pow(B, a, p), S2 = pow(A, b, p);

    document.getElementById("A").innerText = A;
    document.getElementById("B").innerText = B;
    document.getElementById("S1").innerText = S1;
    document.getElementById("S2").innerText = S2;
}
</script>

</body>
</html>



//              10)SHA-1 Message Digest


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


//              6) (AES) Rijndael algorithm logic

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

//          DES

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

//              BLOWFISH ALGO LOGIC

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

