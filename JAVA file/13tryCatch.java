import java.util.Scanner;
class errorExample{
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        System.out.println("Enter the number: ");
        int a=cin.nextInt();
        int b=cin.nextInt();
        try{
            System.out.println("The division of two numbers is: "+(a/b));
        }
        catch(ArithmeticException e){
            System.out.println("Nonzero number is not divisible by zero");
            System.out.println(e);
        }
        finally{
            System.out.println("I'm in finally block");
        }
    }
}