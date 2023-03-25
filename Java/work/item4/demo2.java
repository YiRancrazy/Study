package Java.work.item4;
import java.util.Scanner;
public class demo2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x=200,y=300;
        title:while(true){


            String word = sc.next();
            switch (word){
                case "上":
                    y-=10;
                    break;
                case "下":
                    y+=10;
                    break;
                case "左":
                    x-=10;
                    break;
                case "右":
                    x+=10;
                    break;
                default:
                    break title;
            }

            System.out.println(x+","+y);

        }
        sc.close();
    }
}
