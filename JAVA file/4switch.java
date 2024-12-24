class switchcode {
    public static void main(String[] args){
        
        char grade='A';
        switch(grade){
            case 'A':
                System.out.println("Good");
            case 'B':
                System.out.println("Well Done");
            case 'C':
                System.out.println("Poor");
            default:
                System.out.println("Invalid grade");
        }
    }
    
}
