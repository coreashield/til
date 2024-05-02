class MaxSecond {
    public static void main(String[] args) {
        int[] arry = {-2,-3,-1,-4,-5,8};
        int maxNumber = 0;
        int secondNumber = 0;

        for(int i = 0; i < arry.length; i++){
            if(i == 0){
                maxNumber = arry[i];
                continue;
            }

            else if(i == 1){
                if(maxNumber >= arry[i] ){
                    secondNumber = arry[i];
                }
                else{
                    secondNumber = maxNumber;
                    maxNumber = arry[i];
                }
                continue;
            }
            
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
