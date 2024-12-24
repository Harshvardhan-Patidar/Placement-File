class Multithread extends Thread{
    public void run(){
        System.out.println("Thread is running");
    }
    public static void main(String[] args){
        Multithread t=new Multithread();
        t.start();
    }
}

// OR

class Multithreads implements Runnable{
    public void run(){
        System.out.println("Thread is running");
    }
    public static void main(String[] args){
        Multithreads m=new Multithreads();
        Thread t=new Thread(m);
        t.start();
    }
}