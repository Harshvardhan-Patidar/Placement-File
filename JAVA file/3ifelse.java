class ifelse {
    public static void main(String[] args){
        int age=18;
        if(age>=18){
            System.out.println("You can vote");
        }
        else if(age<18 && age>3){
            System.out.println("You can not vote");
        }
        else{
            System.out.println("You are a kid, No vote");
        }
    }
}
