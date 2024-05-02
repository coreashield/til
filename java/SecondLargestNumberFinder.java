class MaxSecond {
    public static void main(String[] args) {
        int[] arry = {-2,-3,-1,-4,-5,8,0};
        int maxNumber = arry[0];
        int secondNumber = arry[1];
        
        //for문에 들어있을 필요가 없음
        if( maxNumber < secondNumber)
        {
            maxNumber = arry[1];
            secondNumber = arry[0];
        }
            
        for(int i = 2; i < arry.length; i++){
            //현재가 max값보다 클 때 첫번째,두번째 수 변경
            if( maxNumber <= arry[i] ){
                secondNumber = maxNumber;
                maxNumber = arry[i];
            }

            else if( maxNumber >= arry[i] && secondNumber <= arry[i] ){
                secondNumber = arry[i];
            }
        }
        System.out.println("secondMax : " + secondNumber);
    }
}
