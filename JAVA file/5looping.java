class looping {
    static public void main(String[] args){
        for(int i=0;i<5;i++){
            System.out.println(i);
        }
        
        int a=1;
        while(a<5){
            if(a==3){
                continue;
            }
            System.out.println(a);
            a++;
        }

        do{
            if(a==5){
                break;
            }
            System.out.println(a);
            a++;
        }while(a<6);
    }
}
