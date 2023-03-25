package Java.work.item4;
import java.util.Scanner;

public class demo1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        switch (num){
            case 1:
                System.out.println("赤");
                break;
            case 2:
                System.out.println("橙");
                break;
            case 3:
                System.out.println("黄");
                break;
            case 4:
                System.out.println("绿");
                break;
            case 5:
                System.out.println("青");
                break;
            case 6:
                System.out.println("蓝");
                break;
            case 7:
                System.out.println("紫");
                break;

        }
    }
}
