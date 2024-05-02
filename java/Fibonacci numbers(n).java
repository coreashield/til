class Fibo {
    public static void main(String[] args) {
        int n = 10; //
        int[] fiboArry = new int[n];
        fiboArry[0] = 0;
        fiboArry[1] = 1;
        for(int i = 2; i < n ; i++){
            fiboArry[i] = fiboArry[i-1]+fiboArry[i-2];
        }

        System.out.println("fiboArry[n] " + fiboArry[n-1]);
    }

    public static int
}
