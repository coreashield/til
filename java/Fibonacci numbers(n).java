class Fibo {
    public static void main(String[] args) {
        int n = 10;
        int fiboArry = fiboValue(n);

        // n번째 수열을 알고 싶으면 n-1번째 수열을 출력해야 한다.
        System.out.println("fiboArry[n]: " + fiboArry);
    }

    public static int fiboValue(int n) {
        int[] fiboArry = new int[n];
        fiboArry[0] = 0;
        fiboArry[1] = 1;
        for(int i = 2; i < n; i++){
            fiboArry[i] = fiboArry[i-1] + fiboArry[i-2];
        }
        return fiboArry[n-1];
    }
}
