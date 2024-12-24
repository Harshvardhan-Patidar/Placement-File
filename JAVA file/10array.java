class oneDarray{
    public static void main(String[] args){
        int arr[]=new int[3];
        arr[0]=10;
        arr[1]=11;
        arr[2]=12;
        for(int i=0;i<3;i++){
            System.out.print(arr[i]+" ");
        }
    }
}

class twoDarray{
    public static void main(String[] args){
        int arr[][]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}