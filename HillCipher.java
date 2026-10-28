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

