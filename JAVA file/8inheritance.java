class baseClass {
    void parent(){
        int pProperty=5;
        System.out.println("Father property: "+pProperty);
    }
}
class derivedClass extends baseClass{
    void child(int pProperty){
        int cProperty=1+pProperty;
        System.out.println("Child property: "+cProperty);
    }
}
class mainProgram{
    public static void main(String[] args){
        derivedClass obj=new derivedClass();
        obj.parent();
        obj.child(5);
    }
}
