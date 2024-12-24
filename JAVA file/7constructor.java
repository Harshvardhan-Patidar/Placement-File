class program {
    int a;
    program(){
        System.out.println("Default Constructor call "+a);
    }
    program(program obj2){
        System.out.println("Copy Constructor call "+obj2.a);
    }
    program(int a){
        this.a=a;
        System.out.println("Parameterized Constructor call "+a);
    }
    public static void main(String[] args){
        program p = new program();
        p.a=10;
        program p1 = new program(p);
        p1.a=11;
        program p2 = new program(21);
        p2.a=12;
    }
}
