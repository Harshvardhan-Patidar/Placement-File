class classess {
    String name;
    void soundSystem(String color,String comp_name){
        System.out.println("Sound System colour is "+color+" and Company name is "+comp_name);
    }
    public static void main(String[] args){
        classess obj = new classess();
        obj.soundSystem("Black", "Sony");
        obj.name="Harsh";
        System.out.println(obj.name);
    }
}
