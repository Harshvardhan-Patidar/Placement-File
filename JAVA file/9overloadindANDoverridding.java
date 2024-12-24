class overloading{
    static int add(int a,int b){
        return a+b;
    }
    static double add(double a,double b){
        return a+b;
    }
    public static void main(String[] args){
        System.out.println(add(4,5));
    
        System.out.println(add(4.5,5.5));
    }
}


class father{
    void work(){
        System.out.println("father is working");
    }
}
class child extends father{
    void work(){
        System.out.println("Son is playing");
    }
}
class overridding{
    public static void main(String[] args){
        child obj=new child();
        obj.work();
    }
}